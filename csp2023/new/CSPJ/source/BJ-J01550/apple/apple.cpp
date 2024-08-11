#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int d=n,ans=0,sum=0;
	bool flag=0;
	while(d>0){
		if(flag==0){
			if(d%3==1){
				ans=sum+1;
				flag=1;
			}
		}
		int j=d/3;
		if(j*3!=d){
			j++;
		}
		d-=j;
		sum++;
	}
	cout<<sum<<" "<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
