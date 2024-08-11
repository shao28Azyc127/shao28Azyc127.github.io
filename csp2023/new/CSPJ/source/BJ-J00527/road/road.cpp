#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node{
    int price;
    int index;
};

int n,d;
int ans = 0;
int dis[100010];
int price[100010];
node l[100010];

bool cmp(node a,node b){
    return a.price < b.price;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i = 1;i < n;i++){
        cin >> dis[i];
        dis[i] += dis[i-1];
    }
    for (int i = 1;i <= n;i++){
        cin >> price[i];
        l[i].price = price[i];
        l[i].index = i;
    }
    sort(l+1,l+n+1,cmp);
    int right = n-1;
    for (int i = 1;i <= n;i++){
        int x = l[i].price;
        int ind = l[i].index;
        if (ind <= right) {
            int ll = dis[right] - dis[ind-1];
            ans += ceil(ll/(double)d)*price[ind];
            right = ind - 1;
        }
        if (right == 0) break;
    }
    cout << ans;
    return 0;
}
