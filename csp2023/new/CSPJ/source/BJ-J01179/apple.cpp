#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll ans,day;

int vis[1000001];
int sum[1000001];
inline int check(){
    for(int i=1;i<=n;i++){
        if(!vis[i])return i;
    }
    return false;
}
inline int f(int i){
    int t=0;
    for(int j=i+1;j<=n;j++){
        if(!vis[j])t++;
        if(t==3)return j;
    }
    return n;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=0;i*3+1<=n;i++){
        vis[i*3+1]=1;
    }

    while(check()){
        day++;
        for(int i=check();i<=n;i++){
            if(i==n)ans=day;
            if(!vis[i]){
                vis[i]=1;
                i+=f(i);
            }
        }
    }
    cout<<day<<" "<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
