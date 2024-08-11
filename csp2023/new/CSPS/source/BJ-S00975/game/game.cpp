#include<bits/stdc++.h>
using namespace std;

const long long N=2e5;
long long n,ans;
char c[N+5];
char a[N+5];
long long frt[N+5],nxt[N+5];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long l=1;l<=n;l++){
		for(long long r=l+1;r<=n;r++){
			if((r-l+1)%2==1) continue;
			long long len=r-l+1;
			for(long long i=1;i<=len;i++){
				a[i]=c[l+i-1];
				frt[i]=i-1;
				nxt[i]=i+1;
			}
			nxt[len]=0;
			frt[1]=0;
			long long sum=len;
			bool flag=true;
			long long begin=1;
			while(sum>0){
				long long tmp=sum;
				for(long long i=nxt[begin];i!=0;i=nxt[i]){
					if(a[frt[i]]==a[i]){
						nxt[frt[frt[i]]]=nxt[i];
						frt[nxt[i]]=frt[frt[i]];
						if(frt[i]==begin){
							begin=nxt[i];
						}
						sum-=2;
					}
				}
				if(tmp==sum){
					flag=false;
					break;
				}
			}
			if(flag==true) ans++;
		}
	}
	cout<<ans;
	return 0;
}
