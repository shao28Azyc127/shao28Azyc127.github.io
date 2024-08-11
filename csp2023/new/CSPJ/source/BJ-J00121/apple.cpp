#include<bits/stdc++.h>
using namespace std;
bool a[1000000005]={};
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int a1,c,b;
	int n;
	cin>>n;
	while(1){
		b++;
		for(int i=0;i<n;i+=2){
			if(a[i]==1){
				break;
			}
			a[i]=1;
			a1++;
			if(a1==n){
				break;
			}
			if(i==n){
				break;
			}
			else{
				c++;
			}
		}
		if(a1==n){
			cout<<b<<" "<<c;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
