#include<bits/stdc++.h>//g++ t1.cpp -o t1 -O2 -std=c++14 -static
using namespace std;
string s[100005];
string Min[100005];
string Max[100005];
bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(char a,char b){
	return a>b;
}
string MaxMin1,MaxMin2;
int p1,p2;
int n,m;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		MaxMin1+='z';
		MaxMin2+='z';
	}
	for(int i=1;i<=n;i++){
		Min[i]=s[i];
		sort(Min[i].begin(),Min[i].end(),cmp1);
	}
	for(int i=1;i<=n;i++){
		Max[i]=s[i];
		sort(Max[i].begin(),Max[i].end(),cmp2);
		if(Max[i]<=MaxMin1){
			p2=p1;
			MaxMin2=MaxMin1;
			p1=i;
			MaxMin1=Max[i];
		}else if(Max[i]<=MaxMin2){
			p2=i;
			MaxMin2=Max[i];
		}
	}
	for(int i=1;i<=n;i++){
		int p;
		if(i==p1){
			p=p2;
			if(Min[i]<MaxMin2){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			p=p1;
			if(Min[i]<MaxMin1){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	cout<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}