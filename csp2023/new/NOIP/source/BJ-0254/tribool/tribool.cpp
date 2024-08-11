#include<iostream>
#include<vector>
using namespace std;
int t,n,m,f[400010],siz[400010],num1[100010],num2[100010],ans,pos;
bool hehe[100010];
char c[100010];
vector<int> e[400005];
int root(int x) {
	if(x==f[x])
		return x;
	return f[x]=root(f[x]);
}
void delet(int x) {
	if(f[x]==x) {
		if(e[x].empty())
			return;
		bool flag=true;
		for(int i:e[x]){
			if(!flag) {
				e[pos].push_back(i);
				continue;
			}
			pos=i;
			flag=false;
		}
		for(int i:e[x])
			f[i]=pos;
		siz[pos]=siz[x]-1;
		siz[x]=1;
		e[x].clear();
		return;
	}
	siz[root(x)]--;
	for(int i:e[x])
		f[i]=root(x),e[root(x)].push_back(i);
	f[x]=x;
	siz[x]=1;
	e[x].clear();
	return;
}
void merge(int x,int y) {
	if(root(x)==root(y))
		return ;
	if(siz[root(x)]<siz[root(y)])
		swap(x,y);
	siz[root(x)]+=siz[root(y)];
	e[root(x)].push_back(root(y));
	f[root(y)]=root(x);
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>t>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=1;i<=4*n+3;i++)
			f[i]=i,siz[i]=1,e[i].clear();
		for(int i=1;i<=2*n;i++)	
			merge(i,i+2*n);
		for(int i=1;i<=m;i++) {
			cin>>c[i];
			if(c[i]=='T') {
				cin>>num1[i];
				delet(num1[i]);
				delet(num1[i]+n);
				merge(num1[i],4*n+1);
				merge(num1[i]+n,4*n+2);
			}
			if(c[i]=='F') {
				cin>>num1[i];
				delet(num1[i]);
				delet(num1[i]+n);
				merge(num1[i],4*n+2);
				merge(num1[i]+n,4*n+1);
			}
			if(c[i]=='U') {
				cin>>num1[i];
				delet(num1[i]);
				delet(num1[i]+n);
				merge(num1[i],4*n+3);
				merge(num1[i]+n,4*n+3);
			}
			if(c[i]=='+') {
				cin>>num1[i]>>num2[i];
				if(num1[i]==num2[i])
					continue;
				delet(num1[i]);
				delet(num1[i]+n);
				merge(num1[i],num2[i]);
				merge(num1[i]+n,num2[i]+n);
			}
			if(c[i]=='-') {
				cin>>num1[i]>>num2[i];
				if(num1[i]==num2[i]) {
					swap(f[num1[i]],f[num1[i]+n]);
					swap(siz[num1[i]],siz[num1[i]+n]);
					vector<int> haha=e[num1[i]];
					e[num1[i]]=e[num1[i]+n];
					e[num1[i]+n]=haha;
					continue;
				}
				delet(num1[i]);
				delet(num1[i]+n);
				merge(num1[i],num2[i]+n);
				merge(num1[i]+n,num2[i]);
			}
		}
		for(int i=1;i<=n;i++)
			hehe[i]=false;
		ans=0;
		for(int i=1;i<=n;i++)
			if(root(i)==root(i+n)||root(i)==root(i+3*n)||root(i+n)==root(i+2*n)||root(i+2*n)==root(i+3*n)||root(i)==root(4*n+3)||root(i+n)==root(4*n+3)||root(i+2*n)==root(4*n+3)||root(i+3*n)==root(4*n+3))
				hehe[i]=true;
		for(int i=1;i<=m;i++)
			if(c[i]=='+'||c[i]=='-')
				hehe[num1[i]]|=hehe[num2[i]];
		for(int i=1;i<=n;i++)
			ans+=hehe[i];
		cout<<ans<<"\n";
	}
	return 0;
}