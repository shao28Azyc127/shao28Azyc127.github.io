#include<bits/stdc++.h>
using namespace std;
int a[500005][12],lst[12];//0 T   1 F   2 U
int ask[12][5];//1 +   2 -   3 T    4 F    5 U
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==1||c==2){
		int n,m;
		while(t--){
			int ans=0x3f3f3f3f;
			cin>>n>>m;
			int res=0;
			for(int i=1;i<pow(3,n);i++){
				a[i][n]=(a[i-1][n]+1)%3;
				res=0;
				if(a[i-1][n]+1>=3) res=1;
				for(int j=n-1;j>=1;j--){
					a[i][j]=(a[i-1][j]+res)%3;
					if(a[i-1][j]+res>=3) res=1;
					else res=0;
				}
			}
			memset(ask,0,sizeof(ask));
			for(int mm=1;mm<=m;mm++){
				char ccc;
				cin>>ccc;
				if(ccc=='+'){
					ask[mm][1]=-1;
					cin>>ask[mm][2]>>ask[m][3];
				}else if (ccc=='-'){
					ask[mm][1]=-2;
					cin>>ask[mm][2]>>ask[mm][3];
				}else{
					if(ccc=='T') ask[mm][1]=-3;
					if(ccc=='F') ask[mm][1]=-4;
					if(ccc=='U') ask[mm][1]=-5;
					cin>>ask[mm][2];
				}
			}
			int tot=0;
			for(int i=0;i<pow(3,n);i++){
				for(int mm=1;mm<=n;mm++) lst[mm]=a[i][mm];
				int xxx,yyy;
				for(int mm=1;mm<=m;mm++){
					int cc;
					cc=ask[mm][1];
					if(cc==-1){
						xxx=ask[mm][2],yyy=ask[mm][3];
						lst[xxx]=lst[yyy];
					}else if(cc==-2){
						xxx=ask[mm][2],yyy=ask[mm][3];
						if(lst[yyy]==2) lst[xxx]=2;
						if(lst[yyy]==0) lst[xxx]=1;
						if(lst[yyy]==1) lst[xxx]=0;
					}else{
						xxx=ask[mm][2];
						if(cc==-3) lst[xxx]=0;
						if(cc==-4) lst[xxx]=1;
						if(cc==-5) lst[xxx]=2;
					}
				}
				bool fff=1;
				tot=0;
				for(int mm=1;mm<=n;mm++){
					if(lst[mm]==2) tot++;
					if(lst[mm]!=a[i][mm]) fff=0;
				}
				if(fff) ans=min(ans,tot);
			}
			cout<<ans<<endl;
		}
	}
}
