#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    string a;
    cin>>n>>a;
    long long ans;
    for(int i=0;i<n;i++)
    {
        int cac[1000005];
        int c=0;
        for(int j=i;j<n;j++)
        {
            c++;
            cac[c]=a[j];
            if(c>=2&&cac[c]==cac[c-1])
            {
                c-=2;
            }
            if(c==0)ans++;
        }
        c=0;
    }
    cout<<ans;
    return 0;
}
