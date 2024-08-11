#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[1000010],ans[1000010];
int id(int a,int b,int c,int d,int e){
    return 10*(10*(10*(10*a+b)+c)+d)+e;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    for(int i=0;i<1e6;i++) ans[i]=1;
    int t; cin>>t;
    while(t--){
        int a[5];
        for(int i=0;i<5;i++) cin>>a[i];
        for(int i=0;i<5;i++){
            for(int j=0;j<10;j++){
                if(j==a[i]) continue;
                int x=a[i];
                a[i]=j;
                vis[id(a[0],a[1],a[2],a[3],a[4])]=1;
                a[i]=x;
            }
        }
        for(int i=0;i<4;i++){
            for(int j=1;j<10;j++){
                int x=a[i],y=a[i+1];
                a[i]=(a[i]+j)%10,a[i+1]=(a[i+1]+j)%10;
                vis[id(a[0],a[1],a[2],a[3],a[4])]=1;
                a[i]=x,a[i+1]=y;
            }
        }
        for(int i=0;i<1e6;i++){
            if(vis[i]) vis[i]=0;
            else ans[i]=0;
        }
    }
    int cnt=0;
    for(int i=0;i<1e6;i++) cnt+=ans[i];
    cout<<cnt;
    return 0;
}
