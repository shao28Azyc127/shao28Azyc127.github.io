#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;

ll n,i = 0,f,cnt = 0;

ll t(ll &x){
    ll a = 0,b = 0;
    if((x-1)%3 == 0) a = 1;
    b += 1;
    x -=b;
    b += x/3;
    x -= b;
    x += 1;
    return a;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>> n;
    while(n > 0){
        i += 1;
        f = t(n);
        cnt += f;
        if(cnt == 1 && f == 1){
            cout<<i <<' ';
        }
    }
    cout<< i;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
