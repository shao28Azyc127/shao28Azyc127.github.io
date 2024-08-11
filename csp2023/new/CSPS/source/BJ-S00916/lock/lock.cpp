#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int a;
    cin>>a;
    int b[100][8];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>b[i][j];
        }
    }
    if(a==1)
    {
        cout<<81;
        return 0;
    }
    int c=0;
    if(a==2)
    {
        int d=0;
        for(int i=0;i<5;i++)
        {
            if(b[0][i]!=b[1][i])
            {
                c++;

                if(d==0)
                {
                    d=i;
                }
            }
        }
        if(c==0)
        {
            cout<<81;
            return 0;
        }
        if(c==1)
        {
            if(d<4&&d>0)
            {
                cout<<12;
                return 0;
            }
            cout<<10;
            return 0;
        }
        if(c==2)
        {
            cout<<8;
            return 0;
        }
    }
    bool p[6]={};
    if(a>2)
    {
        for(int i=0;i<5;i++)
        {
            bool o[100]={};
            for(int j=0;j<a;i++)
            {
                if(o[j])
                {
                    continue;
                }
                else
                {
                    o[j]=true;
                    p[i]=true;
                }
            }
        }
        for(int i=0;i<5;i++)
        {
            if(p[i])
            {
                c++;
            }
        }
        if(c==0)
        {
            cout<<81;
            return 0;
        }
        if(c==1)
        {
            int e;
            e=10-a;
            cout<<e;
            return 0;
        }
        if(c>=2)
        {
            cout<<1;
            return 0;
        }
    }
    return 0;
}
