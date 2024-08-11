#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,dis[100004],price[100004],pricei[100004],tmp,tmpi,mnp=114514,mni,sumdis=0,sum=0;
    cin >> n >> d;
    for(int i = 0;i < n-1;++i){
        cin >> dis[i];
        sumdis += dis[i];
    }
    cin >> price[0];
    for(int i = 1;i < n-1;++i){
        cin >> price[i];
        pricei[i] = i;
        if(price[i] < mnp){
            mnp = price[i];
            mni = i;
        }
    }
    if(mni = 0){
        if(sumdis % d){
            cout << mnp*(sumdis/d+1);
        }else{
            cout << mnp*(sumdis/d);
        }
    }else{
        for(int i = 0;i < n;++i){
            for(int j = 1;j < n-1;++j){
                if(price[i] < price[i-1]){
                    tmp = price[i];
                    price[i] = price[i-1];
                    price[i-1] = tmp;
                    pricei[i-1] = i;
                    pricei[i] = i-1;
                }
            }
        }
        int sumdis2 = 0;
        for(int i = 0;i < mni;++i){
            sumdis2 += dis[i];
        }
        if(sumdis2 % d){
            sum += mnp*(sumdis2/d+1);
        }else{
            sum += mnp*(sumdis2/d);
        }
        if((sumdis2-sumdis) % d){
            sum += mnp*((sumdis2-sumdis)/d+1);
        }else{
            sum += mnp*((sumdis2-sumdis)/d);
        }
        cout << sum;
    }
    return 0;
}
