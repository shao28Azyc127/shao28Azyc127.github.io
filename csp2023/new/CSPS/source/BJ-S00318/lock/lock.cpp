#include <bits/stdc++.h>
using namespace std;
int p10[10];
int f(int i,int j,int k){
	int t=(i%p10[j+1])/p10[j];
	i-=t*p10[j];
	t=(t+k)%10;
	i+=t*p10[j];
	return i;
}
const int N=1e6+5;
bool b[N];
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	p10[0]=1;
	for(int i=1;i<=6;++i)p10[i]=p10[i-1]*10;
	int n;cin>>n;
	vector<int> v;
	for(int i=0;i<n;++i){
		int a,b,c,d,e;cin>>a>>b>>c>>d>>e;
		v.push_back(e+d*10+c*100+b*1000+a*10000);
	}
	int res=0;
	for(int i=0;i<1e5;++i){
		vector<int> u;
		for(int j=1;j<10;++j){
			for(int k=0;k<5;++k){
                int g=f(i,k,j);
                b[g]=1,u.push_back(g);
                if(k!=4){
                    int g1=f(g,k+1,j);
                    b[g1]=1,u.push_back(g1);
                }
			}
		}
		bool flg=1;
		for(int j=0;j<n;++j)flg&=b[v[j]];
		res+=flg;
		for(int j=0;j<(int)u.size();++j)b[u[j]]=0;
	}
	cout<<res<<'\n';
	return 0;
}
/*
pay attention:
1. cin/cout getchar()
2. sqrt(__int128)
3. N,M
4. freoepn
5. debug
6. memory limits and no RE
think twice, code once
CSPS 1= is easy and xunse
you will get 300+ pts
keep elegant, you'll AKIOI
*/
