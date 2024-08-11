#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	string name;
	long long addl,addr;
};
vector<node>m;
long long adcnt;
int lx(string xx){
	if(xx=="byte"){
		return 1;
	}
	if(xx=="short"){
		return 2;
	}
	if(xx=="int"){
		return 4;
	}
	if(xx=="long"){
		return 8;
	}
	return 0;
}
void solve1(){
	string s;
	int k;
	cin >> s >> k;
	int dq=0;
	string t[110],nm[110];
	for(int i = 1; i <= k; i++){
		cin >> t[i] >> nm[i];
		dq=max(dq,lx(t[i]));
	}
	cout << dq*k <<" "<< dq <<"\n";
	for(int i = 1; i <= k; i++){
		node tmp={nm[i],adcnt,adcnt+lx(t[i])-1};
		adcnt+=dq;
		m.push_back(tmp);
	}

}
void solve2(){
	string t, nm;
	cin >> t >> nm;
	int dq=lx(t);
	cout << adcnt <<"\n";
	node tmp={nm,adcnt,adcnt+dq-1};
	adcnt+=dq;
	m.push_back(tmp);
}
void solve3(){
	string q;
	cin >> q;
	if(q.find('.')>=0 && q.find('.')<1ll*n){
		string qq=q;
		for(int i = qq.find('.')+1; i < n; i++){
			q+=qq[i];
		}
	}
	for(int i = 0; i < m.size(); i++){
		if(m[i].name==q){
			cout << m[i].addl <<"\n";
		}
	}
	
}
void solve4(){
	long long addr;
	cin >> addr;
	int l = 0, r = m.size();
	int mid = (l+r)/2;
	while(l<=r){
		mid=(l+r)/2;
		if(m[mid].addl<=addr && addr<=m[mid].addr){
			break;
		}else if(m[mid].addl>addr){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if(m[mid].addl<=addr && addr<=m[mid].addr){
		cout << m[mid].name\n";
	}else{
		cout <<"ERR\n";
	}
}
int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout <<"["<<lx("int")<<" "<<lx("byte")<<"]\n";
	cin >> n;
	while(n--){
		int op;
		cin >> op;
		if(op==1) solve1();
		else if(op==2) solve2();
		else if(op==3) solve3();
		else if(op==4)	solve4();
	}
	return 0;
}