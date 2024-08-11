#include<bits/stdc++.h>
using namespace std;
int v[100006],a[100006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	cin >> n >> d;
	double sum=0;
	for(int i=0;i<n-1;i++){
		cin >>v[i];
		sum+=v[i];
	}
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int x=0;
	if(sum/d>int(sum/d)){
		x=int(sum/d)+1;
	}else{
		x=sum/d;
	}
	int price=x*a[0];
	cout << price;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
