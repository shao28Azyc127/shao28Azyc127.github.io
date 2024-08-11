#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,c,t,x[100005],id,ans=0,id1[100005],id2[100005];
char v,v_[100005];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		//memset(x,0,sizeof(x));
		ans=0;
		scanf("%d%d",&n,&m);
		if(c==3||c==4){
			for(int i=1;i<=m;i++){
				cin>>v>>id;
				if(v=='T') x[id]=0;
				else if(v=='U') x[id]=1;
				else x[id]=2;
			}
			for(int i=1;i<=n;i++){
				if(x[i]==1){
					ans++;
				}
			}
			printf("%d\n",ans);
		}
		else if(n<=10){
			ans=n;
			for(int i=1;i<=m;i++){
				cin>>v_[i];
				if(v_[i]=='+'||v_[i]=='-'){
					cin>>id1[i]>>id2[i];
				}
				else cin>>id1[i];
			}
			for(int j=0;j<pow(3,n);j++){
				int ii=j,ans_=0;
				bool flag=0;
				for(int i=1;i<=n;i++){
					x[i]=ii%3;
					ii/=3;
					if(x[i]==1) ans_++;
				}
				for(int i=1;i<=m;i++){
					if(v_[i]=='+'){
						x[id1[i]]=x[id2[i]];
					}
					else if(v_[i]=='-'){
						x[id1[i]]=2-x[id2[i]];
					}
					else if(v=='T') x[id1[i]]=0;
					else if(v=='U') x[id1[i]]=1;
					else x[id1[i]]=2;
				}
				ii=j;
				for(int i=1;i<=n;i++){
					//printf("%d ",x[i]);
					if(x[i]!=ii%3){
						flag=1;
						break;
					}
					ii/=3;
				}
				//printf("\n");
				if(flag==0){
					ans=min(ans,ans_);
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}