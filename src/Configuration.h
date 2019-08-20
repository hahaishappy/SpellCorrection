//配置文件类
#pragma once

#include <string.h>

#include <iostream>
#include <map>
using std::map;
using std::string;

class Configuration
{
public:
    Configuration(const string & filepath);
    map<string,string> & getConfigMap();//获取存放配置文件内容的map

private:
    string _filepath;
    map<string,string> _configMap;//配置文件内容
};
