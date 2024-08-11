#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=n;i++)

int n;
struct typ{
	int size;
	int duiqi;
	int ysnum;
	string ysname[105];
	map<string,int> ystyp;
}t[105];
int cnt = 4;
struct yuansu{
	int type;//1=>byte 2=>short 3=>int 4=>long
	string name;
	ll addr;
	int father;
}y[105];
ll cadr = 0;
int yscnt = 0;
map<string,int> a;
map<string,int> b;

void dfys(int tt, string n){
//	cout<<tt<<" "<<n<<endl;
	y[++yscnt].type = tt;
	a[n] = yscnt;
	y[yscnt].name = n;
	if(cadr % t[tt].duiqi == 0) y[yscnt].addr = cadr;
	else y[yscnt].addr = (cadr/t[tt].duiqi+1) * t[tt].duiqi;
	if(t[tt].ysnum>0){
		rep(i, t[tt].ysnum){
			string tpnm = t[tt].ysname[i];
			string new_n = n+"."+tpnm;
//			cout<<t[tt].ystyp[tpnm]<<" "<<new_n<<endl;
			dfys(t[tt].ystyp[tpnm], new_n);
		}
	}
	else cadr = y[yscnt].addr + t[tt].size;
}

int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
	
	t[1].size=t[1].duiqi=1;
	t[2].size=t[2].duiqi=2;
	t[3].size=t[3].duiqi=4;
	t[4].size=t[4].duiqi=8;
	b["byte"]=1;
	b["short"]=2;
	b["int"]=3;
	b["long"]=4;
	cin>>n;
	while(n--){
		int op;
		cin>>op;
		if(op == 1){
			string s; 
			int k;
			cin>>s;
			cin>>k;
			cnt++;
			b[s]=cnt;
			t[cnt].ysnum = k;
			rep(i,k){
				string tt,aa;
				cin>>tt>>aa;
				t[cnt].ystyp[aa] = b[tt];
				t[cnt].ysname[i] = aa;
				if(t[cnt].size % t[b[tt]].duiqi != 0)
					t[cnt].size = (t[cnt].size/t[b[tt]].duiqi+1)*t[b[tt]].duiqi + t[b[tt]].size;
				else t[cnt].size += t[b[tt]].size;
				t[cnt].duiqi = max(t[cnt].duiqi, t[b[tt]].duiqi);
			}
			cout<<t[cnt].size<<" "<<t[cnt].duiqi<<endl;
		}
		if(op == 2){
			string tt, n;
			int tmp = yscnt+1;
			cin>>tt>>n;
			dfys(b[tt], n);
			cout<<y[tmp].addr<<endl;
		}
		if(op == 3){
			string s;
			cin>>s;
			cout<<y[a[s]].addr<<endl;
		}
		if(op == 4){
			ll adr;
			cin>>adr;
			rep(i, yscnt){
//				cout<<y[i].name<<" "<<y[i].addr<<endl;
				if(adr >= y[i].addr && ( adr < y[i+1].addr || i == yscnt) ){
					if(adr < y[i].addr + t[y[i].type].size){
						cout<<y[i].name<<endl;
						break;
					}
					else{
						cout<<"ERR"<<endl;
						break;
					}
				}
				if(i==yscnt) cout<<"ERR"<<endl;
			}
		}
	}
	
    return 0;
}
