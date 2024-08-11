#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int ans = 0;
	int i = 0;
	
	int n;
	cin>>n;
	int sy = n;
	while(n != 0){ 
		if(n % 3 == 0){
			ans = i;
		}
		
		n -= 1;
		i++;
	}
	
	i = 0;
	int j = 0;
	while(sy != 0){
		for(int i = 1;i<=sy;i++){
			if(i==1){
				sy-=1;
			}
			if(i%4 == 0){
				sy--;
			}
		}
		j++;
	}
	
	cout<<j-1<<" "<<ans;
	return 0;
}
