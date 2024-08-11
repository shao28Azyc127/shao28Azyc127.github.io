#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int cnt=0;
    int t;
    cin>>n;
    int tempn=n;
    int day=0;
    while(tempn>=1)
    {
        if(tempn%3>0) t=1;
        else t=0;
        if(tempn%3==1&&day==0) day=cnt+1;
        tempn=tempn-tempn/3-t;
        cnt++;

    }
    cout<<cnt<<' '<<day;

    return 0;
}
