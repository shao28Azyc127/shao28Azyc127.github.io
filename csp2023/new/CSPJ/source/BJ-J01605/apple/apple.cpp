#include<bits/stdc++.h>
using namespace std;
const int maxn=100000000+5;
long long a,ans,x=1;
int b[maxn];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	 cin>>a;
	int num=2;
	for(long long i=1;i<=a;i++){

		if(i==a){
			if(num==2&&b[i]==0){ 
				cout<<x<<" ";
				b[i]=1;
				ans+=1;
			}
			
			num=2;
			i=1;
			
			if(ans==a) {
				cout<<x;
				return 0;
			}
			x+=1;
			ans=0;
		}
		if(num==2 && b[i]==0){
			b[i]=1;
			num=0;
		}
		if(b[i]==1){
			ans+=1;
		}
		
		if(b[i]==0) num+=1;


	}
	
	return 0;
}
