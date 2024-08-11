#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxN=1e9;
bool use[maxN];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n,i=1,days1=1,days2=1,s=3;
	while(cnt>0){
		if(i>n){
			days1++;
			i=1;
			s=3;
		}
		if(use[i]==true){
			i++;
			continue;
		}
		
		if(s==3){
			
			use[i]=true;
			if(i==n){
				days2=days1;
			}
			cnt--;
			s=0;
		}
		s++;	
		i++;
		
	}
	cout<<days1<<" "<<days2;

	return 0;
}
