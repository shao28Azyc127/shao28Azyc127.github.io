#include<bits/stdc++.h>
using namespace std;
long long n=0,ans=0,m=0,cnt=0,x=0;
bool flag=true;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;m=n;
    while(m!=0)
    {
        x=m%3;
        if((x==1) && flag)
        {
            cnt=ans+1;
            flag=false;
        }
        else if(!x)
        {
            ans++;
            m-=m/3;
        }
        else
        {
            ans++;
            m-=(m/3)+1;
        }
    }
    cout<<ans<<' '<<cnt<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}