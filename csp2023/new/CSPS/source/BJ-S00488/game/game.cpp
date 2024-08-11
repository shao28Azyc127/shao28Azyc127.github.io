#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[2000010], b[2000010];int nxt[2000010],ans;
int dp[2000010];stack<int> q;
main(){
    freopen("game.in","r",stdin);
    freopen("game.ans","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    if(n<800){
    for(int i=1;i<=n;i++) {
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(j==8){
                int lll;
                lll=1;
            };
            int siz=j-i+1,sss=j-i+1;
            if((j-i+1)%2) continue;
            memset(b,0,sizeof(b));
            memset(nxt,0,sizeof(nxt));
            for(int z=i;z<=j;z++){
                b[z-i+1]=a[z];
                nxt[z-i+1]=z-i+2;
            }
            int cnt=0,hhh=ans;
            while(siz){
                cnt=siz;
                for(int i=1;i<=sss;i=nxt[i]){
                    if(b[i]==b[nxt[i]]){
                        nxt[i]=nxt[i-1]=nxt[nxt[i]];
                        siz-=2;
                    }
                }
                if(cnt==siz) {
                    ans--;break;}
            }
            ans++;
        }
    }
    cout<<ans;
}
else{
    for(int i=1;i<=n;i++) {
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(!q.empty()){
            int t=q.top();
            //cout<<t<<'\n';
            if(a[i]==a[t]){
                q.pop();
                //book[t]=0;
                dp[i]++;
                ans++;
                ans+=dp[t-1],dp[i]+=dp[t-1];
                //book[i]=min(book[i],book[t-1]);
            }
                else{
                q.push(i);
                if(a[i]==a[i-1]){
                    ans++;
                    ans+=dp[i-2];
                    dp[i]+=dp[i-2]+1;
                }
            }
                //cout<<i<<'\n';

        }
        else{
            q.push(i);
            if(a[i]==a[i-1]){
                    ans++;
                    ans+=dp[i-2];
                    dp[i]+=dp[i-2]+1;
            }
        }
    }
    //while(!q.empty()) q.pop();
/*        if(!q.empty()){
            int t=q.top();
            //cout<<t<<'\n';
            if(a[i]==a[t]){
                q.pop();
                dp[i]++;
                ans++;
                ans+=dp[t-1],dp[i]+=dp[t-1];
            }
            else {
                q.push(i);
                //cout<<i<<'\n';
            }
        }
        else{
            q.push(i);
        }
    }*/
    cout<<ans;
}
}
