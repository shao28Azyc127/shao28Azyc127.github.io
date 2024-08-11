#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int x[10][10];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>x[i][j];
		}
	}
	int ans=0;
	int a[10]={0};
	for(a[1]=0;a[1]<=9;a[1]++){
		for(a[2]=0;a[2]<=9;a[2]++){
			for(a[3]=0;a[3]<=9;a[3]++){
				for(a[4]=0;a[4]<=9;a[4]++){
					for(a[5]=0;a[5]<=9;a[5]++){
						
						int f1=0,f2=0,flag=0,z=0;
						
						for(int i=1;i<=n;i++){
							f1=0,f2=0,z=0;
							for(int j=1;j<=5;j++){
								if(x[i][j]-a[j]==0)continue;
								if(f1==0){
									f1=a[j]-x[i][j];
									if(f1<0) f1+=10;
									z=j;
								}
								else if(f1!=0&&z+1==j){
									f2=a[j]-x[i][j];
									if(f2<0) f2+=10;
								}
								else {
									flag=1;
									break;
								}
							}	
							if(flag==1)break;
							if(f2!=0&&f2!=f1){
								flag=1;
								break;	
							}
							if(f1==0){
								flag=1;
								break;
							} 
						}
						if(f2!=0&&f2!=f1){
							flag=1;
						}
						if(flag==0){
							//cout<<f1<<" "<<f2<<endl;
							ans++;
							//for(int j=1;j<=5;j++){
							//	cout<<a[j]<<" ";
							//}
							//cout<<endl;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
