#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,d;
const int MAXX = 1e5+5;
int v[MAXX];
struct node{
	int x,id;
}a[MAXX];
vector<node> ans;
double y[MAXX];
long long sum = 0ll;
bool cmp(node a,node b){
	if(a.x == b.x)return a.id < b.id;
	else return a.x < b.x;
}
double l = 0;
bool cmp2(node a,node b){
	return a.id < b.id;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d",&n,&d);
	y[1] = 0;
	for(int i=1;i<n;i++){
		scanf("%d",&v[i]);
		y[i+1] = y[i] + 1.0*v[i]/d;
		//cout<<y[i+1]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].id = i;
	}
	ans.push_back(a[n]);
	sort(a+1,a+1+n,cmp);
	int last = n;
	for(int i=1;i<=n;i++){
		if(a[i].id >= last)continue;
		//cout<<"&&"<<a[i].id<<" "<<last<<endl;
		//sum += ceil(y[last]-y[a[i].id]-l)*a[i].x;
		//cout<<"---"<<ceil(y[last]-y[a[i].id]-l)*a[i].x<<endl;
		node tmp;
		tmp.x = a[i].x;
		tmp.id = a[i].id;
		ans.push_back(tmp);
		last = a[i].id;
		//l = ceil(y[last]-y[a[i].id]-l)-y[last]+y[a[i].id];
	}
	sort(ans.begin(),ans.end(),cmp2);
	int sz = ans.size();
	for(int i=0;i<sz-1;i++){
		sum += ceil(y[ans[i+1].id]-y[ans[i].id]-l)*ans[i].x;
		//cout<<"--- "<<ceil(y[ans[i+1].id]-y[ans[i].id]-l)*ans[i].x<<endl;
		last = ans[i].id;
		l = ceil(y[ans[i+1].id]-y[ans[i].id]-l) - (y[ans[i+1].id]-y[ans[i].id]-l);
	}
	printf("%lld",sum);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
