#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int sum[10];
int ks[800],cnt;
int ppow[]={1,10,100,1000,10000};
bool cmp(int a,int b){
    return a>b;
}


int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=4;j>=0;j--){
            cin>>a[i][j];
            sum[i]+=a[i][j]*ppow[j];
        }
    }

    if(n==1){
        cout<<81;
        return 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=4;j>=0;j--){
            int kk=a[i][j];
            for(int k=1;k<=9;k++){
                ks[++cnt]=sum[i]+((kk+k)%10)*ppow[j]-kk*ppow[j];
            }
        }
        for(int j=3;j>=0;j--){
            int kk=a[i][j+1]*10+a[i][j];
            for(int k=1;k<=9;k++){
                int x=a[i][j+1],y=a[i][j];
                if(x-k<0) x=x+10-k;
                else x-=k;
                if(y-k<0) y=y+10-k;
                else y-=k;
                int kkk=x*10+y;
                ks[++cnt]=sum[i]-kk*ppow[j]+kkk*ppow[j];
            }
        }
    }
    int ans=0;
    sort(ks+1,ks+1+cnt,cmp);
    int t1=0;
    for(int i=1;i<=cnt-n+1;i++){
        if(ks[i]==ks[i+n-1] && ks[i]!=0){
            int t1=0;
            for(int j=1;j<=n;j++){
                if(ks[i] == sum[j]){
                    t1=1;
                    break;
                }
            }
            if(t1==1) continue;
            i+=n-1;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
