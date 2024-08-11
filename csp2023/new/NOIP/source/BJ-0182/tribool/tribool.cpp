#include<bits/stdc++.h>
using namespace std;

struct qqq{
	char opt;
	int num;
	int x,y;
}a[100005];

int id,t;
int n,m;
int p[100005],px[100005];
int ans;

void do_it(){
	for(int i=1;i<=m;++i){
		if(a[i].opt=='+'){
			px[a[i].x]=px[a[i].y];
		}
		else if(a[i].opt=='-'){
			px[a[i].x]=-px[a[i].y];
		}
		else{
			px[a[i].x]=a[i].num;
		}
	}
	return;
}

bool check(){
	for(int i=1;i<=n;++i){
		px[i]=p[i];
	}
	do_it();
	for(int i=1;i<=n;++i){
		if(px[i]!=p[i]){
			return 0;
		}
	}
	return 1;
}

void dfs(int l,int cnt){
	if(cnt>=ans){
		return;
	}
	if(l==n+1){
		if(check()==1){
			ans=min(ans,cnt);
		}
		return;
	}
	p[l]=0;
	dfs(l+1,cnt+1);
	p[l]=1;
	dfs(l+1,cnt);
	p[l]=-1;
	dfs(l+1,cnt);
	return;
}

bool flag[200005];

bool findx(int l){
	if(px[l]==0){
		return 1;
	}
	if(flag[l]==1){
		return 0;
	}
	flag[l]=1;
	if(findx(px[l])==1){
		px[l]=0;
		return 1;
	}
	return 0;
}

int fx[200005];

int get_root(int l){
	if(fx[l]==l){
		return l;
	}
	fx[l]=get_root(fx[l]);
	return fx[l];
}

void marge(int l1,int l2){
	int f1=get_root(l1),f2=get_root(l2);
	if(f1!=f2){
		fx[f1]=f2;
	}
	return;
}

vector<int> v[200005];
int que[200005],hx,tx,lx;

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>id>>t;
	if(id==1 || id==2){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>a[i].opt;
				if(a[i].opt=='+' || a[i].opt=='-'){
					cin>>a[i].x>>a[i].y;
				}
				else{
					cin>>a[i].x;
					if(a[i].opt=='U'){
						a[i].num=0;
					}
					if(a[i].opt=='T'){
						a[i].num=1;
					}
					if(a[i].opt=='F'){
						a[i].num=-1;
					}
				}
			}
			ans=n;
			dfs(1,0);
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(id==3 || id==4){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>a[i].opt;
				if(a[i].opt=='+' || a[i].opt=='-'){
					cin>>a[i].x>>a[i].y;
				}
				else{
					cin>>a[i].x;
					if(a[i].opt=='U'){
						a[i].num=0;
					}
					if(a[i].opt=='T'){
						a[i].num=1;
					}
					if(a[i].opt=='F'){
						a[i].num=-1;
					}
				}
			}
			for(int i=1;i<=n;++i){
				px[i]=i;
			}
			do_it();
			ans=0;
			for(int i=1;i<=n;++i){
				if(px[i]==0){
					++ans;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(id==5 || id==6){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>a[i].opt;
				if(a[i].opt=='+' || a[i].opt=='-'){
					cin>>a[i].x>>a[i].y;
				}
				else{
					cin>>a[i].x;
					if(a[i].opt=='U'){
						a[i].num=0;
					}
					if(a[i].opt=='T'){
						a[i].num=1;
					}
					if(a[i].opt=='F'){
						a[i].num=-1;
					}
				}
			}
			for(int i=1;i<=n;++i){
				px[i]=i;
				flag[i]=0;
			}
			do_it();
			for(int i=1;i<=n;++i){
				findx(i);
			}
			ans=0;
			for(int i=1;i<=n;++i){
				if(px[i]==0){
					++ans;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(id==7 || id==8){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>a[i].opt;
				if(a[i].opt=='+' || a[i].opt=='-'){
					cin>>a[i].x>>a[i].y;
				}
				else{
					cin>>a[i].x;
					if(a[i].opt=='U'){
						a[i].num=0;
					}
					if(a[i].opt=='T'){
						a[i].num=1;
					}
					if(a[i].opt=='F'){
						a[i].num=-1;
					}
				}
			}
			for(int i=1;i<=n;++i){
				px[i]=i;
			}
			for(int i=1;i<=2*n;++i){
				fx[i]=i;
				flag[i]=0;
				v[i].clear();
			}
			hx=0;
			tx=0;
			do_it();
			for(int i=1;i<=n;++i){
				if(px[i]<0){
					marge(i,n-px[i]);
					marge(n+i,-px[i]);
				}
				else{
					marge(i,px[i]);
					marge(n+i,n+px[i]);
				}
			}
			for(int i=1;i<=2*n;++i){
				v[get_root(i)].push_back(i);
			}
			for(int i=1;i<=n;++i){
				if(get_root(i)==get_root(n+i) && flag[get_root(i)]==0){
					que[tx]=get_root(i);
					++tx;
					flag[get_root(i)]=1;
				}
			}
			while(1){
				lx=tx-hx;
				if(lx==0){
					break;
				}
				while(lx--){
					int tmp=que[hx];
					++hx;
					for(int i=0;i<(int)(v[tmp].size());++i){
						if(v[tmp][i]<=n){
							if(flag[get_root(n+v[tmp][i])]==0){
								flag[get_root(n+v[tmp][i])]=1;
								que[tx]=get_root(n+v[tmp][i]);
								++tx;
							}
						}
						else{
							if(flag[get_root(v[tmp][i]-n)]==0){
								flag[get_root(v[tmp][i]-n)]=1;
								que[tx]=get_root(v[tmp][i]-n);
								++tx;
							}
						}
					}
				}
			}
			for(int i=1;i<=2*n;++i){
				if(flag[i]==1){
					for(int j=0;j<(int)(v[i].size());++j){
						if(v[i][j]<=n){
							px[v[i][j]]=0;
						}
					}
				}
			}
			ans=0;
			for(int i=1;i<=n;++i){
				if(px[i]==0){
					++ans;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(id==9 || id==10){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=m;++i){
				cin>>a[i].opt;
				if(a[i].opt=='+' || a[i].opt=='-'){
					cin>>a[i].x>>a[i].y;
				}
				else{
					cin>>a[i].x;
					if(a[i].opt=='U'){
						a[i].num=0;
					}
					if(a[i].opt=='T'){
						a[i].num=1;
					}
					if(a[i].opt=='F'){
						a[i].num=-1;
					}
				}
			}
			for(int i=1;i<=n;++i){
				px[i]=i+1;
			}
			for(int i=2;i<=2*n+1;++i){
				fx[i]=i;
				flag[i]=0;
				v[i].clear();
			}
			hx=0;
			tx=0;
			do_it();
			for(int i=2;i<=n+1;++i){
				if(abs(px[i-1])<=1){
					continue;
				}
				if(px[i-1]<0){
					marge(i,n-px[i-1]);
					marge(n+i,-px[i-1]);
				}
				else{
					marge(i,px[i-1]);
					marge(n+i,n+px[i-1]);
				}
			}
			for(int i=2;i<=2*n+1;++i){
				v[get_root(i)].push_back(i);
			}
			for(int i=2;i<=n+1;++i){
				if(get_root(i)==get_root(n+i) && flag[get_root(i)]==0){
					que[tx]=get_root(i);
					++tx;
					flag[get_root(i)]=1;
				}
				if(px[i-1]==0 && flag[get_root(i)]==0){
					que[tx]=get_root(i);
					++tx;
					flag[get_root(i)]=1;
				}
			}
			while(1){
				lx=tx-hx;
				if(lx==0){
					break;
				}
				while(lx--){
					int tmp=que[hx];
					++hx;
					for(int i=0;i<(int)(v[tmp].size());++i){
						if(v[tmp][i]<=n){
							if(flag[get_root(n+v[tmp][i])]==0){
								flag[get_root(n+v[tmp][i])]=1;
								que[tx]=get_root(n+v[tmp][i]);
								++tx;
							}
						}
						else{
							if(flag[get_root(v[tmp][i]-n)]==0){
								flag[get_root(v[tmp][i]-n)]=1;
								que[tx]=get_root(v[tmp][i]-n);
								++tx;
							}
						}
					}
				}
			}
			for(int i=2;i<=2*n+1;++i){
				if(flag[i]==1){
					for(int j=0;j<(int)(v[i].size());++j){
						if(v[i][j]<=n+1){
							px[v[i][j]-1]=0;
						}
					}
				}
			}
			ans=0;
			for(int i=1;i<=n;++i){
				if(px[i]==0){
					++ans;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
