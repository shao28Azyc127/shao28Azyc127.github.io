#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e5 + 10;
int s[N];
int v[N];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n-1; i++){
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    int o = 0;
    int p = 0;
    p += s[0] * (v[0] / d);
    o += v[0] / d * d;
    if(v[0] % d != 0){
        p += s[0];
        o += d;
    o -= v[0];
    }
    for(int i = 1; i < n-1; i++){
        if(s[i] > s[i-1])
            s[i] = s[i-1];
        p += s[i] * ((v[i]-o) / d);bool f = 0;
        if((v[i] - o) % d != 0){
            p += s[i];
            v[i] += d;
            f = 1;
        }
        o += (v[i]-o) / d * d;
        o -= v[i];
        if(f)
            o += d;
    }
    printf("%d", p);
    return 0;
}
