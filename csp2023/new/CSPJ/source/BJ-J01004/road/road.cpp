#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node1{
    long long v;
    long long a;
};

struct node2{
    long long cost;
    long long id;
};

node1 a[100010];
node2 b[100010];

bool cmp(node2 x, node2 y){
    return x.cost < y.cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    long long n;
    long long d;
    cin >> n >> d;

    for(long long i = 1; i < n; i++){
        cin >> a[i].v;
    }
    //1~2 2~3 3~4 ... n-1~n距离

    for(long long i = 1; i <= n; i++){
        cin >> a[i].a;
        b[i].cost = a[i].a;
        b[i].id = i;
    }

    long long sum = 0;

    long long last = 0;

    long long pos = 1;

    for(long long i = 2; i <= n; i++){
        //每多一个站点需要看能卖哪个
        //sort(b + 1, b + i, cmp);
        if(b[i-1].cost < b[pos].cost){
            pos = i-1;
        }
        if(a[i-1].v >= last){
            long long x = (a[i-1].v - last) / d;
            long long y = (a[i-1].v - last) % d;
            long long temp = (x + !(y == 0));

            sum += temp * b[pos].cost;
            last = temp * d - a[i-1].v + last;
        }else{
            last -= a[i-1].v;
        }
    }

    cout << sum;
    return 0;
}
