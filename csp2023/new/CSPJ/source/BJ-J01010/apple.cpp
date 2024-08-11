#include<bits/stdc++.h>

using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans,day=0,date=-1;
    cin>>n;
    ans=n;
    while(ans>=4)
    {
        if(date==-1&&(ans-1)%3==0)
            date=day+1;
        ans-=1+(ans-1)/3;
        day++;

    }
    day+=ans;
    cout<<day<<" ";
    if(date==-1)
        cout<<day;
    else
        cout<<date;
 // 1 2 3 4 5 6 7 8
 // 2 3 5 6 8
 //3 5 8
 //5 8
 //8
 //5

    return 0;
}
