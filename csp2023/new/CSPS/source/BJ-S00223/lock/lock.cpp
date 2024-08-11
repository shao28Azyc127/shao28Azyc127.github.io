#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
int b[100005];
int sw1[10]={1,10,100,1000,10000,100000};
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=1;j<=5;j++){
            a[j]=0;
            cin>>a[j];
            tmp=tmp*10+a[j];
        }
        for(int j=0;j<5;j++){
            for(int k=1;k<=9;k++){
                int jsk=k;
                if(tmp%sw1[j+1]+k*sw1[j]>=sw1[j+1]){
                    jsk=(k-10);
                }
                int f=tmp+jsk*sw1[j];
                b[f]++;
                if(j<4){
                    if(tmp%sw1[j+2]+k*sw1[j+1]>=sw1[j+2]){
                        jsk=(k-10);
                    }else{
                        jsk=k;
                    }
                    //cout<<f<<" "<<jsk<<" "<<sw1[j+1]<<endl;
                    b[f+jsk*sw1[j+1]]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=99999;i++){
        if(b[i]==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
