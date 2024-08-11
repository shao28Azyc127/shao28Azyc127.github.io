#include<bits/stdc++.h>
#define pi(x) freopen(x,"r",stdin);
#define po(x) freopen(x,"w",stdout);
#define ci() fclose(stdin);
#define co() fclose(stdout);
using namespace std;
const int N=3010;
int n,m;
struct word{
	string sp;
	string min_s,max_s;
	int ind;
	char min_c;
}s[N];
bool ans[N];
bool cmp(char a,char b){
	return a>b;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].sp;
		s[i].ind=i;
	}
	//~ sort(s+1,s+n+1);
	
	for(int i=1;i<=n;i++){
		string temp_s=s[i].sp;
		sort(temp_s.begin(),temp_s.end());
		s[i].min_s=temp_s;
		sort(temp_s.begin(),temp_s.end(),cmp);
		s[i].max_s=temp_s;
		//~ cout<<i<<" "<<s[i].min_s<<" "<<s[i].max_s<<endl;
	}
	
	for(int i=1;i<=n;i++){
		bool can=1;
		for(int j=1;j<=n;j++){
			if(s[i].min_s>=s[j].max_s&&i!=j) can=0;   //如果我字典需最小的排列都比他字典需最大的派列大
		}
		ans[i]=can;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
}

int main(){
	pi("dict.in");
	po("dict.out");
	ios::sync_with_stdio(false);
	solve();
	ci();
	co();
}
