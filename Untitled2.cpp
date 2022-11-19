#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("2.in","r",stdin);
	vector<int> num;
	long long sum=0;
	for(int i=0;i<10;i++){
		int tmp;
		cin>>tmp;
		num.push_back(tmp);
	}
	for(int i=0;i<num.size();i++){
//		cout<<num[i]<<" ";
		sum+=num[i];
	}
	cout<<sum;
	return 0;
}
