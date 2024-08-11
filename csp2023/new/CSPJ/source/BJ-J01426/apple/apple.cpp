#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0,x=0;
    while(n>0)
    {
        if(n%3==1&&x==0)x=cnt+1;
        cnt++;
        if(n%3==0)n-=n/3;
        else n-=n/3+1;
    }
    cout<<cnt<<" "<<x<<endl;
    return 0;
}
