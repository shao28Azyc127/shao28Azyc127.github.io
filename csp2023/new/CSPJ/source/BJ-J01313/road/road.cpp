#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,a[1000010],u[1000010],l,d;
    cin >> n >> d;
    for(int i = 1;i <= n;i++)cin >> u[i];
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++) l += u[i];
    cout << (l / d) * a[1];
    return 0;
}
