#include<bits/stdc++.h>
using namespace std;
long long a[100005],v[100005];
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
long long n,d,sum = 0,noww = 0,m = 0,oil = 0;//nowwshiweizhi
    scanf("%lld %lld",&n,&d); //nshizhandian,dshisudu
    for(int i = 0;i < n - 1;i++) scanf("%lld",&v[i]); //vshijuli
    for(int i = 0;i < n;i++) scanf("%lld",&a[i]); //ashijiage
    while(noww < n){
            m = a[noww];
            bool flag = 0;
        for(int i = noww;i < n;i++){
                if(m > a[i]){//ruguoyoubiwopianyide
                    long long tmp = 0;
                for(int j = noww;j < i;j++) tmp += v[j]; //leijilucheng
                        printf("%lld\n",tmp);
                    if(tmp % d == 0){
                            sum += (tmp / d) * m;
                            noww = i;
                            flag = 1;
                            break;
                    }else{
                        long long hope = (tmp - oil) / d * m;
                        long long angel = (tmp / d + 1) * m;
                        if(hope < angel){
                            sum += hope;
                            oil = 0;
                            noww = i;
                            flag = 1;
                            break;
                        }else{
                        sum += angel;
                        oil += (tmp / d + 1) * d - tmp;
                        noww = i;
                        flag = 1;
                        break;
                        }
                    }
                }
        }
        if(flag == 0){
            long long tmp = 0;
        for(int j = noww;j < n;j++) tmp += v[j];
        if(tmp % d == 0){
            sum += (tmp / d) * m;
            printf("%lld",sum);
            return 0;
        }else{
            sum += (tmp / d + 1) * m;
            printf("%lld",sum);
            return 0;
            }
        }
    }
    printf("%lld",sum);
    return 0;
}