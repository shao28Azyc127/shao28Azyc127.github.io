#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	long long s=0;
	int a[100010];
	int b[100010];
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		double q;
		q=a[1]*1.0/d;
		q*=b[1];
		if(q>((a[1]/d)*b[1])){
			cout<<(a[1]/d)*b[1]+1;
		}else{
			cout<<(a[1]/d)*b[1];
		}
		
		return 0;
	}
	for(int i=1;i<n;i++){
		if(b[i]>b[i+1]){
			double q;
			q=a[i]/d;
			s+=q*b[i];
		}else{
			int j;
			for(j=i+1;j<=n;j++){
				if(b[j]<b[i]){
					break;
				}
			}
			int s1;
			for(int k=i;k<j;k++){
				s1+=a[k];
			}
			double q;
			q=s1/d;
			s+=q*b[i];
		}
	}
	cout<<s;
	return 0;
}