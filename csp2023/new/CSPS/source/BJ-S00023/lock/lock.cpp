#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct code{
	int c[7];
	void init(int a1,int a2,int a3,int a4,int a5){
		c[1]=a1;
		c[2]=a2;
		c[3]=a3;
		c[4]=a4;
		c[5]=a5;
	}
}a[10005];
int n;
bool check(code t){
	for(int i=1;i<=n;i++){
		code diff;
		diff.init(0,0,0,0,0);
		for(int j=1;j<=5;j++){
			diff.c[j]=(a[i].c[j]+10-t.c[j])%10;
		}
		/*
		for(int j=1;j<=5;j++){
			cout<<diff.c[j]<<'A';
		}
		cout<<endl;
		for(int j=1;j<=5;j++){
			cout<<t.c[j]<<'B';
		}
		cout<<endl;
		*/
		int cnt=0;
		for(int j=1;j<=5;j++){
			if(diff.c[j]!=0){
				cnt++;
				if(j+1<=5&&diff.c[j+1]==diff.c[j]){
					diff.c[j+1]=0;
				}
				diff.c[j]=0;
			}
		}
		if(cnt!=1){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i].c[j];
		}
	}

	int cnt=0;
	for(int a1=0;a1<=9;a1++){
		for(int a2=0;a2<=9;a2++){
			for(int a3=0;a3<=9;a3++){
				for(int a4=0;a4<=9;a4++){
					for(int a5=0;a5<=9;a5++){
						code tmp;
						tmp.init(a1,a2,a3,a4,a5);
						if(check(tmp)){
							cnt++;
						}
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}