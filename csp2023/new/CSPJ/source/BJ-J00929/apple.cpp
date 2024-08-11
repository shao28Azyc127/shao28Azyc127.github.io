#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int ans,i=0;
	bool flag=0;
	while(1){
//		cout<<n<<" "<<i<<"test"<<endl;
		i++;
		if(flag==0){
			if(n==0){
				ans=i;
				break;
			}
			if((n-1)%3==0){
				ans=i;
				flag=1;
			}
		}
		int tmp=(n-1)/3+1;
		n-=tmp;
		if(n==0){
			break;
		}
	}
	
	cout<<i<<" "<<ans;
	return 0;
}
