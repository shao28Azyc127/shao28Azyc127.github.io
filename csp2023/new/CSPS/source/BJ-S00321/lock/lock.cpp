#include<bits/stdc++.h>
using namespace std;
int n,a[10],ans=0;
int b[100010];
string int_to_str(int n){
	string s;
	for(int i=0;i<5;i++){
		if(n==0) s='0'+s;
		else s=char('0'+n%10)+s;
		n/=10;
	}
	return s;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=0;i<n;i++){
		int code=0;
		for(int j=1;j<=5;j++){
			cin>>a[j];
			code=code*10+a[j];
		}
		string s1=int_to_str(code);
		for(int j=1;j<=99999;j++){
			string s2=int_to_str(j);
			int flag=0;
			for(int k=0;k<=4;k++){
				int n1=s1[k],n2=s2[k];
				if(n1!=n2){
					int n3=s1[k+1],n4=s2[k+1];
					flag++;
					int sub1=n1-n2>0?n1-n2:10+n1-n2;
					int sub2=n3-n4>0?n3-n4:10+n3-n4;
					if(k<4&&sub1==sub2) k++;
				}
			}
			b[j]+=(flag==1);
		}
	}
	for(int i=1;i<=99999;i++)
		ans+=(b[i]==n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
