#include <bits/stdc++.h>
using namespace std;

struct node {
    long long dist, price;
} a[100005];

int n, d;

void dfs(int step, int ndist, int sump){
    if (step == n){
        cout << sump << endl;
        return;
    }
    int minp = a[step].price, minind = step;
    for (int i = step; i <= n; i++){
        if (a[i].price < minp){
            minp = a[i].price;
            minind = i;
            break;
        }
    }

    if (minind == step){
        dfs(n, ceil((double)(a[n].dist-a[step].dist-ndist) / d) * d - (a[n].dist-a[step].dist-ndist), sump+ceil((double)(a[n].dist-a[step].dist-ndist) / d) * a[step].price);
        return;
    }
    dfs(minind, ceil((double)(a[minind].dist-a[step].dist-ndist) / d) * d - (a[minind].dist-a[step].dist-ndist), sump+ceil((double)(a[minind].dist-a[step].dist-ndist) / d) * a[step].price);
    return;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    a[1].dist = 0;
    for (int i = 2; i <= n; i++){
        cin >> a[i].dist;
        a[i].dist += a[i-1].dist;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].price;
    }

    dfs(1, 0, 0);

    return 0;

}
