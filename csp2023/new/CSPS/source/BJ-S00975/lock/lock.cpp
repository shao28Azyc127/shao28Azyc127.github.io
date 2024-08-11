#include<bits/stdc++.h>
using namespace std;

int n;
int a[100][100];
int s[100];

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
	}
	int ans=0;
	for(int k=0;k<=99999;k++){
		int x=k;
		s[1]=x%10;x/=10;
		s[2]=x%10;x/=10;
		s[3]=x%10;x/=10;
		s[4]=x%10;x/=10;
		s[5]=x%10;x/=10;
		bool flag=true;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=1;j<=5;j++){
				if(s[j]!=a[i][j]) cnt++;
			}
			if(cnt==0 || cnt>2) flag=false;
			else if(cnt==2){
				for(int j=1;j<=5;j++){
					if(s[j]!=a[i][j]){
						if(s[j+1]!=a[i][j+1] && (a[i][j+1]+10-s[j+1])%10==(a[i][j]+10-s[j])%10) break;
						else{
							flag=false;break;
						}
					}
				}
			}
		}
		if(flag==true){
			ans++;
		} 
	}
	cout<<ans;
	return 0;
}
