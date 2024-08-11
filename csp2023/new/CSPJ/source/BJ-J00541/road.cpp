#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int brief;
    int dis;
    int price;
};

bool cmp(Node x,Node y)
{
    return x.price < y.price;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    Node station[n+5];
    for (int i = 2;i<=n;i++)
    {
        station[i].brief = i;
        cin >> station[i].dis;
    }
    int first_price;
    cin >> first_price;
    for (int i = 2;i<=n;i++)
    {
        cin >> station[i].price;
    }
    int oil_in = 0,cost = 0;
    // sort(station+1,station+n+1,cmp);
    // first station
    for (int i = 1;;i++)
    {
        if ((i*d) >= station[1].dis){
            cost += first_price * i;
            break;
        }
    }
    // other_station
    for (int i = 2;i<=n-1;i++)
    {
        int price_this_station=0,price_next_station=0;
        for (int j = 1;;j++)
        {
            if ((j*d) >= station[i].dis){
                price_this_station = j * station[i].price;
                break;
                }
        }
        for (int j = 1;;j++)
        {
            if ((j*d) >= station[i].dis){
                price_this_station = j * station[i].price;
                break;
            }
        }
        cost += max(price_next_station,price_this_station);
    }
    cout << cost;
    return 0;
}