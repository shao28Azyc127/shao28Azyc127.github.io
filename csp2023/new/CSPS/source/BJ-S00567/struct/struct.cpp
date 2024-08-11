#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
#define endl '\n'

struct type{
	char name[11];
	int len, shift, amt;
	int typ[111], place[111];
	char nam[105][11];
	unordered_map<string, int> mp;//elem name to type
}d[111];
int D=0;
int r = 0;//storage starting point
int elem[111];
int E=0;
int coord[111];//starting points of elems
unordered_map<string, int> m;//typename to elem index
unordered_map<string, int> mp;//elem name to index


int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	m["byte"] = ++D;
	d[D].len = 1;
	d[D].shift = 1;
	d[D].amt = 0;
	m["short"] = ++D;
	d[D].len = 2;
	d[D].shift = 2;
	d[D].amt = 0;
	m["int"]=++D;
	d[D].len = 4;
	d[D].shift =4;
	d[D].amt = 0;
	m["long"]=++D;
	d[D].len = 8;
	d[D].shift = 8;
	d[D].amt = 0;
	int T;
	cin>>T;
	while(T--){
		int op;
		cin>>op;
		//cout<<"asdf"<<op<<endl;
		if(op==1){
			D++;
			string s;
			cin>>s>>d[D].amt;
			//cout<<d[D].amt<<endl;
			//d[D].name = s;
			strcpy(d[D].name, s.c_str());
			//cout<<"a "<<d[D].amt;
			m[s] = D;
			int j=0;//storage
			int max_shift = 0;
			//cout<<d[D].amt<<endl;
			for(int i = 1; i<=d[D].amt; i++){//calc len, shift
				//	cout<<"i"<<endl;
				string s;
				cin>>s>>d[D].nam[i];
				d[D].mp[s] = i;
				d[D].typ[i] = m[s];
				int sft = d[d[D].typ[i]].shift;
				if(j%sft !=0)
					j = j+sft-j%sft;
				max_shift = max(max_shift, sft);
				d[D].place[i] = j;
				j+=d[d[D].typ[i]].len;
				//cout<<"asdffasd"<<endl;
			}
			d[D].len = j;
			d[D].shift = max_shift;

			cout<<d[D].len<<" "<<d[D].shift<<'\n';
			//return 47;
		}
		else if(op == 2){
				//return 57;
			string t, n;
			cin>>t>>n;
			E++;
			elem[E] = m[t];
			mp[n] = E;
			int sft = d[elem[E]].shift;
			if(r%sft !=0)
				r = r+sft-r%sft;
			coord[E] = r;
			//r+=elem[E].len;
			r+=d[elem[E]].len;
			cout<<coord[E]<<'\n';
		}
		else if(op == 3){
			string s;
			cin>>s;
			int i=0, j=0;
			int n = s.size();
			char tmp[15];
			//string tmps;
			int ans = 0;
			int cur;

			for(j=0; j<n; j++){
				if(s[j] == '.'||j == n-1){
					strcpy(tmp, s.c_str()+i);
					string tmps(tmp);
					int x = mp[tmps];
					ans = d[x].len;
					cur = x;
					break;
				}
			}

			while(j<=n){
				j++;
				if(s[j]=='.'||j==n-1){
					s[j] = 0;
					strcpy(tmp, s.c_str()+i);
					string tmps(tmp);
					int x = d[cur].mp[tmps];
					ans += d[d[cur].typ[x]].len;
					//cout<<s.c_str()+i<<" "<<x<<" "<<d[x].len<<endl;
					i=j+1;
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}
