#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[10][10],ans[110][10],tmp=0,anss=0,f[10],k[10];
bool check(int x[])
{
//    for(int i=1;i<=5;i++) cout<<x[i]<<" ";
//    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int t=0;
        for(int j=1;j<=5;j++)
        {
            if(x[j]!=a[i][j]) f[++t]=j,k[t]=(x[j]+10-a[i][j])%10;
        }
//        cout<<t<<" ";
//        cout<<"yes";
        if(t>2||t<=0) return false;
        if(t==2&&f[2]-f[1]!=1) return false;
        if(t==2&&k[2]!=k[1]) return false;
    }
//    cout<<endl;
    return true;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=5;j++)
        {
            ans[i][j]=a[1][j];
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==ans[tmp+1][i]) continue;
            ans[++tmp][i]=j;
        }
    }
//    cout<<tmp<<endl;
    for(int i=1;i<5;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==ans[tmp+1][i]) continue;
            ans[++tmp][i+1]+=j-ans[tmp][i];
            ans[tmp][i+1]%=10;
            ans[tmp][i]=j;
        }
    }
//    cout<<tmp<<endl;
    for(int i=1;i<=tmp;i++)
    {
        if(check(ans[i]))
        {
            anss++;
//            for(int j=1;j<=5;j++) cout<<ans[i][j];
//            cout<<endl;
        }
//        else for(int j=1;j<=5;j++) cout<<ans[i][j];
//        cout<<endl;
    }
    cout<<anss;
    return 0;
}
