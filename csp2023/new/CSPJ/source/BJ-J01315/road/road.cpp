#include <bits/stdc++.h>
using namespace std;
int n,d,price[100002],sum[100002],Min = 100002,minn;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (int i = 2;i < n;i++){
        scanf("%d",&sum[i]);
        sum[i] += sum[i - 1];
    }
    for (int i = 1;i <= n;i++){
        scanf("%d",&price[i]);
        if (price[i] < Min){
            Min = price[i];
            minn = i;
        }
    }
    int cost = 0;
    for (int i = 1;i < n;i++){
        if (i != minn){
            for (int j = i + 1;j <= n;j++){
                if (price[j] < price[i]){
                    int len = abs(sum[j] - sum[i]);
                    int tmp = len * 1.0 / d + 1.0 - 1;
                    cost += ceil(tmp) * price[i];
                    i = j - 1;
                    break;
                }
            }
        }else{
            cost += (int)abs(sum[n] - sum[i]) / d * price[i];
        }
    }
    printf("%d",cost);
    return 0;
}
