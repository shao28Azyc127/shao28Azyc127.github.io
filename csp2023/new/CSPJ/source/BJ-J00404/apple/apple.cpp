#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000005;
int n,cnt=0,ans,day,lv;
short a[MAXN];
bool dead_=false;
bool chk(){
	for(int i=1;i<=n;i++){
		if(a[i]!=0)return true;
	}
	return false;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	lv=n;
	for(int i=1;i<=n;i++)a[i]=1;
	for(int i=1;;i++){
		for(int j=1;j<=n;j++){
			if(cnt==0 and a[j]!=0){
				lv--;
				a[j]=0;
				cnt=2;
				if(j==n)ans=i;
			}
			else if(a[j]==0)continue;
			else if(cnt!=0)cnt--;
		}
		if(lv==0){
			cout << i << " ";
			break;
		}
		cnt=0;
	}
	cout << ans;
	return 0;
}