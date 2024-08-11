#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,q,m,i=0,j,b=0;
	cin>>n;
	m=n;
	while(n>0){
        q=((n-1)/3)+1;
        if((n-1)%3==0&&b==0){
			j=i+1;
			b=1;
        }
        n=n-q;

        i++;
	}
	n=m;
	cout<<i<<" "<<j;
}
