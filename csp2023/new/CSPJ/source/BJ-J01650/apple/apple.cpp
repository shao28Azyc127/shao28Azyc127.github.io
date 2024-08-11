#include<iostream>
using namespace std;
int a[100000000];
int n,c,d;
bool e(){
	for(int i=0;i<n;i++){
		if(a[i]) return true;
	}
	return false;
}
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		a[i]=1;
	}
	while(e()){
		int l=3;
		for(int i=0;i<n;i++){
			if(!a[i]) continue;
			if(l==3){
				l=1;
				a[i]=0;
			}
			else
			{
				l++;
			}
			if(i==n-1) c=d+1;
		}
		d++;
	}
	cout<<d<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
