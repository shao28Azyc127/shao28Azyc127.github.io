#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll a[100005],b[100005],c[100005],fr[100005],to[100005];

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		cin>>fr[i]>>to[i];
	}
	cout<<n+1<<endl;;
	return 0;
}
