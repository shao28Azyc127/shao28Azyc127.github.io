#include<bits/stdc++.h>
using namespace std;
double n, d, ans;
int dis;
struct Zhan{
    int a, b, c;
}c[100005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i < n; i++){
        cin >> c[i].a;
        c[i].c = c[i-1].c+c[i].a;
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i].b;
    }
    ans+=c[1].b*ceil(c[1].a/d);
    dis+=ceil(c[1].a/d)*d;
    for(int i = 2; i < n; i++){
        if(c[i-1].b<=c[i].b)c[i].b = c[i-1].b;
        while(dis<c[i].c){
            ans+=c[i].b;
            dis+=d;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}