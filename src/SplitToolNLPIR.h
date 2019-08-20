//分词工具类
#pragma once

#include "SplitTool.h"

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class Configuration;
class SplitToolNLPIR
:public SplitTool
{
public:
    SplitToolNLPIR();
    virtual ~SplitToolNLPIR();

    virtual vector<string> cut(const string & sentence)=0;

private:
    Configuration & _conf;//配置文件路径
};
