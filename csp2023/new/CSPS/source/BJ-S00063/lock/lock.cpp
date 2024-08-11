#include<bits/stdc++.h>
using namespace std;
int st[5],nst[5];
int cnt[100005];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&st[0],&st[1],&st[2],&st[3],&st[4]);
		int tm=0;
		for(int j=0;j<=4;j++){
			tm*=10;
			tm+=st[j];
		}
		for(int j=0;j<=4;j++){
			memcpy(nst,st,sizeof st);
			for(int k=1;k<=9;k++){
				nst[j]=(nst[j]+1)%10;
				int tmp=0;
				for(int l=0;l<=4;l++){
					tmp*=10;
					tmp+=nst[l];
				}
				cnt[tmp]++;
			}
		}
		for(int j=0;j<=3;j++){
			memcpy(nst,st,sizeof st);
			for(int k=1;k<=9;k++){
				nst[j]=(nst[j]+1)%10;
				nst[j+1]=(nst[j+1]+1)%10;
				int tmp=0;
				for(int l=0;l<=4;l++){
					tmp*=10;
					tmp+=nst[l];
				}
				cnt[tmp]++;
			}
		}
	}
	int ret=0;
	for(int i=0;i<=99999;i++){
		if(cnt[i]==n){
			ret++;
		}
	}
	printf("%d\n",ret);
	return 0;
}