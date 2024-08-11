#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[10000]={1000000};
struct node{
    int a,b,c;
}t[10000050];
bool cmp(node x,node y){
    return x.b<y.b;
}
int temp;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
    sort(t+1,t+m+1,cmp);
    for(int i=1;i<=m;i++) cout<<t[i].b;
    for(int i=1;i<=n;i++){
        for(int j=i;i>=1;j--){
            if(t[i].b-1==t[j].b) dp[i]=min(dp[i],t[j-1].c);
        }
    }
    while(temp<dp[n]){
        temp+=k;
    }
    printf("%d",temp);
    return 0;
}
