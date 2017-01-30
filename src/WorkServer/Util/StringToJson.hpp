//
// Created by yang on 16-8-16.
//

#ifndef TSHH_STRINGTOJSON_HPP
#define TSHH_STRINGTOJSON_HPP

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string.h>
class StringToJson {
public:
    StringToJson()= default;
    StringToJson(int type,std::unordered_map<std::string,std::vector<std::string>> &content){
        this->type=type;
        this->content=content;
    }
    std::string intToByte(int length){
        //std::cout << length << "    "<<type <<std::endl;
        char arr[8];
       /* for(int i=0;i<8;i++){
            printf("cdddd%d ",arr[i]);
        }*/
        //printf("\n");
        arr[0]=(char)(length & 0x7f);
        arr[1]=(char)((length >> 7)&0x7f);
        arr[2]=(char)((length >>14)&0x7f);
        arr[3]=(char)((length >>21)&0x7f);
        arr[4]=(char)(type & 0x7f);
        arr[5]=(char)((type >> 7)&0x7f);
        arr[6]=(char)((type >>14)&0x7f);
        arr[7]=(char)((type >>21)&0x7f);
        //printf("%d\n",arr[0]);
        std::string Str;
        for(int i=0;i<8;i++){
           // printf("ddddd%d",arr[i]);
            Str+=arr[i];
        }
       // printf("\n");
        //printf("byte:%d\n",strlen(arr));
       // std::cout << "Str:" <<Str<<"  "<<Str.size()<<std::endl;
        return Str;
    }
    std::string ObjectToJson(){
        std::string String="{";
        int len=content.size();
        for(const auto &p:content){
            String+="\"";
            String+=p.first;
            String+="\":[";
            int length=(p.second).size();
            for(const auto &q:p.second){
                String+="\"";
                String+=q;
                String+="\"";
                if(--length!=0)
                String+=",";
            }
            if(--len!=0){
                 String+="],";
            }else{
                String+="]";
            }
        }
        String+="}";
        int length=String.size();
        std::string Str=intToByte(length);
        Str+=String;
        return  Str;
    }
private:
    int type;
    std::unordered_map<std::string,std::vector<std::string>> content;

};


#endif //TSHH_STRINGTOJSON_HPP
