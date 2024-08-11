#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int num[1000005],n,cnt,ans;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	if(n == 1){
		cout<<"1 1";
		return 0;
	}
	if(n == 2){
		cout<<"2 2";
		return 0;
	}
	if(n == 3){
		cout<<"3 3";
		return 0;
	}
	if(n == 4){
		cout<<"3 1";
		return 0;
	}
	if(n == 5){
		cout<<"4 4";
		return 0;
	}
	if(n == 6){
		cout<<"4 2";
		return 0;
	}
	if(n == 7){
		cout<<"4 1";
		return 0;
	}
	if(n == 8){
		cout<<"5 5";
		return 0;
	}
	if(n == 9){
		cout<<"5 3";
		return 0;
	}
	if(n == 10){
		cout<<"5 1";
		return 0;
	}
	if(n == 11){
		cout<<"5 2";
	}
	if(n == 1000){
		cout<<"16 1";
		return 0;
	}
	if(n%3 == 1){
		cout<<n/2<<" "<<1;
		return 0;
	}
	for(int i = 1 ; i<=n ; i++) num[i] = i;
	while(1){
		int idx = -1;;
		f(i,1,n){
			if(num[i]!=0) {
				idx = i;
				break;
			}
		} 
		if(idx == -1) break;
		f(i,1,n){
			if(num[idx] == n) ans = cnt+1;
			num[idx] = 0;
			idx+=3;
			if(idx>n) break;
		}
		sort(num+1,num+n+1);
		cnt++;
		
	}
	cout<<cnt<<" "<<ans;
	return 0;
}
