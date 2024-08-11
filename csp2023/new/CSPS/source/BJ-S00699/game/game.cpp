#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct node{
	int l,r;
};
vector<node> V;
int ans=0;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	int len=s.size();
	for(int i=0;i<len-1;i++){
		if(s[i]==s[i+1]){
			ans++;
			V.push_back({i,i+1});
		}
	}
	int vlen=V.size();
	bool flag=true;
	while(flag){
		for(int i=0;i<vlen;i++){
			if(V[i].l-1<0 || V[i].r+1>=len)continue;
			while(s[V[i].l-1]==s[V[i].r+1]){
				V[i].l--;
				V[i].r++;
				ans++;
				//cout<<1<<" "<<V[i].l<<" "<<V[i].r<<endl;
				if(V[i].l-1<0 || V[i].r+1>=len)break;
			}
		}
		for(int i=0;i<vlen;i++){
			for(int j=i+1;j<vlen;j++){
				if(V[j].l>=V[i].l && V[j].r<=V[i].r)V[j].l=-1;
			}
		}
		flag=false;
		for(int i=0;i<vlen;i++){
			for(int j=i+1;j<vlen;j++){
				if(V[i].l==-1 || V[j].l==-1)continue;
				if(V[j].l==V[i].r+1){
					flag=true;
					ans++;
					V[i].r=V[j].r;
					V[j].l=-1;
					//cout<<2<<" "<<V[i].l<<" "<<V[i].r<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
