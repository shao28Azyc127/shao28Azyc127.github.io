#include<bits/stdc++.h>
using namespace std;
int n,m;char a[1000000];
char zc[10000],xc[10000];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;cin>>a;int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int len=0;for(int k=0;k<n;k++)zc[k]='1';
			for(int k=i;k<=j;k++){
				zc[len]=a[k];len++;
			}int pp=1;
			while(len>0){
				int gg=0;
				for(int k=0;k<len;k++){
					if(zc[k]==zc[k+1]&&k+1<len){
						for(int l=k+2;l<len;l++)zc[l-2]=zc[l];
						len-=2;gg=1;
					}zc[k]=zc[k];
				}if(gg==0){pp=0;break;}
			}if(pp){ans++;}
		}
	}cout<<ans<<endl;return 0;
}