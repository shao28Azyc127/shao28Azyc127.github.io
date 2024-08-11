#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 109;
int T;
struct node{
	ll siz, mem;
	vector<string> v;
};
struct node2{
	string t;
	ll loc;
};
map<string, node> s;
map<string, node2> m;
ll use;
int len;
char way[20];
ll sormem;
vector<string> sor;
int main(){
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	s["byte"].siz = 1;
	s["short"].siz = 2;
	s["int"].siz = 4;
	s["long"].siz = 8;
	cin>>T;
	while(T--){
		int opt;
		scanf("%d", &opt);
		if(opt==1){
			int k;
			ll mx = 0;
			string nm;
			cin>>nm;
			scanf("%d", &k);
			node temp;
			for(int i=1; i<=k; ++i){
				string snm;
				cin>>snm;
				temp.v.push_back(snm);
				mx = max(mx, s[snm].siz);
			}
			temp.siz = mx;
			temp.mem = k;
			s[nm] = temp;
			printf("%lld %lld\n", mx*k, mx);
		}else if(opt==2){
			string tp, nm;
			cin>>tp>>nm;
			sor.push_back(nm);
			++sormem;
			node2 temp;
			temp.t = tp;
			temp.loc = use + 1;
			m[nm] = temp;
			printf("%lld", use+1);
			use += s[tp].siz * s[tp].mem;
		}else if(opt==3){
			bool fst = 0;
			ll nowloc = 0;
			string nowtp;
			string r, poi;
			cin>>r;
			int rlen = r.length();
			for(int i=0; i<rlen; ++i){
				if(r[i]=='.'){
					poi = way;
					for(int j=len-1; ~i; --i) way[j] = '\0';
					len = 0;
					
					if(!fst){
						fst = 1;
						nowloc = m[poi].loc;
						nowtp = m[poi].t;
					}else{
						node temp = s[nowtp];
						for(int j=0; j<temp.v.size(); ++j){
							if(temp.v[j]==poi){
								break;
							}else{
								nowloc += temp.siz;
							}
						}
					}
				}else{
					way[len] = r[i];
					++len;
				}
			}
			printf("%lld\n", nowloc);
		}else{
			cout<<"ERR\n";
		}
	}
	return 0;
}
