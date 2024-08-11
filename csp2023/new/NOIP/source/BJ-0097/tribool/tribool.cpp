#include <cstdio>
#include <vector>
using namespace std;
const int rev[5] = {1,0,3,2,4};
int c,t,n,m,x,y,typ[100005],to[100005],fa[200005],siz[200005],color[200005],sum,ans;
bool flag[200005],chk;
char op;
vector <int> g[200005];
int getfa(int pos){
    return pos == fa[pos] ? pos : fa[pos] = getfa(fa[pos]);
}
void merge(int pos1,int pos2){
    pos1 = getfa(pos1);
    pos2 = getfa(pos2);
    if(pos1 != pos2){
        fa[pos1] = pos2;
        siz[pos2] += siz[pos1];
    }
}
void dfs(int pos){
    for(int i = 0;i < g[pos].size();i++){
        if(color[g[pos][i]] < 0){
            color[g[pos][i]] = !color[pos];
            dfs(g[pos][i]);
        }
        else if(color[g[pos][i]] == color[pos]){
            flag[pos] = true;
        }
    }
    chk |= flag[pos];
    sum += siz[pos];
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= 2 * n;i++){
            flag[i] = false;
            fa[i] = i;
            g[i].clear();
            color[i] = -1;
        }
        for(int i = 1;i <= n;i++){
            siz[i] = 1;
            typ[i] = 0;
            to[i] = i;
        }
        for(int i = n + 1;i <= 2 * n;i++){
            siz[i] = 0;
        }
        while(m--){
            scanf(" %c%d",&op,&x);
            if(op == 'T'){
                typ[x] = 2;
            }
            else if(op == 'F'){
                typ[x] = 3;
            }
            else if(op == 'U'){
                typ[x] = 4;
            }
            else if(op == '+'){
                scanf("%d",&y);
                typ[x] = typ[y];
                to[x] = to[y];
            }
            else{
                scanf("%d",&y);
                typ[x] = rev[typ[y]];
                to[x] = to[y];
            }
        }
        for(int i = 1;i <= n;i++){
            if(typ[i] == 0){
                merge(i,to[i]);
                merge(n + i,n + to[i]);
            }
            else if(typ[i] == 1){
                merge(i,n + to[i]);
                merge(n + i,to[i]);
            }
            else if(typ[i] == 4){
                flag[i] = flag[n + i] = true;
            }
        }
        for(int i = 1;i <= 2 * n;i++){
            flag[getfa(i)] |= flag[i];
        }
        for(int i = 1;i <= n;i++){
            g[getfa(i)].push_back(getfa(n + i));
            g[getfa(n + i)].push_back(getfa(i));
        }
        ans = 0;
        for(int i = 1;i <= 2 * n;i++){
            if(i == fa[i] && color[i] < 0){
                chk = false;
                sum = color[i] = 0;
                dfs(i);
                if(chk){
                    ans += sum;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
