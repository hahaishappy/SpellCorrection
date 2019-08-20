#pragma once

#include "SplitTool.h"

#include <iostream>
#include <vector>
using std::vector;
using std::string;

class Configuration;
class SplitToolCppJieba
:public SplitTool
{
public:
    SplitToolCppJieba(); 
    virtual ~SplitToolCppJieba();
    
    virtual vector<string> cut(const string & sentence)=0;//分词函数，春促函数，提供接口
private:
    Configuration & _conf;//配置文件路径
};

