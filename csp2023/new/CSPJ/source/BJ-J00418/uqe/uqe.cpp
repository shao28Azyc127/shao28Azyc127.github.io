#include <bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>t>>m;
	while(t--){
		cin>>a>>b>>c;
		if(b*b-4*a*c<0) cout<<"NO"<<endl;
		else if(b==0 && c==0) cout<<0<<endl;
		else{
			for(int x=m;x>=-1*m;x--){
				if(x*x*a+x*b+c==0){
					cout<<x;
					break;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
