#include<bits/stdc++.h>
using namespace std;
long long n=0,d=0,ans=0,n1=0,d1=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int m=n;
    while(n>0)
    {
        n=n-(n+2)/3;
        d++;
    }
    while(m>0)
    {
        if(m%3==1)
        {
            ans=d1+1;
            break;
        }
        m=m-(m+2)/3;
        d1++;
    }
    cout<<d<<" "<<ans;
    return 0;
}
