#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,i=-1,ans=1,flag=0;
	map<int,int>m;
	cin>>n;
	while(m.size()!=n){
		int tmp=i;
		i+=3;
		for(int j=tmp;j<=i;j++){
			if(m.count(j)){
				i++;
			}
		}
		i--;
		if(i>n&&!m.count(i)){
			ans++;
			int j=1;
			while(m.count(j)){
				j++;
			}
			i=j;
		}
		if(i==n){
			flag=1;
		}
		m[i]=1;
	}
	cout<<ans<<' '<<ans;
	return 0;
}