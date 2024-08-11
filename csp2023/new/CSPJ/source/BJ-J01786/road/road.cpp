#include<bits/stdc++.h>
using namespace std;
long long n,l,sum,sum1,xx=0;
long long v[100001],a[100001],buy1[100001];
bool buy[100001]={1};
int main(){
	freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>l;
    for(int i=0;i<n-1;i++){
    	cin>>v[i];
    	sum1+=v[i];
	}if(sum1%l!=0){
		sum1/=l;
		sum1++;
	}else{
		sum1/=l;
	}
	for(int i=0;i<n;i++){
    	cin>>a[i];
		if(a[i]<a[xx]){
			for(int j=xx;j<i;j++){
				buy1[xx]+=v[j];
			}
    		xx=i;
    		buy[i]=1;
		}
	}for(int i=0;i<n-1;i++){
		if(buy[i]==1){
			if(buy1[i]%l!=0){
				buy1[i]/=l;
				buy1[i]++;
			}else{
				buy1[i]/=l;
			}
			if(sum1>=buy1[i]){
				sum1-=buy1[i];
				sum+=buy1[i]*a[i];
			}else{
				sum+=sum1*a[i];
				sum1=0;
			}

		}
	}cout<<sum;
	fclose(stdin);
    fclose(stdout);
    return 0;
}
