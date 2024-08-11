#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define REPG(i,h,x) for(int i=h[x];~i;i=edge[i].next)
#define CLR(a,x) memset(a,x,sizeof(a));
const int INF=0x3f3f3f3f;

const int N=3005;
int n,m,cnt[N][26];
char str[N][N],tmp1[N],tmp2[N];
vector<pii> A,B;
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cnt[i][str[i][j]-'a']++;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) tmp1[j]=str[i][j];
		sort(tmp1+1,tmp1+1+m);
		bool flag=true;
		// for(int k=1;k<=m;k++) printf("%c",tmp1[k]);
		// puts("!");
		A.clear();
		for(int k=0;k<26;k++) if(cnt[i][k]) A.push_back({k,cnt[i][k]});
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			B.clear();
			for(int k=25;k>=0;k--) if(cnt[j][k]) B.push_back({k,cnt[j][k]});
			int cur1=0,cur2=0,cur3=0,cur4=0;
			// for(auto i:A) printf("{%d %d}",i.first,i.second);
			// puts("");
			// for(auto i:B) printf("{%d %d}",i.first,i.second);
			// puts("");
			while(cur1<A.size()&&cur2<B.size()){
				if(A[cur1]==B[cur2]){cur1++,cur2++;continue;}
				if(A[cur1].first<B[cur2].first) break;
				if(A[cur1].first>B[cur2].first){flag=false;break;}
				if(A[cur1].second!=B[cur2].second){flag=false;break;}	
			}
			// for(int k=1;k<=m;k++) tmp2[k]=str[j][k];
			// // for(int k=1;k<=m;k++) printf("%c",tmp2[k]);
			// // puts("");
			// sort(tmp2+1,tmp2+1+m,greater<char>());
			// for(int k=1;k<=m;k++){
			// 	if(tmp1[k]>tmp2[k]){flag=false;break;}
			// 	if(tmp1[k]<tmp2[k]) break;
			if(!flag) break;
		}
		printf("%d",flag);
	}
	return 0;
}