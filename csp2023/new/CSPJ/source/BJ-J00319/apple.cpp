#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long a,c=2,b=2;
	cin>>a;
	if(a==1){
		cout<<1<<" "<<1;
		
	} if(a==2){
		cout<<2<<" "<<2;
	} else{
		while(b<a){
				c+=1;
				b+=c;
			
		}
		cout<<c+1;
		if(a%3==1){
				cout<<1;
			
		} else{
				cout<<c+1;
			
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;

}
