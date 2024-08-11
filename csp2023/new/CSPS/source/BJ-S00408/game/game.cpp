//#define dbg
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
char a[N];
long long dp[N];
vector<int> del[N];
priority_queue<int> heap[N];
int main(){
	ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	del[i].push_back(1);
    	dp[i]=0;
    }
    long long ans=0;
    for(int i=2;i<=n;i++){
    	#ifdef dbg
    	cout<<"i:"<<i<<endl;
    	#endif
    	for(auto j:del[i]){
    		if(a[i-j]==a[i]){
				if(a[i-j-1]!=a[i-j])dp[i]+=dp[i-j-1]+1;
				else dp[i]++;
				heap[i].push(j+1);
    			if(i+1>j+2)del[i+1].push_back(j+2);
    		}
    		#ifdef dbg
    		cout<<"  j:"<<j<<endl;
    		#endif
    	}
    	#ifdef dbg
    	cout<<"dpi:"<<dp[i]<<endl;
    	#endif
    	ans=ans+dp[i];
    }
    cout<<ans;
    return 0;
}