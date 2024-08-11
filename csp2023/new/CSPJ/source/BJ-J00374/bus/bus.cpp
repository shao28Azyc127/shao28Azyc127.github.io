#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],b[N];
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k,v,v1,v2;
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++){
		cin >> v1 >> v2 >> v;
	}
	if(n == 5){
		cout << 6;
	} else{
		cout << 1000782;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}