#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a))
const int INF=0x3f3f3f3f;

const int N=8005;;
int n,p[N],tot,buc[N],buc2[N],cnt;
char str[N],str2[N];
// ll ans=0;
inline void init(){
	for(int i=1,mid=0,maxr=0;i<=tot;i++){
		if(i<=maxr) p[i]=min(p[mid*2-i],maxr-i);
		while(str2[i-p[i]-1]==str2[i+p[i]+1]) p[i]++;
		if(i+p[i]>maxr) maxr=i+p[i],mid=i;
	}
}
int jc[N],jccnt;
// void solve(int l,int r){
// 	if(l==r) return;
// 	int mid=l+r>>1;
// 	solve(l,mid),solve(mid+1,r);
// 	for(int i=mid-1;i>=(l+mid-1)/2;i--){
// 		int pos=(i+1)*2;
// 		if(p[pos]) buc[i+p[pos]/2]++;
// 	}
// 	for(int i=mid+1;i<=(r+mid+1)/2;i++){
// 		int pos=(i+1)*2;
// 		if(p[pos]) buc2[i-p[pos]/2+1]++;
// 	}
// 	// printf("[%d %d] %d %d\n",l,r,buc[mid],buc2[mid+1]);
// 	ans+=buc[mid]*buc2[mid+1];
// 	ans+=p[(mid+1)*2]/2;
// 	for(int i=mid-1;i>=(l+mid-1)/2;i--){
// 		int pos=(i+1)*2;
// 		if(p[pos]) buc[i+p[pos]/2]--;
// 	}
// 	for(int i=mid+1;i<=(r+mid+1)/2;i++){
// 		int pos=(i+1)*2;
// 		if(p[pos]) buc2[i-p[pos]/2+1]--;
// 	}
// }
bool is[N][N];
int ans;
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%s",&n,str+1);
	for(int len=2;len<=n;len+=2)
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			// printf("%d %d %c %c\n",i,j,str[i],str[j]);
			if(len==2&&str[i]==str[j]){is[i][j]=true;continue;}
			if(str[i]==str[j]&&is[i+1][j-1]) is[i][j]=true;
			else for(int k=i;k<=j;k++) if(is[i][k]&&is[k+1][j]){is[i][j]=true;break;}
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) if(is[i][j]) ans++;
	printf("%d\n",ans);
// 	str2[++tot]='@',str2[++tot]='#';
// 	for(int i=1;i<=n;i++) str2[++tot]=str[i],str2[++tot]='#';
// 	str2[++tot]='!';
// 	init();
// 	for(int i=1;i<=n;i++){
// 		int pos=(i+1)*2;
// 		// printf("%d ",p[pos]/2);

// 	}
// 	puts("");
// 	for(int i=1;i<=n;i++)
// 		for(int j=i+1;j<=n;j++){

// 			int tot=0;
// 			if(j==i+1) {
// 				if(str[i]==str[j]) ans++;
// 				continue;
// 			}
// 			int maxr=-INF,minl=INF;
// 			for(int k=i;k<=j-1;k++){
// 				int pos=(k+1)*2,posl=k*2,posr=(k+2)*2;
// 				int l=k-p[pos]/2+1,r=k+p[pos]/2;
// 				if(r<=j&&l>=i){
// 					int lposl=k-p[posl]/2+1,rposl=k+p[posl]/2;
// 					int lposr=k-p[posr]/2+1,rposr=k+p[posr]/2;
// 					if(rposr<=j) maxr=max(rposr,maxr);
// 					if(lposl>=i) minl=min(lposl,minl);
// 					if((lposl<i||p[posl]<p[pos])&&(rposr>j||p[pos]>p[posr])){
// 						tot+=r-l+1;
// 					}				
// 				}
				
// 			}
// 			// printf("%d %d %d %d\n",i,j,minl,maxr);
// if(minl!=INF){
// 					int posm=(i+minl)/2;
// 					if(p[(posm+1)/2]>minl-i+1) tot+=minl-i+1;
// 				}
// 				if(maxr!=-INF){
// 					int posm=(j+maxr)/2;
// 					if(p[(posm+1)/2]>j-maxr+1) tot+=j-maxr+1;
// 				}
// 			if(j-i+1==tot) printf("%d %d\n",i,j);
// 			if(tot==j-i+1) ans++;
// 		}
	// printf("%d\n",ans);
	// // for(int i=1;i<=n;i++) ans+=p[(i+1)*2]/2,buc[i-p[(i+1)*2]/2]++,printf("%d ",p[(i+1)*2]/2);
	// // for(int i=1;i<=n;i++){
	// // 	int pos=(i+1)*2;
	// // 	if(p[i*2]<p[pos]&&p[pos]>p[(i+2)*2]) jc[++jccnt]=i,ans+=p[pos]/2;
	// // }
	// solve(1,n);
	// // for(int i=1;i<=n;i++){
	// // 	int pos=(i+1)*2;
	// // 	int r=i+p[pos]/2,l=i-p[pos]/2+1;
	// // 	buc[r]++,buc2[l]++;
	// // }
	// // for(int i=1;i<=jccnt;i++) printf("%d\n",jc[i]);
	// // ans+=jccnt*(jccnt-1)/2;
	// // for(int i=1;i<=jccnt;i++){

	// // }
	// printf("%d %d\n",ans,jccnt);
	return 0;
}