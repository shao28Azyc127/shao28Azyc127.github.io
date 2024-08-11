#include<bits/stdc++.h>
using namespace std;
int N=1000000000;
int n,m;//station,liter to kilometer
vector<int>sta;
vector<int>oil;
int min1;
/*5 4
10 10 10 10
9 8 9 6 5*/
int main(){
freopen("roud.in","r",stdin);
freopen("roud.out","w",stdout);
	cin>>n>>m;
	min1=N;
	int sum1=0;
	int a;
	for(int i=1;i<n;i++){
		scanf("%d",&a);
		sum1+=a;
		sta.push_back(a);
	} 
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		oil.push_back(a);
	}
int kkk=sum1/oil[0];
if(kkk*oil[0]!=sum1)
kkk++
	cout<<kkk;
	return 0;	
}