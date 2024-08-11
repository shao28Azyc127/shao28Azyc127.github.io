#include <iostream>
using namespace std;

int n,m,k;
struct road{
	int to[20004];
	int tim;
	int cnt = 0;
};
road r[20004];
int ans = 100000;
void findway(int t, int place)
{
	if(place == n){
		if(t < ans && t % k == 0){
			ans  = t;
		}
		return;
	} 
	for(int i = 0; i < r[place].cnt; i++){
		if(t >= r[place].tim)
		{
			findway(t+1,r[place].to[i]);
		}
	}
	return;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	
	cin>>n>>m>>k;
	int u;
	for(int i=0;i<m;i++){
		cin >> u;
		cin>>r[u].to[r[u].cnt]>>r[u].tim;
		r[u].cnt++;
	}
	findway(k,1);
	if(ans == 100000) cout<<-1;
	else cout << ans;
	return 0;
}
