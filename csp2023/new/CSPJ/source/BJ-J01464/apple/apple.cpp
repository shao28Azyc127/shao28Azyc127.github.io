#include<iostream>
using namespace std;
int n;
int ans=0;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin>>n;
    int num=0;
    bool flag=0;
    while(n)
    {
        ans++;
        int sum=n/3;
        if((n-1)%3==0&&flag==0)
        {
            num=ans;
            flag=1;
        }
        if(n%3!=0)
        {
            sum++;
        }
        n-=sum;

    }
    cout<<ans<<"\n"<<num;
    return 0;
}
