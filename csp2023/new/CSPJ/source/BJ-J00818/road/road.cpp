#include<bits/stdc++.h>
using namespace std;
int v[100005];
int vn[100005];
int A[100005];
int a[100005];
int dp[100005];
int N;
int vis[100005];
int n,d;
int mval=1e9;
void f(int x){
    if(x==N+1){
        int dis=0;
        int val=0;
        for(int i=1;i<=N;i++){
            dis=vn[i];
            val+=a[i]*A[i];
            if(val*d<dis)return ;
        }
        mval=min(val,mval);
        if(val==63){
            for(int i=1;i<=N;i++)cout<<a[i]<<" ";
            cout<<endl;
        }
        return ;
    }
    for(int i=0;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[x]=i;
            f(x+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&N,&d);
    int sum=0;
    int minn=1e9;
    int mini;
    //cout<<N;
    for(int i=1;i<=N-1;i++){
        scanf("%d",&v[i]);
        sum+=v[i];
        if(i>1)vn[i]=vn[i-1]+v[i];
        else vn[i]=v[i];
    }
    for(int i=1;i<=N;i++){
        scanf("%d",&A[i]);
        if(minn>A[i]){
            minn=A[i];
            mini=i;
        }
    }
    //cout<<minn<<endl;
    if(minn==a[1])printf("%d",ceil((double)ceil((double)sum/d)/A[1]));
    else{
        n=sum/minn;
        f(1);
        cout<<mval<<endl;
    }
    return 0;
}

