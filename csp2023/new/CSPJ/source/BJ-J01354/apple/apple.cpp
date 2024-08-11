#include<iostream>
using namespace std;
long long n,ans,cnt;
bool a[1000000005];
void cmp()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==false)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(cmp()==true)
    {
        cnt++;
        int i=1,j=3;
        while(i!=n)
        {
            if(a[i]==false&&j==3)
            {
                a[i]=true;
                j=1;
            }
            if(a[n]==true)ans=cnt;
            i++;
        }
    }
    cout<<cnt<<ans;
}