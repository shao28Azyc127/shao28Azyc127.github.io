#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rd(){
    int x=0;int f=1;

    char b = getchar();
    while(!isdigit(b)){
        if(b=='-') f=-1;
        b=getchar();
    }
    while (isdigit(b)){
        x = x*10 + b - '0';
        b = getchar();
    }
    return x*f;

}


int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n = rd();
    //cout << n<<endl;
    ll cnt;
    ll ans=0;
    ll temp = n-1;
    ll day=0;
    bool flg=0;
    for(int i = 1; i <= temp ;i ++){
        if(n<=3){
           // cout << 0%3<< endl;
            day = i+n;
            break;
        }
        for(int j = 1;j <= n;j++){
            if((j-1)%3==0){
                if(j == n&&!flg){
                    ans = i;
                    flg=true;
                }
                cnt++;
            }
        }
        n-=cnt;
        cnt=0;
    }
    day--;
    if(!flg){
        ans = day;
    }
    //if(temp%3==0) {ans = 1;}
    cout << day <<" "<< ans;
    return 0;
}
