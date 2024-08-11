#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3010;
const LL P = 998244353,base = 131;
int n,m;
LL pw[N],hmax[N][N],hmin[N];
char str[N][N];
inline bool cmp1(char a,char b)
{
	return a < b;
}
inline bool cmp2(char a,char b)
{
	return a > b;
}
inline LL get_max(int x,int l,int r)
{
	return ((hmax[x][r] - (hmax[x][l-1] * pw[r-l+1])) % P + P) % P;
}
inline LL get_min(int l,int r)
{
	return ((hmin[r] - hmin[l-1] * pw[r-l+1]) % P + P) % P;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> (str[i]+1);
	pw[0] = 1;
	for(int i = 1;i <= m;++i) pw[i] = pw[i-1] * base % P;
	for(int i = 1;i <= n;++i) 
	{
		sort(str[i]+1,str[i]+m+1,cmp2);
		for(int j = 1;j <= m;++j) hmax[i][j] = (hmax[i][j-1] * base  + str[i][j]) % P;
	}
	for(int i = 1;i <= n;++i)
	{
		sort(str[i]+1,str[i]+m+1,cmp1);
		for(int j = 1;j <= m;++j) hmin[j] = (hmin[j-1] * base + str[i][j]) % P;
		bool flag = true;
		for(int j = 1;j <= n;++j)
		{
			if(j == i) continue ;
			int l = 1,r = m,ans = 0;
			while(l <= r)
			{
				int mid = (l + r) >> 1;
				if(get_max(j,1,mid) == get_min(1,mid)) ans = mid,l = mid + 1;
				else r = mid - 1;
			}
			if(ans < n && str[i][ans+1] < str[j][ans+1]) continue ;
			else flag = false;
		}
		sort(str[i]+1,str[i]+m+1,cmp2);
		if(flag) cout << 1;
		else cout << 0;
	}
	cout << '\n';
	return 0;
}
