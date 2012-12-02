#include "ACN.h"
#include <iostream>
typedef KeyTree<char,NodeData> TreeType; //？这里为什么还要typedef
ACN::ACN()  //构造函数
{
    head->state= 0;
    size = 1;
}
void ACN::add_pattern(const char* pat)
{
    TreeType::iterator ite;
    ite = head.iter();//返回一个深度迭代的迭代器
    const char* read = pat;
    NodeData ins;
    while(*read!=0){
        if(!ite->has_key(*read)){
            ins.state = size++; //size是状态编号
            ite = ite->add_child(*read, ins);
            invalid = true;
        }else{
            ite = (*ite)[*read];
        }
        read++;
    }
    output[ite->v().state].push_back(pat);//添加输出
}
TreeType* ACN::_goto(TreeType* from,char key)
{
    if(from == &head){
        if(head.has_key(key)) return head[key];  //根据图理解
        else return &head;
    }else{
        if(from->has_key(key)) return (*from)[key];
        return failure[from->v().state];
    }
}
void ACN::caculate_failure()
{
    if(!invalid) return;
    failure.resize(size);
    TreeType::wide_iterator ite;//广度迭代器
    for(ite = head.wide_iter();ite!=false;ite++){
        if(ite->depth()<=1) 
            failure[(*ite)->state]=&head;
        else{
            TreeType* to = _goto(failure[ite->parent()->v().state],ite.key());
            failure[ite->v().state] = to;
            if(!output[to->v().state].empty()){
                vector<string>::iterator ins,end,ins_pos;
                ins = output[to->v().state].begin();
                end = output[to->v().state].end();
                ins_pos = output[ite->v().state].end();
                output[ite->v().state].insert(ins_pos,ins,end);
            }
        }
    }
    invalid = false; //计算完失败函数则将invalid置为false.
}
void ACN::open_buffer(const char* buff)
{
    document = buff;
    caculate_failure();
    clear();
}
void ACN::clear()
{
    read_ptr = document;
    tree_ptr = &head;
    last_result = NULL;
}
bool ACN::fetch(string& res,int& pos)   //参数是引用形式
{
    if(invalid) caculate_failure();
    char read;
    if(last_result){   //想要这块执行看来需要循环调用，找到所有匹配输出结果
        res = (*last_result)[last_idx];
        pos = read_ptr-document-res.size();
        last_idx++;
        if(last_idx==last_result->size()) last_result = NULL;
        return true;
    }
    while(*read_ptr){
        read = *read_ptr;//读入一个字符
        tree_ptr = _goto(tree_ptr,read);
        vector<string>& c = output[tree_ptr->v().state];
        if(!c.empty()){
            res = c[0];
            read_ptr++;
            pos = read_ptr-document-res.size(); //找到的匹配串的开始位置
            tree_ptr = _goto(tree_ptr,read);
            if(c.size()>1){
                last_result = &c;
                last_idx = 1;
            }
            return true;
        }
        read_ptr++;
    }
    return false;
}
