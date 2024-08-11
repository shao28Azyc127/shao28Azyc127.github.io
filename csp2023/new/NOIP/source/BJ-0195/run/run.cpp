#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    long long x,y,z;
}a[100005];
bool cmp(node l1,node l2){
    return l1.x<l2.x;
}
long long dp[2][100005];
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,m,k,d;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        sort(a+1,a+m+1,cmp);
        memset(dp,-0x3f,sizeof dp);
        dp[0][0]=0;
        long long mx=0;
        for(int i=1;i<=m;i++){
            long long mx2=0;
            for(int j=0;j<=k;j++){
                if(j>=(a[i].x-a[i-1].x))dp[i%2][j]=dp[1-i%2][j-(a[i].x-a[i-1].x)]-d*(a[i].x-a[i-1].x);
                else dp[i%2][j]=mx-d*j;
                if(j>=a[i].y)dp[i%2][j]+=a[i].z;
                mx2=max(mx2,dp[i%2][j]);
                //cout<<dp[i%2][j]<<" ";
            }
            //cout<<endl;
            mx=mx2;
        }
        cout<<mx<<endl;
    }
    return 0;
}
