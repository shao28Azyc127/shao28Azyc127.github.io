#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,m,d=0,ans=0;
    cin>>n;m=n;
    while(m)
    {
        if(ans==0&&(m-1)%3==0)ans=d+1;
        int k=ceil(m*1.0/3.0);
        m-=k;
        d++;
    }
    printf("%d %d\n",d,ans);
    return 0;
}
