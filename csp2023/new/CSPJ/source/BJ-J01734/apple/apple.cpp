#include<bits/stdc++.h>
using namespace std;
int n,num=0,day=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	int flag=0;
	while(n){
		day++;
		if(n%3==0){
			n-=n/3;
		}else if(n%3==1){
			if(flag==0){
				num=day;
				flag=1;
			}
			n-=n/3+1;
		}else if(n%3==2){
			n-=n/3+1;
		}
	}
	cout<<day<<" "<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
