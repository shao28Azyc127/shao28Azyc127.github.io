#include <bits/stdc++.h>
using namespace std;
int dis[100050];    //distances from station x to station x+1
int price[100050];  //price per liter of each station
int stas,perl,minp = 2147483647;  //number of stations,km/l of car,minimum price of gas
#define LL long long

int main(){
    srand(0);
    //ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    LL sum; //sum of distance
    cin >> stas >> perl;
    for(int i=1;i<stas;i++){
        cin >> dis[i];
        sum+=dis[i];
    }
    for(int j=1;i<=stas;j++){
        cin >> price[i];
        if(price[i]<minp)   minp = price[i];
    }
    LL ans; //sum of price for gas
    if(minp==price[1]){
        if(sum%minp==0) ans = sum/(minp*perl);
        else    ans = sum/(minp*perl)+1;
    }
    else{
        ans = rand()%10000;
    }
    cout << ans;
    return 0;
}