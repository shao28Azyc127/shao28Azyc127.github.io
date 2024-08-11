#include<iostream>
#include<string>
using namespace std;
int n;
string a;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>a;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[0]==a[1]){
			cout<<1;
		}
	    if(a[0]!=a[1]){
			cout<<0;
		}
	}
    return 0;
}