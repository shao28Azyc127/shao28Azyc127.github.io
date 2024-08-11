#include<bits/stdc++.h>
using namespace std;
int main(){
	 freopen("apple.in","r",stdin);
	 freopen("apple.out","w",stdout);
	 int n,a[100000001],b[10000001],ans=0,k;
	 cin>>n;
	 for(int i=1;i<=n;i++){
		cin>>a[i];
	 }
	 for(int j=1;j<=n;j++){
		b[j]=0;
	 }
	 if(n==1){
		 cout<<1;
	 }
	 while(a[1]!=0){
		 ans++;
		 for(int i=1;i<=n;i++){
			 if(a[i]!=n){
				 k=ans-1;
			 }
		 }
		 for(int i=1;i<=n;i+=3){
			 a[i]=0;
			 for(int j=1;j<=n;j++){
				 if(a[i]!=0 && b[j]==0){
					b[j]=a[i];
					continue;
				 }
			 }
		 }
		 for(int i=1;i<=n;i++){
			 a[i]=b[i];
			 b[i]=0;
		 }
	 }
	 cout<<ans<<" "<<k;
	 fclose(stdin);
	 fclose(stdout);
	 return 0;
}