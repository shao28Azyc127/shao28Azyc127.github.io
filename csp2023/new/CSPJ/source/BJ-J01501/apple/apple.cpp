#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n=0;
    cin>>n;
    int ans1=0,ans2=0;
    int temp=n;
    while(temp)
    {
        if(temp%3==1&&!ans2)ans2=ans1+1;
        temp-=((temp)-1)/3+1;
        ans1++;
    }
    cout<<ans1<<' '<<ans2;

    fclose(stdin);
    fclose(stdout);
    return 0;
}