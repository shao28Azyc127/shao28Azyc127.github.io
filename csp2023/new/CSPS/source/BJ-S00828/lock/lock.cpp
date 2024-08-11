#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int a[10][10];
int s[10];
int h[N];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
        s[i]=a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5];
    }
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int k=0;k<=9;k++){
                if(j==1){
                    h[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+k]++;
                }else if(j==2) h[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+k*10+a[i][5]]++;
                else if(j==3) h[a[i][1]*10000+a[i][2]*1000+k*100+a[i][4]*10+a[i][5]]++;
                else if(j==4) h[a[i][1]*10000+k*1000+a[i][3]*100+a[i][4]*10+a[i][5]]++;
                else h[k*10000+a[i][2]*1000+a[i][3]*100+a[i][4]*10+a[i][5]]++;
            }
        }
        for(int j=1;j<=4;j++){
            for(int k=0;k<=9;k++){
               if(j==1){
                    h[a[i][1]*10000+a[i][2]*1000+a[i][3]*100+(a[i][4]+k)%10*10+(a[i][5]+k)%10]++;
                }else if(j==2) h[a[i][1]*10000+a[i][2]*1000+(a[i][3]+k)%10*100+(a[i][4]+k)%10*10+a[i][5]]++;
                else if(j==3) h[a[i][1]*10000+(a[i][2]+k)%10*1000+(a[i][3]+k)%10*100+a[i][4]*10+a[i][5]]++;
                else if(j==4) h[(a[i][1]+k)%10*10000+(a[i][2]+k)%10*1000+a[i][3]*100+a[i][4]*10+a[i][5]]++;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=10000000;i++){
        if(h[i]==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
