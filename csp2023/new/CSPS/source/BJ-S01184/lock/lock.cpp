#include<iostream>
using namespace std;
int kn[12][12][12][12][12];
int bp(int n,int m){
	if((n+m)<=9)return n+m;
	else return (n+m)%10;
}
int bm(int n,int m){
		if((n-m)>=0)return n-m;
		else return n+(10-m);
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n,nown1,nown2,nown3,nown4,nown5;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nown1>>nown2>>nown3>>nown4>>nown5;
		for(int j=1;j<=5;j++){//位数
			for(int k=1;k<6;k++){//幅度
				if(j==1){
					if(bp(nown1,k)==bm(nown1,k)){
						kn[nown5][nown4][nown3][nown2][bm(nown1,k)]++;
					}
					else {
						kn[nown5][nown4][nown3][nown2][bm(nown1,k)]++;
						kn[nown5][nown4][nown3][nown2][bp(nown1,k)]++;
					}
				}
				if(j==2){
					if(bp(nown2,k)==bm(nown2,k))kn[nown5][nown4][nown3][bm(nown2,k)][nown1]++;
					else {
						kn[nown5][nown4][nown3][bm(nown2,k)][nown1]++;
						kn[nown5][nown4][nown3][bp(nown2,k)][nown1]++;
					}
					
				}
				if(j==3){
					if(bp(nown3,k)==bm(nown3,k))kn[nown5][nown4][bm(nown3,k)][nown2][nown1]++;
					else {
						kn[nown5][nown4][bm(nown3,k)][nown2][nown1]++;
						kn[nown5][nown4][bp(nown3,k)][nown2][nown1]++;
					}
				}
				if(j==4){
					if(bp(nown4,k)==bm(nown4,k))kn[nown5][bm(nown4,k)][nown3][nown2][nown1]++;
					else {
						kn[nown5][bm(nown4,k)][nown3][nown2][nown1]++;
						kn[nown5][bp(nown4,k)][nown3][nown2][nown1]++;
					}
				}
				if(j==5){
					if(bp(nown5,k)==bm(nown5,k))kn[bm(nown5,k)][nown4][nown3][nown2][nown1]++;
					else {
						kn[bm(nown5,k)][nown4][nown3][nown2][nown1]++;
						kn[bp(nown5,k)][nown4][nown3][nown2][nown1]++;
					}
				}
			}
		}
		//----------------------------------2--------------------------------------------
		for(int j=2;j<=5;j++){//位数
			for(int k=1;k<6;k++){//幅度
				if(j==2){
					if(bp(nown2,k)==bm(nown2,k))kn[nown5][nown4][nown3][bp(nown2,k)][bp(nown1,k)]++;
					else {
						kn[nown5][nown4][nown3][bm(nown2,k)][bm(nown1,k)]++;
						kn[nown5][nown4][nown3][bp(nown2,k)][bp(nown1,k)]++;
					}
				}
				if(j==3){
					if(bp(nown3,k)==bm(nown3,k))kn[nown5][nown4][bp(nown3,k)][bp(nown2,k)][nown1]++;
					else {
						kn[nown5][nown4][bm(nown3,k)][bm(nown2,k)][nown1]++;
						kn[nown5][nown4][bp(nown3,k)][bp(nown2,k)][nown1]++;
					}
				}
				if(j==4){
					if(bp(nown4,k)==bm(nown4,k))kn[nown5][bm(nown4,k)][bm(nown3,k)][nown2][nown1]++;
					else {
						kn[nown5][bm(nown4,k)][bm(nown3,k)][nown2][nown1]++;
						kn[nown5][bp(nown4,k)][bp(nown3,k)][nown2][nown1]++;
					}
				}
				if(j==5){
					if(bp(nown5,k)==bm(nown5,k))kn[bm(nown5,k)][bm(nown4,k)][nown3][nown2][nown1]++;
					else {
						kn[bm(nown5,k)][bm(nown4,k)][nown3][nown2][nown1]++;
						kn[bp(nown5,k)][bp(nown4,k)][nown3][nown2][nown1]++;
					}
				}
				
			}
		}
	}
	int ans=0;
	for(int i1=0;i1<10;i1++)
		for(int i2=0;i2<10;i2++)
			for(int i3=0;i3<10;i3++)
				for(int i4=0;i4<10;i4++)
					for(int i5=0;i5<10;i5++)
						if(kn[i1][i2][i3][i4][i5]==n)ans++;
	cout<<ans;
	return 0;
	//coding i love you very much,so plz never gonna TLE,never gonna MLE,never gonna UKE and RE,never gonna WA,never gonna OLE,never gonna DSC and RP++;
}
