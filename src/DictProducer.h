//配置文件类
#pragma once

#include <string.h> 

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
using std::set;
using std::string;
using std::map;
using std::unordered_map;
using std::vector;
using std::pair;

class SplitTool;

class DictProducer
{
public:
    DictProducer(const string & dir);
    DictProducer(const string & dir,SplitTool * splitTool);//处理中文i

    void bulid_dict();//创建英文词典
    void bulid_cn_dict();//创建中文词典

    void store_dict(const string & filepath);//将词典写入文件
    void show_files()const;//查看文件路径，作为测试用

private:
    string get_files();//获取文件的绝对路径
    void push_dict(const string & word,int cnt);//存储某个单词
    string processSentences(const string & presentences);
    string processWord(const string & preword);

private:
    string _dir;//语料库文件存放路径
    vector<string> _files;//语料库文件的绝对路径集合
    unordered_map<string,int> _wordDict;//单词的词典(词频统计)
    unordered_map<string,set<int>> _indexDict;//索引的词典
    map<string,string> _dict;//配置文件内容
    SplitTool * _splitTool;//分词工具
};
