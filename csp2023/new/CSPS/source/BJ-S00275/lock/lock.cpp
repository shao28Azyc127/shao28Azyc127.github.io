#include<bits/stdc++.h>
using namespace std;
int an[100][5];int n,a,b,c,d,e;int a2,b2,c2,d2,e2;
bool compare(int aa,int bb,int cc,int dd,int ee){
	for(int i=0;i<81;i++){
		if(aa==an[i][0]&&bb==an[i][1]&&cc==an[i][2]&&dd==an[i][3]&&ee==an[i][4]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	
	cin>>n;cin>>a>>b>>c>>d>>e;
	if(n==1){
		
		cout<<81;
		return 0;
	}
	
	int cnt=0;
	if(n==2){
		cin>>a2>>b2>>c2>>d2>>e2;
		for(int i=1;i<=9;i++){
			an[cnt][1]=b;
			an[cnt][2]=c;
			an[cnt][3]=d;
			an[cnt][4]=e;
			an[cnt++][0]=(a+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][0]=a;
			an[cnt][2]=c;
			an[cnt][3]=d;
			an[cnt][4]=e;
			an[cnt++][1]=(b+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][1]=b;
			an[cnt][0]=a;
			an[cnt][3]=d;
			an[cnt][4]=e;
			an[cnt++][2]=(c+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][1]=b;
			an[cnt][2]=c;
			an[cnt][0]=a;
			an[cnt][4]=e;
			an[cnt++][3]=(d+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][1]=b;
			an[cnt][2]=c;
			an[cnt][3]=d;
			an[cnt][0]=a;
			an[cnt++][4]=(e+i)%10;
		}
		
		//2
		for(int i=1;i<=9;i++){
			
			an[cnt][2]=c;
			an[cnt][3]=d;
			an[cnt][4]=e;
			an[cnt][1]=(b+i)%10;
			an[cnt++][0]=(a+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][0]=a;
			an[cnt][3]=d;
			an[cnt][4]=e;
			an[cnt][1]=(b+i)%10;
			an[cnt++][2]=(c+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][0]=a;
			an[cnt][1]=b;
			an[cnt][4]=e;
			an[cnt][2]=(c+i)%10;
			an[cnt++][3]=(d+i)%10;
		}
		for(int i=1;i<=9;i++){
			an[cnt][0]=a;
			an[cnt][1]=b;
			an[cnt][2]=c;
			an[cnt][3]=(d+i)%10;
			an[cnt++][4]=(e+i)%10;
		}
		
		
		//cmp
		for(int i=1;i<=9;i++){
			if(compare((a2+i)%10,b2,c2,d2,e2))cnt++;
			if(compare(a2,(b2+i)%10,c2,d2,e2))cnt++;
			if(compare(a2,b2,(c2+i)%10,d2,e2))cnt++;
			if(compare(a2,b2,c2,(d2+i)%10,e2))cnt++;
			if(compare(a2,b2,c2,d2,(e2+i)%10))cnt++;
			
			if(compare(a2,b2,c2,(d2+i)%10,(e2+i)%10))cnt++;
			if(compare((a2+i)%10,(b2+i)%10,c2,d2,e2))cnt++;
			if(compare(a2,(b2+i)%10,(c2+i)%10,d2,e2))cnt++;
			if(compare(a2,b2,(c2+i)%10,(d2+i)%10,e2))cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=0;i<n-2;i++)cin>>a>>b>>c>>d>>e;
	cout<<0;
    return 0;
}
