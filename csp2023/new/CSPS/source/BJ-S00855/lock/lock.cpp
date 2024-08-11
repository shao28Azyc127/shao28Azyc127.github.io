#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
int b[10],ans;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=5;++j)
			cin>>a[i][j];
	for(int a1=0;a1<=9;++a1)
		for(int a2=0;a2<=9;++a2)
			for(int a3=0;a3<=9;++a3)
				for(int a4=0;a4<=9;++a4)
					for(int a5=0;a5<=9;++a5){
						b[1]=a1,b[2]=a2,b[3]=a3,b[4]=a4,b[5]=a5;
						bool res=true;
						for(int i=1;i<=n;++i){
							int dif=0,did[10],cnt=0;
							for(int j=1;j<=5;++j)did[j]=0;
							for(int j=1;j<=5;++j)
								if(a[i][j]!=b[j])dif++,did[++cnt]=j;
							if(dif==0){res=false;break;}
							if(dif>2){res=false;break;}
							if(dif==1)continue;
							if(did[1]!=did[2]-1){res=false;break;}
							if(dif==2){
								int c1=(a[i][did[1]]-b[did[1]]+10)%10;
								int c2=(a[i][did[2]]-b[did[2]]+10)%10;
								if(c1!=c2){res=false;break;}
							}
						}
						if(res)ans++;
					}
	cout<<ans<<endl;
	return 0;
}