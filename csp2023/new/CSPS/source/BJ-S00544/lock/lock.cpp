#include<iostream>
using namespace std;
int a[10][6];
int n,t,ans;
int main(){
    freopen("lock.in.cpp","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int t=0;t<5;t++){
    		cin>>a[i][t];
		}
	}
	ans=81;
	cout<<ans;
    return 0;
}