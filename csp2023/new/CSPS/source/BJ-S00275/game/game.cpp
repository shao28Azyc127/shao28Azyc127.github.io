#include<bits/stdc++.h>
using namespace std;
char a[1100];
int l;
bool b[1100];
bool P(int x,int y){
	for(int i=x;i<y;i++){
		b[i]=true;
	}
	
	for(int i=0;i<(y-x)/2;i++){
		int m=1000;
		for(int j=x;j<y;j++){
			if(a[j]!=a[m])m=j;
			else{
				b[m]=false;
				b[j]=false;
			}
		}
	}
	for(int i=x;i<y;i++){
		if(b[i])return false;
	}
	return true;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>l;
	string s;
	cin>>s;
	for(int i=0;i<l;i++){
		a[i]=s[i];
	}
	int cnt=0;
	if(l<=100){
		for(int i=0;i<l;i++){
			for(int j=1;j<l/2;j++){
				if(i+j*2<l){
					if(P(i,i+j*2))
					cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	cout<<0;
    return 0;
}
