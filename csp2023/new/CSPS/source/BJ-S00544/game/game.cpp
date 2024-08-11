#include<bits/stdc++.h>
using namespace std;
long long n,ans;
#define MAXN 1000000
char ch[MAXN];
int main(){
    freopen("game1.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>ch[i];
	}
	long long t=0;
	for(int i=0;i<n;i++){
		while(ch[i+t]==ch[i+1+t]){
			ans++;
			t++;
			if(2*t<=i+1){
				break;
			}
		}
	}
	cout<<ans;
}