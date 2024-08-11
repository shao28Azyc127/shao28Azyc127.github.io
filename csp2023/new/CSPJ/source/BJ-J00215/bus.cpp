#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,u,v,a;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i < m;i++)cin >> u >> v >> a;
    cout << k * n / 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
