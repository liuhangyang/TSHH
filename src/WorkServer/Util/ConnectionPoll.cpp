//
// Created by yang on 16-8-4.
//

#include "ConnectionPoll.h"

ConnectionPoll * ConnectionPoll::connPool=nullptr;
//构造函数
ConnectionPoll::ConnectionPoll(std::string url, std::string user, std::string password, int maxSize) {
    this->url=url;
    this->username=user;
    this->password=password;
    this->maxSize=maxSize;
    //得到mysql驱动
    driver=get_driver_instance();
    //开始初始化大小为maxSize的一半
    InitConnection(maxSize/2);

}
/*
 * 初始化连接池
 */
void
ConnectionPoll::InitConnection(int iInitialSize) {
    std::lock_guard<std::mutex> locker(mutex);
    Addconn(iInitialSize);
}

/**
 * 创建一个连接
 * @return
 */
Connection* ConnectionPoll::CreateConnection(){
    Connection *conn=driver->connect(this->url,this->username,this->password);  //建立连接
    return conn;
}

/*
 * 添加连接
 */
void
ConnectionPoll::Addconn(int size){
    if(this->getCurSize()+size >=this->getMaxSize()){
        return;
    }
    for(int i=0;i<size;i++){
        Connection *conn=this->CreateConnection();
        std::shared_ptr<Connection> sp(conn,[](Connection *conn){
            delete conn;
        });
       /* std::shared_ptr<Connection> sp(conn);
        delete conn;*/
        connlist.push_back(std::move(sp));
        this->curSize++;
    }
}
/**
 * 销毁连接池
 */
void
ConnectionPoll::DestoryConnPool(){
   for(auto &conn:connlist){
       std::shared_ptr<Connection> &&sp=std::move(connlist.front());
       sp->close();
   }
}
/**
 *   销毁一个连接
 */
void
ConnectionPoll::DestoryOneConn() {
    std::shared_ptr<Connection> &&sp=std::move(connlist.front());
    sp->close();
}
/**
 *  销毁连接池首先销毁连接池中的连接.
 */
ConnectionPoll::~ConnectionPoll() {
   this->DestoryConnPool();
}
/**
 *
 * 扩大数据库连接池
 */
void
ConnectionPoll::EnlargeConn(int size) {
    std::lock_guard<std::mutex> locker(mutex);
    this->Addconn(size);
    this->curSize+=size;
}
/**
 * 缩小连接池
 */
void
ConnectionPoll::ReduceConn(int size) {
    std::lock_guard<std::mutex> locker(mutex);
    if(curSize < size){
        return;
    }
    for(int i=0;i<size;i++){
        this->DestoryOneConn();
    }
    this->curSize-=size;
}
/**
 *
 *  得到连接池实例
 */
ConnectionPoll*
ConnectionPoll::GetInstance() {
    if(connPool == NULL) {
        connPool = new ConnectionPoll("tcp://127.0.0.1", "root", "root", 50);
    }
        return connPool;

}
/*
 * 返回当前已经在使用的连接.
 */
int
ConnectionPoll::getCurSize() {
    return  curSize;
}
/*
 * 返回连接池的最大容量.
 */
int
ConnectionPoll::getMaxSize() {
    return maxSize;
}
/*
 * 获得一条数据库连接
 */
std::shared_ptr<Connection>
ConnectionPoll::GetConnection(){
    Connection *conn;
    std::lock_guard<std::mutex> locker(mutex);
    if(connlist.size() > 0){
        std::shared_ptr<Connection> sp=connlist.front();
        connlist.pop_front();
        if(sp->isClosed()){
            std::cout << "cdcd"<<std::endl;
            conn=this->CreateConnection();
            if(conn==NULL){
                --curSize;
            }else{
                std::cout << "ddddddd"<<std::endl;
                std::shared_ptr<Connection> sp(conn,[](Connection *conn){
                    delete conn;
                });
            }
        }
        return  sp;

    }else{
            conn=this->CreateConnection();
            if(conn){
                ++curSize;
                std::shared_ptr<Connection> sp(conn,[](Connection *conn){
                    delete conn;
                });
                return sp;
            }

    }
  //  std::cout << "feifei"<<std::endl;*/
       //    return sp;
    std::cout << "yang"<<std::endl;
    return NULL;
}

/**
 *将数据库连接放回连接池的容器中
 */
 void
ConnectionPoll::ReleaseConnection(std::shared_ptr<Connection> &ret){
    std::lock_guard<std::mutex> locker(mutex);
    connlist.push_back(ret);
}



