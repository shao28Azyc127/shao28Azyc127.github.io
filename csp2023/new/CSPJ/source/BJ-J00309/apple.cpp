#include<iostream>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n;
    cin>>n;
    long long i=n;
    long long ans1=0,ans2=-1;
    while(i>0)
    {
        int j=i;
        i%3==0?(i-=i/3):(i-=i/3+1);
        ans1++;
        if(j%3==1&&ans2==-1)ans2=ans1;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}