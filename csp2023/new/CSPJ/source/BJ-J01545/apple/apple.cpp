include<iostream>
using namespace std;

int main()
{
    freopen("apple.in","w",stdin);
    freopen("apple.out","r",stdout);
    int n,a=0,c=0,ans=0;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        c++;
        if(cnt<=n)
        {
            cnt+=3;
        }
        else
        {
            a++;
            cnt+=a+3;
        }
        if(cnt%n==0)
        {
            ans=cnt/n;
        }
    }
    if(cnt%n==0)
    {
        cout<<cnt/n;
    }
    else
    {
        cout<<cnt/n+1;
    }
    cout<<" "<<ans;
    return 0;
}
