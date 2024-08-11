#include<bits/stdc++.h>

using namespace std;

int apple[10000000],eapple[10000000];
int day=1,x=1;

void rm(int j,int n){
	for(int i=j;i<=n;i++){
		apple[i]=apple[i+1];
	}
}

int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	apple[0]=0;
	int x;
	cin>>x;
	for(int i=1;i<=x;i++){
		apple[i]=i;
	}
	int nn,nn2=0;
	nn=x;
	int n=1;
	int rmf=0;
	while(nn>0){
		nn2=nn;
		for(int i=1;i<=nn2;i++){
			if(i%3==1){
				eapple[n]=i;
				cout<<apple[eapple[n]]<<" ";
				n++;
			}
		}
		for(int k=1;k<=n;k++){
			if(apple[eapple[k]]==x){
				rmf++;
				rm(apple[k],nn);
				cout<<day;
			}
			else{
				//cout<<apple[eapple[k]-rmf]<<" ";
				rm(apple[eapple[k]-rmf],nn);
				rmf++;
				nn--;
			}
		}
		rmf=0;
		n=1;
		day++;
	}
	cout<<day<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
