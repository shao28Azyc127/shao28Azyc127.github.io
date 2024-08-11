#include<bits/stdc++.h>
using namespace std;
long long n,d=0,sum=0,num=0;
bool a[1000010];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(num<n){
		sum++;
		int k=2;
		for(int i=1;i<=n;i++){
			if(!a[i]) k++;
			if(k==3){
				k=0;
				num++;
				a[i]=true;
				if(i==n) d=sum;
			}
		}
	}
	printf("%lld %lld",sum,d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
