#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
struct rp{
	int l,r;
}t[N];
int n,ans=0;
int tail=0,cnt[N];
char s[N];
void work(int sl,int sr){
	int i=sl-1,j=sr+1;
	while(i>=1&&j<=n){
		if(s[i] != s[j]) break;
		ans++;
		t[++tail].l=i;
		t[tail].r=j;
		cnt[j]++;
		i--,j++;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	s[0]='  ';
	for(int i=1;i<=n;i++){
		cin >> s[i];
		if(s[i] == s[i-1]){
			ans++;
			t[++tail].l=i-1;
			t[tail].r=i;
			cnt[i]++;
		}
	}
	int temp=tail;
	for(int i=1;i<=temp;i++){
		work(t[i].l,t[i].r);
	}
	for(int i=1;i<=tail;i++){
        //cout << t[i].l-1 << " " << cnt[t[i].l-1] << endl;
		ans+=cnt[t[i].l-1];
		cnt[t[i].r]+=cnt[t[i].l-1];
	}
	cout << ans;
	return 0;
}