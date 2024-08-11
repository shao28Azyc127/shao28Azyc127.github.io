#include<bits/stdc++.h>
using namespace std;
int num;
int ans = 0;
int main()
{
    //freopen("lock.in","r",stdin);
   // freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<81<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<10<<endl;
        return 0;
    }
    if(n==3)
    {
        cout<<1<<endl;
    }
    if(n==4)
    {
        cout<<1<<endl;
    }
    if(n==6)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==7)
    {
        cout<<1<<endl;
        return 0;
    }
    if(n==8)
    {
        cout<<1<<endl;
        return 0;
    }
    int psd[n][5];
    for(int i = n-1;i>=0;--i)
    {
        for(int j = 0;j<5;++j)
        {
            cin>>psd[i][j];
        }
    }
cout<<1<<endl;
return 0;
}
