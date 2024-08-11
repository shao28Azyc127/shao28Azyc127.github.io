#include<bits/stdc++.h>
using namespace std;
//cout << "thanks god,places help me AK CSP-J" << endl£»
const int N=1e5+1;
long long jia[N],ju[N],zj,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i=1;i<n;i++) cin >> ju[i];
    for(int i=1;i<=n;i++) cin >> jia[i];
    for(int i=1;i<n;i++)
    {
        zj+=ju[i];
    }
    zj/=k;
    ans=zj*jia[1];
    cout << ans;
    return 0;
}
