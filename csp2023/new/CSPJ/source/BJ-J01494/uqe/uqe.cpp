#include<iostream>
using namespace std;
unsigned long long T,M,i;
double a[100005],b[100005],c[100005];
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	for(i=1;i<=T;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(i=1;i<=T;i++){
		if(b[i]==0&&c[i]==0){
			cout<<"0 1"<<endl;
		}else if(((b[i]*b[i])-(4*a[i]*c[i]))<0){
			cout<<"NO"<<endl;
		}else if(((b[i]*b[i])-(4*a[i]*c[i]))==0){
			cout<<"0 1"<<endl;
		}
	}
	return 0;
}
