#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[10][6];
int tol[10];
bool k[100005];
bool kt[100005];
int powt[8];
int ans;

int init(){
    powt[1]=1;
    for(int i=2;i<=5;i++){
        powt[i]=powt[i-1]*10;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
                //cout<<":"<<tol[1]+((j+a[1][i])%10-a[1][i])*powt[6-i]<<endl;
                k[tol[1]+((j+a[1][i])%10-a[1][i])*powt[6-i]]=1;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
                //cout<<tol[1]+((j+a[1][i])%10-a[1][i])*powt[6-i]+((j+a[1][i+1])%10-a[1][i+1])*powt[5-i]<<endl;
                k[tol[1]+((j+a[1][i])%10-a[1][i])*powt[6-i]+((j+a[1][i+1])%10-a[1][i+1])*powt[5-i]]=1;
        }
    }
    return 0;
}

int work(int N){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=9;j++){
                //cout<<tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]<<":"<<k[tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]]<<endl;
                kt[tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]]=1;
                //cout<<tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]<<":"<<kt[tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]]<<endl;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=9;j++){
                //cout<<tol[1]+((j+a[1][i])%10-a[1][i])*powt[6-i]+((j+a[1][i+1])%10-a[1][i+1])*powt[5-i]<<endl;
                kt[tol[N]+((j+a[N][i])%10-a[N][i])*powt[6-i]+((j+a[N][i+1])%10-a[N][i+1])*powt[5-i]]=1;
        }
    }
    for(int i=0;i<=99999;i++){
        k[i]&=kt[i];
    }
    memset(kt,0,sizeof(kt));
    return 0;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
            tol[i]+=a[i][j];
            tol[i]*=10;
        }
        tol[i]/=10;
    }
    init();
    for(int i=2;i<=n;i++){
        work(i);
    }
    ans=0;
    for(int i=0;i<=99999;i++){
        ans+=k[i];
    }
    cout<<ans<<endl;
    return 0;
}
