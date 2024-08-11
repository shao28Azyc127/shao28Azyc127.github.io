#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int aa[100000];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ll n;
    scanf("%lld",&n);
    ll n1 = n;
    while (n--){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        ll t = a*10000+b*1000+c*100+d*10+e;
        //a
        for (int i = a+1; i <= 9; i++){
            ll t1 = i*10000+b*1000+c*100+d*10+e;
            aa[t1]++;
        }
        for (int i = a-1; i >= 0; i--){
            ll t1 = i*10000+b*1000+c*100+d*10+e;
            aa[t1]++;
        }
        //b
        for (int i = b+1; i <= 9; i++){
            ll t1 = a*10000+i*1000+c*100+d*10+e;
            aa[t1]++;
        }
        for (int i = b-1; i >= 0; i--){
            ll t1 = a*10000+i*1000+c*100+d*10+e;
            aa[t1]++;
        }
        //c
        for (int i = c+1; i <= 9; i++){
            ll t1 = a*10000+b*1000+i*100+d*10+e;
            aa[t1]++;
        }
        for (int i = c-1; i >= 0; i--){
            ll t1 = a*10000+b*1000+i*100+d*10+e;
            aa[t1]++;
        }
        //d
        for (int i = d+1; i <= 9; i++){
            ll t1 = a*10000+b*1000+c*100+i*10+e;
            aa[t1]++;
        }
        for (int i = d-1; i >= 0; i--){
            ll t1 = a*10000+b*1000+c*100+i*10+e;
            aa[t1]++;
        }
        //e
        for (int i = e+1; i <= 9; i++){
            ll t1 = a*10000+b*1000+c*100+d*10+i;
            aa[t1]++;
        }
        for (int i = e-1; i >= 0; i--){
            ll t1 = a*10000+b*1000+c*100+d*10+i;
            aa[t1]++;
        }
        //ab
        int a1=a,b1=b;
        for (int i = 1; i <= 9; i++){
                //cout <<a1 << " " << b1 << endl;
            a1--;b1--;
            if (a1 < 0)a1+= 10;
            if (b1 < 0) b1 += 10;
            ll t1 = a1*10000+b1*1000+c*100+d*10+e;
            aa[t1]++;
        }
        //bc
        int c1=c;
        b1=b;
        for (int i = 1; i <= 9; i++){
            c1--;b1--;
            if (c1 < 0)c1 += 10;
            if (b1 < 0) b1 += 10;
            ll t1 = a*10000+b1*1000+c1*100+d*10+e;
            aa[t1]++;
        }
        //cd
        c1=c;
        int d1=d;
        for (int i = 1; i <= 9; i++){
            c1--;d1--;
            if (c1 < 0)c1+= 10;
            if (d1 < 0) d1 += 10;
            ll t1 = a*10000+b*1000+c1*100+d1*10+e;
            aa[t1]++;
        }
        //de
        d1=d;
        int e1=e;
        for (int i = 1; i <= 9; i++){
            d1--;e1--;
            if (d1 < 0)d1+= 10;
            if (e1 < 0) e1 += 10;
            ll t1 = a*10000+b*1000+c*100+d1*10+e1;
            aa[t1]++;
        }
        aa[t] = -114;
    }
    ll sum = 0;
    for (int i = 1; i <= 99999; i++){
        //cout << aa[i];
        if (aa[i] == n1){
            sum++;
        }
    }
    cout << sum;
    return 0;
}
