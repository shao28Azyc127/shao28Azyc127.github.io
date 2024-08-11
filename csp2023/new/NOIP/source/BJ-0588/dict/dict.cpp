#include<bits/stdc++.h>
#define N 3050
using namespace std;
char a[N][N];
int b[N][26];
int st[N],ed[N],edmi[26];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m,k,sst,eed,edmmi,edmminum;
	edmmi=1e9;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	memset(edmi,3001,sizeof(edmi));
	for(int i=0;i<n;i++){
		sst=25;eed=0;
		for(int j=0;j<m;j++){
			k=a[i][j];
			if(k-'a'>eed)eed=k-'a';
			if(k-'a'<sst)sst=k-'a';
			b[i][k-'a']++;
		}
		st[i]=sst;
		ed[i]=eed;
		if(eed<edmmi){
			edmmi=eed;
			edmminum=i;
		}
		if(b[i][eed]<edmi[eed])edmi[eed]=b[i][eed];
	}
	for(int i=0;i<n;i++){
		if(st[i]>=edmmi&&edmminum!=i){
			cout<<"0";
			continue;
		}
		else{
			cout<<"1";
			continue;
		}
	}
	/*cout<<endl;
	for(int i=0;i<n;i++)
		cout<<st[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<ed[i]<<" ";
	cout<<endl;
	cout<<"edmmi:"<<edmmi<<endl;*/
	return 0;
}