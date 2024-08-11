#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],ans,cnt,num[10],dif1,dif2;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)cin >> a[i][j];
	for(int i=0;i<=99999;i++){
		int temp=i;
		bool flag=1;
		for(int j=1;j<=5;j++){
			num[5-j+1]=temp%10;
			temp/=10;
		}
		for(int j=1;j<=n;j++){
			dif1=dif2=0;int cnt=0;
			for(int k=1;k<=5;k++){
				if(num[k]!=a[j][k]){
					cnt++;
					if(!dif1)dif1=k;
					else if(!dif2)dif2=k;
				}
			}
			if(cnt==2){
				int c1,c2;
				if(a[j][dif1]<num[dif1])c1=10+a[j][dif1]-num[dif1];
				else c1=a[j][dif1]-num[dif1];
				if(a[j][dif2]<num[dif2])c2=10+a[j][dif2]-num[dif2];
				else c2=a[j][dif2]-num[dif2];
				if(abs(dif2-dif1)!=1||c1!=c2){flag=0;break;}
			}else if(cnt!=1){flag=false;break;}
		}
		if(flag){
			ans++;
			//cout << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}