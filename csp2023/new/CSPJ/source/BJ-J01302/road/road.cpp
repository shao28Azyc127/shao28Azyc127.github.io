#include<iostream>

using namespace std;

typedef long long LL;

LL n,d;
LL v[100010]={};
LL a[100010]={};

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(LL i=0;i<n-1;i++){
		cin>>v[i];
	}
	for(LL i=0;i<n;i++){
		cin>>a[i];
	}
	LL minn=a[0];
	LL sumroad=v[0];
	LL summ=0;
	LL oil=0;
	for(int i=1;i<n-1;i++){
		if(a[i]<minn){
			if(((sumroad-oil)%d)!=0){
				summ=summ+((((sumroad-oil)/d)+1)*minn);
				LL buy=(((sumroad-oil)/d)+1)*d;
				oil=buy-sumroad+oil;
			}else{
				summ=summ+((((sumroad-oil)/d))*minn);
			}
			minn=a[i];
			sumroad=0;
		}
		sumroad=sumroad+v[i];
	}
//	cout<<sumroad<<" "<<minn<<" "<<summ<<endl;
	if(((sumroad-oil)%d)!=0){
		summ=summ+((((sumroad-oil)/d)+1)*minn);
		LL buy=(((sumroad-oil)/d)+1)*d;
		oil=buy-sumroad;
	}else{
		summ=summ+((((sumroad-oil)/d))*minn);
	}
	cout<<summ<<endl;
	return 0;
}
