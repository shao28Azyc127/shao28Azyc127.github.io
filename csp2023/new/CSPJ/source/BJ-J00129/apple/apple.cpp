#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int i=1,cnt=0,g=0,k,ans;
bool f=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int a[n+5]={};
    while(g!=n)
    {
        cnt++;
        k=g;
        if((n-k-1)%3==0&&f==false)
        {
            ans=cnt;
            f=true;
        }
        for(int i = 0;i < n-k;i+=3)
        {
            a[i]++;
            g++;
        }
        sort(a,a+n);
    }
    cout<<cnt<<" "<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}