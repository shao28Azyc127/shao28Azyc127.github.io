#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int ans=0;
void game(int b,int n){
	for(int i = n;i >= b;i--){
		if(a[i]==a[i-1] && a[i]!=0 && a[i-1]!=0){
			if(a[i]==a[i-2]){
				int j = i;
				while(a[j]==a[i]){
					j--;
				}
				int k = 1;
				while(k<i-j){
					ans+=i-j-k;
					k+=2;
				}
				for(int k = j;k <= i;k++){
					a[k]=0;
				}
				if(j!=0 && (i-j)%2==0) ans++;
				i-=i-j;continue;
			}
			else{
				a[i]=a[i-1]=0;
				for(int j = i;j <= n;j++){
					swap(a[j],a[j+1]);
					swap(a[j-1],a[j]);
				}
			}
			if(a[n]==0){
				ans++;
			}
			i=n;
		}
	}
	if(a[b]==0) ans++;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	game(1,n);
	cout<<ans;
	return 0;
}
