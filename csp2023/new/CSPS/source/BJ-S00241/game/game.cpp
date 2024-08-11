#include<bits/stdc++.h>
using namespace std;
int vis[30],o[2000005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	long long m=0;
	int n;
	string a;
	cin>>n>>a;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n;j+=2){
			int h=0,q=0;
			for(int z=i;z<=j;z++){
				if(vis[a[z]-'a']==1){
					for(int l=z-1;l>=i;l--){
						if(o[l]==0){
							if(a[l]==a[z]){
								o[l]=1;
								o[z]=1;
							}
							else{
								h=0;
							}
							break;
						}
					}
					if(h==1){
						break;
					}
					q++;
					vis[a[z]-'a']=0;
				}
				else{
					vis[a[z]-'a']=1;
				}
				if(h==1){
					break;
				}
			}
			if(h==0 && q*2==j-i+1){
				m++;
			}
			else{
				for(int i=0;i<=25;i++){
					vis[i]=0;
				}
			}
		}
	}
	cout<<m;
	return 0;
}