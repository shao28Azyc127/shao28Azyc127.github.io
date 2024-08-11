#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long l[N];
long long w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n;
	long long d;
	cin>>n>>d;
	for(int i=2;i<=n;i++){
		long long t;
		cin>>t;
		l[i]=l[i-1]+t;
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int now=1;
	long long ans=0;
	long long s=0;
	for(int i=2;i<=n-1;i++){
		if(w[i]<w[now]){
			long long len=l[i]-l[now];
			if(s>len){
				s=s-len;
				len=0;
			}
			else{
				len-=s;
				s=0;
			}
			long long r=len/d+(len%d>0);
			s+=r*d-len;
			ans=ans+w[now]*r;
			now=i;
		}
	}
	long long len=l[n]-l[now];
			if(s>len){
				s=s-len;
				len=0;
			}
			else{
				len-=s;
				s=0;
			}
			long long r=len/d+(len%d>0);
			s+=r*d-len;
			ans=ans+w[now]*r;
	cout<<ans;
	return 0;
}