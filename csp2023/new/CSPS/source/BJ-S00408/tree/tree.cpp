#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
struct la{
 int a,b,c;
}land[N];
vector<int> gr[N];
priority_queue<pair<pair<int,int>,int>> q;
int plday[N];
bool vis[N];
int n;
int tp(){
	int day=0;
	q.push(make_pair(make_pair(-1,-1),1));
	int now;
	while(!q.empty()){
		day++;
		now=q.top().second;
		plday[now]=day;
		q.pop();
		vis[now]=1;
		for(auto v:gr[now]){
			if(!vis[v])q.push(make_pair(make_pair(land[v].a,land[v].b+land[v].c),v));
		}	
	}
	int max1=0;
	int maxn;
	int add;
	for(int i=1;i<=n;i++){
		int len;
		if(land[i].c>=0){
			len=(day-plday[i])*(land[i].b+(day+plday[i])*(land[i].c>>1));
		}
		else{
			int n=(land[i].c/land[i].b);
			if(n>plday[i])len=(n-plday[i])*(land[i].b+(n+plday[i])*(land[i].c>>1));
			else n=plday[i];
			if(day>n)len+=day-n;
		}
		if(max1>land[i].a-len){
			maxn=i;
			max1=land[i].a-len;
			add=max(1,land[i].b+land[i].c*day);
		}
		if(max1==land[i].a-len){
			int tadd=max(1,land[i].b+land[i].c*day);
			if(tadd<add){
				max1=i;
				add=max(1,land[i].b+land[i].c*day);
			}
		}
	}
	while(max1>0){
		day++;
		max1-=max(1,land[maxn].b+land[maxn].c*day);
	}
	return day;
}
int sp[N];
priority_queue<pair<int,int>> heap;
int ntp(){
	heap.push(make_pair(sp[1],1));
	int day=1;
	int now;
	while(!q.empty()){
		now=q.top().second;
		q.pop();
		vis[now]=1;
		plday[now]=day;
		for(auto v:gr[now]){
			if(!vis[v])heap.push(make_pair(sp[v],v));
		}
		day++;
	}
	int max1=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		int len=(day-plday[i])*max(1,land[i].b);
		if(max1>land[i].a-len){
			max1=land[i].a-len;
			maxn=i;
		}
		else if(max1==land[i].a-len){
			if(sp[maxn]<sp[i]){
				maxn=i;
			}
		}
	}
	int tday;
	if(max1>0) tday=max1/max(1,land[maxn].b);
	day+=tday;
	return day;
}
int main(){
	ios::sync_with_stdio(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    //int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
    	cin>>land[i].a>>land[i].b>>land[i].c;
    	if(land[i].c==0){
    		cnt++;
    	}
    }
    if(cnt==n){
    	 for(int i=1;i<=n;i++){
			sp[i]=land[i].a/max(land[i].b,1);
    	}
    	cout<<ntp()<<endl;
    	return 0;
    }
    for(int i=1;i<n;i++){
    	int u,v;
    	cin>>u>>v;
    	gr[u].push_back(v);
    }
    cout<<tp();
    return 0;
}