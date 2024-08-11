#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,a[MAXN],b[MAXN],minn=INT_MAX,minnplc,pls,mon,d,box/*剩余未使用的里程*/;
bool enid=false;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n-1;i++)
		cin >> b[i];
	for(int i=1;i<=n;i++)cin >> a[i];
	minn=a[1];
	for(int i=1;i<=n;i++){//始发站点
		if(a[i]<minn){
			if(pls%d==0)mon+=pls/d*minn;
			else {
				if((pls-box)%d==0){
					mon+=pls/d*minn;
					box=0;
				}
				else if((pls-box)%d!=0){
					mon+=(((pls-box)/d)+1)*minn;
					box+=(d-(pls-box))%d;
				}
			}
			minn=a[i];
			minnplc=i;
			pls=0;
			if(i==n)enid=true;
		}
		if(i==n and !enid){
			if(pls%d==0)mon+=pls/d*minn;
			else {
				if((pls-box)%d==0){
					mon+=pls/d*minn;
					box=0;
				}
				else if((pls-box)%d!=0){
					mon+=(((pls-box)/d)+1)*minn;
					box+=(d-(pls-box))%d;
				}
			}
		}
		pls+=b[i];
	}
	cout << mon;
	return 0;
}