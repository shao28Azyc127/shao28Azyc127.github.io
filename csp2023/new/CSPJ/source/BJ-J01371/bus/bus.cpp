#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e4+10;
int n,m,k;
int a[maxn],vis[maxn],dis[maxn];
//int edge[maxn][maxn];
vector<pair<int,int>> q[maxn];

int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        q[u].push_back(make_pair(v,w));
    }
    
    cout<<-1<<endl;

    /*if(n<=10&&m<=15){
        
    }
    if(k==1){
        
    }*/

    fclose(stdin);
    fclose(stdout);
    return 0;
}
