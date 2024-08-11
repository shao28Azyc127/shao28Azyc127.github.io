#include <iostream>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,d,v[100005],a[100005];
	cin>>n>>d;
	int km=0;
	for(int i=1;i<=n-1;i++){
		cin>>v[i];
		km+=v[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=100005;i++){
		if(d*i>=km){
			cout<<a[1]*i;
			break;
		}
	}
	return 0;
}

