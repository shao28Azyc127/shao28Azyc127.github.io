#include <bits/stdc++.h>
using namespace std;
int n,cnt=0,a[10000000],vis[10000000],tmp=1;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int b;
	if(n<=3) cout<<n<<" "<<n;
	else {
		for(int i=1;i<=n;i++) a[i]=i;
		for(int i=1;i<=n/2+1;i++){
			int tmp=1;
			for(int j=1;j<=n;j++){
				 if(a[j]!=0) {
					tmp=j;
					break;
				 }
			}
			for(int j=tmp;j<=n;j+=3){
				if(a[j]!=0){
					if(a[j]==n)b=cnt;
					a[j]=0;
					vis[j]=1;
				} 
			}
			cnt++;
		}
		cout<<cnt<<" "<<b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
