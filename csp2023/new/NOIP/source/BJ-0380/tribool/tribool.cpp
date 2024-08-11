#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e5+5;
int a[N],b[N],v[N];

int cal(int x)
{
    if(x==0)return 1;
    if(x==1)return 0;
    if(x==2)return 2;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            memset(v,0,sizeof(v));
            char op;
            int x,y;
            cin>>op>>x;
            if(op=='T'){
                if(!v[x])b[x]=1,v[x]=1;
                a[x]=1;
            }
            if(op=='F'){
                if(!v[x])b[x]=0,v[x]=1;
                a[x]=0;
            }
            if(op=='U'){
                if(!v[x])b[x]=2,v[x]=1;
                a[x]=2;
            }
            if(op=='+'){
                cin>>y;
                if(!v[x])b[x]=a[y],v[x]=1;
                if(!v[y])b[y]=a[y],v[y]=1;
                a[x]=a[y];
            }
            if(op=='-'){
                cin>>y;
                if(!v[x])b[x]=cal(a[y]),v[x]=1;
                if(!v[y])b[y]=a[y],v[y]=1;
                a[x]=cal(a[y]);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=a[i]!=b[i];
        cout<<cnt<<endl;
        //for(int i=1;i<=n;i++)
            //printf("%d %d\n",b[i],a[i]);
    }
    return 0;
}
