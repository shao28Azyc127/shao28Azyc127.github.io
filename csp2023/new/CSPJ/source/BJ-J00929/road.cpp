#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int u[N];
int a[N];
int v[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>u[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	long long sum=0,last=0;
	for(int i=1;i<n;i++){
//		cout<<i<<"i"<<endl;
		long long tmp;
		long long us;
		if(v[i]==0){
			us=u[i];
		}
		int j;
		v[i]=1;
		for(j=i+1;j<n;j++){
			if(a[i]<a[j]&&v[j]==0){
				us+=u[j];
				v[j]=1;
//				cout<<j<<"j"<<endl;
			}
			else{
				break;
			}
		}
		if(us>=last){
			us-=last;
			last=0;
		}
		else{
			last-=us;
			us=0;
		}
//		cout<<us<<"us"<<endl;
		
		if(us%d!=0){
			tmp=us/d+1;
		}else{
			tmp=us/d;
		}
		
		
		sum+=tmp*a[i];
		last=d*tmp-us+last;
//		cout<<tmp*a[i]<<" "<<d*tmp<<" "<<last<<"test"<<endl;
		i=j-1;
	}
	
	cout<<sum;
	return 0;
}
