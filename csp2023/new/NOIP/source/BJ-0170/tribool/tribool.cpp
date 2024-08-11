

#include <bits/stdc++.h>

using namespace std;

int c, T, n, m;
struct query{
    char c;
    int from, to;
}q[100010];
int tri[100010], p[100010], Min = 1e9;

void dfs(int dep){
    if(dep > n){
        for(int i = 1; i <= n; i++) p[i] = tri[i];
        // bool chk = true;
        // for(int i = 1; i <= n; i++) if(tri[i] != 0) chk = false;

        for(int i = 1; i <= m; i++){
            if(q[i].c == 'T') p[q[i].to] = 1;
            else if(q[i].c == 'F') p[q[i].to] = 0;
            else if(q[i].c == 'U') p[q[i].to] = 2;
            else if(q[i].c == '+') p[q[i].to] = p[q[i].from];
            else{
                if(p[q[i].from] == 2) p[q[i].to] = 2;
                else p[q[i].to] = p[q[i].from] ^ 1;
            }
         //   if(chk) cout << i << ' ' << q[i].c << ' ' << q[i].from << ' ' << q[i].to << ' ' << p[q[i].to] << ' ' << p[q[i].from] << endl;
        }
       
        bool b = true;
        for(int i = 1; i <= n; i++)
            if(tri[i] != p[i]){
                b = false;
                break;
            }
        if(!b) return;
        int cnt = 0; 
        // for(int i = 1; i <= n; i++) cout << p[i] << ' ';
        // cout << endl;
        for(int i = 1; i <= n; i++) cnt += (tri[i] == 2);
        if(cnt < Min){
            Min = cnt;
            // for(int i = 1; i <= n; i++) cout << tri[i] << ' ' << p[i] << endl;
            // cout << endl;
        }
        return;
    }
    for(int i = 0; i <= 2; i++){
        tri[dep] = i;
        dfs(dep + 1);
    }
}

void sub1(){
    dfs(1);
    cout << Min << endl;
}

void sub2(){
    for(int i = 1; i <= m; i++){
        if(q[i].c == 'T') tri[q[i].to] = 1;
        else if(q[i].c == 'U') tri[q[i].to] = 2;
        else tri[q[i].to] = 0;
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++) cnt += (tri[i] == 2);
    cout << cnt << endl;
}

int fa[100010];

int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void sub3(){
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
        if(q[i].c == 'U'){
            tri[q[i].to] = 2;
        }
    for(int i = 1; i <= m; i++)
        if(q[i].c == '+'){
            int x = q[i].from, y = q[i].to;
            x = find(x), y = find(y);
            if(x == y) continue;
            if(tri[x] == 2 && tri[y] != 2) fa[y] = x;
            else if(tri[x] != 2 && tri[y] == 2) fa[x] = y;
            else fa[y] = x;
        }

    int cnt = 0;
    for(int i = 1; i <= m; i++) cnt += (tri[find(i)] == 2);
    cout << cnt << endl;
}

// void paintU(int x){
//     tri[x] = 2;
//     if(fa[x] == x) return;
//     paint(fa[x]);
// }

// void sub4(){
//     for(int i = 1; i <= n; i++) fa[i] = i;
//     for(int i = 1; i <= m; i++){
//         int x = q[i].from, y = q[i].to;
//         if(q[i].c == '+'){
//             x = find(x), y = find(y);
//             if(x == y){
//                 if(tri[q[i].from] != tri[q[i].to])
//                     tri[x] = 2;
//             }
//         }

//     }
// }

int main (){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> T;
    while(T--){
        memset(q, 0, sizeof(q));
        Min = 1e9;
        memset(tri, 0, sizeof(tri));
        memset(p, 0, sizeof(p));
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
            cin >> q[i].c;
          //  cout << i << ' ' << q[i].c << endl;
            if(q[i].c == 'T' || q[i].c == 'F' || q[i].c == 'U') cin >> q[i].to;
            else cin >> q[i].to >> q[i].from;
           //  << ' ' << q[i].from << ' ' << q[i].to << endl;
        }
        if(c == 1 || c == 2) sub1();
        // if(c == 3 || c == 4) sub2();
        // else if(c == 5 || c == 6) sub3();
        else sub2();
    }

    return 0;
}