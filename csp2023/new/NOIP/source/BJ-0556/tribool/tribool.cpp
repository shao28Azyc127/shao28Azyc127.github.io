#include<bits/stdc++.h>

using namespace std;

int num,T;
int n,m,ans;
int x[10005];
int x_[15];
int fa[10005];
bool t[10005];

void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
}

int find(int u){
	while(fa[u]!=u) fa[u]=find(fa[u]);
	return fa[u];
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>num>>T;
	if(num==1 || num==2){
		while(T--){
			cin>>n>>m;
			if(n==10){
				for(int i1=1;i1<=3;i1++)
				for(int i2=1;i2<=3;i2++)
				for(int i3=1;i3<=3;i3++)
				for(int i4=1;i4<=3;i4++)
				for(int i5=1;i5<=3;i5++)
				for(int i6=1;i6<=3;i6++)
				for(int i7=1;i7<=3;i7++)
				for(int i8=1;i8<=3;i8++)
				for(int i9=1;i9<=3;i9++)
				for(int i10=1;i10<=3;i10++)
				x[1]=i1,x[2]=i2,x[3]=i3,x[4]=i4,x[5]=i5,x[6]=i6,x[7]=i7,x[8]=i8,x[9]=i9,x[10]=i10;
				for(int i=1;i<=10;i++){
					x_[i]=x[i];
				}
				
				for(int i=1;i<=m;i++){
					char c;
					cin>>c;
					if(c=='T'){
						int a;
						cin>>a;
						x[a]=1;
					}
					if(c=='F'){
						int a;
						cin>>a;
						x[a]=2;
					}
					if(c=='U'){
						int a;
						cin>>a;
						x[a]=3;
					}
					if(c=='+'){
						int a,b;
						cin>>a>>b;
						x[a]=x[b];
					}
					if(c=='-'){
						int a,b;
						cin>>a>>b;
						if(x[b]==1) x[a]=2;
						if(x[b]==2) x[a]=1;
						if(x[b]==3) x[a]=3;
					}
				}
				
				bool flag=true;
				for(int i=1;i<=10;i++){
					if(x[i]!=x_[i]){
						flag=false;
					}
				}
				if(flag){
					int ans=0;
					for(int i=1;i<=n;i++){
						if(x_[i]==3) ans++;
					}
					cout<<ans;
					
				}
				
			}
		}
	}
	
	if(num==3 || num==4){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char c;
				cin>>c;
				if(c=='T'){
					int a;
					cin>>a;
					x[a]=1;
				}
				if(c=='F'){
					int a;
					cin>>a;
					x[a]=2;
				}
				if(c=='U'){
					int a;
					cin>>a;
					x[a]=3;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(x[i]==3) ans++;
			}
			cout<<ans<<endl;
		}
	}
	
	if(num==5 || num==6){
		
		while(T--){
			cin>>n>>m;
			init();
			for(int i=1;i<=m;i++){
				char c;
				cin>>c;
				if(c=='U'){
					int a;
					cin>>a;
					t[a]=true;
					t[fa[a]]=true;
				}
				if(c=='+'){
					int a,b;
					cin>>a>>b;
					fa[a]=b;
					if(t[a]==true || t[b]==true) t[a]=t[b]=true;
				}
			}
			for(int i=1;i<=n;i++){
				fa[i]=find(fa[i]);
				t[i]=t[fa[i]];
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(t[i]==true) ans++;
			}
			cout<<ans;
		}
	}
/*	
	if(num==5 || num==6){
		while(T--){
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char c;
				cin>>c;
				if(c=='U'){
					int a;
					cin>>a;
					x[a]=3;
				}
				if(c=='+'){
					int a,b;
					cin>>a>>b;
					x[a]=x[b];
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(x[i]==3) ans++;
			}
			cout<<ans<<endl;
		}
	}
*/	
	return 0;
}
