#include "DictProducer.h"
#include <fstream>
#include <sstream>
using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::istringstream;

DictProducer::DictProducer(const string & dir)
:_dir(dir)
{}

DictProducer::DictProducer(const string & dir,SplitTool * splitTool)
:_dir(dir)
,_splitTool(splitTool)
{}

string DictProducer::get_files()
{//这个函数还没有看懂是干什么的
    return " ";
}

void DictProducer::push_dict(const string & word,int cnt)
{//这里只完成索引的存储
    for(auto & c:word)
    {
        string tmp;
        tmp+=c;
        if(_indexDict.count(tmp))
        {
            auto ret=_indexDict.find(tmp);
            (ret->second).insert(cnt);
        }
        else
        {
            set<int> s{cnt};
            _indexDict.insert(std::make_pair(tmp,s));
        }
    }
}

string DictProducer::processSentences(const string & presentences)
{
    string tmp;
    for(auto & c:presentences)
    {
        if(!isalpha(c))
            tmp+=" ";
        else if(isupper(c))
            tmp+=tolower(c);
        else
            tmp+=c;
    }
    return tmp;
}

string DictProducer::processWord(const string & preword)
{
    for(auto & ch:preword)
    {
        if(!isalpha(ch))
            return string();
    }
    return preword;
}

void DictProducer::bulid_dict()//创建英文词典
{//这里进行词频统计并存储到文件中，并且生成索引的词典
    ifstream ifs(_dir);
    if(!ifs.good())
    {
        cout<<"ifstream open "<<_dir<<" error!"<<endl;
        return;
    }

    string line;
    while(getline(ifs,line))
    {
        string tmp=processSentences(line);
        istringstream iss(tmp);
        string preword;
        while(iss>>preword)
        {
            string word=processWord(preword);
            if(word != string())
            {
                ++_wordDict[word];
            }
        }
    }

    ifs.close();

    int cnt=1;
    for(auto & elem:_wordDict)
    {
        push_dict(elem.first,cnt);
        ++cnt;
    }
}

void DictProducer::bulid_cn_dict()//创建中文词典
{
//同上，不过是中文版本的
}

void DictProducer::store_dict(const string & filepath)
{//把四个词典存储到文件中
    //先存储索引文件
    ofstream ofs(filepath);
    if(!ofs.good())
    {
        cout<<"ofstream create "<<filepath;
        return;
    }

    for(auto & elem:_indexDict)
    {
        ofs<<elem.first<<" ";
        for(auto & c:(elem.second))
        {
            ofs<<c<<" ";
        }
        ofs<<endl;
    }

    ofs.close();
}

void DictProducer::show_files()const
{
    for(auto & elem : _files)
    {
        cout<<">>> "<<elem<<endl;
    }
}

int main()
{
    DictProducer dict("holy.txt");
    dict.bulid_dict();
    dict.store_dict("dict.txt");
    return 0;
}
