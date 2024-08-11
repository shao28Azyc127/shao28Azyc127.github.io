#include <bits/stdc++.h>
using namespace std;
int c,t;
void rd(int &x)
{
    scanf("%d",&x);
}
void wd(int x)
{
    printf("%d\n",x);
}
void rc(char &x)
{
    cin>>x;
}
int cv(char x)
{
    if(x=='T')
    {
        return 1;
    }
    if(x=='F')
    {
        return -1;
    }
    if(x=='U')
    {
        return 0;
    }
    return 3;
}
void dfs(int s,int n,vector<vector<int>>&tcc,vector<int>&cc)
{
    if(s==1)
    {
        while(tcc.size()!=0)
        {
            tcc.pop_back();
        }
        while(cc.size()!=0)
        {
            cc.pop_back();
        }
    }
    if(s>n)
    {
        tcc.push_back(cc);
        return;
    }
    for(int i=-1;i<=1;i++)
    {
        cc.push_back(i);
        dfs(s+1,n,tcc,cc);
        cc.pop_back();
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    rd(c);
    rd(t);
    for(int k=0,n,m;k<t;k++)
    {
        rd(n);
        rd(m);
        vector<int>p;
        p.resize(n+1,3);
        if(c==3||c==4)
        {
            int cnt=0;
            for(int q=0;q<m;q++)
            {
                char v;
                int i;
                rc(v);
                rd(i);
                p[i]=cv(v);
            }
            for(size_t i=0;i<p.size();i++)
            {
                if(p[i]==0)
                {
                    cnt++;
                }
            }
            wd(cnt);
        }
        else
        {
            vector<vector<int>>tcc;
            vector<int>cc;
            dfs(1,n,tcc,cc);
            for(int q=0;q<m;q++)
            {
                char v;
                int i=0,j=0;
                rc(v);
                if(v=='T'||v=='F'||v=='U')
                {
                    rd(i);
                    p[i]=cv(v);
                }

                if(v=='+')
                {
                    rd(i);
                    rd(j);
                    p[i]=p[j];
                }
                if(v=='-')
                {
                    rd(i);
                    rd(j);
                    p[i]=-p[j];
                }
            }
        }
    }
    return 0;
}
