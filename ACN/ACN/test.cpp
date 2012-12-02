#include "Tree.h"
#include <iostream>
using namespace std;

int main()
{
    KeyTree<char,int> tree;
    KeyTree<char,int>::iterator iter;
    KeyTree<char,int>::wide_iterator wide;
    iter = tree.add_child('a',1);
    iter->add_child('b',2);
    iter->add_child('c',3);
    iter = tree.add_child('d',4);
    iter->add_child('e',5);
    wide = tree.wide_iter();
    while(wide){
        cout<<wide->v()<<endl;
        wide++;
    }
}
