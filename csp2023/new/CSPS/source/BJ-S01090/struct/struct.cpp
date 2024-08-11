//可以 T3惯例大模拟：直奔T3
//做着做着感觉好像也不是纯大模拟，但是懒得写数据结构了，就这样吧
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
int N;
unsigned long long addr,ad;
string name[105],name2[105];
int nametoval[105],length[105],nametoval2[105];
int num=1,num2=1;
//结构体里定义结构体，用结构体打败结构体
struct val
{
    string nme;
    int isstr=-1;
    int fa;
    int numson=0;
    int son[105];
    int mad;
    unsigned long long addl,adr;
}v[100005],v2[100005];
int cnt=1,cnt2=1;

//比较字符串异同
bool check(string s,string m)
{
    if(s.size()!=m.size()) return false;
    for(int i=0;i<s.size();i++)
        if(s[i]!=m[i])
            return false;
    return true;
}

//创建之快捷函数
void create(string s,int is,int f,int ma,unsigned long long l,unsigned long long r)
{
    v[cnt].nme=s;
    v[cnt].fa=f;
    v[cnt].isstr=is;
    v[cnt].mad=ma;
    v[cnt].addl=l;
    v[cnt].adr=r;
    cnt++;
}
void create2(string s,int is,int f,int ma,unsigned long long l,unsigned long long r)
{
    v2[cnt2].nme=s;
    v2[cnt2].fa=f;
    v2[cnt2].isstr=is;
    v2[cnt2].mad=ma;
    v2[cnt2].addl=l;
    v2[cnt2].adr=r;
    cnt2++;
    if(is!=-1)
    {
      //  cout<<"is="<<is<<endl;
      //  cout<<"v[is].nme="<<v[is].nme<<endl;
       // cout<<"v[cnt2]."
        int t=cnt2-1;
        int aaaddd=l;
        for(int i=1;i<=v[is].numson;i++)
        {
            v2[t].numson++;
            v2[t].son[v2[t].numson]=t;
            create2(v[v[is].son[i]].nme,v[v[is].son[i]].isstr,t,v[v[is].son[i]].mad,aaaddd,(v[v[is].son[i]].adr-v[v[is].son[i]].addl)+aaaddd);
            aaaddd+=(v[v[is].son[i]].adr-v[v[is].son[i]].addl);
            aaaddd++;
        }
    }
}

void print(int i,int fin)
{
    if(v2[i].fa==0)
    {
        for(int i=0;i<v2[i].nme.size();i++)
            cout<<v2[i].nme[i];
        cout<<'.';
        return ;
    }
    print(v2[i].fa,fin);
    for(int i=0;i<v2[i].nme.size();i++)
        cout<<v2[i].nme[i];
    if(i!=fin)
        cout<<'.';

}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>N;
    while(N--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int maxad=-1;
            cin>>name[num];
            num++;
            create(name[num-1],cnt,0,0,ad,0);
            int t=cnt-1;
            nametoval[num-1]=t;
            int k;
            cin>>k;
            for(int i=1;i<=k;i++)
            {
                string s;
                cin>>s;
                if(check(s,"byte"))
                {
                    string x;
                    cin>>x;
                    v[t].numson++;
                    v[t].son[v[t].numson]=cnt;
                    create(x,-1,t,1,ad,ad);
                    ad++;
                    maxad=max(maxad,1);
                }
                else if(check(s,"short"))
                {
                    string x;
                    cin>>x;
                    v[t].numson++;
                    v[t].son[v[t].numson]=cnt;
                    if(ad%2!=0) ad++;
                    create(x,-1,t,2,ad,ad+1);
                    ad+=2;
                    maxad=max(maxad,2);
                }
                else if(check(s,"int"))
                {
                    string x;
                    cin>>x;
                    v[t].numson++;
                    v[t].son[v[t].numson]=cnt;
                    if(ad%4!=0) ad=(ad/4+1)*4;
                    create(x,-1,t,4,ad,ad+3);
                    ad+=4;
                    maxad=max(maxad,4);
                }
                else if(check(s,"long"))
                {
                    string x;
                    cin>>x;
                    v[t].numson++;
                    v[t].son[v[t].numson]=cnt;
                    if(ad%8!=0) ad=(ad/8+1)*8;
                    create(x,-1,t,8,ad,ad+7);
                    ad+=8;
                    maxad=max(maxad,8);
                }
                else
                {
                    for(int i=1;i<=num;i++)
                    {
                        if(check(name[i],s))
                        {
                            string x;
                            cin>>x;
                            v[t].numson++;
                            v[t].son[v[t].numson]=cnt;
                            if(ad%length[i]!=0) ad=(ad/length[i]+1)*length[i];
                            create(x,i,t,v[nametoval[i]].mad,ad,ad+length[i]-1);
                            ad+=length[i];
                            maxad=max(maxad,length[i]);
                            break;
                        }
                    }
                }
            }
            if(ad%maxad!=0) ad=(ad/maxad+1)*maxad;
            v[t].mad=maxad;
            v[t].adr=ad-1;
            cout<<v[t].adr-v[t].addl+1<<' '<<maxad<<endl;
            length[num-1]=ad-v[t].addl;
            ad=addr;
        }

        else if(op==2)
        {
            string t,n;
            cin>>t>>n;
            int ans=0;
            for(int i=1;i<=num;i++)
                if(check(name[i],t))
                {
                    if(addr%v[nametoval[i]].mad!=0 && addr!=0)
                        addr=(addr/v[nametoval[i]].mad+1)*v[nametoval[i]].mad;
                    ans=addr;
                    name2[num2]=n;
                    nametoval2[num2]=cnt2;
                    num2++;
                    create2(n,nametoval[i],0,v[nametoval[i]].mad,addr,addr+length[i]-1);
                    addr+=length[i];
                    break;
                }
            cout<<ans<<endl;
        }

        else if(op==3)
        {
            string s;
            cin>>s;
        //    cout<<"Hi there?"<<endl;
            string x="";
            int y=0;
     //       cout<<"Is anyone here?"<<endl;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!='.')
                    x+=s[i];
                else
                {
                    y=i+1;
                    break;
                }
            }
        //    cout<<"Have something wrong here?"<<endl;
            int res=-1;
            for(int i=1;i<=num2;i++)
            {
                if(check(name2[i],x))
                {
                    int gb=nametoval2[i];
                    bool flflfl=false;
                    while(y<s.size())
                    {
                      //  cout<<"Or here?"<<endl;
                        x="";
                        for(int j=y;j<s.size();j++)
                        {
                            if(s[j]!='.') x+=s[j];
                            else{
                                y=j+1;
                                flflfl=true;
                                break;
                            }
                        }
                        if(flflfl==false) y=s.size();
                       // cout<<"gb="<<gb<<endl;
                       // cout<<"v2[gb].nme="<<v2[gb].nme<<endl;
                       // cout<<"v2[gb].numson="<<v2[gb].numson<<endl;
                       // cout<<x<<endl;
                       if(v2[gb].numson==0)
                            break;
                        for(int k=1;k<=v2[gb].numson;k++)
                        {
                         //   cout<<"Did i come here?"<<endl;
                            if(check(x,v2[v2[gb].son[k]].nme))
                            {
                                res=v2[v2[gb].son[k]].addl;
                                gb=v2[gb].son[k];
                              //  cout<<"Here?"<<endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
         //   cout<<"Hey!"<<endl;
            cout<<res<<endl;
        }

        else if(op==4)
        {
            int ADD;
            cin>>ADD;
            bool flfl=false;
            for(int i=1;i<=cnt2;i++)
            {
                if(v2[i].addl<=ADD && v2[i].adr>=ADD && v2[i].isstr==-1)
                {
                    flfl=true;
                    print(i,i);
                    break;
                }
            }
            if(flfl==false)
                cout<<"ERR"<<endl;
        }
    }
    //历时2个小时30分钟 终于完成了T3大模拟做法
    //历时2个小时50分钟 终于调完了语法错误 开始调程序
    return 0;
}
