#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10;
int n,a[N][6],ans,tmp[6];
int check(){
	for(int i=1;i<=n;i++){
		int d1=0,d2=0;
		for(int j=1;j<=5;j++) if(a[i][j]!=tmp[j]){
			 if(!d1) d1=j;
			 else if(!d2) d2=j;
			 else return 0;
		}
		if(!d1) return 0;
		if(d2 && d2-d1!=1) return 0;
		if(d2){
			int s1=a[i][d1]-tmp[d1],s2=a[i][d2]-tmp[d2];
			if(s1<0) s1+=10;
			if(s2<0) s2+=10;
			if(s1!=s2) return 0;
		}
	}
	return 1;
}
void dfs(int x){
    if(x>5){
		ans+=check();
		return;
	}
    for(int i=0;i<=9;i++) tmp[x]=i,dfs(x+1);
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    dfs(1);
	cout<<ans<<endl;
    return 0;
}
