#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,top,cnt,pos[maxn];//第i个被定义的字符串的开始位置
string a[maxn];//第i个被定义的是谁
map<string,int> sz,num,mark;//大小，对齐要求，第几个被定义
map<string,string> type;//类型
struct node
{
    int k;
    string s[200],t[200];
};
map<string,node> info;
void init()
{
    sz["byte"]=1;
    sz["short"]=2;
    sz["int"]=4;
    sz["long"]=8;
    num["byte"]=1;
    num["short"]=2;
    num["int"]=4;
    num["long"]=8;
}
inline void work1()
{
    int k,x=0;
    string na;
    node z;
    cin>>na>>k;
    z.k=k;
    for(int i=1;i<=k;i++)
    {
        string t,s;
        cin>>t>>s;
        z.t[i]=t;
        z.s[i]=s;
        num[na]=max(num[na],num[t]);
        int y=(x/num[t])*num[t];
        if(y<x) y+=num[t];
        x=y+sz[t];
        // cout<<"x: "<<x<<endl;
    }
    int y=(x/num[na])*num[na];
    if(y<x) y+=num[na];
    x=y;
    sz[na]=x;
    printf("%d %d\n",sz[na],num[na]);
    info[na]=z;
}
inline void work2()
{
    string t,s;
    cin>>t>>s;
    type[s]=t;
    int x=(top/num[t])*num[t];
    if(x<top) x+=num[t];
    cnt++;
    a[cnt]=s;
    mark[s]=cnt;
    pos[cnt]=x;
    top=x+sz[t];
    printf("%d\n",pos[cnt]);
}
inline void work3()
{
    string s;
    cin>>s;
    printf("%d\n",pos[mark[s]]);
}
inline void work4()
{
    int addr;
    cin>>addr;
    int x=upper_bound(pos+1,pos+cnt+1,addr)-pos-1;
    string s=a[x];
    // cout<<"------ "<<addr<<" "<<x<<" "<<s<<" "<<pos[x]<<" "<<sz[type[s]]<<endl;
    if(pos[x]+sz[type[s]]-1>=addr)
    {
        cout<<s<<endl;
    }
    else puts("ERR");
}
void work()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1) work1();
        else if(op==2) work2();
        else if(op==3) work3();
        else work4();
    }
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    init();
    work();
    return 0;
}