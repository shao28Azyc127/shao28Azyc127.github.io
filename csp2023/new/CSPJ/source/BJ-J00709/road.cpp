#include<bits/stdc++.h>
using namespace std;
int n,d;
const int maxn=100007;
struct point{
	int dis,v;
}p[maxn];
bool cmp(point x,point y){
	if(x.v!=y.v)return x.v<y.v;
	return x.dis<y.dis;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	p[0].dis=0;
	for(int i=1;i<n;i++){
		int in;
		cin>>in;
		p[i].dis=p[i-1].dis+in;
		
	}
	int lon=p[n-1].dis;
	//cout<<lon<<endl;
	for(int i=0;i<n;i++){
		cin>>p[i].v;
	}
	sort(p,p+n,cmp);
	point path[maxn];
	int siz=1;
	path[0]=p[0];
	for(int i=1;i<n;i++){
		if(p[i].dis<path[siz-1].dis){
			path[siz]=p[i];
			siz++;
		}
	}
	//for(int i=0;i<siz;i++){
	//	cout<<path[i].dis<<" ";
	//}
	//cout<<endl;
	int now=0,ans=0;
	for(int i=siz-1;i>=0;i--){
		if(now>=lon){
			//cout<<lon<<" ";
			break;
		}
		if(i!=0){
			int want=path[i-1].dis-now;
			//cout<<want<<" ";
			if(want%d==0){
				ans+=(path[i].v*(want/d));
				now=path[i-1].dis;
			}else{
				ans+=(path[i].v*(want/d+1));
				now+=(d*(want/d+1));
			}
			
		}
		if(i==0){
			int want=lon-now;
			//cout<<want<<" ";
			if(want%d==0){
				ans+=(path[i].v*(want/d));
				now=path[i-1].dis;
			}else{
				ans+=(path[i].v*(want/d+1));
				now+=(d*(want/d+1));
			}
		}
		//cout<<ans<<" "<<now<<endl;	
	}
	cout<<ans;
	return 0;
}