#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 1e5+10;
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
int n,d;
int dis;
int v[Max],a[Max];
int flu;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=rd();d=rd();
    ll sum[Max];
    for(int i = 1; i < n ;i++){
        v[i] = rd();
        sum[i] = sum[i-1] + v[i];
    }
    int mixx = 2147482547,s;
    for(int i = 1; i <= n ; i++){
        a[i] = rd();
        if(a[i] < mixx){
            mixx = a[i];
            s=i;
        }
    }
    //cout << s << endl;
    if(s==1){
        int ans;
        ans = sum[n-1]/d;
        if(sum[n-1]%d != 0) ans++;
        ans *= a[1];
        cout << ans;
        return 0;
    }
    int now = 1;
    int ans = 0;
    for(int i = 1; i <= n ; i++){
        if(a[i] < a[now]&&i != n){
            flu = (sum[i-1] - sum[now-1]-dis)/d;
            if((sum[i-1] - sum[now-1]-dis)%d != 0) flu++;
            ans += flu*a[now];
            dis+=(flu*d) - sum[i-1] + sum[now-1];
            now = i;
        }
        if(i == n){
            flu = (sum[n-1] - sum[now-1]-dis)/d;
            if((sum[n-1] - sum[now-1]-dis)%d != 0) flu++;
            ans += flu*a[now];
            //cout << now << " "<<sum[n-1]<< " " << sum[now-1] <<" "<<dis <<endl;
        }
        //cout <<ans <<" p " <<now << " " << flu << " " << dis<< endl;
    }
    cout << ans;
    return 0;
}
