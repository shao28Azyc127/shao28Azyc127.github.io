#include<bits/stdc++.h>
#define in(...) scanf(__VA_ARGS__)
#define out(...) printf(__VA_ARGS__)
#define up(i,l,r) for(int i=l;i<=r;i++)
#define dn(i,r,l) for(int i=r;i>=l;i--)
#define fr(i,bg,ed,eq) for(i=bg;i!=ed;i=eq)
#define rpt(num) int tt=num;while(tt--)
using namespace std;
const int N=10;
const int num[5]={1,10,100,1000,10000};
typedef long long ll;

int n;
int a[N][5];
string sta[N];
int ans=0;
bool ok(string fr,string to){
	int ttmp=0;
	int idxa=-1,idxb=-1;
	if(fr==to){
		return false;
	}
	up(i,0,4){
		if(fr[i]!=to[i]){
			ttmp++;
			if(ttmp>2){
				return false;
			}
			if(idxa==-1){
				idxa=i;
			}else{
				idxb=i;
				if(idxb!=idxa+1){
					return false;
				}
			}
		}
	}
	if(ttmp==1){
		return true;
	}
	int suba=(fr[idxa+1]+10-fr[idxa])%10;
	int subb=(to[idxa+1]+10-to[idxa])%10;
	return suba==subb;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

	in("%d",&n);
	up(i,1,n){
		up(j,0,4){
			in("%d",a[i]+j);
		}
	}
	up(i,1,n){
		sta[i]="00000";
		up(j,0,4){
			sta[i][j]=a[i][j]+'0';
		}
	}
	string tmp="00000";
	up(i,0,99999){
		up(j,0,4){
			tmp[4-j]=i/num[j]%10+'0';
		}
		bool isok=1;
		up(j,1,n){
			if(!ok(sta[j],tmp)){
				isok=0;
				break;
			}
		}
		ans+=isok;
	}
	out("%d\n",ans);
	return 0;
}
