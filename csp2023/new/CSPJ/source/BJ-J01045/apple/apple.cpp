#include<bits/stdc++.h>
using namespace std;
long long n,ans,sum,cnt;
bool f=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>an;
	for(int i=1;;i++){
		sum++;
		int w=n%3;
		int v=n/3;
		if(w==1&&!f){ans=i;f=1;}
		if(w==0)cnt=v;
		else cnt=v+1;
		n-=cnt;
		if(n<=0)break;
	}
	cout<<sum<<" "<<ans;
	return 0;
}
