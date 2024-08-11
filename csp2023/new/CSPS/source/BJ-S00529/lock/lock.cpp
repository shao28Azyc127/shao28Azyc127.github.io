#include<bits/stdc++.h>
#define ffor(i,l,r) for(int i=(l),i##_end=(r);i<=i##_end;i++)
#define rfor(i,l,r) for(int i=(l),i##_end=(r);i>=i##_end;i--)
using namespace std;
using ll = long long;
int pw10[10] = {1,10,100,1000,10000,100000,1000000};
int sets(int s,int i,int v){
	int tmp = pw10[5-i+1];
	int tmp2 = pw10[5-i];
	return s/tmp*tmp+v*tmp2+s%tmp2;
}
int gett(int s,int i){
	return s/pw10[5-i]%10;
}
int n;
int val[10];
bool init[100010];
bool cnt[100000][10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	ffor(i,1,n){
		int u,tmp = 0;
		ffor(j,1,5){
			cin>>u;
			tmp = tmp*10+u;
		} 
		val[i] = tmp;
		init[tmp] = 1;
	}
	ffor(i,1,n){
		ffor(j,1,5){
			ffor(k,0,9){
				int tmp = sets(val[i],j,k);
				cnt[tmp][i] = 1;
			}
		}
	}
	ffor(i,1,n){
		ffor(j,1,4){
			ffor(k,0,9){
				int v = val[i];
				
				int tmp = sets(v,j,k);
				tmp = sets(tmp,j+1,(k+gett(v,j+1)-gett(v,j))%10);
				cnt[tmp][i] = 1;
			}
		}
	}
	int ans = 0;
	ffor(i,0,99999){
		if(init[i]) continue;
		ffor(j,1,n) {
			if(!cnt[i][j]) goto eed;
		}
		ans++;
		eed:;
	}
	cout<<ans;
	return 0;
}