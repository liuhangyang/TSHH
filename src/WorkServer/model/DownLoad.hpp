//
// Created by yang on 16-8-5.
//

#ifndef TSHH_DOWNLOAD_HPP
#define TSHH_DOWNLOAD_HPP

#include <string>
class DownLoad {
public:
    DownLoad() = default;
    ~DownLoad() = default;
    DownLoad(int do_id, int da_id, int t_id)
    {
        this->download_id = do_id;
        this->datad_id = da_id;
        this->ts_id = t_id;
    }

    /*get方法*/
    int get_download_id()
    {
        return this->download_id;
    }
    int get_datad_id()
    {
        return this->datad_id;
    }
    int get_ts_id()
    {
        return this->ts_id;
    }

    /*set方法*/
    void set_download_id( int do_id)
    {
        this->download_id = do_id;
    }
    void set_datad_id( int da_id)
    {
        this->datad_id = da_id;
    }
    void set_ts_id( int t_id)
    {
        this->ts_id = t_id;
    }

private:
    int download_id;        /*主键*/
    int datad_id;           /*确定资料  外键*/
    int ts_id;              /*下载者ID  外键*/
};


#endif //TSHH_DOWNLOAD_HPP
