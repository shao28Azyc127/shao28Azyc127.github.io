#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=100020;
int n,f[12],ans=0,s1,s2,s3,s4,d[N],e[N];
signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	memset(e,0,sizeof(e));
	cin>>n;
	for(int i=1;i<=n;i++){
		s2=0;
		for(int j=1;j<=5;j++) cin>>s1,s2=s2*10+s1;
		e[s2]=-999;
		d[i]=s2;
	}
	for(int i=1;i<=n;i++){
		s1=d[i];
		for(int j=1;j<=5;j++) f[6-j]=s1%10,s1/=10;
		for(int j=1;j<=5;j++){
			for(int z=1;z<=9;z++){
				f[j]=(f[j]+z+10)%10;
				s2=10000*f[1]+1000*f[2]+100*f[3]+10*f[4]+f[5];
				e[s2]++;
				f[j]=(f[j]-z+10)%10;
			}
		}
		for(int j=1;j<=4;j++){
			for(int z=1;z<=9;z++){
				f[j]=(f[j]+z+10)%10,f[j+1]=(f[j+1]+z+10)%10;
				s2=10000*f[1]+1000*f[2]+100*f[3]+10*f[4]+f[5];
				e[s2]++;
				f[j]=(f[j]-z+10)%10,f[j+1]=(f[j+1]-z+10)%10;
			}
		}
	}
	for(int i=0;i<=99999;i++) ans+=(e[i]==n);
	cout<<ans<<"\n";
	return 0;
}
/* 
 * why am i even here
 * 
 * wasn't i like, retired two years ago or something?
 * 
 * how am i supposed to get prizes in this 
 * 
 * im stupid plz help
 */
