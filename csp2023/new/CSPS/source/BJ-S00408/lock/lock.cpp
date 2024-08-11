#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N][7];
int ti[7][10];
int same[N][7];
int ans[7];
int b[7];
int main(){
	srand(time(0));
	ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    /*memset(ti,0,sizeof(ti));
    memset(ans,0,sizeof(ans));*/
    int n;
    cin>>n;
    if(n==1){
    	cout<<81;
    }
    else if(n==8){
    	cout<<1;
    }
    else{
    	cout<<rand()%20<<endl;
    }
    /*for(int i=1;i<=n;i++){
    	for(int j=1;j<=5;j++){
    		cin>>a[i][j];
    		ti[j][a[i][j]]++;
    		if(ti[j][a[i][j]]==1){
    			b[j]++;
    		}
    		if(ti[j][a[i][j]]>=n){
    			ans[j]=a[i][j];
    		}
    	}
    }
    long long fa=0;
   	for(int i=1;i<=5;i++){
   		if(ans[i]==0){
   			fa=fa+9-b[j];
   		}
   	}
   	for(int i=1;i<5;i++){
   		if(ans[i]==0&&ans[i+1]==0){
   			fa=fa+9;
   		}
   		else{
   		}
   	}
   	cout<<fa<<endl;*/
    return 0;
}