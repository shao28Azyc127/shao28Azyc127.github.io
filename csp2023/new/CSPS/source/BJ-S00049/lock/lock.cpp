#include <iostream>
#include <cstdio>
using namespace std;
const int N=17;
int n;
int num[N][10];
int num1[10], numc[10];
int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>num[i][j];
	int ans=0;
	for(int a=0;a<=9;a++){
		for(int b=0;b<=9;b++){
			for(int c=0;c<=9;c++){
				for(int d=0;d<=9;d++){
					for(int e=0;e<=9;e++){//Ã¶¾ÙÕıÈ·ÃÜÂëabcde
						num1[1]=a;num1[2]=b;num1[3]=c;num1[4]=d;num1[5]=e;
						bool f=1;
						for(int i=1;i<=n;i++){//Ã¶¾Ù´íÎóÃÜÂëABCDE
							for(int j=1;j<=5;j++){//Ïà¼õµÃ²î
								if(num1[j]>=num[i][j])
									numc[j]=num1[j]-num[i][j];
								else
									numc[j]=num1[j]+10-num[i][j];
							}
							int cnt=0, were=0, were2=0;
							for(int j=1;j<=5;j++)
								if(numc[j]!=0){
									cnt++;
									if(were) were2=j;
									if(!were) were=j;
								}
							if(!(cnt==1 || (cnt==2 && numc[were]==numc[were2] && were2==were+1)))
								f=0;
						}
						ans+=f;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}