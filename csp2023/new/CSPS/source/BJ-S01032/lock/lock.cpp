#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
int cnt[15][15][15][15][15];
int tmp[10];
signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;cin >> n;
	fr(i,1,n){
		fr(j,1,5)cin >> tmp[j];
		fr(k,1,9){
			cnt[(tmp[1]+k)%10][tmp[2]][tmp[3]][tmp[4]][tmp[5]]++;
			cnt[tmp[1]][(tmp[2]+k)%10][tmp[3]][tmp[4]][tmp[5]]++;
			cnt[tmp[1]][tmp[2]][(tmp[3]+k)%10][tmp[4]][tmp[5]]++;
			cnt[tmp[1]][tmp[2]][tmp[3]][(tmp[4]+k)%10][tmp[5]]++;
			cnt[tmp[1]][tmp[2]][tmp[3]][tmp[4]][(tmp[5]+k)%10]++;
			
			cnt[tmp[1]][tmp[2]][tmp[3]][(tmp[4]+k)%10][(tmp[5]+k)%10]++;
			cnt[tmp[1]][tmp[2]][(tmp[3]+k)%10][(tmp[4]+k)%10][tmp[5]]++;
			cnt[tmp[1]][(tmp[2]+k)%10][(tmp[3]+k)%10][tmp[4]][tmp[5]]++;
			cnt[(tmp[1]+k)%10][(tmp[2]+k)%10][tmp[3]][tmp[4]][tmp[5]]++;
			
		}
		
	}
	int ans=0;
	fr(a,0,9)fr(b,0,9)fr(c,0,9)fr(d,0,9)fr(e,0,9)ans+=cnt[a][b][c][d][e]==n;
	cout << ans;
	return 0;
}
