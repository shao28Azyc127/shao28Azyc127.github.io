#include <iostream>
#include <cstdio>
using namespace std;
const int N=1e5+5;
int a[N],b[N],d[N],e[N];
char o[15];
int n,m,c,t,x,ans=0,q;
bool check(int x,int x2,int x3,int x4,int x5,int x6,int x7,int x8,int x9,int x10){
	int g[15];
	g[1]=x;
	g[2]=x2;
	g[3]=x3;
	g[4]=x4;
	g[5]=x5;
	g[6]=x6;
	g[7]=x7;
	g[8]=x8;
	g[9]=x9;
	g[10]=x10;
	for(int j=1;j<=m;j++){
		if(o[j]=='U')	g[e[j]]=3;
		else if(o[j]=='T')	g[e[j]]=1;
		else if(o[j]=='F') g[e[j]]=2;
		else if(o[j]=='+') g[b[j]]=g[d[j]];
		else{
			if(g[d[j]]==1){
				g[b[j]]=2;
			}
			else if(g[d[j]]==2){
				g[b[j]]=1;
			}
			else{
				g[b[j]]=g[d[j]];
			}
		}
	}
	if(g[1]==x&&g[2]==x2&&g[3]==x3&&g[4]==x4&&g[5]==x5&&g[6]==x6&&g[7]==x7&&g[8]==x8&&g[9]==x9&&g[10]==x10){
		return true;
	}
	return false;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	char v;
	cin >>c>>t;
	while(t--){
		ans=0;
		cin >>n>>m;
		for(int i=1;i<=1005;i++){
			a[i]=0;
			b[i]=0;
			d[i]=0;
		}
		if(c==3||c==4){
			for(int i=1;i<=m;i++){
				cin >>v>>x;
				if(v=='U'){
					a[x]=1;
				}
				else{
					a[x]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]!=0){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		else if(c==5||c==6){
			for(int i=1;i<=m;i++){
				cin >>v;
				if(v=='U'){
					cin >>x;
					a[x]=1;
				}
				else{
					cin >>b[i]>>d[i];
				}
			}
			for(int j=1;j<=1000;j++){
				for(int i=1;i<=m;i++){
					if(a[d[i]]!=0&&d[i]!=0){
						a[b[i]]=1;
					}
					else if(a[d[i]]==0&&d[i]!=0&&a[b[i]]==1){
						a[b[i]]=0;
					}
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]!=0){
					ans++;
					//cout<<i<<endl;
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=m;i++){
				cin >>o[i];
				if(o[i]=='U'||o[i]=='T'||o[i]=='F'){
					cin >>e[i];
				}
				else{
					cin >>b[i]>>d[i];
				}
				q=1000000;
				for(int d1=1;d1<=3;d1++){
					for(int d2=1;d2<=3;d2++){
						for(int d3=1;d3<=3;d3++){
							for(int d4=1;d4<=3;d4++){
								for(int d5=1;d5<=3;d5++){
									for(int d6=1;d6<=3;d6++){
										for(int d7=1;d7<=3;d7++){
											for(int d8=1;d8<=3;d8++){
												for(int d9=1;d9<=3;d9++){
													for(int d10=1;d10<=3;d10++){
														ans=0;
														if(check(d1,d2,d3,d4,d5,d6,d7,d8,d9,d10)){
															if(d1==3) ans++;
															if(d2==3) ans++;
															if(d3==3) ans++;
															if(d4==3) ans++;
															if(d5==3) ans++;
															if(d6==3) ans++;
															if(d7==3) ans++;
															if(d8==3) ans++;
															if(d9==3) ans++;
															if(d10==3) ans++;
															q=min(q,ans);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			cout<<q<<endl;
		}
		
		
	}
	
	
	return 0;
	}
