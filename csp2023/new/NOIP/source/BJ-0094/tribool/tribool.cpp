#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
const int MAXN = 1e5 + 5;
int C,Test;
int n,m;
int ans;

enum Stat{
    F = 0,
    U = 1,
    T = 2,
    X = 3 // We don't know the var's status
};
Stat var[MAXN];
Stat srch[MAXN];
vector<pair<pair<int,int>,bool> > ops;

template <class T>
    inline void clear(T &x){
        T y;
        swap(x,y);
    }

inline Stat fei(Stat a){
    switch (a){
        case F:
            return T;
        case U:
            return U;
        case T:
            return F;
        default:
            abort();
    }
    abort();
}

void dfs(int idx,int cnt){
    if (cnt >= ans)return;
    if (idx == n + 1){
        for (int i = 1;i <= n;i ++)
            var[i] = srch[i];
        for (auto it : ops){
            if (it.second)
                var[it.first.first] = var[it.first.second];
            else
                var[it.first.first] = fei(var[it.first.second]);
        }
        for (int i = 1;i <= n;i ++)
            if (var[i] != srch[i])
                return;
        ans = min(ans,cnt);
        return;
    }
    srch[idx] = T;
    dfs(idx + 1,cnt);
    srch[idx] = F;
    dfs(idx + 1,cnt);
    srch[idx] = U;
    dfs(idx + 1,cnt + 1);
}

int main(){
    #ifndef kevin
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    #endif
    scanf("%d%d",&C,&Test);
    while (Test --){
        // printf("REMAIN Tests: %d\n",Test + 1);
        clear(ops);
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i ++)
            var[i] = X;
        var[n + 1] = T;
        var[n + 2] = F;
        var[n + 3] = U;
        if (3 <= C && C <= 4){
            while (m --){
                char op[2];
                int x;
                scanf("%s%d",op,&x);
                if (op[0] == 'T')var[x] = T;
                if (op[0] == 'F')var[x] = F;
                if (op[0] == 'U')var[x] = U;
            }
            int cnt = 0;
            for (int i = 1;i <= n;i ++)
                if (var[i] == U)
                    cnt ++;
            printf("%d\n",cnt);
        }else{
            while (m --){
                char op[2];
                int x,y;
                scanf("%s",op);
                if (op[0] == 'T'){
                    scanf("%d",&x);
                    ops.push_back(mp(mp(x,n + 1),true));
                }else if (op[0] == 'F'){
                    scanf("%d",&x);
                    ops.push_back(mp(mp(x,n + 2),true));
                }else if (op[0] == 'U'){
                    scanf("%d",&x);
                    ops.push_back(mp(mp(x,n + 3),true));
                }else if (op[0] == '+'){
                    scanf("%d%d",&x,&y);
                    ops.push_back(mp(mp(x,y),true));
                }else if (op[0] == '-'){
                    scanf("%d%d",&x,&y);
                    ops.push_back(mp(mp(x,y),false));
                }
                
            }
            ans = MAXN;
            dfs(1,0);
            printf("%d\n",ans);
        }
    }
    return 0;
}