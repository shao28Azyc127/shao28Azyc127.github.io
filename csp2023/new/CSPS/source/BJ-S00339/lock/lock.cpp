#include<bits/stdc++.h>
#define int long long
using namespace std;

void inn(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
}

int n;
int a[10][10];
int check=0;
int no[10];

int zero(int x){return (!x)?10:x;}

signed main(){
	inn();
	cin>>n;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];

	for(int i=1;i<=5;i++)
		for(int j=2;j<=n;j++)
			if(a[j-1][i]!=a[j][i]){
				check++,no[check]=i;
				break;
			}
		
	if(check>2){
		cout<<0<<endl;
		return 0;
	}
	
	if(!check||n==1){
		cout<<81<<endl;
		return 0;
	}
	
	if(n==2){
		if(check==1){
			if(no[1]==5||no[1]==1)cout<<10<<endl;
			else cout<<12<<endl;
		}
		else{
			int fir=zero(a[1][no[2]])-zero(a[1][no[1]]);
			int sec=zero(a[2][no[2]])-zero(a[2][no[1]]);
			if(fir!=sec)cout<<0<<endl;
			else cout<<8<<endl;
		}
		return 0;
	}
	else{
		if(check==1)cout<<10-n<<endl;
		else{
			int sum=0;
			int temp=zero(a[1][no[2]])-zero(a[1][no[1]]);
			for(int i=2;i<=n;i++){
				int qwq=zero(a[i][no[2]])-zero(a[i][no[1]]);
				if(qwq!=temp)sum++;
			}
			if(sum)cout<<0<<endl;
			else cout<<10-n<<endl;
		}
	}
	return 0;
}