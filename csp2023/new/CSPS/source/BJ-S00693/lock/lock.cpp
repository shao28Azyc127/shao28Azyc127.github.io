#include<iostream>
using namespace std;
long long ans1=0;
int h[15],f[15][15],n;
void work(int x1,int x2,int x3,int x4,int x5){
	h[1]=x1;
	h[2]=x2;
	h[3]=x3;
	h[4]=x4;
	int flag=0,ff1,ff2;
	h[5]=x5;
	for(int i=1;i<=n;i++){
		int xx=0,xx1,xx2,yy1,yy2,ff1=0,ff2=0;
		if(flag==1){ 
			break;
		}
		for(int j=1;j<=5;j++){
			if(f[i][j]!=h[j]){
				xx++; 
				if(xx==1){
					xx1=j;
					if(h[j]>f[i][j]){
						ff1=1;
					}
					else{
						ff1=2;
					}
					yy1=f[i][j]-h[j];
				}
				else{
					if(xx==2){
						yy2=f[i][j]-h[j];
						if(h[j]>f[i][j]){
							ff2=1;
						}
						else{
							ff2=2;
						}
						if(xx1!=j-1||(ff1==ff2&&yy1!=yy2)){
							flag=1;
							break;
						}
						if(ff1!=ff2){
							if((yy1+yy2*-1!=10&&yy1+yy2*-1!=-10)){
								flag=1;
								break;
							}
						}
					}
					else{
						flag=1;
						break;
					}
				}
			}
		}
		if(xx==0){
			flag=1;
			break;
		}
	}
	if(flag==0){
		ans1++;
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>f[i][j];
		}
	}
	for(int a=0;a<=9;a++){
		for(int b=0;b<=9;b++){
			for(int c=0;c<=9;c++){
				for(int d=0;d<=9;d++){
					for(int e=0;e<=9;e++){
						work(a,b,c,d,e);
					}
				}
			}
		}
	}
	cout<<ans1;
	return 0;
}