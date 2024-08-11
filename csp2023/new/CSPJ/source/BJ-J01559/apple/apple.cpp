#include <bits/stdc++.h>
using namespace std;
int main(){
 freopen("apple.in","r",stdin);
  freopen("apple.ans","w",stdout);
    int n,r=0,d=0,x=0;cin>>n; bool a[n];
 			int js=0; 
	for(int i=0;i<=n;i++){
		a[i]=1;
	}
	while(x!=n){
		x=0;
		js=2;
		for(int j=0;j<n;j++){
			
					  if (a[j]==1&&js<2) js++;
			          else if (a[j]==1&&js==2){ a[j]=0; js=0;}
//      					if(a[n]==0) r=d;  
			
		}
		for(int i=0;i<n;i++){
			if(a[i]==0) x++;
		}

		//if(x==n) break;
//		if(a[n]==0) rem=d;
		d++;
		if(a[n]==0) r=d;  
			
//		cout<<d<<endl;
	}
	if(r==0) r=d;
	cout<<d<<" "<<r<<endl;
    return 0;
}
