#include<bits/stdc++.h>
using namespace std;
int C,T,n,m,ans;
struct point{
	int pt;//-1:T -2:U -3:F
	bool nt;
	bool operator == (const point k){
		return (!(nt^k.nt))&&(pt==k.pt);
	}
}endp[100010];
int tendp[100010];
void check(point b){
	if(b.nt&&b.pt<0){
		b.nt=0;
		b.pt=0-4-b.pt;
		return ;
	}
}
point find(point b){
	if(b.pt<0){
		check(b);
		return b;
	}
	if(endp[b.pt]==b){
		if(b.nt==1){
			point bb;
			bb.pt=-2;
			bb.nt=0;
			return bb;
		}
		return b;
	}
	point bb=b;
	bb=find(endp[bb.pt]);
	bb.nt = !(b.nt^bb.nt);
	return bb;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	if(C==3||C==4){
		while(T--){
			scanf("%d%d",&n,&m);
			char tv;
			int tp;
			ans=0;
			for(int i = 1;i <= n;i++){tendp[i]=0;}
		    for(int i = 1;i <= m;i++){
				//scanf("%c%d",&tv,&tp);
				cin>>tv>>tp;
				if(tv=='U'){tendp[tp]=1;continue;}
			}
			for(int i = 1;i <= n;i++){
				if(tendp[i])ans++;
			}
			printf("%d\n",ans);
		}
		return 0;
	}
	while(T--){
		scanf("%d%d",&n,&m);
		char tv;
		int tp,tp2;
		ans=0;
		for(int i = 1;i <= n;i++){endp[i].nt=0;endp[i].pt=i;}
		for(int i = 1;i <= m;i++){
			cin>>tv>>tp;
			if(tv=='T')endp[tp].pt=-1;
			else if(tv=='U')endp[tp].pt=-2;
			else if(tv=='F')endp[tp].pt=-3;
			else{
				scanf("%d",&tp2);
				endp[tp]=find(endp[tp2]);
				if(tv=='-'){
					endp[tp].nt = (!endp[tp].nt);
					check(endp[tp]);
				}
			}
			//cout<<tp<<" "<<endp[tp].nt<<" "<<endp[tp].pt<<endl;
		}
		for(int i = 1;i <= n;i++){
		    for(int j = 1;j <= n;j++){
			    endp[j]=find(endp[j]);
		    }
		}
		for(int i = 1;i <= n;i++){
			//cout<<i<<" "<<endp[i].nt<<" "<<endp[i].pt<<endl;
			if(endp[i].pt==-2){
				ans++;continue;
			}if(endp[i].nt&&(endp[i].pt==i)){
				ans++;continue;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}