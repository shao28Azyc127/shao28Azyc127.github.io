#include <bits/stdc++.h>
using namespace std;
struct zhan{
    int l;
    int cost;
}z[100010];
long long n,d,lst[100010],money = 0;
double now = 0;
bool cmp(zhan a,zhan b){
    if(a.cost < b.cost) return true;
    return false;
}
int main(){
    freopen("road1.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> z[i].l;
    }
    for(int i = 0;i < n;i++){
        cin >> z[i].cost;
    }
    for(int i = 0;i < n;i++){
        if(i == 0) lst[0] = 0;
        lst[i] = lst[i - 1] + z[i].l;
    }
    for(int i = 0;i < n - 1;i = i){
        int k = 1;
        while(i + k < n - 1 && z[i + k].cost >= z[i].cost) k++;
        double need = 1.0 * (lst[i + k] - lst[i] - now * d) / d;
        money += ceil(need) * z[i].cost;
        now += (ceil(need) - need);
        i += k;
    }
    cout << money << endl;
    return 0;
}
