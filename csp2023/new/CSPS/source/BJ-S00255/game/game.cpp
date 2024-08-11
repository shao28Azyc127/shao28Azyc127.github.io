#include <bits/stdc++.h>
using namespace std;
const int maxn=8010;
int ans,n,a[maxn],las[maxn],last2[maxn],rem[maxn];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char sig;
        cin>>sig;
        a[i]=sig-'a'+1;
    }
    if(a[2]==a[1])
    {
        las[2]=last2[2]=1;
        rem[1]=1;
    }
    for(int i=3;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=last2[i-1];j++)
        {
            if(a[i]==a[rem[j]-1])
            {
                las[i]+=(1+las[rem[j]-2]);
                cnt++;
                rem[cnt]=rem[j]-1;
            }
        }
        if(a[i]==a[i-1])
        {
            cnt++;
            rem[cnt]=i-1;
            las[i]+=(las[i-2]+1);
        }
        last2[i]=cnt;
    }
    for(int i=1;i<=n;i++)
    {
        ans+=las[i];
        cout<<las[i]<<" ";
    }
    cout<<ans<<endl;
    return 0;
}
