#include <map>
#include <stack>
#include <string>
#include "Tree.h"
using namespace std;

/*struct Node{
    char pt;
    int idx;
    int depth;
    map<char,Node*> next;
    Node& get_next(char go)
    {
        if(next.find(go)==next.end()){
            next[go] = new Node();
            next[go]->pt = go;
            next[go]->depth = ++this->depth;
        }
        return *next[go];
    }
    wide_iterator wide_iterator();
    depth_iterator depth_iterator();
};*/
struct NodeData{
    int state;
};
class ACN{
    typedef KeyTree<char,NodeData> TreeType;
    int size;
    KeyTree<char,NodeData> head;
    const char* document;
    const char* read_ptr;
    TreeType* tree_ptr;
    map<int,vector<string> > output;
    vector<TreeType*> failure;
    vector<string>* last_result;
    int last_idx;
    bool invalid;
    void caculate_failure();
    TreeType* _goto(TreeType* from,char key);
    public:
    ACN();
    void add_pattern(const char* pat);
    void open_buffer(const char* buff);
    bool fetch(string& res,int& pos);
    void clear();
};
