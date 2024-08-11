#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

const int MAXN=110;
string s[MAXN][MAXN]; //ith struct, jth variable's name
string tp[MAXN][MAXN]; //ith struct, jth variable's type
map<string,int> w; //how many variables within struct s
map<string,int> l; //struct s's size
map<string,int> m; //struct s's number
map<string,int> nm; //element s's number
string e[MAXN];//ith element's name
map<string,string> t; //element s's type;
map<string,long long> bga; //element s's begin address
int cnt; //how many structs
int c;//how many elements
long long pra=0; //present(last) address

bool bas(string tpe)
{
	if(tpe=="byte"||tpe=="short"||tpe=="int"||tpe=="long") return 1;
	else return 0;
}

int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	cin>>T;
	l["byte"]=1; l["short"]=2; l["int"]=4; l["long"]=8;
	while(T--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			string tpn;
			cin>>tpn;
			m[tpn]=++cnt;
			int k;
			cin>>k;
			w[tpn]=k;
			int sz=0;
			for(int i=1;i<=k;i++)
			{
				cin>>tp[cnt][i]>>s[cnt][i];
				sz=max(sz,l[tp[cnt][i]]);
			}
			cout<<sz*k<<' '<<sz<<endl;
			sz*=k;
			l[tpn]=sz;
		}
		if(op==2)
		{
			c++;
			string st,n;
			cin>>st>>n;
			e[c]=n;
			nm[n]=c;
			t[n]=st;
			pra=(pra%l[st]==0?pra+l[st]:(pra/l[st]*l[st]+l[st]*2));//calculate address
			bga[n]=pra-l[n]+1;
			cout<<bga[n]-1<<endl;
		}
		if(op==3)
		{
			string str;
			cin>>str;
			int len=str.size();
			int ans=0;
			string ele="";
			int i;
			int dts=0;
			for(i=0;i<len;i++) dts+=(str[i]=='.');
			if(dts==0) {cout<<bga[str]-1; continue;}
			for(i=0;i<len;i++)
			{
				if(str[i]!='.') ele+=str[i];
				else break;
			}
			i++;
			string tpn="";
			ans=bga[ele];
			string te=t[ele];
			for(int k=1;k<=dts&&i<len;i++)
			{
				if(str[i]!='.') tpn+=str[i];
				if(str[i]=='.'||i==len-1)
				{
					k++;
					int paa;
					for(int j=1;j<=w[te];j++)
					{
						if(s[m[te]][j]==tpn) {paa=j; break;}
					}
					ans+=(paa-1)*l[te]/w[te];
					te=tp[m[te]][paa];
					tpn="";
				}
			}
			cout<<ans<<endl;
		}
		if(op==4)
		{
			int tadd;
			cin>>tadd;
			tadd++;
			if(tadd>pra) {cout<<"ERR\n"; continue;}
			int na=0;
			string ele;
			bool fl=0;
			for(int i=1;i<=c;i++)
			{
				if(tadd>na&&tadd<bga[e[i]]) {cout<<"ERR\n"; fl=1; break;}
				if(tadd>=bga[e[i]]) {i++; na=bga[e[i]]-1+l[t[e[i]]];}
				else {ele=i-1; break;}
			}
			if(fl==1) continue;
			cout<<ele;
			string te=t[ele];
			tadd=tadd-bga[ele]+1;
			while(!bas(te))
			{
				cout<<'.';
				int nd=(tadd%(l[te]/w[te])==0?tadd/(l[te]/w[te]):tadd/(l[te]/w[te])+1);
				cout<<s[m[te]][nd];
				ele=s[m[te]][nd];
				te=tp[m[te]][nd];
			}
			cout<<endl;
		}
	}
	return 0;
}
