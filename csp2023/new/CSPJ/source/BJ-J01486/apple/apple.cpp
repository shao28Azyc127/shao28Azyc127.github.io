#include<iostream>
#include<cstdio>
using namespace std;
int upqz(int n){
	if(n%3)return n/3+1;
	return n/3;
}
int main(){
	freopen("apple1.in",r,stdin);
	freopen("apple1.ans",w,stdout);
	int n,ans=0,last,flag=1;
	cin>>n;
	int an=n;
	while(n){
		if(n%3==1&&flag){
			last=ans+1;
			flag=0;
		}
		int a=upqz(n);
		n-=a;
		ans++;
	}
	cout<<ans<<" "<<last;
	fclose(stdin);
	fclose(stdout);
	return 0;
}