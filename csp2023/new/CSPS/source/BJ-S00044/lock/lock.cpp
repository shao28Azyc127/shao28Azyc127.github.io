#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans=0;
int rec[10];
int st[13][10];
int d[10];
void dfs(int k){
    if(k==6){
        //for(int i=1;i<=5;i++){
        //    cout<<rec[i]<<" ";
        //}
        //cout<<endl;
        bool flg=1;
        for(int i=1;i<=n;i++){
            int cnt0=0;
            int cnt1=0;
            for(int j=1;j<=5;j++){
                d[j]=rec[j]-st[i][j];
            }
            for(int j=0;j<=5;j++){
                if((d[j]%10+10)%10!=(d[j+1]%10+10)%10)cnt0++;
            }
            for(int j=1;j<=5;j++){
                if(d[j]!=0)cnt1++;
            }
            if((cnt0!=2)||(cnt1>2)){
                //cout<<cnt0<<" "<<cnt1<<endl;
                flg=false;
                break;
            }
        }
        if(flg){
            //for(int i=1;i<=5;i++){
            //    cout<<rec[i]<<" ";
            //}
            //cout<<endl;
            ans++;
        }
        return;
    }
    for(int i=0;i<=9;i++){
        rec[k]=i;
        dfs(k+1);
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>st[i][j];
        }
    }
    dfs(1);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
