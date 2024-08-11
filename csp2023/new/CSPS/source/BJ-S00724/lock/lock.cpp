#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define ull unsigned long long
#define ap (a+j)%10
#define bp (b+j)%10
#define cp (c+j)%10
#define dp (d+j)%10
#define ep (e+j)%10
using namespace std;
int n,a,b,c,d,e,cnt[100005],ans;
int pin(int f,int g,int h,int i,int j){
    return f*10000+g*1000+h*100+i*10+j;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c>>d>>e;
        for(int j=1;j<=9;j++){
            cnt[pin(ap,b,c,d,e)]++;
            cnt[pin(a,bp,c,d,e)]++;
            cnt[pin(a,b,cp,d,e)]++;
            cnt[pin(a,b,c,dp,e)]++;
            cnt[pin(a,b,c,d,ep)]++;

            cnt[pin(ap,bp,c,d,e)]++;
            cnt[pin(a,bp,cp,d,e)]++;
            cnt[pin(a,b,cp,dp,e)]++;
            cnt[pin(a,b,c,dp,ep)]++;
        }
    }
    for(int i=0;i<=99999;i++)if(cnt[i]==n)ans++;
    cout<<ans;
    return 0;
}
