#include<bits/stdc++.h>
using namespace std;
int n,c=0;
int lock[10][10];
int password[10]={1,1,1,1,1,1,1,1};
bool f;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<5;j++) cin>>lock[i][j];
	if(n==1) cout<<81;
	else{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int l=0;l<5;l++)
					if(lock[i][l]!=lock[j][l]) password[l]=0;
		for(int i=0;i<5;i++) if(!password[i]) c+=1;
		cout<<(10-n)*c;
	}
	return 0;
}
