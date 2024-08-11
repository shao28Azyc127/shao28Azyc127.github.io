#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int m[15][15][15][15][15],a,b,c,d,e;
ll ans;

int main(){
	ios::sync_with_stdio(false);
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int z=1;z<=n;z++){
		cin>>a>>b>>c>>d>>e;
		for(int i=1;i<=9;i++){
			m[(a+i)%10][b][c][d][e]++;
			if(m[(a+i)%10][b][c][d][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][(b+i)%10][c][d][e]++;
			if(m[a][(b+i)%10][c][d][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][b][(c+i)%10][d][e]++;
			if(m[a][b][(c+i)%10][d][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][b][c][(d+i)%10][e]++;
			if(m[a][b][c][(d+i)%10][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][b][c][d][(e+i)%10]++;
			if(m[a][b][c][d][(e+i)%10]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[(a+i)%10][(b+i)%10][c][d][e]++;
			if(m[(a+i)%10][(b+i)%10][c][d][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][(b+i)%10][(c+i)%10][d][e]++;
			if(m[a][(b+i)%10][(c+i)%10][d][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][b][(c+i)%10][(d+i)%10][e]++;
			if(m[a][b][(c+i)%10][(d+i)%10][e]==n){
				ans++;
			}
		}
		for(int i=1;i<=9;i++){
			m[a][b][c][(d+i)%10][(e+i)%10]++;
			if(m[a][b][c][(d+i)%10][(e+i)%10]==n){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
