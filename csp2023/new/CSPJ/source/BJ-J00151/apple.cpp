#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,cnt;
bool flag=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    //freopen("apple2.in","r",stdin);
    cin>>n;
    while(n>0)
    {
        cnt++;
        if(n%3==1 && flag==false)
        {
            ans=cnt;
            flag=true;
        }
        n-=(n/3+(n%3!=0));
    }
    cout<<cnt<<' '<<ans;
    return 0;
}
