#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
struct A
{
    int a[5];
};
string change(A x)
{
    string s="";
    for(int i=0;i<=4;i++)s+=x.a[i]+'0';
    return s;
}
map<string,int> mp;
bool operator ==(A x,A y)
{
    for(int i=0;i<=4;i++)if(x.a[i]!=y.a[i])return 0;
    return 1;
}
A jl[10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        A t;
        for(int j=0;j<=4;j++)cin>>t.a[j];
        jl[i]=t;
        for(int j=0;j<=4;j++)
        {
            for(int k=0;k<=9;k++)
            {
                A y=t;
                if(t.a[j]==k)continue;
                y.a[j]=k;
                mp[change(y)]++;
            }
        }
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=9;k++)
            {
                A y=t;
                y.a[j]+=k;
                y.a[j-1]+=k;
                y.a[j]%=10;
                y.a[j-1]%=10;
                mp[change(y)]++;
            }
        }
    }
    int cnt=0;
    for(int i1=0;i1<=9;i1++)
    {
        for(int i2=0;i2<=9;i2++)
        {
            for(int i3=0;i3<=9;i3++)
            {
                for(int i4=0;i4<=9;i4++)
                {
                    for(int i5=0;i5<=9;i5++)
                    {
                        A t;
                        t.a[0]=i1;
                        t.a[1]=i2;
                        t.a[2]=i3;
                        t.a[3]=i4;
                        t.a[4]=i5;
                        if(mp[change(t)]==n)
                        {
                            bool f=0;
                            for(int i=1;i<=n;i++)if(t==jl[i])f=1;
                            if(f==0)cnt++;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}