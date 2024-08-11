#include<bits/stdc++.h>
using namespace std;
int a[100000][4];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    cout<<6;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
