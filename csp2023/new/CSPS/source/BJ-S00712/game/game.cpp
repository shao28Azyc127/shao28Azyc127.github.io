#include<bits/stdc++.h>
using namespace std;
int n,ans;
string a;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>a;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            ans++;
            for(j=i;j<n-2;j++)
            {
                a[j]=a[j+2];
            }
            n-=2;
            i-=2;
        }
    }
    cout<<ans;
    return 0;
}
