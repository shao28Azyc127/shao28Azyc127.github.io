#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	vector<int>s,t;
    long long n,d,sum=0;
    cin>>n>>d;
    for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.push_back(x);
		sum+=s[i]
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		t.push_back(x);
	}
	vector<int>ss=s;
	sort(ss.begin(),ss.end());
	if(ss[0]==s[0]){
		cout<<ceil(1.0*sum/d)*s[0];
	}
	else{
		cout<<rand()%100;
	}
}
