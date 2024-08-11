#include<bits/stdc++.h>
using namespace std;
long long n,cnt,daytot,tmp,tot,bookone,sheng,a[10000005];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	tot=n;//zongshu
	for(int i=1;i<=n;i++)a[i]=0;
	while(cnt!=n){//meinawan
		sheng=0;
		cnt=0;
		daytot++;
		for(int i=1;i<=n;i++){
			if(a[i]!=0)cnt++;//nazou
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				tmp=i;
				break;
			}
		}
		for(int i=tmp;i<=n;i++){
			if(a[i]!=0){
				sheng++;
			}
			if(i-tmp==0&&a[i]==0){
				a[i]=daytot;
			}else if((i-tmp-sheng)%3==0&&a[i]==0){
				a[i]=daytot;
			}
		}
	}
	cout<<daytot-1<<" "<<a[n]<<endl;
	return 0;
}
//yanglizhongyuguole!!!!__11:16
