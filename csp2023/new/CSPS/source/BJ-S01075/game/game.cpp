#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000005;
string s;
int n;
ll ans,med[10005],mst[10005],dp[10005][10005];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s=" "+s;
    if(n<=800){
        for(int i = 1;i+1<=n;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans++;
            }
        }
        for(int len=4;len<=n;len+=2){
            for(int i = 1;i+len-1<=n;i++){
                int j = i+len-1;
                if(dp[i+1][j-1]==1&&s[i]==s[j]){
                    dp[i][j]=1;
                    ans++;
                    continue;
                }
                for(int k = i+1;k+2<=j;k+=2){
                    if(dp[i][k]==1&&dp[k+1][j]==1){
                        dp[i][j]=1;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    else{
        for(int i = 1;i+1<=n;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                mst[i]++,med[i+1]++;
                st[i].push_back(i+1),ed[i+1].push_back(i);
                ans++;
            }
        }
        for(int len=2;len<=n;len+=2){
            for(int j=n;j-len+1>=1;j--){
                int i=j-len+1;
                if(dp[i][j]!=1) continue;
                if(i>1&&j<n&&s[i-1]==s[j+1]&&dp[i-1][j+1]==0){
                    dp[i-1][j+1]=1;
               //     cout<<i-1<<" "<<j+1<<endl;
                    st[i-1].push_back(j+1),ed[j+1].push_back(i-1);
                    med[j+1]++;
                    mst[i-1]++;
                    ans++;
                }
                if(mst[j+1]>0){
                    ans+=mst[j+1];
                    mst[i]+=mst[j+1];
                    for(int k=0;k<st[j+1].size();k++){
                        int y=st[j+1][k];
                        if(dp[i][y]==1){
                            ans--;
                            mst[i]--;
                            continue;
                        }
                        dp[i][y]=1;
                        st[i].push_back(y);
                        ed[y].push_back(i);
                    }
                }/*
                if(i>1&&med[i-1]>0){
                    ans+=med[i-1];
                    med[j]+=med[i-1];
                    for(int k = 0;k<ed[i-1].size();k++){
                        int x=ed[i-1][k];
                        dp[x][j]=1;
                        st[x].push_back(j);
                        ed[j].push_back(x);
                    }
                }*/
               // cout<<i<<" "<<j<<" "<<ans<<" "<<mst[4]<<endl;
            }
        }
        cout<<ans;
    }
    return 0;
}
