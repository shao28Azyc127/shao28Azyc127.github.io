#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int num, T;
int n, m;
int tp[20];
int fa[N];
char t34[N];
int ans34;
bool isu[N];
int o[20], cal[N][3];
int ans56;
struct node{
    bool cen;
    int t;
}poi[N<<1];
bool isopt(char c){
    if(c=='+' || c=='-' || c=='T' || c=='F' || c=='U')
        return 1;
    return 0;
}
int mn;
int fan(int i){
    if(i==3) return 3;
    if(i==1) return 2;
    return 1;
}
void judge(){
    for(int i=1; i<=m; ++i){
        int d = cal[i][0];
        int pf = cal[i][1];
        int pt = cal[i][2];
        if(d==0){
            tp[pt] = tp[pf];
        }else if(d==1){
            tp[pt] = fan(tp[pf]);
        }else if(d==2){
            tp[pf] = 1;
        }else if(d==3){
            tp[pf] = 2;
        }else{
            tp[pf] = 3;
        }
    }
    int acnt = 0;
    for(int i=1; i<=n; ++i){
        if(o[i]^tp[i]) return;
        if(o[i]==3) ++acnt;
    }
    mn = min(mn, acnt);
}
void dfs(int loc){
    for(int i=1; i<=3; ++i){
        o[loc] = tp[loc] = i;
        if(loc==1){
            judge();
            for(int j=1; j<=n; ++j) tp[j] = o[j];
        }else dfs(loc-1);
    }
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin>>num>>T;
    if(num==1 || num==2){
        while(T--){
            mn = 0x7f7f7f7f;
            scanf("%d%d", &n, &m);
            for(int i=1; i<=m; ++i){
                char c = getchar();
                while(!isopt(c)) c = getchar();
                if(c=='+'){
                    cal[i][0] = 0;
                    int v1,v2;
                    scanf("%d%d", &v1, &v2);
                    cal[i][1] = v2;
                    cal[i][2] = v1;
                }else if(c=='-'){
                    cal[i][0] = 1;
                    int v1,v2;
                    scanf("%d%d", &v1, &v2);
                    cal[i][1] = v2;
                    cal[i][2] = v1;
                }else if(c=='T'){
                    int v;
                    scanf("%d", &v);
                    cal[i][0] = 2;
                    cal[i][1] = v;
                }else if(c=='F'){
                    int v;
                    scanf("%d", &v);
                    cal[i][0] = 3;
                    cal[i][1] = v;
                }else{
                    int v;
                    scanf("%d", &v);
                    cal[i][0] = 4;
                    cal[i][1] = v;
                }
            }
            dfs(n);
            printf("%d\n", mn);
            memset(cal, 0, sizeof(cal));
        }
    }if(num==3 || num==4){
        while(T--){
            scanf("%d%d", &n, &m);
            for(int i=1; i<=m; ++i){
                char c = getchar();
                while(!isopt(c)) c = getchar();
                int v;
                scanf("%d", &v);
                t34[v] = c;
            }
            for(int i=1; i<=n; ++i)
                if(t34[i]=='U') ++ans34;
            printf("%d\n", ans34);
            for(int i=1; i<=n; ++i) t34[i] = '\0';
            ans34 = 0;
        }
    }
    return 0;
}