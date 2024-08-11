#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n, d, v[100010];
int dp[100010][1000010];
double vtot;

struct station{
    int num;
    int p;
}a[1000010];

bool cmp(station x, station y){
    return x.num < y.num;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> v[i];
        vtot+=v[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i].num;
        a[i].p = i;
    }
    sort(a+1, a+n+1, cmp);
    if(a[1].p == 1){
        cout << a[1].num*ceil(vtot/d) << endl;
        return 0;
    }
    return 0;
}
