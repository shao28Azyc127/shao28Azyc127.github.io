#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct struct_
{
    bool bas;
    int l,bt;
    vector<int> ad;
    vector<string> tp,na;
    map<string,int> num;
    struct_()
    {
        bas=0;
        l=0;
        bt=1;
        ad=vector<int>();
        tp=vector<string>();
        na=vector<string>();
        num=map<string,int>();
    }
    struct_(bool nbas,int nl,int nbt)
    {
        bas=nbas;
        l=nl;
        bt=nbt;
        ad=vector<int>();
        tp=vector<string>();
        na=vector<string>();
        num=map<string,int>();
    }
    struct_(bool nbas,int nl,int nbt,vector<int> nad,vector<string> ntp,vector<string> nna,map<string,int> nnum)
    {
        bas=nbas;
        l=nl;
        bt=nbt;
        ad=nad;
        tp=ntp;
        na=nna;
        num=nnum;
    }
};
map<string,struct_> ss;
int nn;
void init()
{
    ss[""]=struct_();
    ss["byte"]=struct_(1,1,1);
    ss["short"]=struct_(1,2,2);
    ss["int"]=struct_(1,4,4);
    ss["long"]=struct_(1,8,8);
    nn=0;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int k;
            cin>>s>>k;
            ss[s]=struct_();
            for(int j=0;j<k;j++)
            {
                cin>>ss[s].tp[j]>>ss[s].na[j];
                ss[s].num[na]=j;
                ss[s].ad[j]=ss[s].ad[j-1]+ss[ss[s].na[j-1]].l;
                ss[s].bt=max(ss[s].bt,ss[ss[s].na[j-1]].bt);
            }
            ss[s].l=ss[s].ad[k-1]+ss[ss[s].na[k-1]].l;
            ss[s].l=ss[s].l/ss[s].bt+!!(ss[s].l%ss[s].bt);
        }
        if(op==2)
        {
            cin>>ss[""].tp[nn+1]>>ss[""].na[nn+1];
            ss[""].num[ss[""].na[nn+1]]=nn+1;
            ss[""].ad[nn+1]=ss[""].l+1;
            ss[""].l=ss[""].ad[nn+1]+ss[ss[""].tp[nn+1]].l;
        }
        if(op==3)
        {

        }
        if(op==4)
        {

        }
    }
    return 0;
}
//to be continued...
