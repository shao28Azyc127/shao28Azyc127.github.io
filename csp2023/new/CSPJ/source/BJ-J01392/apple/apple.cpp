#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int d=0;
	int dn=-1;
	while(n!=0){
		d++;
		if((n-1)%3==0 && dn==-1){
			dn=d;
		}
		n=n-(1+(n-1)/3);
	}
	cout<<d<<" "<<dn;
	return 0;
}
