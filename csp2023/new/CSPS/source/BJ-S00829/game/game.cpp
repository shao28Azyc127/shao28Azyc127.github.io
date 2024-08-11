#include<bits/stdc++.h>
using namespace std;
int n;
string c;
bool is_deleable(int l,int r){
	string tmpc(c,l-1,r-l+1);
	if(r-l==1) return c[l-1]==c[r-1];
	if((r-l)%2==0) return 0;
	string::iterator it;
	bool p=1;
	while(p){
		p=0;
		if(tmpc.size()==0) return 1;
		for(it=tmpc.begin();it<tmpc.end();it++){
			char s1=*it,s2=*(it+1);
			if(s1==s2){
				it=tmpc.erase(it);
				it=tmpc.erase(it);
				it--;
				p=1;
			}
		}
	}
	return 0;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n>>c;
	int ans=0;
	for(int len=2;len<=n;len+=2){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(is_deleable(l,r)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
