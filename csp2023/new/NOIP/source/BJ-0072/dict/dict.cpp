#include<bits/stdc++.h>
using namespace std;
string s[3005];
string rev_s[3005];
struct node{
	string s;
	int id,op;
}b[6005];
int pos[3005];
bool cmp(node x,node y){
	if(x.s!=y.s) return x.s<y.s;
	else if(x.id!=y.id) return x.id<y.id;
	else return x.op<y.op;
}
int cnt[32];
int bcnt=0;
set<int>S;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int tmp=s[i].size();
		for(int j=0;j<26;j++) cnt[j]=0;
		for(int j=0;j<tmp;j++) cnt[s[i][j]-'a']++;
		s[i]="";
		for(int j=0;j<26;j++){
			for(int k=1;k<=cnt[j];k++){
				s[i]=s[i]+(char)('a'+j);
			}
		}
		b[++bcnt]=(node){s[i],i,0};
		rev_s[i]=s[i];
		reverse(rev_s[i].begin(),rev_s[i].end());
		b[++bcnt]=(node){rev_s[i],i,1};
	}
	sort(b+1,b+1+bcnt,cmp);
	for(int i=1;i<=bcnt;i++){
		if(b[i].op==1){
			S.insert(i);
			pos[b[i].id]=i;
		}
	}
	if(n==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		S.erase(pos[i]);
		int tmp=*S.begin();
		if(s[i]<b[tmp].s){
			printf("1");
		}
		else printf("0");
		S.insert(pos[i]);
	}
	puts("");
	return 0;
}