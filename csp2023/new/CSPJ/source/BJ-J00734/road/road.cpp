#include<bits/stdc++.h>
using namespace std;

int n, d;
int dist[100005], price[100005];
int totdist, minprice, minn;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;

    for(int i=1; i<=n-1; i++){
        cin >> dist[i];
        totdist += dist[i];
    }
    for(int i=1; i<=n; i++){
        cin >> price[i];
    }

    //cout << totdist << " " << d << endl;
    if(totdist%d == 0){
        cout << (totdist/d)*price[1];
    }
    else if(totdist%d != 0){
        cout << ((totdist/d)+1)*price[1];
    }

    return 0;
}
