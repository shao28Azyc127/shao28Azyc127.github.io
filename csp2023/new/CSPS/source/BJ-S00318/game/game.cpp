#include <bits/stdc++.h>
using namespace std;
int n,res;string s;
struct Sol1{
	bool f[805][805]={0};
	void solve(){
		for(int i=1;i<n;++i)f[i][i+1]=(s[i]==s[i+1]);
		for(int len=4;len<=n;len+=2){
			for(int l=1,r=len;r<=n;++l,++r){
				for(int k=l+1;k<=r-1;++k){
					if(f[l][k]&&f[k+1][r]){
						f[l][r]=1;
						break;
					}
				}
				if(s[l]==s[r]&&f[l+1][r-1])f[l][r]=1;
			}
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j)res+=f[i][j];
		}
		cout<<res<<'\n';
	}
}A;
struct Sol2{
	int f[200005][2]={0};
	void solve(){
		f[1][0]=f[1][1]=0,f[2][0]=0,f[2][1]=(s[1]==s[2]);
		for(int i=3;i<=n;++i){
			string t;t+=s[i];
			for(int j=i-1;j>=1;--j){
				t=s[j]+t;
				int k=0;
				while(k+1<t.size()&&t[k]==t[k+1])k+=2;
				//t=t.substr(k,t.size()-k);
				t.erase(0,k);
				if(t.size()==0){
                    f[i][0]+=f[j][0]+f[j][1];
                    f[i][1]+=f[j-1][1]+1;
                    break;
				}
			}
		}
		for(int i=1;i<=n;++i)res+=f[i][1];
		cout<<res<<'\n';
	}
}B;
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin>>n>>s;
	s=' '+s;
	if(n<=800){A.solve();return 0;}
	if(n<=8000){B.solve();return 0;}
	for(int i=1;i<n;++i){
        if(s[i]==s[i+1]){
            ++res;
            for(int k=1;i-k>=1&&i+1+k<=n;++k){
                if(s[i-k]==s[i+1+k])++res;
                else break;
            }
        }
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
