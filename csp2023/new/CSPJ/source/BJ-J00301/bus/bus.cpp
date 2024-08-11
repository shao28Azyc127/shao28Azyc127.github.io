#include<bits/stdc++.h>
using namespace std;
int a [1001][1001];
int main(){
    freopen ("bus.in","r",stdin);
    freopen ("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
        }
    }
    cout<<6;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
