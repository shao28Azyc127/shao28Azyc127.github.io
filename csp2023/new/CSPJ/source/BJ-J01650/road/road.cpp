#include<iostream>
using namespace std;
int a[100000],b[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,d,o=0,m=0;
	cin>>n>>d;
	for(int i=0;i<n-1;i++){
		 cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int i=0,j=1;
	while(i<n){
		while(o<a[j]||b[j]<b[j+1]){
			o+=d;
			m+=b[i];
			j++;
		}
		while(o>a[i]){
			o-=a[i];
			i++;
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
