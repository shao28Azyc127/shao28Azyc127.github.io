#include<bits/stdc++.h>
using namespace std;
int n,stk[1000005],sp,lst[1005],lk[1000005];
string s;
long long ans,f[1000005];
bool dp[8005][8005];
void wk(){
    for(int i=0;i<(n-1);i++){
        if(s[i]==s[i+1])
            dp[i][i+1]=true;
    }
    for(int len=4;len<=n;len+=2){
        for(int i=0;(i+len-1)<n;i++){
            int j=i+len-1;
            if(lk[j]<i)
                continue;
            if((s[i]==s[j])&&(dp[i+1][j-1]==true)){
            	dp[i][j]=true;
            	continue;
            }
            for(int k=j;k!=-1;k=lk[k]){
            	if((dp[i][lk[k]-1]==true)&&(dp[lk[k]][j]==true)){
            	    dp[i][j]=true;
            	    break;
            	}
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(dp[i][j]==true)
                ans++;
        }
    }
    printf("%lld",ans);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        lst[int(s[i])]=-1;
        lk[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(lst[int(s[i])]==-1)
            lst[int(s[i])]=i;
        else{
            lk[i]=lst[int(s[i])];
            lst[int(s[i])]=i;
        }
    }
    if(n<=8000){
        wk();
        return 0;
    }
    stk[1]=0;
    sp=1;
    for(int i=1;i<n;i++){
    	if(int(s[i])==int(s[stk[sp]])&&sp>=1){
            ans++;
            if(stk[sp]==0){
                f[i]=1;
                sp--;
                continue;
            }
    	    ans+=f[stk[sp]-1];
    	    f[i]=f[stk[sp]-1]+1;
    	    sp--;
    	}
    	else
            stk[++sp]=i;
    }
    printf("%lld",ans);
    return 0;
}