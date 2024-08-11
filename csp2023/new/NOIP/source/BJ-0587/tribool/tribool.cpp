#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,vn[100005],vm[100005];
char x[100005],k;
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>m;
		int vi,vj,n1=0;
		for(int j = 1;j <= m;j++){
			cin>>k;
			if(k=='T' || k=='U' || k=='F'){
				cin>>vi;
				x[vi]=k;
			}else if(k=='+'){
				cin>>vi>>vj;vn[vi]=vj;
			}else if(k=='-'){
				cin>>vi>>vj;n1=1;vm[vi]=vj;
			}
		}
		if(n1==0){
			for(int b = 1;b <= n;b++){
				if(x[b]=='U' || x[vn[b]]=='U') n1++;
			}
			cout<<n1<<endl;
		}
	}
	return 0;
}
