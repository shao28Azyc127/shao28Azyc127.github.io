#include<bits/stdc++.h>
using namespace std;
int a[1000010],n,s=0,q=1,cnt;
bool flag;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(;;){
		if(flag){
			cout<<s-1<<" "<<cnt;
			return 0;
		}
		s++;
		flag=true;
		for(int i=1;i<=n;i++){
			if(a[i]==0 && q%3==1){
				a[i]++;
				q++;
				if(i==n) cnt=s;
				flag=false;
			}else if(a[i]==0){
				q++;
				flag=false;
			}
		}
		q=1;
	}
	return 0;
}
//show me the ID