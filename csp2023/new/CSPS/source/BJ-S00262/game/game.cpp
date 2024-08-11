#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=2e6+100;
long long n,a[N],p=0,ans=0;
char c[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>c;
	for(int i=0;i<n-1;i++){
		p=0;
		for(int j=i+1;j<=n-1;j+=2){
			if(c[j]==c[j-1]){
				if(p==0) ans++;
				continue;
			}
			else{
				if(p==0){
					p++;
					a[p]=j-1;
					p++;
					a[p]=j;
					continue;
				}
				if(c[j-1]==c[a[p]]){
					p--;
				}
				else{
					p++;
					a[p]=j-1;
				}
				if(c[j]==c[a[p]]){
					p--;
				}
				else{
					p++;
					a[p]=j;
				}
			}
			if(p==0){
				ans++;
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
