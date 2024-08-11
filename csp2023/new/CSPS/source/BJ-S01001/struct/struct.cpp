#include<bits/stdc++.h>
using namespace std;
string memo[1000005]; //内存对应元素(若在结构体内则为x.y结构)
string name;
int strmemo,strdq; //结构体内存，结构体内存对齐要求
int k;
map<string,string> strdy,ys; //结构体成员名字对应类型；元素(名字)所对应类型
map<string,int> memfil,firdir; //数据类型占据内存；元素内存
void init()
{
    memfil["int"]=4,memfil["short"]=2;
    memfil["long"]=8,memfil["byte"]=1;
    return;
}
string stname[10005],sttype[10005];
int nowmemo=0; //当前占用最大内存
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    init();
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1) //定义结构体
        {
            cin>>name;
            cin>>k;
            strdq=0;
            for(int i=1;i<=k;i++)
            {
                string a,b;
                cin>>a>>b;
                strdq=max(strdq,memfil[a]);
                if(strmemo%memfil[a]==0)
                    strmemo+=memfil[a];
                else
                {
                    while(strmemo%memfil[a]!=0)
                        strmemo++;
                    strmemo+=memfil[a];
                }
                strdy[b]=a;
                stname[i]=b;
                sttype[i]=a;
            }
            while(strmemo%strdq!=0)
                strmemo++;
            cout<<strmemo<<" "<<strdq<<endl;
        }
        if(op==2) //定义元素
        {
            //cout<<name<<endl;
            string t,n; //数据类型，名字
            cin>>t>>n;
            //ys[n]=t;
            if(t==name) //结构体
            {
                for(int i=1;i<=k;i++)
                {
                    //cout<<"NOWMEMO: "<<nowmemo<<endl;
                    string now=sttype[i];
                    int nowm=memfil[now];
                    int ylmemo=nowmemo;
                    if(nowmemo%nowm==0)
                    {
                        ylmemo=nowmemo;
                        nowmemo+=nowm;
                    }
                    else
                    {
                        while(nowmemo%nowm!=0)
                            nowmemo++;
                        ylmemo=nowmemo;
                        nowmemo+=nowm;
                    }
                    //cout<<ylmemo<<" "<<nowmemo<<endl;
                    if(i==1) //新元素起始地址
                        cout<<ylmemo<<endl;
                    string nowdir=n+"."+stname[i];
                    firdir[nowdir]=ylmemo;
                    for(int j=ylmemo;j<=nowmemo;j++)
                        memo[j]=nowdir;
                }
            }
            else //基本类型
            {
                int nowm=memfil[t];
                int ylmemo=nowmemo;
                if(nowmemo%nowm==0)
                    nowmemo+=nowm;
                else
                {
                    while(nowmemo%nowm)
                        nowmemo++;
                    ylmemo=nowmemo;
                    nowmemo+=nowm;
                }
                cout<<ylmemo<<endl;
                string nowdir=n;
                firdir[n]=ylmemo;
                for(int j=ylmemo;j<=nowmemo;j++)
                    memo[j]=nowdir;
            }
        }
        if(op==3) //访问元素
        {
            string ask;
            cin>>ask;
            cout<<firdir[ask]<<endl;
        }
        if(op==4) //访问内存
        {
            int askad;
            cin>>askad;
            if(memo[askad]=="")
                cout<<"ERR\n";
            else
                cout<<memo[askad]<<endl;
        }
    }
}
