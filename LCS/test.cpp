#include"LCS.h"

int main()
{
   char *m="BDCABA";
   char *n="ABCBDAB";
   int mlen=strlen(m);
   int nlen=strlen(n);
   int **searcharr=new int*[nlen+1];
    for(int i=0;i<nlen+1;i++){
      // &(searcharr[i])= new int[mlen+1];
       searcharr[i]= new int[mlen+1];
}

   
  // int **searcharr=new int[nlen+1][7];
    //int **searcharr=new int[][mlen+1];
   //int **searcharr=search;
   int l=(mlen>=nlen?mlen:nlen);
   char *sub=new char[l];
   LCS test;
   test.init(searcharr,mlen,nlen);
   test.create(m,n,searcharr);
   test.find(m,n,searcharr,sub);
   delete []searcharr;
}
