#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[20][20],hehe[100010],ans;
char c;
int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	for(int i=0;i<=99999;i++) {
		hehe[i]=true;
		for(int j=1;j<=n;j++) {
			bool flag=false;
			long long cnt=0;
			for(int k=1,num=i;k<=5;k++,num/=10)
				if(a[j][k]!=num%10)
					cnt++;
			if(cnt==1)
				flag=true;
			if(cnt==2)
				for(int k=1,num=i;k<=4;k++,num/=10)
					if(a[j][k]!=num%10&&(a[j][k]-a[j][k+1]+10)%10==(num%10-num%100/10+10)%10)
						flag=true;
			if(!flag) {
				hehe[i]=false;
				break;
			}
		}
	}
	for(int i=0;i<=99999;i++)
		if(hehe[i])
			ans++;
	cout<<ans<<"\n";
	return 0;
}