#include<bits/stdc++.h>
using namespace std;
long long n,d,money[100010];
long long num[100010];
long long w,minn=100050,sum;
long long minnn=100010;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>num[i];
		sum+=num[i];
	}
	for(int i=1;i<=n;i++){
		cin>>money[i];    
		if(money[i]<minn){
			minn=money[i];
			w=i;
		}
	}
	if(w==1){
		cout<<(sum/d)*minn<<endl;
		return 0;
	}
	else{
		int a;
		for(int i=1;i<w;i++){
			if(money[i]<minnn){
				minnn=money[i];
				a=i;
			}
		}
		int sum1=0;
		for(int i=1;i<=a;i++)
			sum1+=num[i];
		minn=money[1]*(sum1/d+1);
	}
	cout<<minn;
	return 0;
}
