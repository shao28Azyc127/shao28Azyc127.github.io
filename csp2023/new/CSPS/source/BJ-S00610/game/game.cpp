#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<vector>
using namespace std;
vector <char> v;
int n,i,j;
char t,a[2000099];
bool flag;
vector<char>::iterator it=v.begin();
vector<char>::iterator it2=it;
bool gameend(){
	if(v.empty())return true;
	for(int i=0;i<(v.size()-1);i++){
		if(v[i]==v[i+1])return false;
	}
	return true;
}
void pret(){
	for(int i=0;i<v.size();i++){
		if(v[i]==v[i+1]){
			int j=i;
			it2=it;
			cout<<"12";
			do{
				it2++;
				j++;	
				cout<<"123";				
			}while(v[j]==v[i]);
			cout<<"1234";
			v.erase(it,it2);
			cout<<"12345";
			for(vector<char>::iterator it=v.begin();it<=v.end();it++){
				cout<<*it;
			}
			return;
		}
		++it;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	cin>>a;
	for(i=0;i<n;i++){
		v.push_back(a[i]);
	}
	if(gameend()){
		cout<<0;
		return 0;
	}
	
	while(!gameend()){
		pret();	
	}
	printf("%d",n-v.size());
	for(vector<char>::iterator it=v.begin();it<=v.end();it++){
		cout<<*it;
	}
	return 0;
}