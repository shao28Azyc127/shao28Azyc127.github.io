#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],s[N];
struct Node{
	int val;
	int id;
}pr[N];
bool cmp(Node x,Node y){
	if(x.val!=y.val) return x.val<y.val;
	return x.id>y.id;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d;
	int minid=INT_MAX,point=1;
	int left=0;
	int ans=0;
	scanf("%d%d",&n,&d);
	int idi=n-1;
	for(int i=1;i<n;++i){
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}for(int i=1;i<=n;++i){
		cin>>pr[i].val;
		pr[i].id=i;
	}
	sort(pr+1,pr+n,cmp);
	if(pr[1].id==1){
		cout<<(double)(s[n])/double(d)*pr[1].val;
		return 0;
	}
	while(minid!=1){
		if(pr[point-1].val!=pr[point].val&&point!=1){
			minid=pr[point-1].id;
			int kkksc03=((s[idi]-s[minid-1]-left)/(d))*pr[minid].val;
			ans+=kkksc03;
			idi=minid-1;
		}
		++point;
	}cout<<ans<<endl;
	return 0;
}
