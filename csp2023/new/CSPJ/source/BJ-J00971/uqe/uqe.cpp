#include<bits/stdc++.h>
using namespace std;
int main(){
    popen("uqe.in","r");
    popen("uqe.out","w"); 
    float T,M,a[100],b[100],c[100];   
    cin>>T>>M;
	for(int i=1;i<=T;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=T;i++){
		if(b[i]*b[i]-4*a[i]*c[i]<0){
			cout<<"NO";
		}
		else{
			cout<<(sqrt(b[i]*b[i]-4*a[i]*c[i])-b[i])/2/a[i];
		}
		cout<<endl;
	}
return 0;
}
