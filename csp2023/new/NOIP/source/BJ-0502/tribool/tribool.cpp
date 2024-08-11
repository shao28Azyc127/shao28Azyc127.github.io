#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
struct Edge{
    int v, u;//val, current
    int next;
}e[100010];//excludes 0
int head[100010];
int cnt;
bool recorded[10010][10010];
void add(int u, int v){
    if(recorded[u][v] || recorded[v][u]) return;
    e[++cnt].next = head[u];
    head[u] = cnt;
    e[cnt].u = u;
    e[cnt].v = v;
    recorded[u][v] = true;
}
void del(int u, int v){
    for(int k = head[u]; k > 0; k = e[k].next){
        if(e[e[k].next].v == v){
            e[k].next = e[e[k].next].next;
            e[k].next = 0;
            recorded[u][v] = false;
            return;
        }
    }
}
struct Element{
    bool is_related;
    int related_id;
    bool is_positive;
    char val;// 0 = F, 1 = T, 2 = U
    bool changed;
}records[100010];
bool has_accurate_val(int i){
    return (records[i].val == 'U' || records[i].val == 'T' || records[i].val == 'F') && (!records[i].is_related);
}
char negative(char origin){
    if(origin == 'T') return 'F';
    if(origin == 'F') return 'T';
    if(origin == 'U') return 'U';
    return 0;
}
void dfs(int j){//j is in records[j]
    //cout<<j<<' '<<head[j]<<endl;
    for(int k = head[j]; k > 0; k = e[k].next){
        if(records[e[k].v].changed) continue;
        records[e[k].v].is_related = false;
        records[e[k].v].changed = true;
        if(records[e[k].v].is_positive) records[e[k].v].val = records[e[k].u].val;
        else records[e[k].v].val = negative(records[e[k].u].val);
        dfs(e[k].v);
    }
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c = read(), t = read();
    for(int i=0;i<t;i++){
        int n = read(), m = read();
        memset(records, 0, sizeof(records));
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch == '+'){
                int u = read(), v = read();
                records[u].is_related = true;
                records[u].related_id = v;
                records[u].is_positive = true;
                records[u].changed = false;
                records[u].val = 0;
                add(v, u);
            }
            else if(ch == '-'){
                int u = read(), v = read();
                records[u].is_related = true;
                records[u].related_id = v;
                records[u].is_positive = false;
                records[u].changed = false;
                records[u].val = 0;
                add(v, u);
            }
            else{
                int u = read();
                if(records[u].related_id > 0){
                    del(records[u].related_id, u);
                }
                records[u].is_related = false;
                records[u].related_id = 0;
                records[u].is_positive = true;
                records[u].changed = false;
                records[u].val = ch;
            }
        }
        if(c == 3 || c == 4){
            int ans = 0;
            for(int j=1;j<=n;j++){
                ans += (!records[j].is_related && records[j].val == 'U');
            }
            printf("%d\n", ans);
            continue;
        }
        for(int j=1;j<=n;j++){
            //cout<<j<<' '<<records[j].changed<<' '<<has_accurate_val(j)<<endl;
            if((!records[j].changed) && has_accurate_val(j)){
                dfs(j);
                //cout<<"dfs completed.\n";
                records[j].changed = true;
            }
        }
        if(c == 5 || c == 6){
            int ans = 0;
            for(int j=1;j<=n;j++){
                ans += (!records[j].is_related && records[j].val == 'U');
            }
            printf("%d\n", ans);
            continue;
        }
    }
    return 0;
}
