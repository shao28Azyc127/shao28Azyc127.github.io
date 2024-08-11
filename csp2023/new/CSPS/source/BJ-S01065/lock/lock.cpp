#include<bits/stdc++.h>
using namespace std;
int sum=1,n,a[10];
int main(){
	//freopen("lock.in","r",stdin);
	//freopen("lock.out","w",stdout);
	cin>>n;
	int i;
	for(int i=0;i<n;i++){
		
		for(int j=0;j<4;j++){
			cin>>a[i];
		}
	}
	sum+=45;
	int aa=0;
	for(int i=0;i<n;i++){	

		for(int j=0;j<4;j++){
			if(j!=4){
				aa=max(a[j],a[j+1]);	
			}
			sum+=9-aa;
		}
	}
	cout<<sum<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}