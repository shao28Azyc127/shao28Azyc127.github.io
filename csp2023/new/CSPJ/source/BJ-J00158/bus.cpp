#include <bits/stdc++.h>

using namespace std;
bool ri[1001][1001];
int ra[1001][1001],n,m,k;
unsigned long long int na[1001];
unsigned long long int maxi(unsigned long long int a,unsigned long long int b){
    return a>b?a:b;
}
void dfs(int x){
    if(x==n) return;
    for(int i=1;i<=n;i++){
        if(ri[x][i]){
            if(maxi(ra[x][i],na[x])+1<na[i]){
                na[i]=maxi(ra[x][i],na[x])+1;
                dfs(i);
            }
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int u,v,a;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++) na[i]=-1;
    na[1]=k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&a);
        ri[u][v]=true;
        ra[u][v]=a;
    }
    dfs(1);
    if(na[n]==-1) printf("-1\n");
    else{
        if(na[n]%k!=0) na[n]=na[n]-na[n]%k+k;
        cout<<na[n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
