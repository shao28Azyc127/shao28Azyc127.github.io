#include<bits/stdc++.h>
using namespace std;
const int N = 15,M = 1e5 + 5;
int O,T,n,m,k[N][5],d[N],now[N],ans,l[M],cnt,num[M];
bool vis[M],f;
vector<int> e[M];
int get(char c){
    if(c == 'T') return 1;
    if(c == 'F') return 2;
    return 3;
}
int F(int x){
    if(x <= 2) return 3 - x;
    return 3;
}
void dfs(int x,int sum){
    if(x > n){
        memcpy(now,d,sizeof(d));
        for(int i = 1;i <= m;i++){
            if(k[i][1] == 1)
                now[k[i][2]] = now[k[i][3]];
            else if(k[i][1] == 2)
                now[k[i][2]] = F(now[k[i][3]]);
            else now[k[i][2]] = k[i][3];
        }
        for(int i = 1;i <= n;i++)
            if(now[i] != d[i]) return;
        ans = min(ans,sum); return;
    }
    d[x] = 1; dfs(x + 1,sum); //T
    d[x] = 2; dfs(x + 1,sum); //F
    d[x] = 3; dfs(x + 1,sum + 1); //U
}
void dfs2(int x){
    vis[x] = 1,ans++;
    for(int v : e[x]){
        if(!vis[v]) dfs2(v);
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&O,&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(l,0,sizeof(l)); memset(vis,0,sizeof(vis));
        for(int i = 1;i <= m;i++){
            string s; int x,y; cin >> s;
            if(s[0] == '+'){
                scanf("%d%d",&x,&y);
                k[i][1] = 1,k[i][2] = x,k[i][3] = y;
                if(x != y)
                    l[x] = 0,e[y].push_back(x);
            }
            else if(s[0] == '-'){
                scanf("%d%d",&x,&y);
                k[i][1] = 2,k[i][2] = x,k[i][3] = y;
                l[x] = 0;
            }
            else{
                scanf("%d",&x);
                k[i][1] = 3,k[i][2] = x,k[i][3] = l[x] = get(s[0]);
            }
        }
        if(O <= 2){ //20
            ans = 1e9; dfs(1,0);
            printf("%d\n",ans);
        }
        else if(O == 3 || O == 4){ //20
            ans = 0;
            for(int i = 1;i <= n;i++){
                if(l[i] == 3) ans++;
            }
            printf("%d\n",ans);
        }
        else if(O == 5 || O == 6){ //0
            ans = 0;
            for(int i = 1;i <= n;i++)
                if(l[i] == 3){
                    dfs2(i);
                }
            printf("%d\n",ans);
        }
        else if(O == 7 || O == 8){ //0
            for(int i = 1;i <= n;i++) num[i] = 1;
            ans = 0;
            for(int i = 1;i <= m;i++){
                int x = k[i][2],y = k[i][3];
                if(k[i][1] == 1){
                    if(!vis[x]) vis[x] = 1,num[x] = num[y];
                    else{
                        //if(num[x] != num[y]) 
                    }
                }
                else{

                }
            }
            printf("%d\n",ans);
        }
        else{
            printf("%d\n",rand() % (n + 1));
        }
        for(int i = 1;i <= n;i++)
            e[i].clear();
    }
    return 0;
}