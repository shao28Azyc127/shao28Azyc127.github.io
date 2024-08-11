#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cur1=0,cur2=0,cur3=0;
union basicType {
	long long Long;
	int Int;
	short Short;
	bool Byte;
};
struct basicVarible {
	basicType val;
	string name;
	void init(int type,long long val_,string name_) {
		switch(type) {
		case 1:
			val.Byte=val_;
			break;
		case 2:
			val.Short=val_;
			break;
		case 3:
			val.Int=val_;
			break;
		case 4:
			val.Long=val_;
			break;
		}
		name=name_;
	}
};
struct basicStruct {
	vector<basicVarible> val;
	string name;
	bool isTemplate;
} temp1[105];
struct complicateStruct {
	vector<basicStruct> val1;
	vector<basicVarible> val2;
	bool isTemplate;
	string name;
} temp2[105];
struct Var {
	basicStruct basic;
	complicateStruct comp;
	basicVarible varib;
} varible[105];
int main() {
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int op;
		cin>>op;
		switch(op) {
		case 1:
			string name;
			int n;
			cin>>name>>n;
			basicStruct t1;
			complicateStruct t2;
			basicVarible v;
			bool comp=0;
			for(int i=1;i<=n;i++) {
				string s,n2;
				cin>>s>>n2;
				if(s=="long"){
					v.init(4,0,n2);
					t1.val.push_back(v);
					t2.val2.push_back(v);
				}else if(s=="int") {
					v.init(3,0,n2);
					t1.val.push_back(v);
					t2.val2.push_back(v);
				} else if(s=="short") {
					v.init(2,0,n2);
					t1.val.push_back(v);
					t2.val2.push_back(v);
				} else if(s=="byte") {
					v.init(1,0,n2);
					t1.val.push_back(v);
					t2.val2.push_back(v);
				} else {
					for(int j=1;j<=100;j++) {
						if(temp1[j].name==s) {
							t2.val1.push_back(temp1[j]);
							comp=1;
						}
					}
				}
			}
			if(!comp) {
				temp1[++cur1]=t1;
			} else {
				temp2[++cur2]=t2;
			}
			break;
		case 2:

		}
	}
    return 0;
}
