#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,m,a,b,c;
void text(){
    cin>>t>>m;
    while(t--){
    	cin>>a>>b>>c;
    	if(b==0&&c==0){
    		cout<<0<<'\n';
    		continue;
		}
		cout<<"NO"<<'\n';
	}
}
signed main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    text();
    return 0;
}