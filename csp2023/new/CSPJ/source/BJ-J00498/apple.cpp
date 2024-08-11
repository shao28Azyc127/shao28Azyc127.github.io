#include<bits/stdc++.h>
using namespace std;
bool v[1000000005];
int main(){
	int n,i=1,ts=1,x=0,j,ans1;
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(x<n){
		while(i<=n){
			while(v[i]==true){
				i++;
			}
			if(i>n){
				continue;
			}
			v[i]=true;
			if(i==n){
				ans1=ts;
			}
			x++;
			j=0;
			i++;
			while(j<2){
				if(v[i]==false){
					i++;
					j++;
				}
				else{
					i++;
				}
			}
		}
		ts++;
		i=1;
	}
	cout<<ts-1<<" "<<ans1;
	return 0;
}