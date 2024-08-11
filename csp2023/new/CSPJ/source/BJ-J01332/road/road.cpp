#include<bits/stdc++.h>
using namespace std;
int u[100005];
int a[100005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>u[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    int mn=999999;
    int w=0;
    for(int i=1;i<=n;i++){
        if(a[i]<mn){
            mn=a[i];
            w=i;
        }
    }
    int y=0;
    for(int i=1;i<=n;i++){
        u[i+1]-=y;
        int k=u[i]/d+1;
        y=k*d-u[i];
        if(i!=w) sum+=k*d;
        else{
            int cnt=0;
            for(int j=i;j<=n;j++) cnt+=u[i];
            cnt-=y;
            cnt/=d;
            sum+=cnt*a[i]+1;
            cout<<sum;
            return 0;
        }

    }
    return 0;
}

