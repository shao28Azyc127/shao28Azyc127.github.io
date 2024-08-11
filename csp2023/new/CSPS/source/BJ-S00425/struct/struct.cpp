

#include <bits/stdc++.h>

using namespace std;

int n;
int m;
bool A = true;
bool B = true;
bool C = true;
bool D = true;
int Bcounter;
char op;
struct newid{
	string name;
	string type;
	long long l;
	long long r;
} ti[109];
int cc = 0;
struct cz{
	int op;
	string s;
	int number;
	string kind;
	string ming;
	string name[109];
	string typ[109];
	int maxim;
	int totalcost;
	string ast; //asktype -> 2
	string asn; //askname
	string ase; //askelement
	long long asa; //askaddress
	string distri[1009];
} ids[109];
long long curplace;

void findaddr(string name , string type , long long l , long long r){
	cz a;
	for(int i = 1; i <= n; i++){
		if(ids[i].s == name){
			a = ids[i];
		}
	}
	string qf = "";
	string req = "";
	int countt = 0;
	while(type[countt] != '.' && countt < type.length()){
		qf += type[countt];
		countt ++;
	}
	for(int i = countt + 1; i < type.length(); i ++){
		req += type[i];
	}
	if(req == ""){
		for(int i = 1; i <= a.number; i++){
			if(a.name[i] == qf){
				cout << l + (i - 1) * a.maxim << endl;
			}
		}
	}else{
		for(int i = 1; i <= a.number; i++){
			if(a.name[i] == qf){
				findaddr(a.typ[i] , req , l + (i - 1) * a.maxim , l + i * a.maxim - 1);
			}
		}
	}
}

bool findname(long long addr , long long l , long long r , int id){
	newid a;
	a = ti[id];
	cz aa;
	for(int i = 1; i <= n; i++){
		if(ids[i].s == ti[id].type){
			aa = ids[i];
			break;
		}
	}
	for(int i = 1; i <= aa.number; i++){
		int l = l  + (i - 1) * a.maxim;
		int r = l + i * a.maxim - 1;
		if(l <= addr && addr <= r){
			if(ti[k].type == "int" || ti[k].type == "long" || ti[k].type == "short" || ti[k].type == "byte"){
				cout << ti[k].name;
			}else{
				cout << ti[k].name << '.';
				findname(addr , l , r , id);
			}
		}
	}
}

int main(){
	freopen("struct.in" , "r" , stdin);
	freopen("struct.out", "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> ids[i].op;
		int op = ids[i].op;
		if(op == 1){
			A = false;
			Bcounter ++;
			if(Bcounter > 1){
				B = false;
			}
			cin >> ids[i].s >> ids[i].number;
			for(int j = 1; j <= ids[i].number; j++){
				cin >> ids[i].typ[j] >> ids[i].name[j];
				if(ids[i].typ[j] == "int"){
					ids[i].maxim = max(ids[i].maxim , 4);
				}else if(ids[i].typ[j] == "long"){
					ids[i].maxim = max(ids[i].maxim , 8);
				}else if(ids[i].typ[j] == "char"){
					ids[i].maxim = max(ids[i].maxim , 2);
				}else if(ids[i].typ[j] == "byte"){
					ids[i].maxim = max(ids[i].maxim , 1);
				}else{
					for(int k = 1; k <= n; k++){
						if(ids[k].s == ids[i].typ[j]){
							ids[i].maxim = max(ids[i].maxim, ids[k].totalcost);
						}
					}
				}
				if(ids[i].typ[j] != "short" && ids[i].typ[j] != "int" && ids[i].typ[j] != "long" && ids[i].typ[j] != "byte"){
					C = false;
				}
				if(ids[i].typ[j] != "long"){
					D = false;
				}
			}
			ids[i].totalcost = ids[i].maxim * ids[i].number;
			cout << ids[i].totalcost << ' ' << ids[i].maxim << endl;
			
	// zhe li hai you di zhi fen bu mei you xie
	
		}else if(op == 2){
			cin >> ids[i].kind >> ids[i].ming;
			cout << curplace << endl;
			cc ++;
			ti[cc].name = ids[i].ming;
			ti[cc].type = ids[i].kind;
			ti[cc].l = curplace; 
			if(ids[i].kind == "int"){
				curplace += 4;
			}else if(ids[i].kind == "long"){
				curplace += 8;
			}else if(ids[i].kind == "short"){
				curplace += 2;
			}else if(ids[i].kind == "byte"){
				curplace += 1;
			}else{
				for(int k = 1; k <= n; k ++){
				 	if(ids[k].s == ids[i].kind){
				 		curplace += ids[k].totalcost;
				 	}
				}
			}
			ti[cc].r = curplace - 1;
		}else if(op == 3){
			cin >> ids[i].ase;
			string qf = "";
			int cnt = 0;
			while(ids[i].ase[cnt] != '.' && cnt < ids[i].ase.length()){
				qf += ids[i].ase[cnt];
				cnt ++;
			}
			string req = "";
			for(int m = cnt + 1; m < ids[i].ase.length(); m++){
				req += ids[i].ase[m];
			}
			for(int m = 1; m <= cc; m ++){
				if(ti[m].name == qf){
					findaddr(ti[m].type , req , ti[m].l , ti[m].r);
				}
			}
		}else if(op == 4){
			cin >> ids[i].asa;
			cout << ids[i].asa << endl;
			for(int k = 1; k <= cc + 2; k++){
				if(ti[k].l <= ids[i].asa && ids[i].asa <= ti[k].r){
					if(ti[k].type == "int" || ti[k].type == "long" || ti[k].type == "short" || ti[k].type == "byte"){
						cout << ti[k].name;
					}else{
						cout << ti[k].name << '.';
						findname(ids[i].asa , ti[k].l , ti[k].r , k);
						k = cc + 12312312;
					}
				}
			}
		}
		
	}

	return 0;
}
//wo chao! chao ji da mo ni!
//FRICK THIS AAAA