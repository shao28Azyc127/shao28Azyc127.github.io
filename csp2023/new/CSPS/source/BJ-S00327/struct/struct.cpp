#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int n;
int op;
int kk=0;
map<string,int> id;
string s;
struct wow{
	int type,id;
};
struct node{
	//int st,siz,mxp;
	ll l,r;
	string id;
	//map<string,int> id;
	//vector<wow> mem;
}st[N];
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	scanf("%d",&n);
	int i,j,k,mxp,tc,len;
	wow tmp;
	ll pos=0,tp;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&op);
		/*if(op<=1)
		{
			if(op==1) {
				cin>>s;
				id[s]=++kk;
				scanf("%d",&k);
				st[kk].siz=k;
			}
			else {
				++kk;
				st[kk].siz=(k=1);
			}
			mxp=1;
			tc=0;
			for(j=1;j<=k;j++)
			{
				cin>>s;
				if(s[0]=='b') tmp.type=1,mxp=max(mxp,1);
				else if(s[0]=='s') tmp.type=2,mxp=max(mxp,2);
				else if(s[0]=='i') tmp.type=4,mxp=max(mxp,4);
				else tmp.type=8,mxp=max(mxp,8);
				cin>>s;
				st[kk].id[s]=++tc;
				tmp.id=tc;
				st[kk].mem.push_back(tmp);
			}
			st[kk].st=pos;
			st[kk].mxp=mxp;
			pos=0;
			for(j=0;j<k;j++)
			{
				if(st[kk].mem[j].type==1) ++pos;
				else if(st[kk].mem[j].type==2) {
					if(pos%2) pos+=(2-pos%2);
					pos+=2;
				}
				else if(st[kk].mem[j].type==4) {
					if(pos%4) pos+=(4-pos%4);
					pos+=4;
				}
				else {
					if(pos%8) pos+=(8-pos%8);
					pos+=8;
				}
			}
			printf("%d %d\n",pos,st[kk].mxp);
		}
		*/
		if(op==2)
		{
			cin>>s;
			++kk;
			if(s[0]=='b') {
				st[kk].l=pos,st[kk].r=pos;
				pos++;
			}
			else if(s[0]=='s') {
				if(pos%2) pos+=(2-pos%2);
				st[kk].l=pos,st[kk].r=pos+1;
				pos+=2;
			}
			else if(s[0]=='i') {
				if(pos%4) pos+=(4-pos%4);
				st[kk].l=pos,st[kk].r=pos+3;
				pos+=4;
			}
			else {
				if(pos%8) pos+=(8-pos%8);
				st[kk].l=pos,st[kk].r=pos+7;
				pos+=8;
			}
			cin>>st[kk].id;
			printf("%lld\n",st[kk].l);
		}
		else if(op==4)
		{
			scanf("%lld",&tp);
			for(j=1;j<=kk;j++)
			{
				if(st[j].l<=tp&&st[j].r>=tp) 
				{
					cout<<st[j].id<<"\n";
					break;
				}
			}
			if(j>kk) puts("ERR");
		}
	}
	return 0;
}
