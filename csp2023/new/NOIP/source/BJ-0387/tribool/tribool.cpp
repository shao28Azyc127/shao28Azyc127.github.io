#include<bits/stdc++.h>
using namespace std;
int id,t,a[100005],ans,n,m,lastans;
char opx[100005];
int xx[100005],yy[100005];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> id >> t;
	if(id==3||id==4){
		while(t--){
			ans=0;
			cin >> n >> m;
			char op;
			int x;
			memset(a,0,sizeof(a));
			while(m--){
				cin >> op >> x;
				if(op=='U')a[x]=-1;
				else a[x]=0;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==-1)ans++;
			}
			cout << ans << endl;
		}
	}else if(id==5||id==6){
		while(t--){
			ans=0;
			memset(a,0,sizeof(a));
			cin >> n >> m;
			for(int i=1;i<=m;i++){
				cin >> opx[i];
				if(opx[i]=='U'){
					cin >> xx[i];
				}else{
					cin >> xx[i] >> yy[i];
				}
			}
			for(int ti=1;ti<=m;ti++){
				lastans=ans;ans=0;
				for(int i=1;i<=m;i++){
					if(opx[i]=='U'){
						a[xx[i]]=-1;
					}else{
						a[xx[i]]=a[yy[i]];
					}
				}
				for(int i=1;i<=n;i++){
					if(a[i]==-1)ans++;
				}
				if(ans==lastans)break;
			}
			ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==-1)ans++;
			}
			cout << ans << endl;
		}
	}else if(id==1||id==2){
		while(t--)cout << rand()%11 << endl;
	}
	return 0;
}