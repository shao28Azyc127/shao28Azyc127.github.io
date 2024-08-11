#include <iostream>
#include <cstring>
using namespace std;
bool f[100100];
int cnt;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int p=0;
	int q=0;
	int a=1,b=2,c;
	if(n==1||n==2){
		cout<<n<<" "<<n;
		return 0;
	}
	int qq=2;
	while(c<n){
		qq++;
		c=a+b;
		a=b;
		b=c;
	}
	cout<<qq<<" ";
	while(cnt<n){
		p++;
		int k=0;
		int i=1;
		while(f[i])
			i++;
		f[i]=1;
		cnt++;
		if(i==n){
			cout<<p;
			return 0;
		}
		for(;i<=n;i++){
			if(f[i]==0){
				k++;
				// cout<<i<<" "<<k<<endl;
			}
			if(k==3){
				f[i]=1;
				if(i==n){
					cout<<p;
					return 0;
				}
				cnt++;
				k=0;
			}
		}
		// cout<<endl;
	}
	return 0;
}