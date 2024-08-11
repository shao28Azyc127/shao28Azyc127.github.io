#include<bits/stdc++.h>
using namespace std;
struct{
    long long l;
    long long p;
}a[100001];
long long all=0,ant = 0 ;
int main(){
    //freopen("road.in","w",stdin);
    //freopen("road.out","r",stdout);
    long long n,d;
    cin >>n >>d;
    for(long long i = 1;i<=n-1;i++){
        cin >>a[i].l;
        all+=a[i].l;
    }
    for(long long i = 1;i<=n;i++){
        cin >>a[i].p;
    }
    long long min = a[1].p;
    long long min1 = 0;
    for(long long i = 1;i<=n;i++){
        if(a[i].p < min){
            min1 = 1;
        }
    }
    if(min1 == 0){
        if(all%d== 0){
            cout <<all/d*min;
            return 0;
        }else{
            cout <<(all/d+1)*min;
            return 0;
        }
    }
    long long road = a[1].l;
    long long x=0;
    for(long long i = 2;i<=n;i++){
        if(a[i].p < min){
            if(road % d ==0){
                ant+=road/d*min;
                min = a[i].p;
                road = a[i].l;
            }else{
                ant+=(road/d+1)*min;
                x=road%d;
                min = a[i].p;
                a[i].l-=x;
                road = a[i].l;
            }
        }else{
            road+=a[i+1].l;
        }
    }
    cout <<ant;
}