#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define maxn 3008
using namespace std;
string str[maxn],minn="";
int sum[150]={0};
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str[i];
		memset(sum,0,sizeof(sum));
		for(int j=0;j<m;j++){
			sum[(int)str[i][j]]++;
		}
		//cout<<"ok"<<endl;
		string x;
		for(int j=140;j>=0;j--){
			while(sum[j]--){
				x+=char(j);
			}
		//	cout<<x<<endl;
		}str[i]=x;
		//cout<<"ok"<<endl;
		if(i==1)minn=str[i];
		else minn=min(minn,str[i]);
		//cout<<i<<endl;
	}
	
	for(int i=1;i<=n;i++){
		memset(sum,0,sizeof(sum));
		string s;
		if(str[i]==minn){
			cout<<1;
			continue;
		}
		for(int j=0;j<m;j++){
			sum[(int)str[i][j]]++;
		}
		for(int j=0;j<140;j++){
			while(sum[j]--){
				s+=char(j);
			}
		}
	//	cout<<s;
	//s=str[i];
	//	sort(s.begin(),s.end());
		if(s<=minn) cout<<"1";
		else cout<<"0";
	}
	return 0;
}
