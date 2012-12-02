#include"LCS.h"

void LCS::init(int **searcharr,int mslen, int nslen)
{
   int i=0,j=0;
    for(i;i<=nslen;i++)
        for(j;j<=mslen;j++)
           {
              *((*searcharr+i)+j)=0;
           }
    return;
}

void LCS::create(char *m,char *n,int **searcharr)
{
    int mslen=strlen(m);
   int nslen=strlen(n);
    int i=0,j=0;
    for(i=1;i<=nslen;i++)
     for(j=1;j<=mslen;j++)
      {
           if(*(n+i-1)==*(m+j-1))
              *((*searcharr+i)+j)=*((*searcharr+i-1)+j-1)+1;
            else
              *((*searcharr+i)+j)=(*((*searcharr+i-1)+j)>=*((*searcharr+i)+j-1)?*((*searcharr+i-1)+j):*((*searcharr+i)+j-1));
          
      }
  return;
}
void LCS::find(char *m,char *n,int **searcharr,char *sub)
{
    int mslen=strlen(m);
    int nslen=strlen(n);
    int i=nslen,j=mslen,k=0;
    int sublen=*((*searcharr+nslen)+mslen);
    cout<<"The longest common substr's length is:  "<<sublen<<endl;
    while(i!=0&&j!=0)
      {
         if(*(n+i-1)==*(m+j-1))
            {
                *(sub+k)=*(m+j-1);
                i--;
                j--;
                k++;
            }
          else
            {
                if(*((*searcharr+i)+j-1)>=*((*searcharr+i-1)+j))
                    j--;
                 else
                    i--;
                
            }

      }
      
      char *tem=new char[strlen(sub)];
     int t,s=0;
      for(t=strlen(sub)-1;t>=0;t--)
        {
           *(tem+s)=*(sub+t);
             s++;
        }
        sub=tem;
      //strrev(strdup(sub));
     cout<<"The longest common substr is:  "<<sub<<endl;
     return;
}
