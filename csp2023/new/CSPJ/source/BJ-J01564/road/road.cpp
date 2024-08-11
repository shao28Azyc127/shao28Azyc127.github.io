#include <bits/stdc++.h>
using namespace std;
int n,d;
const int N=1e6+5;
int v[N],a[N],money[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>v[i];
		money[i]=v[i]+money[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	int place=1;
	double leftoil=0;
	while(place!=n){
		int nextplace=place;
		while(a[nextplace]>=a[place]&&nextplce<n){
			nextplace++;
		}
		int lenth=money[nextplace]-money[place-1];
		int oilneed=(lenth+d-1)/d-leftoil;
		int oilmoney=oilneed*a[place];
		cnt+=oilmoney;
		leftoil=((lenth+d-1)/d-lenth/d);
		place=nextplace;
	}
	cout<<cnt;
	return 0;
}
