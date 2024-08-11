#include<bits/stdc++.h>
using namespace std;
long long n,s,q,f;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	long long t=n;
	while(t){
		s++;
		if((t%3)==1&&f!=1){
			q=s;
			f=1;
		}
		t-=((t-1)/3+1);
	}
	cout<<s<<" "<<q;
	return 0;
}
