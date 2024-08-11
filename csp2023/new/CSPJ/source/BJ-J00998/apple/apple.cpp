#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,anst,size;
vector<int> v;
int main(){
	freopen("apple.in","r",stdin);freopen("apple.out","w",stdout);
	cin>>n;
	size=n;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	while(!v.empty()){
		ans++;
		for(int t=0;t<size;t+=2){
			size--;
			//cout<<v[t]<<" ";
			if(v[t]==n){
				anst=ans;
			}
			v.erase(v.begin()+t);
		}
	}
	cout<<ans<<" "<<anst<<endl;
	return 0;
}
