#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int MAXP = 1e5+1;

int n, d, recentstation=1;
double recentoil=0.00;
int dis[N]={0};
int price[N]={0};
long long ans=0;

long long getdis(int station1, int station2){
    long long res = 0;
    for (int i=station1; i<station2; i++){
        res = res+dis[i];
    }
    return res;
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d", &n, &d);
    for (int i=1; i<n; i++){
        scanf("%d", &dis[i]);
    }
    for (int i=1; i<=n; i++){
        scanf("%d", &price[i]);
    }

    if (n == 1){
        printf("0");
        return 0;
    }

    price[n] = MAXP;

    while (recentstation < N){
        bool suc_find = false;

        for (int i=recentstation+1; i<=n; i++){
            if (price[i] < price[recentstation]){
                suc_find = true;
                long long recent_dis = getdis(recentstation, i);
                double recentdis = recent_dis-recentoil*d;
                long long oil = recentdis/d;
                if (oil*d < recentdis){
                    oil++;
                }

                long long recent_price = price[recentstation]*oil;
                ans = ans+recent_price;
                recentoil = oil+recentoil-(recent_dis*1.00/d);
                recentstation = i;
                break;
            }
        }

        if (suc_find == false){
            long long recent_dis = getdis(recentstation, n);
            double recentdis = recent_dis-recentoil*d;
            long long oil = recentdis/d;
            if (oil*d < recentdis){
                oil++;
            }

            long long recent_price = price[recentstation]*oil;
            ans = ans+recent_price;
            break;
        }
    }

    printf("%lld", ans);
    return 0;
}
