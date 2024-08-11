#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;
const int NR=1e2+5;
typedef long long LL;
struct Lei
{
	int k;
	LL st[NR],len[NR];
	int l[NR];
	string s[NR];
	LL B,LEN;
}lei[NR];
int numl=4;
map<string,int> mpl;
struct Bian
{
	string s;
	LL st;
	int l;
}bian[NR];
int numb;
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	mpl["byte"]=1;
	mpl["short"]=2;
	mpl["int"]=3;
	mpl["long"]=4;
	lei[1].k=-1,lei[1].B=1,lei[1].LEN=1;
	lei[2].k=-1,lei[2].B=2,lei[2].LEN=2;
	lei[3].k=-1,lei[3].B=4,lei[3].LEN=4;
	lei[4].k=-1,lei[4].B=8,lei[4].LEN=8;
	int Q;cin>>Q;
	LL nw=0;
	while(Q--)
	{
		int op;cin>>op;
		if(op==1)
		{
			++numl;
			string s;cin>>s;
			mpl[s]=numl;
			cin>>lei[numl].k;
			int k=lei[numl].k;
			lei[numl].B=0;
			for(int i=1;i<=k;++i)
			{
				string t,n;
				cin>>t>>n;
				lei[numl].s[i]=n;
				lei[numl].l[i]=mpl[t];
				lei[numl].B=max(lei[numl].B,lei[lei[numl].l[i]].B);
			}
			lei[numl].st[1]=0,lei[numl].len[1]=lei[lei[numl].l[1]].LEN;
			for(int i=2;i<=k;++i)
			{
				LL o=lei[numl].st[i-1]+lei[numl].len[i-1];
				o=((o-1)/lei[lei[numl].l[i]].B+1)*lei[lei[numl].l[i]].B;
				lei[numl].st[i]=o;
				//cout<<o<<endl;
				lei[numl].len[i]=lei[lei[numl].l[i]].LEN;
				//printf("%d %d\n",lei[numl].st[i],lei[numl].len[i]);
			}
			lei[numl].LEN=((lei[numl].st[k]+lei[numl].len[k]-1)/lei[numl].B+1)*lei[numl].B;
			cout<<lei[numl].LEN<<' '<<lei[numl].B<<'\n';
		}
		if(op==2)
		{
			string t,n;cin>>t>>n;
			++numb;
			bian[numb].s=n,bian[numb].l=mpl[t];	
			bian[numb].st=(nw+lei[bian[numb].l].B-1)/lei[bian[numb].l].B*lei[bian[numb].l].B;
			nw=bian[numb].st+lei[bian[numb].l].LEN;
			//cout<<nw<<endl;
			cout<<bian[numb].st<<'\n';
		}
		if(op==3)
		{
			string s;cin>>s;
			string t;
			int nwl=0;
			LL ans=0;
			s+='.';
			for(int i=0;i<s.size();++i)
			{
				if(s[i]=='.')
				{
					//cout<<t<<endl;
					//cout<<nwl<<endl;
					if(nwl==0)
					{
						for(int j=1;j<=numb;++j)
						{
							if(bian[j].s==t)
							{
								nwl=bian[j].l;
								ans+=bian[j].st;
								break;
							}
						}
					}
					else
					{
						for(int j=1;j<=lei[nwl].k;++j)
						{
							if(lei[nwl].s[j]==t) 
							{
								//printf("%d\n",j);
								ans+=lei[nwl].st[j];
								nwl=lei[nwl].l[j];
								break;
							}
						}
					}
					t="";
				}
				else
				{
					t+=s[i];
				}
			}
			cout<<ans<<endl;
		}
		if(op==4)
		{
			LL addr;cin>>addr;
			int nwl=0;
			string ans;
			while(nwl<1||nwl>4)
			{
				if(nwl==0)
				{
					int x=-1;
					for(int i=1;i<=numb;++i)
					{
						if(bian[i].st<=addr&&addr<bian[i].st+lei[bian[i].l].LEN) {x=i;break;}
					}
					if(x==-1) {ans="ERR";break;}
					ans+=bian[x].s;
					nwl=bian[x].l;
					addr-=bian[x].st;
					if(nwl>4) ans+='.';
				}
				else
				{
					int x=-1;
					for(int i=1;i<=lei[nwl].k;++i)
					{
						if(lei[nwl].st[i]<=addr&&addr<lei[nwl].st[i]+lei[nwl].len[i])
						{
							x=i;break;
						}
					}
					if(x==-1) {ans="ERR";break;}
					ans+=lei[nwl].s[x];
					addr-=lei[nwl].st[x];
					nwl=lei[nwl].l[x];
					if(nwl>4) ans+='.';
					
				}
			}
			cout<<ans<<endl;
		}
	}
	/*
	for(int i=1;i<=numl;++i)
	{
		cout<<lei[i].B<<' '<<lei[i].LEN<<'\n';
	}
	for(int i=1;i<=numb;++i)
	{
		cout<<bian[i].s<<endl;
		cout<<bian[i].st<<' '<<bian[i].l<<'\n';
	}
	*/
	return 0;
}