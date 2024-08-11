#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string st;
char tmp;
int main(){
	ios::sync_with_stdio(false);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%lld",&n);
    cin>>st;
    for(int i = 0;i < n;i++){
		stack<char> a;
		a.push(st[i]);
		for(int j = i+1;j < n;j++){
		    tmp=st[j];
		    if(a.empty()){
				a.push(tmp);
				continue;
			}
		    if(a.top()==tmp){
		    	a.pop();
		    	if(a.empty()){
				    ans++;
				}
	    	}else{
			    a.push(tmp);
		    }
		}
	}
	printf("%lld",ans);
    return 0;
}