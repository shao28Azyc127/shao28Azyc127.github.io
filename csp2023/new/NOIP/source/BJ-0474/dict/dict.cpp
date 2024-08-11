#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <cstdio>
using namespace std;
int n,m;
int a[3005][30];
int mx[30],rem=1e9,mxv,pd1=0,pd2=0;
int smx[30],mxs[3005],smxs[3005];
int b[3005];
char c;
bool comp(int o[],int p[]){
	int itr=0;
	while(o[itr]==p[itr]&&itr<m){
		itr++;
	}
	return o[itr]<p[itr];
}
bool compnum(int o[],int p[]){
	int itr=25;
	while(o[itr]==p[itr]&&itr>0){
		itr--;
	}
	return o[itr]<p[itr];
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    mx[25]=m+1;
    mx[25]=m+1;
    if(n==1){
		cout<<1;
		return 0;
	}
    for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>c;
			a[i][(int)c-'a']++;
		}
		/*for(int j = 0;j<26;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl<<"mx";
		for(int i = 0;i<26;i++){
			cout<<mx[i]<<" ";
		}
		cout<<endl<<"  ";*/
		if(compnum(a[i],mx)){
			mxv=i;
			for(int j = 0;j<26;j++){
				smx[j]=mx[j];
				mx[j]=a[i][j];
			}
		}else if(compnum(a[i],smx)){
			smx[m]=0;
			for(int j = 0;j<26;j++){
				smx[j]=a[i][j];
			}
		}
	}
	//cout<<"----"<<endl;
	for(int j = 25,k=0;j>=0;j--){
		for(int l = 0;l<mx[j];l++){
			mxs[k]=j;
			k++;
		}
	}
	for(int j = 25,k=0;j>=0;j--){
		for(int l = 0;l<smx[j];l++){
			smxs[k]=j;
			k++;
		}
	}
	/*cout<<"smx:"<<endl;
	for(int i = 0;i<26;i++){
		cout<<smx[i]<<" ";
	}
	cout<<endl;
	for(int i = 0;i<m;i++){
		cout<<(char)(smxs[i]+'a');
	}
	cout<<endl<<"mx:";
	for(int i = 0;i<26;i++){
		cout<<mx[i]<<" ";
	}
	cout<<endl;
	for(int i = 0;i<m;i++){
		cout<<(char)(mxs[i]+'a');
	}
	cout<<endl<<endl;*/
	for(int i = 0;i<n;i++){
		for(int j = 0,k=0;j<26;j++){
			for(int l = 0;l<a[i][j];l++){
				b[k]=j;
				k++;
			}
		}
		/*for(int j = 0;j<m;j++){
			cout<<(char)(b[j]+'a');
		}
		cout<<endl;*/
		if(i!=mxv){
			cout<<(comp(b,mxs)?1:0);
			//cout<<endl;
		}else{
			cout<<(comp(b,smxs)?1:0);
			//cout<<endl;
		}
	}
    return 0;
}
