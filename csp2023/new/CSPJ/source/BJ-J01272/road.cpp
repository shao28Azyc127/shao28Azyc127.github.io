#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=1e6+5;
int n,d;
int v[maxn],a[maxn];
int cost=0;
vector<int>cnt;
void f(int aim){
    if(aim==0){
        return;
    }
    int ans=1e6+5;
    int min1=maxn;
    for(int i=aim;i>=1;i--){
        if(a[i]<=min1){
            min1=a[i];
            ans=i;
        }
    }
    cnt.push_back(ans);
    f(ans-1);
}
void solve(int now,int remain){
    if(cnt[now]==n){
        return;
    }
    long long sum=0;
    for(int i=cnt[now];i<cnt[now-1];i++){
        sum+=v[i];
    }
    sum-=remain;
    int x=sum-sum%d;
    x/=d;
    if(sum%d!=0){
        x++;
    }
    cost+=x*a[cnt[now]];
    now--;
    remain=x*d-sum;
    solve(now,remain);
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    a[0]=1e6+5;
    cnt.push_back(n);
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f(n-1);
    solve(cnt.size()-1,0);
    cout<<cost<<endl;
    return 0;
}
