#include <bits/stdc++.h>
using namespace std;

struct st{
    int a, b, c;
}s[100001];
bool cmp(st x, st y){
    if(x.a != y.a){
        return x.a < y.a;
    }else{
        return x.b > y.b;
    }
}
bool cmp2(st x, st y){
    if(x.a != y.a){
        return x.a > y.a;
    }else{
        return x.b > y.b;
    }
}
int main(){
    freopwn("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    int n, m, k, now = 1, time = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> s[i].a >> s[i].b >> s[i].c;
    }
    sort(s + 1, s + n + 1, cmp);
    now = 1;
    if(m == 1){
        while(now != 1){
            for(int i = m; i >= 1 && time >= s[i].c; i++){
                if(s[i].b == now){
                    now = s[i].a;
                    time++;
                }
            }
        }
        cout << time;
        return 0;
    }
    while(now != 1 || time % k != 0){
        time = 0;
        now = n;
        for(int i = m; i > 1; i++){
            if(now == s[i].b){
                now = s[i].a;
                time++;
            }
        }
        sort(s + 1, s + n + 1, cmp2);
    }
    cout << time;
    return 0;
}