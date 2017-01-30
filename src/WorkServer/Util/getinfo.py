#!/usr/bin/env python
# coding=utf-8
import urllib 
import urllib2
import json
import sys
default_encoding='utf-8'
if sys.getdefaultencoding()!=default_encoding:
      reload(sys)
      sys.setdefaultencoding(default_encoding)
def getinfo(username,passwd):
    url="http://115.159.152.176/httpost.php?sid="+username+"&passwd="+passwd
    #print type(url)
    req=urllib2.Request(url)  
    res_data=urllib2.urlopen(req)
    res=res_data.read();
    js=json.loads(res,encoding='utf-8')
    dict={}
    #for k in js:
    #    dict[k.encode()]=js[k].encode()
    for k in js:
        dict[k.encode()]=js[k].encode()
    #for m in dict:
     #  print m,dict[m]
    return dict

getinfo("04143162","Y18220744696");
