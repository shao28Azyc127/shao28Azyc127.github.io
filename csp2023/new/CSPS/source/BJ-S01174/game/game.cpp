#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;
int n, s[N], l[N];
ll f[N][2], dp[N], ans, cnt;
struct Node{
	int id, w;
} stk[N];
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int top;// q; Node t;
	scanf("%d", &n);
	s[1] = getchar();
	while(s[1]<'a'||s[1]>'z') s[1]=getchar();
	for(int i = 2; i <= n; i++)
		s[i] = getchar();
	for(int i = 1; i <= n; i++){
		top = 0;
		for(int j = i; j <= n; j++){
			if(top&&stk[top].w==s[j]) top--;
			else stk[++top] = {i, s[j]};
			if(!top) ans++;//cout<<i<<" "<<j<<" "<<ans<<endl;
		}
	}
	printf("%lld\n", ans);
	return 0;
}