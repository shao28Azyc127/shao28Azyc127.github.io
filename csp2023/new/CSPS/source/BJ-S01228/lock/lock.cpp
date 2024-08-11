#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=15;
int s[maxn][10],k[100005][6];
bool check(int a,int b){
    int d1=0,d2=0;
    for (int i=1;i<=5;i++){
        if (s[a][i]!=k[b][i]){
            if (!d1)d1=i;
            else d2=i;
        }
    }
    if (d1!=0&&d2==d1+1){
        int a1=s[a][d1],a2=s[a][d2];
        for (int j=1;j<=10;j++){
            a1=(a1+1)%10;a2=(a2+1)%10;
            if (a1==k[b][d1]&&a2==k[b][d2])return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=5;j++){
            cin>>s[i][j];
        }
    }
    int cnt=0;
    for (int i=0;i<1e5;i++){
        int p=i;
        for (int j=5;j>=1;j--){
            k[i][j]=p%10;
            p/=10;
        }
    }
   // cout<<check(1,104);
    for (int a=0;a<100000;a++){
        int flag=1;
        for (int i=1;i<=n;i++){
            int c=0;
            for (int j=1;j<=5;j++){
                if (s[i][j]!=k[a][j])c++;
            }
            if (c==1){
                continue;
            }
            if (c==2&&check(i,a)){
                    continue;
            }
            flag=0;
        }
        if (flag)cnt++;
    }
    cout<<cnt;
}
