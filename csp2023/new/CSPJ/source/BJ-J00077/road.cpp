#include<bits/stdc++.h>
using namespace std;
int a[100000], b[100000], ans, n, d, minx=-1000, mini, ma, c;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i=1;i<=n-1;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        if(b[i]<minx){
            mini=i;
            minx=b[i];
        }
    }
    for(int i=1;i<=n;i++){
        ma=0;
        for(int j=mini;j<=n-1;j++){
            ma+=a[j];
        }
        if(ma%d==0) ans+=ma/d*minx;
        else ans+=(ma/d+1)*minx;
        if(mini==1) cout << ans;
        minx=-1000;
        c=mini;
        for(int j=1;j<c;j++){
            if(b[j]<minx){
                minx=b[i];
                mini=j;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
