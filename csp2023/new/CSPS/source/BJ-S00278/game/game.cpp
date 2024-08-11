#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+10;
char s[MAXN];
int dp[MAXN][MAXN];
int vis[MAXN][MAXN];
int b[MAXN];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ll n,ans=0;
    scanf("%lld",&n);
    scanf("%s",s);
    for(int i=0; i<n; i++){
        dp[i][i]=1;
    }
    for(int i=0; i<n-1; i++){
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			ans++;
		}
	}
    for(int i=3; i<n; i+=1){
		for(int l=0; i+l<n; l++){
			memset(b,0,sizeof(b));
			int r=i+l;
			int mid=l+(r-l+1)/2-1;
			if(dp[l][mid]&&dp[mid+1][r]&&i!=2){
				ans++;
				dp[l][r]=1;
				//cout<<l<<" "<<r<<" 11111111111111111111111111111"<<endl;
				continue;
			}
			int ff=0;
			for(int j=l; j<r; j++){
				if(ff) break;
				if(dp[l][j]&&dp[j+1][r-(j-l)-1]&&dp[r-(j-l)][r]){
					if(!(l==j&&s[l]!=s[r])){
						ans++;
						dp[l][r]=1;
						//cout<<l<<" "<<r<<" 222222222222222222222222222"<<endl;
					}
					break;
				}else if(!dp[l][j]){
					//cout<<l<<" "<<r<<endl;
					int la=j;
					b[la-1]=1;
					for(int k=j; k<=r; k++){
						if(!dp[la][k]){
							if(la==k-1&&b[la-1]){
								ff=1;
								//cout<<j<<" "<<k<<" 11"<<endl;
								break;
							}else if(la==k-1){
								b[k-1]=1;
								la=k;
								//cout<<j<<" "<<k<<" 22"<<endl;
							}else{
								la=k;
								//cout<<j<<" "<<k<<" 33"<<endl;
							}
						}
						//cout<<j<<" "<<la<<" "<<k<<" for"<<endl;
					}	
					//cout<<j<<" "<<la<<" "<<r<<" xx"<<endl;
					if(!ff&&la!=r){
						ans++;
						dp[l][r]=1;
						//cout<<l<<" "<<r<<" "<<j<<" 33333333333333333333333333"<<endl;
						break;
					}	
				}
			}
		}
	}
	printf("%lld",ans);
    return 0;
}
