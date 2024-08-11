#include<bits/stdc++.h>
using namespace std;
int n,a[1001000];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	int top1=n,top2=0,ans1=0,ans2;
	while(1){
		ans1++;
		for(int i=1;i<=top1;i+=3){
			if(a[i]==n){
				ans2=ans1;
			}
			a[i]=0;
		}
		top2=0;
		for(int i=1;i<=top1;i++){
			if(a[i])a[++top2]=a[i];
		}
		top1=top2;
		if(!top2)break;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
