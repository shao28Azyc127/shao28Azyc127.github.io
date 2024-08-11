#include <iostream>
#include <cstdio>
using namespace std;
long long n,a[10],b[10],c[10],d[10],e[10],w1,w2,f,vis1[10],vis2[10],vis3[10],vis4[10],vis5[10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
	}
	if(n==2){
		for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[i]!=a[j]) a[n+1]=1;
			if(b[i]!=b[j]) b[n+1]=1;
			if(c[i]!=c[j]) c[n+1]=1;
			if(d[i]!=d[j]) d[n+1]=1;
			if(e[i]!=e[j]) e[n+1]=1;
			}
		}
		if(a[n+1]==1){
			if(c[n+1]==1||d[n+1]==1||e[n+1]==1) {
				cout<<0;
				return 0;
			}
			if(b[n+1]==1){
				if(((b[1]+a[1])==(b[2]+a[2]))||(b[1]-a[1]==b[2]-a[2])||(b[1]-a[1]+a[2]-b[2])%10==0){
					cout<<8;
					return 0;
				}
				else{
					cout<<0;
					return 0;
			}
		}
			else{
				if((a[2]-a[1])%2==0){
					cout<<10<<endl;
					return 0;
				}
				else{
					cout<<8<<endl;
					return 0;
				}
			}
		}
	
		if(b[n+1]==1){
			if(d[n+1]==1||e[n+1]==1) {
				cout<<0;
				return 0;
			}
			if(c[n+1]==1){
				if(((c[1]+b[1])==(c[2]+b[2]))||(c[1]-b[1]==c[2]-b[2])||(c[1]-b[1]+b[2]-c[2])%10==0){
					cout<<8;
					return 0;
				}
				else{
					cout<<0;
					return 0;
			}
		}
			else{
				if((b[2]-b[1])%2==0){
					cout<<10<<endl;
					return 0;
				}
				else{
					cout<<8<<endl;
					return 0;
				}
			}
		}
		if(c[n+1]==1){
			if(e[n+1]==1) {
				cout<<0;
				return 0;
			}
			if(d[n+1]==1){
				if(((c[1]+d[1])==(d[2]+c[2]))||(d[1]-c[1]==d[2]-c[2])||(d[1]-c[1]+c[2]-d[2])%10==0){
					cout<<8;
					return 0;
				}
				else{
					cout<<0;
					return 0;
			}
		}
			else{
				if((c[2]-c[1])%2==0){
					cout<<10<<endl;
					return 0;
				}
				else{
					cout<<8<<endl;
					return 0;
				}
			}
		}
			if(d[n+1]==1){
			if(e[n+1]==1){
				if(((d[1]+e[1])==(d[2]+e[2]))||(e[1]-d[1]==e[2]-d[2])||(e[1]-d[1]+d[2]-e[2])%10==0){
					cout<<8;
					return 0;
				}
				else{
					cout<<0;
					return 0;
			}
		}
			else{
				if((a[2]-a[1])%2==0){
					cout<<10<<endl;
					return 0;
				}
				else{
					cout<<8<<endl;
					return 0;
					}
				}
			}
			if(e[n+1]==1){
				if((e[2]-e[1])%2==0){
					cout<<10<<endl;
					return 0;
				}
				else{
					cout<<8<<endl;
					return 0;
				}
			}
		}
	for(int i=1;i<=n;i++){
		if(vis1[a[i]]==0){
			a[n+1]++;
			vis1[a[i]]=1;
		}
		if(vis2[b[i]]==0){
			b[n+1]++;
			vis2[b[i]]=1;
		}
		if(vis3[c[i]]==0){
			c[n+1]++;
			vis3[c[i]]=1;
		}
		if(vis4[d[i]]==0){
			d[n+1]++;
			vis4[d[i]]=1;
		}
		if(vis5[e[i]]==0){
			e[n+1]++;
			vis5[e[i]]=1;
		}
	}
	if(n==1) cout<<81<<endl;
	else cout<<10-max(a[n+1],max(b[n+1],max(c[n+1],max(d[n+1],e[n+1]))))<<endl;
	return 0;
}