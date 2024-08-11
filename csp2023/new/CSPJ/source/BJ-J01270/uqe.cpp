#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cout << "NO" << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}