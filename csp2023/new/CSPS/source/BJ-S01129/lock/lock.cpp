#include <bits/stdc++.h>
using namespace std;
int a[10][10];
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)for(int j=1;j<=5;++j)cin>>a[i][j];
    if(n==1)cout<<81;
    else{
        int ans=0;
        for(int i=0;i<=9;++i){
            for(int j=0;j<=9;++j){
                for(int k=0;k<=9;++k){
                    for(int l=0;l<=9;++l){
                        for(int m=0;m<=9;++m){
                            bool ncan=0;
                            for(int p=1;p<=n;++p){
                                int cnt=0;
                                if(a[p][1]!=i)cnt++;
                                if(a[p][2]!=j)cnt++;
                                if(a[p][3]!=k)cnt++;
                                if(a[p][4]!=l)cnt++;
                                if(a[p][5]!=m)cnt++;
                                if(cnt>=3){
                                    ncan=1;
                                    break;
                                }
                                if(!(a[p][1]!=i&&a[p][2]!=j&&a[p][3]==k&&a[p][4]==l&&a[p][5]==m&&(a[p][1]-i+10)%10==(a[p][2]-j+10)%10||
                                     a[p][1]==i&&a[p][2]!=j&&a[p][3]!=k&&a[p][4]==l&&a[p][5]==m&&(a[p][2]-j+10)%10==(a[p][3]-k+10)%10||
                                     a[p][1]==i&&a[p][2]==j&&a[p][3]!=k&&a[p][4]!=l&&a[p][5]==m&&(a[p][3]-k+10)%10==(a[p][4]-l+10)%10||
                                     a[p][1]==i&&a[p][2]==j&&a[p][3]==k&&a[p][4]!=l&&a[p][5]!=m&&(a[p][4]-l+10)%10==(a[p][5]-m+10)%10||
                                     a[p][1]!=i&&a[p][2]==j&&a[p][3]==k&&a[p][4]==l&&a[p][5]==m||
                                     a[p][1]==i&&a[p][2]!=j&&a[p][3]==k&&a[p][4]==l&&a[p][5]==m||
                                     a[p][1]==i&&a[p][2]==j&&a[p][3]!=k&&a[p][4]==l&&a[p][5]==m||
                                     a[p][1]==i&&a[p][2]==j&&a[p][3]==k&&a[p][4]!=l&&a[p][5]==m||
                                     a[p][1]==i&&a[p][2]==j&&a[p][3]==k&&a[p][4]==l&&a[p][5]!=m)){
                                    ncan=1;
                                    break;
                                }
                            }
                            if(ncan)continue;
                            else ans++;
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
