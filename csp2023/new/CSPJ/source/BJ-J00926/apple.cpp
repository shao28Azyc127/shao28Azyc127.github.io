#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long ans1,ans2;
struct num{
    int from,to;
}num[1000005];

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    if(n == 1){
        cout << 1 << " " << 1;
        return 0;
    }
    m = n;
    while(m){
        m -= (m+2)/3;
        ans1++;
    }
    cout << ans1 << " ";
    num[n+1] = {-1,1};
    num[n] = {n-1,0};
    num[1] = {n+1,2};
    for(int i = 2;i < n;i++){
        num[i] = {i-1,i+1};
    }
    for(int j = 1;j <= ans1;j++){
        for(int i = num[n+1].to;i;i = num[num[num[i].to].to].to){
            num[num[i].from].to = num[i].to;
            num[num[i].to].from = num[i].from;
            if(i == n){
                cout << j;
                return 0;
            }
        }
    }
}
