//ÖÖÊ÷
#include<bits/stdc++.h>
using namespace std;
long long a;
long long b;
long long c;
long long cnt,ans;
long long s1=1;
int n;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		cnt=i-1;
		while(a>0){
			cnt++;
			if(b+(cnt*c)<=1 && c<=0){
				cnt=cnt+a-1;
				break;
			}
			a-=max(b+(cnt*c),s1);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}