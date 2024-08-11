#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    int number;
    int price;
    int dis;
    int mingci;
}a[100005];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    long long sumDis=0,money = 0;
    for(int i=1;i<=n-1; i++){
        a[i].number = i;
        cin >> a[i].dis;
        sumDis += a[i].dis;
    }
    a[n].number=n;
    a[n].dis=0;
    int minP=999999,index=1;
    for(int i=1; i<=n; i++){
        cin >> a[i].price;
        if(a[i].price < minP){
            index = i;
            minP = a[i].price;
        }
    }

    if(index == 1){
        if(sumDis%d==0){
            money = sumDis/d;
        }else{
            money = sumDis/d +1;
        }
        money = money * a[1].price;
        cout << money;
        return 0;
    }
    int i=1;
    while(i<=n){
            int j;
            int dis = a[i].dis;
            for(j=i+1; j<=n; j++){
                if(a[j].price>=a[i].price){
                    dis += a[j].dis;
                    continue;
                }else{
                    break;
                }
            }
            int youN=0;

            if(dis%d == 0) {
                youN = dis/d;
            }else {

                youN = dis/d + 1;
                a[j].dis = a[j].dis - youN*d + dis;
            }

            money = money + youN*a[i].price;

            i = j;

    }
    cout << money;

    fclose(stdin);
    fclose(stdout);
    return 0;
}