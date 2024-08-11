#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=0;
unordered_map<string,ll>sz,s2;
unordered_map<string,string>tp;
unordered_map<string,vector<pair<string,string>>>mbs;
int n;
ll nowmx=0;
string s;
ll calc(int l,ll st,string nowtp){
	if(l>=s.size())return st;
	string cur;
	while(l<s.size()&&s[l]!='.')cur+=s[l++];
	l++;
	ll sum=0;
	for(auto i:mbs[nowtp]){
		ll tmp=(sum+s2[i.first]-1)/s2[i.first]*s2[i.first]-sum;
		if(i.second==cur){
			return calc(l,tmp+st,i.first);
		}
		st+=tmp+sz[i.first];
		sum+=tmp+sz[i.first];
	}
	return -1;
}
string clc(ll st,ll addr,string nowtp){
	ll sum=0;
	for(auto i:mbs[nowtp]){
		sum+=(sum+s2[i.first]-1)/s2[i.first]*s2[i.first]-sum;
		if(sz[i.first]+sum+st>addr){
			if(sum+st>addr)return "ERR";
			if(i.first=="byte"||i.first=="short"||i.first=="int"||i.first=="long")return i.second;
			string ans=clc(sum+st,addr,i.first);
			if(ans=="ERR")return "ERR";
			return i.second+"."+ans;
		}
		sum+=sz[i.first];
	}
	return "ERR";
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	sz["byte"]=s2["byte"]=1;
	sz["short"]=s2["short"]=2;
	sz["int"]=s2["int"]=4;
	sz["long"]=s2["long"]=8;
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		if(op==1){
			string name;
			ll cnt,mxsz=0,sum=0;
			cin>>name>>cnt;
			vector<pair<string,string>>m;
			for(int i=1;i<=cnt;i++){
				string tpp,nm;
				cin>>tpp>>nm;
				m.push_back({tpp,nm});
				mxsz=max(mxsz,s2[tpp]);
				sum+=(sum+s2[tpp]-1)/s2[tpp]*s2[tpp]-sum+sz[tpp];
			}
			sum+=(sum+mxsz-1)/mxsz*mxsz-sum;
			sz[name]=sum;
			s2[name]=mxsz;
			mbs[name]=m;
			cout<<sz[name]<<" "<<mxsz<<'\n';
		}
		if(op==2){
			string type,name;
			cin>>type>>name;
			nowmx+=(nowmx+s2[type]-1)/s2[type]*s2[type]-nowmx;
			cout<<nowmx<<"\n";
			tp[name]=type;
			nowmx+=sz[type];
			mbs[""].push_back({type,name});
			s2[""]=max(s2[""],s2[type]);
		}
		if(op==3){
			cin>>s;
			cout<<calc(0,0,"")<<"\n";
		}
		if(op==4){
			ll addr;
			cin>>addr;
			cout<<clc(0,addr,"")<<'\n';
		}
	}
	return 0;
}