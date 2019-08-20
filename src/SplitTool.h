#pragma once

#include <iostream>
#include <vector>
using std::vector;
using std::string;

class SplitTool
{
public:
    SplitTool();
    virtual ~SplitTool();

    //分词函数，纯虚函数，提供接口
    virtual vector<string> cut(const string & sentence)=0;

};
