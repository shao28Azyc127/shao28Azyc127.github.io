#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d2;
int f(int x){
	int t=0;
	while(x){
		t++;
		if((x-1)%3==0&&d2==0){
			d2=t;
		}
		x-=(1+(x-1)/3);
	}
	return t;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	cin>>n;
	cout<<f(n)<<" "<<d2<<endl;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
