#include<bits/stdc++.h>
using namespace std;
int ans, k, n, m, a1, a, b;
bool ma[1000][1000]={0};
int s[10005]={100000};
int d(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(ma[i][j]==1)
                s[j]=min(s[j], s[i]+1);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(ma[i][j]==1)
                s[j]=min(s[j], s[i]+1);
        }
    }
    return s[n];
}
int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> a1;
        ma[a][b]=1;
    }
    cout << d();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
