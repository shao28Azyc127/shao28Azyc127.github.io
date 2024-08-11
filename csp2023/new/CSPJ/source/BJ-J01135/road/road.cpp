#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node{
	int v,p;
}a[N];
int n,d,sum,ans;
void text(){
    cin>>n>>d;
    for(int i=1;i<n;i++){
    	cin>>a[i].v;
    	sum+=a[i].v;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].p;
	}
	if(sum%d==0){
		cout<<(sum/d)*a[1].p;
	}
	else{
		cout<<(sum/d+1)*a[1].p;
	}
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    text();
    return 0;
}