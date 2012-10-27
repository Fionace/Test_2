#include "ACN.h"
#include <iostream>
using namespace std;

int main()
{
    ACN acn;
    acn.add_pattern("he");
    acn.add_pattern("she");
    acn.add_pattern("his");
    acn.add_pattern("hers");
    acn.open_buffer("ushers");
    string result;
    int pos;
    while(acn.fetch(result,pos)){
        cout<<pos<<":"<<result<<endl;
    }

    return 0;
}
