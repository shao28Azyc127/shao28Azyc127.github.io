#include<bits/stdc++.h>
using namespace std;
int c[5],sum;
bool a[11][11][11][11][11][8];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
	int b;
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4];
		for(int k=0;k<=9;k++){
			if(k!=c[0]){
				a[k][c[1]][c[2]][c[3]][c[4]][i]=1;
			}
		}for(int k=0;k<=9;k++){
			if(k!=c[1]){
				a[c[0]][k][c[2]][c[3]][c[4]][i]=1;
			}
		}for(int k=0;k<=9;k++){
			if(k!=c[2]){
				a[c[0]][c[1]][k][c[3]][c[4]][i]=1;
			}
		}for(int k=0;k<=9;k++){
			if(k!=c[3]){
				a[c[0]][c[1]][c[2]][k][c[4]][i]=1;
			}
		}for(int k=0;k<=9;k++){
			if(k!=c[4]){
				a[c[0]][c[1]][c[2]][c[3]][k][i]=1;
			}
		}
		int ca,cb;
		for(int k=1;k<=9;k++){
			if(k+c[0]>9){
				ca=k+c[0]-10;
			}else{
				ca=k+c[0];
			}if(k+c[1]>9){
				cb=k+c[1]-10;
			}else{
				cb=k+c[1];
			}a[ca][cb][c[2]][c[3]][c[4]][i]=1;
		}for(int k=1;k<=9;k++){
			if(k+c[1]>9){
				ca=k+c[1]-10;
			}else{
				ca=k+c[1];
			}if(k+c[2]>9){
				cb=k+c[2]-10;
			}else{
				cb=k+c[2];
			}a[c[0]][ca][cb][c[3]][c[4]][i]=1;
		}for(int k=1;k<=9;k++){
			if(k+c[2]>9){
				ca=k+c[2]-10;
			}else{
				ca=k+c[2];
			}if(k+c[3]>9){
				cb=k+c[3]-10;
			}else{
				cb=k+c[3];
			}a[c[0]][c[1]][ca][cb][c[4]][i]=1;
		}for(int k=1;k<=9;k++){
			if(k+c[3]>9){
				ca=k+c[3]-10;
			}else{
				ca=k+c[3];
			}if(k+c[4]>9){
				cb=k+c[4]-10;
			}else{
				cb=k+c[4];
			}a[c[0]][c[1]][c[2]][ca][cb][i]=1;
		}
	}
	for(int aa=0;aa<=9;aa++){
		for(int ba=0;ba<=9;ba++){
			for(int ca=0;ca<=9;ca++){
				for(int da=0;da<=9;da++){
					for(int ea=0;ea<=9;ea++){
						if(b==1){
							if(a[aa][ba][ca][da][ea][0]==1){
								sum++;
							}
						}else if(b==2){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1){
								sum++;
							}
						}else if(b==3){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1){
								sum++;
							}
						}else if(b==4){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1&&a[aa][ba][ca][da][ea][3]==1){
								sum++;
							}
						}else if(b==5){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1&&a[aa][ba][ca][da][ea][3]==1&&a[aa][ba][ca][da][ea][4]==1){
								sum++;
							}
						}else if(b==6){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1&&a[aa][ba][ca][da][ea][3]==1&&a[aa][ba][ca][da][ea][4]==1&&a[aa][ba][ca][da][ea][5]==1){
								sum++;
							}
						}else if(b==7){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1&&a[aa][ba][ca][da][ea][3]==1&&a[aa][ba][ca][da][ea][4]==1&&a[aa][ba][ca][da][ea][5]==1&&a[aa][ba][ca][da][ea][6]==1){
								sum++;
							}
						}else if(b==8){
							if(a[aa][ba][ca][da][ea][0]==1&&a[aa][ba][ca][da][ea][1]==1&&a[aa][ba][ca][da][ea][2]==1&&a[aa][ba][ca][da][ea][3]==1&&a[aa][ba][ca][da][ea][4]==1&&a[aa][ba][ca][da][ea][5]==1&&a[aa][ba][ca][da][ea][6]==1&&a[aa][ba][ca][da][ea][7]==1){
								sum++;
							}
						}
					}
				}
			}
		}
	}cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
