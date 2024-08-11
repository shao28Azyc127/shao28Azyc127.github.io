/*#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
int n,m,cc,t,o,p,cnt;
char c;
struct va{
	int val;
	int dval;
	int sta;
	int dsta;
}a[100005];
int rl[100005];
int pd[100005];
void rf(int f,int ans){
	if(pd[f]==1){
		if(ans%2==1){
			cnt+=ans;
			//cout<<"[+1]"<<ans;
		}else{
			//cout<<"ans"<<ans;
		}
		return;
	}
	pd[f]=1;
	rl[f]=-4;
	if(a[f].dval!=f){
		if(a[f].dsta==1){
			ans++;
		}
		rf(a[f].dval,ans);
	}
}
int main(){
    freopen("tribool2.in","r",stdin);
    freopen("tribool.out","w",stdout);
	cin>>cc>>t;
	while(t--){
		cin>>n>>m;
		cnt=0;
		for(int i = 1;i<=n;i++){
			rl[i]=-32767;
		}
		for(int i = 1;i<=n;i++){
			a[i].val=i;
			a[i].dval=i;
			a[i].sta=0;
			a[i].dsta=0;
		}
		for(int i = 1;i<=n;i++){
			cin>>c>>o;
			if(c=='-'){
				cin>>p;
				a[o].val=a[p].val;
				a[o].dval=p;
				a[o].sta=1-a[p].sta;
				a[o].dsta=1;
			}else if(c=='+'){
				cin>>p;
				a[o].val=a[p].val;
				a[o].dval=p;
				a[o].sta=a[p].sta;
				a[o].dsta=0;
			}else if(c=='T'){
				a[o].val=-1;
				a[o].sta=0;
				a[o].dsta=0;
			}else if(c=='F'){
				a[o].val=-2;
				a[o].sta=0;
				a[o].dsta=0;
			}else if(c=='U'){
				a[o].val=-3;
				a[o].sta=0;
				a[o].dsta=0;
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(a[j].val<0){
					rl[j]=a[j].val;
				}else{
					if(rl[a[j].val]!=-32767){
						if(a[j].sta==0){
							rl[j]=rl[a[j].val];
						}else{
							rl[j]=(rl[a[j].val]==-3?-3:(rl[a[j].val]==-1?-2:-1));
						}
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				pd[j]=0;
			}
			if(rl[i]==-32767){
				rf(i,0);
			}
		}
		for(int i = 1;i<=n;i++){
			//cout<<a[i].dsta<<" ";
			cnt+=(rl[i]==-3?1:0);
		}
		//cout<<endl;
		cout<<cnt<<endl;
	}
    return 0;
}
*/