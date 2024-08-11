#include<iostream>
using namespace std;
int n=0,k=0,x=0,y=0;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	k=n;
	while(k!=0){
		x+=1;
		k-=1;
		if(k%3==0&&y==0){
			y=x;
		}
		k-=k/3;
	}
	cout<<x<<" "<<y;
	return 0;
}
