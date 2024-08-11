#include<bits/stdc++.h>
using namespace std;
struct tree{
	bool plat;
	long long h,wth;
	int b,c;
	vector<int> way;
}a[100010];
int n;
int day;
int ans=0;
void grow(){
	for(int i=1;i<=n;i++){
		if(a[i].plat==true) a[i].h+=max(a[i].b+(day*a[i].c),1);
	}
}
bool chek(){
	for(int i=1;i<=n;i++){
		if(a[i].plat!=true||a[i].h<a[i].wth)return false;
	}
	return true;
}
void dfs(int step,int sum){
	if(sum>n){
		while(!chek()){
			grow();
			day++;
		}
		
	}
	int len=a[step].way.size();
	for(int i=1;i<=len;i++){
		if(a[a[step].way[i]].plat!=true){
			a[a[step].way[i]].plat=true;
			grow();
			day++;
			dfs(a[step].way[i],sum++);
			a[a[step].way[i]].plat=false;
		}
	}
	return ;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%d%d",&a[i].wth,&a[i].b,&a[i].c);
		a[i].h=0;
		a[i].plat=false;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u].way.push_back(v);
		a[v].way.push_back(u);
	}
	dfs(1,1);
	printf("%d",ans);
	return 0;
}
/*int main(){
	  / int
	    int_
	 // int
	/// int
	  " int "
	  # int
	    int
}*/
