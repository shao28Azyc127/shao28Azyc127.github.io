#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 1e5;
int a[maxn];
int b[maxn];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    b[0] = 0;
    cin >> n >> m;
    for(int i = 1;i < n;i++){
        cin >> b[i];
        b[i] += b[i - 1];
    }
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    long long ans = 0,i = 0,j = 0,dis,hy,sy = 0;
    while(i != n - 1){
        j = i + 1;
        while(j != n - 1 && a[j] > a[i]){
            j++;
        }
        dis = b[j] - b[i];
        if(dis > sy){
            dis -= sy;
        }
        else{
            sy -= dis;
            dis = 0;
        }
        hy = ceil((double)dis / (double)m);
        sy = hy * m - dis;
        ans += hy * a[i];
        i = j;
    }
    cout << ans;
    return 0;
}
