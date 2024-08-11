#include <bits/stdc++.h>
using namespace std;

struct C{
    int w;
    int id;
    int pid;
};

int dis[100005];
C m[100005];

bool cmp1(const C &x, const C &y){
    return x.w < y.w;
}

bool cmp2(const C &x, const C &y){
    return x.id < y.id;
}

int main(){
    freopen("road.in", r, stdin);
    freopen("road.out", w, stdout);
    
    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i++){
        cin >> dis[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> m[i].w;
        m[i].id = i;
    }

    sort(m + 1, m + n + 1, cmp1);
    for(int i = 1; i <= n; i++) m[i].pid = i;
    sort(m + 1, m + n + 1, cmp2);

    int c = 1;
    int pay = 0;
    for(int i = 1; i <= n; i++){
        pay += ceil(dis[i] / (double)d) * m[c].w;
        if(m[i].id < m[c].id){
            c = i;
        }
    }

    cout << pay;

    return 0;
}
