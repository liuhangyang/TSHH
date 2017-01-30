//
// Created by yang on 16-8-21.
//

#ifndef TSHH_LOGIN_HPP
#define TSHH_LOGIN_HPP

#include <string>
#include<string.h>
#include <iostream>
#include <python2.7/Python.h>
#include <unordered_map>
class Login {
public:
    Login()= default;
    Login(std::string username,std::string passwd){
        this->username=username;
        this->passwd=passwd;
    }
    std::unordered_map<std::string,std::string> getstuinfo(){
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('./')");
        if(!Py_IsInitialized()){
            std::cout << "init  error"<<std::endl;
        }
        PyObject *pMouble=NULL;
        PyObject *pFunc=NULL;
        pMouble=PyImport_ImportModule("getinfo");
        if(pMouble == NULL){
            std::cout << "import error"<<std::endl;
        }
        pFunc=PyObject_GetAttrString(pMouble,"getinfo");
        if(pFunc == NULL){
            std::cout << "get func error!"<<std::endl;
        }
        PyObject *pArgs=PyTuple_New(2);
        PyTuple_SetItem(pArgs,0,Py_BuildValue("s",username.c_str()));
        PyTuple_SetItem(pArgs,1,Py_BuildValue("s",passwd.c_str()));
        PyObject *pReturn = NULL;
        pReturn = PyEval_CallObject(pFunc,pArgs);
        //int size=PyDict_Size(pReturn);
       // std::cout << "字典的大小:"<<size<<std::endl;

        const char *buf1=NULL;
        const char *status=NULL;

        std::unordered_map<std::string,std::string> info;
        PyObject *pStatus=PyDict_GetItemString(pReturn,"st");
        PyArg_Parse(pStatus,"s",&status);
        if(strcmp(status,"200")==0){
            PyObject *pName =PyDict_GetItemString(pReturn,"xm");
            PyObject *pNumber=PyDict_GetItemString(pReturn,"xh");
            PyObject *pXy=PyDict_GetItemString(pReturn,"xy");
            PyObject *pZy=PyDict_GetItemString(pReturn,"zy");
            PyObject *pXzb=PyDict_GetItemString(pReturn,"xzb");
            const char *name=NULL;
            const char *number=NULL;
            const char *xy=NULL;
            const char *zy=NULL;
            const char *xzb=NULL;
            PyArg_Parse(pName,"s",&name);
            PyArg_Parse(pNumber,"s",&number);
            PyArg_Parse(pXy,"s",&xy);
            PyArg_Parse(pZy,"s",&zy);
            PyArg_Parse(pXzb,"s",&xzb);
        //std::cout << "姓名:"<<buf<<std::endl;
       // PyArg_Parse(pReturn,"s",&buf1);
        info["st"]=status;
        info["xh"]=number;
        info["xm"]=name;
        info["xy"]=xy;
        info["zy"]=zy;
        info["xzb"]=xzb;
        }else{
            const char* value;
            PyObject *pValue =PyDict_GetItemString(pReturn,"value");
            PyArg_Parse(pValue,"s",&value);
            info["st"]=status;
            info["value"]=value;
        }
        Py_Finalize();
        return info;
    }


private:
    std::string username;
    std::string passwd;
};


#endif //TSHH_LOGIN_HPP
