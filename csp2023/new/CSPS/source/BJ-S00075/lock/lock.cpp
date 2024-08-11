#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10;
int a[N][N];
int n,cnt=0;
bool check(int l1,int l2,int l3,int l4,int l5){
	int l[6];
	l[1]=l1,l[2]=l2,l[3]=l3,l[4]=l4,l[5]=l5;
	for(int i=1;i<=n;i++){
		int qcnt=0,qdis=0,qpos=0;
		bool flag=true;
		for(int j=1;j<=5;j++){
			if(a[i][j]-l[j]==0) continue;
			int dis=0;
			if(a[i][j]<l[j]) dis=a[i][j]+10-l[j];
			else dis=a[i][j]-l[j];
			if(dis!=qdis){
				if(qdis==0) qdis=dis,qpos=j,qcnt++;
				else return false;
			}
			else{
				if(j-qpos>1) return false;
				qpos=j,qcnt++;
				if(qcnt>2) return false;
			}
		}
		if(qcnt==0) return false;
	}
	//cout<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<" "<<l5<<endl;
	return true;
}
signed main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=5;j++) scanf("%lld",&a[i][j]);
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				for(int h=0;h<=9;h++){
					for(int p=0;p<=9;p++){
						if(check(i,j,k,h,p)) cnt++;
					}
				}
			}
		}
	}
	printf("%lld\n",cnt);
	return 0;
}