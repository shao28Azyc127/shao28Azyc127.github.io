#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#define int long long
#define PROBLEMNAME "struct"
#define INFILE PROBLEMNAME ".in"
#define OUTFILE PROBLEMNAME ".out"
using namespace std;
template<typename T> inline T ReadInt(){
	char ch = getchar();
	bool sgn = false;
	T ans = 0;
	while((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if(ch == '-') ch = getchar(),sgn = true;
	while('0' <= ch && ch <= '9'){
		ans = (ans << 3) + (ans << 1) + (ch ^ 48);
		ch = getchar();
	}
	return ans * (sgn?-1:1);
}
inline void ReadString(string &Str,bool ClearStr = true){
	ClearStr && (Str = "",0);	
	char ch = getchar();
	while(ch == ' ' || ch == '\t' || ch == '\n' || 
		ch == '\r' || ch == '\f' || ch == '\v')
		ch = getchar();
	while(ch != ' ' && ch != '\t' && ch != '\n' &&
		ch != '\r' && ch != '\f' && ch != '\v')
		Str += ch,ch = getchar();
}
template<typename T> inline void WriteInt(T x){
	if(x < 0) putchar('-'),x *= -1;
	if(x >= 10) WriteInt(x / 10);
	putchar('0' + x % 10);
}
inline void WriteString(const string &Str){
	for(int i = 0;i < Str.size();i ++)
		putchar(Str[i]);
}
struct Structure{
	vector<Structure*> SubStructs;
	map<string,int> MembermapSI;
	map<int,string> MembermapIS;
	vector<int> RelPos;
	int Align,Size;
	string Name;
	Structure():Name(""),Align(0),Size(0){
		SubStructs.push_back(nullptr),RelPos.push_back(0);
	}
	Structure(const string &Name):Name(Name),Align(0),Size(0){
		SubStructs.push_back(nullptr),RelPos.push_back(0);
	}
	inline void AddMember(Structure* Member,const string &IDStr){
		Align = max(Align,Member -> Align);
		int Membercnt = MembermapSI.size();
		MembermapSI[IDStr] = Membercnt + 1;
		MembermapIS[Membercnt + 1] = IDStr;
		SubStructs.push_back(Member);
		int LastTail = Membercnt?RelPos[Membercnt] + 
			SubStructs[Membercnt] -> Size:0;
		RelPos.push_back((LastTail / Member -> Align + 
			bool(LastTail % Member -> Align)) * Member -> Align);
		LastTail = RelPos[Membercnt + 1] + SubStructs[Membercnt + 1] -> Size;
		Size = (LastTail / Align + bool(LastTail % Align)) * Align;
	}
};
struct Variable{
	Structure* Type;
	int Addr;
	Variable():Type(nullptr),Addr(-1){}
	Variable(int Addr):Addr(Addr),Type(nullptr){}
	Variable(Structure* Type,int Addr):Type(Type),Addr(Addr){}	
} Var[110];
map<string,Structure*> Structs;
map<string,int> VariablesSI;
map<int,string> VariablesIS;
inline void ParseLocationIdentifier(const string &LocID,vector<string> &LocVec,bool ClearVec = true){
	ClearVec && (LocVec.clear(),0);
	string tmp = "";
	for(int i = 0;i < LocID.size();i ++){
		if(LocID[i] == '.')
			LocVec.push_back(tmp),tmp = "";
		else tmp += LocID[i];
	}
	LocVec.push_back(tmp);
}
inline void DumpLocationIdentifier(const vector<string> &LocVec,string &LocID,bool ClearStr = true){
	ClearStr && (LocID = "",0);
	for(int i = 0;i < LocVec.size();i ++){
		LocID += LocVec[i];
		i != LocVec.size() - 1 && (LocID += '.',0);
	}
}
signed main(){
	freopen(INFILE,"r",stdin);
	freopen(OUTFILE,"w",stdout);
	vector<string> vec;
	string S,s1,s2;
	int n,op,k;
	n = ReadInt<int>();
	Structs["long"] = new Structure("long");
	Structs["long"] -> Align = 8;
	Structs["long"] -> Size = 8;
	Structs["int"] = new Structure("int");
	Structs["int"] -> Align = 4;
	Structs["int"] -> Size = 4;
	Structs["short"] = new Structure("short");
	Structs["short"] -> Align = 2;
	Structs["short"] -> Size = 2;
	Structs["byte"] = new Structure("byte");
	Structs["byte"] -> Align = 1;
	Structs["byte"] -> Size = 1;
	while(n --){
		op = ReadInt<int>();
		if(op == 1){
			ReadString(S),k = ReadInt<int>();
			Structure* s = new Structure(S);
			for(int i = 1;i <= k;i ++){
				ReadString(s1),ReadString(s2);
				s -> AddMember(Structs[s1],s2);
			}
			Structs[S] = s;
			WriteInt(s -> Size),putchar(' '),WriteInt(s -> Align);
		}else if(op == 2){
			ReadString(s1),ReadString(s2);
			int VarCnt = VariablesSI.size();
			int LastTail = VarCnt?Var[VarCnt].Addr + Var[VarCnt].Type -> Size:0;
			int BegAddr = (LastTail / Structs[s1] -> Align + 
				bool(LastTail % Structs[s1] -> Align)) * Structs[s1] -> Align;
			Var[VarCnt + 1] = Variable(Structs[s1],BegAddr);
			VariablesSI[s2] = VarCnt + 1;
			VariablesIS[VarCnt + 1] = s2;
			WriteInt(Var[VarCnt + 1].Addr);
		}else if(op == 3){
			ReadString(s1),ParseLocationIdentifier(s1,vec);
			Variable v = Var[VariablesSI[vec[0]]];
			int Addr = v.Addr;Structure* s = v.Type;
			for(int i = 1;i < vec.size();i ++){
				int MemberID = s -> MembermapSI[vec[i]];
				Addr += s -> RelPos[MemberID];
				s = s -> SubStructs[MemberID];
			}
			WriteInt(Addr);
		}else{
			k = ReadInt<int>(),vec.clear();
			int ID = -1,VarCnt = VariablesSI.size();
			for(int i = 1;i <= VarCnt;i ++)
				if(Var[i].Addr <= k && k < Var[i].Addr + Var[i].Type -> Size)
					ID = i;
			if(ID == -1){
				WriteString("ERR");
				goto _continue;
			}
			Structure* s = Var[ID].Type;vec.clear();
			vec.push_back(VariablesIS[ID]),k -= Var[ID].Addr;
			while(s -> Name != "int" && s -> Name != "long" && 
				s -> Name != "short" && s -> Name != "byte"){
				ID = -1;
				for(int i = 1;i < s -> RelPos.size();i ++)
					if(s -> RelPos[i] <= k && k < s -> RelPos[i] + s -> SubStructs[i] -> Size)
						ID = i;
				if(ID == -1){
					WriteString("ERR");
					goto _continue;
				}
				k -= s -> RelPos[ID];
				vec.push_back(s -> MembermapIS[ID]);
				s = s -> SubStructs[ID];
			}
			DumpLocationIdentifier(vec,s1);
			WriteString(s1);
		}
		_continue:putchar('\n');
	}
	return 0;
}
