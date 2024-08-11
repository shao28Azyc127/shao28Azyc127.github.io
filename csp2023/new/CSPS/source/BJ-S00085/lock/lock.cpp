#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#include <bitset>
using namespace std;
#define int long long
#define mod 998244353
#define mp make_pair
#define fi first
#define se second
#define pb push_back

int n,a[11][7],b[7],dis[7],ans;

bool ck()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            dis[j]=(a[i][j]-b[j]+10)%10;
        }
        int num1=0,num2=0;
        for(int j=1;j<=5;j++)
        {
            if(dis[j])
            {
                if(!num1) num1=j; else if(!num2) num2=j; else return 0;
            }
        }
        if(!num1) return 0;
        if(num1&&num2&&abs(num1-num2)!=1) return 0;
        if(num1&&num2&&dis[num1]!=dis[num2]) return 0;
    }
    //for(int i=1;i<=5;i++) cout<<b[i]<<" "; cout<<endl;
    return 1;
}

signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n; for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) cin>>a[i][j];
    for(int i=0;i<=9;i++) for(int j=0;j<=9;j++) for(int k=0;k<=9;k++) for(int p=0;p<=9;p++) for(int q=0;q<=9;q++)
    {
        b[1]=i; b[2]=j; b[3]=k; b[4]=p; b[5]=q;
        if(ck()) ans++;
    }
    cout<<ans<<endl;
}
