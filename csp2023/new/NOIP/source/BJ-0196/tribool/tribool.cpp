#include <bits/stdc++.h>
using namespace std;
long long c, t, n, m, qwq[100005], qwqwq[100005], mn = 1e18, fz[100005], fz2[100005], zg[100005], valq[100005], hea[100005], tot = 0;
struct Edge{
    long long next, to;
} edge[100005];
void add(long long a, long long b){
    edge[++tot] = Edge{hea[a], b};
    hea[a] = tot;
    return ;
}
void dfs2(long long now){
    if (valq[now]){
        return ;
    }
    valq[now] = 1;
    for (long long i = hea[now]; i; i = edge[i].next){
        long long v = edge[i].to;
        dfs2(v);
    }
    return ;
}
void queryinit(){
    tot = 0;
    for (long long i = 1; i <= 100000; i++){
        valq[i] = 0;
        hea[i] = 0;
    }
    return ;
}
char opt[100005];
void dfs(long long now){
    if (now == n + 1){
        for (long long i = 1; i <= n; i++){
            fz2[i] = fz[i];
        }
        for (long long i = 1; i <= m; i++){
            if (opt[i] == '+'){
                fz2[qwq[i]] = fz2[qwqwq[i]];
            }else if (opt[i] == '-'){
                if (fz2[qwqwq[i]] == 0){
                    fz2[qwq[i]] = 1;
                }else if (fz2[qwqwq[i]] == 1){
                    fz2[qwq[i]] = 0;
                }else{
                    fz2[qwq[i]] = 2;
                }
             }else if (opt[i] == 'T'){
                fz2[qwq[i]] = 1;
             }else if (opt[i] == 'F'){
                fz2[qwq[i]] = 0;
             }else{
                fz2[qwq[i]] = 2;
             }
        }
        bool flg = true;
        for (long long i = 1; i <= n; i++){
            if (fz[i] != fz2[i]){
                flg = false;
                break;
            }
        }
        long long cnt = 0;
        for (long long i = 1; i <= n; i++){
            if (fz[i] == 2){
                cnt++;
            }
        }
        if (flg){
            mn = min(mn, cnt);
        }
        return ;
    }
    fz[now] = 0;
    dfs(now + 1);
    fz[now] = 1;
    dfs(now + 1);
    fz[now] = 2;
    dfs(now + 1);
    return ;
}
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> t;
    if (c >= 3 && c <= 4){
        while (t--){
            cin >> n >> m;
            for (long long i = 1; i <= m; i++){
                cin >> opt[i];
                if (opt[i] == '+' || opt[i] == '-'){
                    cin >> qwq[i] >> qwqwq[i];
                }else{
                    cin >> qwq[i];
                }
            }
            for (long long i = 1; i <= n; i++){
                zg[i] = 0;
            }
            for (long long i = 1; i <= m; i++){
                 if (opt[i] == 'T'){
                    zg[qwq[i]] = 1;
                 }else if (opt[i] == 'F'){
                    zg[qwq[i]] = 0;
                 }else{
                    zg[qwq[i]] = 2;
                 }
            }
            long long cntq = 0;
            for (long long i = 1; i <= n; i++){
                if (zg[i] == 2){
                    cntq++;
                }
            }
            cout << cntq << endl;
        }
        return 0;
    }
    if (c >= 5 && c <= 6){
        while (t--){
            cin >> n >> m;
            queryinit();
            for (long long i = 1; i <= m; i++){
                cin >> opt[i];
                if (opt[i] == '+' || opt[i] == '-'){
                    cin >> qwq[i] >> qwqwq[i];
                }else{
                    cin >> qwq[i];
                }
            }
            for (long long i = 1; i <= n; i++){
                zg[i] = 0;
            }
            for (long long i = 1; i <= m; i++){
                 if (opt[i] == 'T'){
                    zg[qwq[i]] = 1;
                 }else if (opt[i] == 'F'){
                    zg[qwq[i]] = 0;
                 }else if (opt[i] == 'U'){
                    zg[qwq[i]] = 2;
                 }else{
                    zg[qwq[i]] = zg[qwqwq[i]];
                    add(qwqwq[i], qwq[i]);
                 }
            }
            long long cntq = 0;
            for (long long i = 1; i <= n; i++){
                if (zg[i] == 2 && !valq[i]){
                    dfs2(i);
                }
            }
            for (long long i = 1; i <= n; i++){
                if (valq[i]){
                    cntq++;
                }
            }
            cout << cntq << endl;
        }
        return 0;
    }
    if (c >= 1 && c <= 2){
        while (t--){
            cin >> n >> m;
            for (long long i = 1; i <= m; i++){
                cin >> opt[i];
                if (opt[i] == '+' || opt[i] == '-'){
                    cin >> qwq[i] >> qwqwq[i];
                }else{
                    cin >> qwq[i];
                }
            }
            mn = 1e18;
            dfs(1);
            cout << mn << endl;
        }
        return 0;
    }
    if (c >= 7 && c <= 8){
        while (t--){
            cin >> n >> m;
            for (long long i = 1; i <= m; i++){
                cin >> opt[i];
                if (opt[i] == '+' || opt[i] == '-'){
                    cin >> qwq[i] >> qwqwq[i];
                }else{
                    cin >> qwq[i];
                }
            }
            for (long long i = 1; i <= n; i++){
                zg[i] = 0;
            }
            for (long long i = 1; i <= m; i++){
                 if (opt[i] == '+'){
                    zg[qwq[i]] = zg[qwqwq[i]];
                 }else{
                    if (zg[qwqwq[i]] == 0){
                        zg[qwq[i]] = 1;
                    }else if (zg[qwqwq[i]] == 1){
                        zg[qwq[i]] = 0;
                    }else{
                        zg[qwq[i]] = 2;
                    }
                 }
            }
            long long cntq = 0;
            for (long long i = 1; i <= n; i++){
                if (zg[i] == 1 || zg[i] == 2){
                    cntq++;
                }
            }
            cout << cntq << endl;
        }
        return 0;
    }
     while (t--){
        cin >> n >> m;
        for (long long i = 1; i <= m; i++){
            cin >> opt[i];
            if (opt[i] == '+' || opt[i] == '-'){
                cin >> qwq[i] >> qwqwq[i];
            }else{
                cin >> qwq[i];
            }
        }
        for (long long i = 1; i <= n; i++){
            zg[i] = 0;
        }
        for (long long i = 1; i <= m; i++){
            if (opt[i] == '+'){
                zg[qwq[i]] = zg[qwqwq[i]];
            }else if (opt[i] == '-'){
                if (zg[qwqwq[i]] == 0){
                    zg[qwq[i]] = 1;
                }else if (zg[qwqwq[i]] == 1){
                    zg[qwq[i]] = 0;
                }else{
                    zg[qwq[i]] = 2;
                }
            }else if (opt[i] == 'T'){
                zg[qwq[i]] = 1;
            }else if (opt[i] == 'F'){
                zg[qwq[i]] = 0;
            }else{
                zg[qwq[i]] = 2;
            }
        }
        long long cntq = 0;
        for (long long i = 1; i <= n; i++){
            if (zg[i] == 1 || zg[i] == 2){
                cntq++;
            }
        }
        for (long long i = 1; i <= n; i++){
            zg[i] = 1;
        }
        for (long long i = 1; i <= m; i++){
            if (opt[i] == '+'){
                zg[qwq[i]] = zg[qwqwq[i]];
            }else if (opt[i] == '-'){
                if (zg[qwqwq[i]] == 0){
                    zg[qwq[i]] = 1;
                }else if (zg[qwqwq[i]] == 1){
                    zg[qwq[i]] = 0;
                }else{
                    zg[qwq[i]] = 2;
                }
            }else if (opt[i] == 'T'){
                zg[qwq[i]] = 1;
            }else if (opt[i] == 'F'){
                zg[qwq[i]] = 0;
            }else{
                zg[qwq[i]] = 2;
            }
        }
        long long cntq2 = 0;
        for (long long i = 1; i <= n; i++){
            if (zg[i] == 0 || zg[i] == 2){
                cntq2++;
            }
        }
        cout << min(cntq, cntq2) << endl;
    }
    return 0;
}
