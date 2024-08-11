#include<bits/stdc++.h>
using namespace std;
char s[200005];
int p=0,y=0,x=0;
int l=1;
char a='A',e;
int n,c=0;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	cin>>n;
	cin>>e;
	s[0]=e;
	x=e;
	for(int i=1;i<n;i++){
		cin>>e;
		if(e==s[l-1] && a!=e){
			a=e;
			l-=1;
			c+=1;
			if(p==1){
				x+=1;
				c+=x;
			}
			else x=0;
			y=1;
			p=0;
		}
		else if(e!=a){
			s[l]=e;
			l+=1;
			if(y=1){
				x+=1;
				y=0;
				p=1;
			}
			if(p==1) p=0;
		}
		else p=1;
	}
	cout<<c;
	return 0;
}
