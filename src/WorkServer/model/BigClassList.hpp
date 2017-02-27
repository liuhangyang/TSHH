//
// Created by yang on 16-8-5.
//

#ifndef TSHH_BIGCLASSLIST_HPP
#define TSHH_BIGCLASSLIST_HPP


class BigClassList {

public:
    BigClassList() = default;
    ~BigClassList() = default;
    BigClassList( int big_cl_id, int single_cl_id )
    {
        this->big_class_id = big_cl_id;
        this->single_class_id = single_cl_id;
    }
    /*get 方法*/
    int get_big_class_id()
    {
        return this->big_class_id;
    }

    int get_single_class_id()
    {
        return this->single_class_id;
    }

    /*set 方法*/
    void set_big_class_id( int big_cl_id)
    {
        this->big_class_id = big_cl_id;
    }

    void set_single_class_id( int single_cl_id)
    {
        this->single_class_id = single_cl_id;
    }

private:
    int big_class_id;       /*大班ID  外键*/
    int single_class_id;    /*小班ID  外键*/
};


#endif //TSHH_BIGCLASSLIST_HPP
