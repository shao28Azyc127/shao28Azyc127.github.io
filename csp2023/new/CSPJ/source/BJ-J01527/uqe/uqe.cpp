#include<bits/stdc++.h>
using namespace std;

int t, m,v[100005],a[100005];
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int sj=(b*b)-(4*a*c);
		if(sj<0){
			puts("NO");
			continue;
		}
		int p=(-b)+sqrt(sj);
		int q=(2*a)
		int gen=p/q;
		if(gen)cout<<gen<<endl;
	}
	return 0;
}
