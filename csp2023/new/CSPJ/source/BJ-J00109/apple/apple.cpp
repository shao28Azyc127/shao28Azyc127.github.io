#include<bits/stdc++.h>
using namespace std;
int n,ans1=1,ans2,cnt=1,sum=1;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	for(int i=1;cnt<n;i++){
		cnt+=i;
		ans1++;
	}
	if((n)%(1+2)==1&&ans2==0){
		ans2=1;
	}
	sum=2;
	for(int i=1;i<=ans1;i++){
		if((n)%(i+sum+1)==sum&&ans2==0){
			ans2=i+1;
		}
		sum+=i;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}