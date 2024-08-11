#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int>>g[10010];
int n,m,k,ans;
bitset<10010>t,t1;
inline int read(){
	register int f=0,x=0,t=getchar();
	while(t<'0'||t>'9')f=t=='-',t=getchar();
	while(t>='0'&&t<='9')x=x*10+(t^48),t=getchar();
	return f?-x:x;
}
signed main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	n=read(),m=read(),k=read();
	int mn=2e9;
	while(m--){
		int u=read(),v=read(),a=read();
		g[u].push_back({a,v});
		if(u==1)mn=min(mn,a);
	}
	if(mn==2e9)return cout<<"-1\n",0;
	ans=((mn+k-1)/k)*k;
	while(1){
		t[1]=1;
		for(int i(0);i<k;++i){
			t1=0;
			int nw=t._Find_first();
			while(nw<=n){
				for(auto i:g[nw])if(i.first<=ans)t1[i.second]=1;
				nw=t._Find_next(nw);
			}
			t=t1,++ans;
			if(ans%100==0&&clock()>CLOCKS_PER_SEC*0.98){ans=-1;break;}//TLE
		}
		if(ans==-1||t[n])break;
		
	}
	cout<<ans<<'\n';
	return 0;
}
/*
	文件	内存	In&Out	调试	大数据		对拍	long long	 时间(大样例)	期望得分
T1	True	True	True	True	True	1			True		0.00		100
T2	True	True	True	True	True	0.5			True		0.00		100
T3	True	True	True	True	True	0			True		0.01		100
T4	True	True	True	True	True	0			True		0.75		75
总	True	True	True	True	True	1.5			True		0.76		375

乱搞卡常之神JZX Orz!
助我卡过T4！！
*/