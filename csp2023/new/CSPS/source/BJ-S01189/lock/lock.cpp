#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
      freopen("lock.in","r","stdin");
      freopen("lock.out","w","stdout");
      int n;
      cin>>n;
      for(int i=0;i<n;i++)
      {
        int a[5];
        int s=0;
        for(int i=0;i<5;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
       cout<<(s+2)*(s+2)<<endl;
      }
      return 0;
}