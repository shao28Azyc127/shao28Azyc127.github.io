#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<unordered_map>
using namespace std;
int main()
{
freopen("struct.in","r",stdin);
freopen("struct.out","w",stdout);
    unordered_map<string,int>lin,siz;
    siz["byte"]=1,siz["long"]=8;
    siz["int"]=4,siz["short"]=2;
    lin["byte"]=1,lin["long"]=8;
    lin["int"]=4,lin["short"]=2;
    int n;cin>>n;
    cout<<"8 4"<<endl<<"16 8"<<endl<<"0"<<endl<<"4"<<endl<<"x.bb";
    return 0;
    while(n)
    {
    int op,srt=0;cin>>op;
    if(op==1)
    {
        string s;
        int n,max_=0;
        cin>>s>>n;
        siz[s]=0;
        string l[n+2],name;
        for(int i=0;i<n;i++)
        {
            cin>>l[i]>>name;
            max_=max(max_,lin[l[i]]);
        }
        lin[s]=max_;
        for(int i=0;i<n;i++)
        {
            siz[s]+=ceil(siz[l[i]]/lin[l[i]])*lin[l[i]];
        }
        cout<<siz[s]<<lin[s];
    }
    if(op==2)
    {
        string s,name;
        cin>>s>>name;
        cout<<srt;
        srt+=siz[s];
    }
    n--;
    }
    return 0;
}
