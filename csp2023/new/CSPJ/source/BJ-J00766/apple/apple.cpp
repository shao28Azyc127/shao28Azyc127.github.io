#include<bits/stdc++.h>
using namespace std;
int n,k,s,q;
bool a[10000005],u;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	k=n;
	while(k){
		int l=3;
		for(int i=1;i<=n;i++){
			if(a[i]==false){
				if(l==3){
					a[i]=true;
					l=0;
					k--;
					//cout<<i<<endl;
				}
				l++;
			}
		}
		s++;
		if(a[n]==true&&u==false){
			q=s;
			u=true;
		}                                                               
	}
	cout<<s<<" "<<q;
	return 0;
}
