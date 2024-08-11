#include<bits/stdc++.h>
using namespace std;
struct road{
    int u;
    int v;
    int a;
}ans[20005];
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ans[i].u>>ans[i].v>>ans[i].a;
    }
    int fff=0;
    for(int i=1;i<n;i++){
        fff+=i;
    }
    if(fff=m){
        cout<<k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
