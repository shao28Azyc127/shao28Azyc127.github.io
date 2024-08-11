#include <iostream>
using namespace std;

int n,now_stp;

struct node{
	string name,type;
	int num;
	string c_type[105];
	string c_name[105];
	long long xd_stp[105];
	long long act_stp[105];
	long long to_l,l;
} str[105];
int cnt;

void locate(int id,long long stp){
	while(stp % str[id].to_l != 0) stp++;
	for(int i = 1;i <= str[id].num;i++){
		str[id].act_stp[i] = stp + str[id].xd_stp[i];
		if(str[id].type != "byte" && str[id].type != "short" && str[id].type != "int" && str[id].type != "long"){
			for(int j = 1;j <= cnt;j++){
				if(str[j].type == str[id].type){
					locate(j,str[id].act_stp[i]);
					break;
				}
			}
		}
	}
	now_stp = stp;
}

int search(string id,int num){
	string fst_id;
	int i = 0;
	for(i = 0;i < id.size();i++){
		if(id[i] == '.') break;
		fst_id += id[i];
	}
	if(fst_id == id){
		for(int i = 1;i <= str[num].num;i++){
			if(str[num].c_name[i] == id){
				return str[num].act_stp[i];
			}
		}
	}else{
		for(int i = 1;i <= cnt;i++){
			if(str[i].name == fst_id){
				return search(id.substr(i + 1),i);
			}
		}
	}
	return 0;
}

int main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);

	cin >> n;
	while(n--){
		int op;
		cin >> op;
		if(op == 1){
			cnt++;
			cin >> str[cnt].type >> str[cnt].num;
			long long p = 0,l = 0,len = 0;
			for(int i = 1;i <= str[cnt].num;i++){
				cin >> str[cnt].c_type[i] >> str[cnt].c_name[i];
				if(str[cnt].c_type[i] == "byte"){
					str[cnt].xd_stp[i] = p;
					p++;
					l = max(l,1ll);
					len++;
				}else if(str[cnt].c_type[i] == "short"){
					while(p % 2 != 0) p++;
					str[cnt].xd_stp[i] = p;
					p += 2;
					l = max(l,2ll);
					len += 2;
				}else if(str[cnt].c_type[i] == "int"){
					while(p % 4 != 0) p++;
					str[cnt].xd_stp[i] = p;
					p += 4;
					l = max(l,4ll);
					len += 4;
				}else if(str[cnt].c_type[i] == "long"){
					while(p % 8 != 0) p++;
					str[cnt].xd_stp[i] = p;
					p += 8;
					l = max(l,8ll);
					len += 8;
				}else{
					for(int j = 1;j <= cnt;j++){
						if(str[j].type == str[cnt].c_type[i]){
							while(p % str[j].to_l != 0) p++;
							str[cnt].xd_stp[i] = p;
							p += str[j].l;
							l = max(l,str[j].to_l);
							len += str[j].l;
							break;
						}
					}
				}
			}

			while(len % l != 0) len++;
			str[cnt].to_l = l;
			str[cnt].l = len;
			cout << len << ' ' << l << endl;
		}else if(op == 2){
			string type,name;
			cin >> type >> name;
			for(int i = 1;i <= cnt;i++){
				if(type == str[i].type){
					str[i].name = name;
					while(now_stp % str[i].to_l != 0) now_stp++;
					cout << now_stp << endl;
					locate(i,now_stp);
					while(now_stp % str[i].to_l != 0) now_stp++;
					break;
				}
			}
		}else if(op == 3){
			string id;
			cin >> id;
			string fst_id;
			int i = 0;
			for(i = 0;i < id.size();i++){
				if(id[i] == '.') break;
				fst_id += id[i];
			}
			for(int i = 1;i <= cnt;i++){
				if(str[i].name == fst_id){
					cout << search(id.substr(i + 1),i) << endl;
					break;
				}
			}
		}else{
			long long stp;
			cin >> stp;

		}
	}
}