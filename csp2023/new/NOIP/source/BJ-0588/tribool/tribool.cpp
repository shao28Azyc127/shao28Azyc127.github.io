#include<bits/stdc++.h>
#define N 100050
using namespace std;
int a[N];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,n,m,k,q;
	char v;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		while(m--){
			cin>>v;
			if(v=='T'){
				cin>>k;
				a[k]=1;
			}
			if(v=='F'){
				cin>>k;
				a[k]=2;
			}
			if(v=='U'){
				cin>>k;
				a[k]=3;
			}
			if(v=='+'){
				cin>>k>>q;
				if(!a[k]&&a[q] || a[k]&&a[q]){
					a[k]=a[q];
				}
				else if(!a[q]&&a[k]){
					a[k]=0;
				}
			}
			if(v=='-'){
				cin>>k>>q;
			}
		}
		cout<<0<<endl;
	}
	return 0;
}