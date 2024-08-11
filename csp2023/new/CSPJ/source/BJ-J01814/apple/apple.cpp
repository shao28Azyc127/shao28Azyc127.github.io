#include<iostream>
using namespace std;
int n,cnt=0,ans,m;
bool flag=false;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    while(n>0)
    {
        cnt++;
        if(n%3==1&&flag==false)
        {

            ans=cnt;
            flag=true;
        }
        if(n%3==1||n%3==2)
        {
            n=n-n/3;
            n--;

        }
        else
        {
            n=n-n/3;
        }
    }
    cout<<cnt<<" ";
    cout<<ans<<endl;
    return 0;
}