#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
char l[maxn];
int y[maxn]={1};
int main(){
memset(y,1,sizeof(y));
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);
int n,ans=0;
cin>>n;
cin>>l;
int f=1,f1=0;
while(f){
	f=0;
	for(int i=0;i<n-1;i++){
		if(y[i]!=0){
			int x=-1;
			for(int j=i+1;j<n;j++){
				if(y[j]!=0){
					x=j;
					break;}
			}
			if(x==-1){break;}
			if(l[i]==l[x]){
				f=1;
				y[i]=0;
				y[x]=0;
				ans++;
			}
		}
	}
}
for(int i=0;i<n;i++){if(y[n]==1) f1=0;}
if(f1){
	ans++
	}
cout<<ans;
return 0;
}