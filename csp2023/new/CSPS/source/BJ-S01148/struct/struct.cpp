#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int flag[100010];
struct node
{
    string x;
    int id;
} x[110];
inline void B()
{
    string y;
    cin>>y>>x[++cnt].x;
    if(y=="byte")
    {
        int t=0;
        while(flag[t])
        {
            ++t;
        }
        x[cnt].id=t;
        flag[t]=cnt;
    }
    else if(y=="short")
    {
        int t=0;
        while(flag[2*t])
        {
            ++t;
        }
        x[cnt].id=2*t;
        flag[2*t]=cnt;
        flag[2*t+1]=cnt;
    }
    else if(y=="int")
    {
        int t=0;
        while(flag[4*t])
        {
            ++t;
        }
        x[cnt].id=4*t;
        flag[4*t]=cnt;
        flag[4*t+1]=cnt;
        flag[4*t+2]=cnt;
        flag[4*t+3]=cnt;
    }
    else if(y=="long")
    {
        int t=0;
        while(flag[8*t])
        {
            ++t;
        }
        x[cnt].id=8*t;
        flag[8*t]=cnt;
        flag[8*t+1]=cnt;
        flag[8*t+2]=cnt;
        flag[8*t+3]=cnt;
        flag[8*t+4]=cnt;
        flag[8*t+5]=cnt;
        flag[8*t+6]=cnt;
        flag[8*t+7]=cnt;
    }
    cout<<x[cnt].id<<endl;
    return;
}
inline void C()
{
    string y;
    cin>>y;
    for(int i=1;i<=cnt;++i)
    {
        if(x[i].x==y)
        {
            cout<<x[i].id<<endl;
        }
    }
    return;
}
inline void D()
{
    int p;
    cin>>p;
    if(flag[p])
    {
        cout<<x[flag[p]].x<<endl;
    }
    else
    {
        cout<<"ERR"<<endl;
    }
    return;
}
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,a;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        if(a==2)

        {
            B();
        }
        else if(a==3)
        {
            C();
        }
        else if(a==4)
        {
            D();
        }
    }
    return 0;
}
