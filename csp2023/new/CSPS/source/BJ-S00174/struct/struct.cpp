#include<bits/stdc++.h>
using namespace std;

#define MAXN 5000005

inline void chkmax( int &x , int k ){ x = max( x , k ); }

int q,tycnt,req[MAXN],opt[MAXN],adrq[MAXN],flag1;
string typs[MAXN],nams[MAXN],qrys[MAXN];
int Ans[MAXN][2];
string Ans2[MAXN];

struct elem{ //只用来描述结构体内部的子变量
	string nam; int typ;
	elem(){ nam = "",typ = 0; }
};

struct stru{ //只用来描述结构体
	vector<elem> eles;
	map<string,int> eid;
	string nam; int req;
	stru(){ nam = "",req = 0; eid.clear(),eles.clear(); }
};

struct vari{ //用来描述变量，精确到基本类型
	string nam;
	int up; //依次隶属于所处结构体的层级
	int typ,st;
	vari(){ typ = st = up = 0; nam = ""; }
};

vector<stru> S;
vector< vector<vari> > Vs;
map<string,int> M;

inline void init(){
	req[1] = 1; M["byte"] = 1;
	req[2] = 2; M["short"] = 2;
	req[3] = 4; M["int"] = 3;
	req[4] = 8; M["long"] = 4; tycnt = 4;
}

int pos,cnt = 0,fc[MAXN];
vari bel[MAXN],id[MAXN];
map<string,int> varid;

inline void pushbase( vari &V ){
	int siz = req[V.typ];
	while( pos % siz ) pos ++; V.st = pos;
	for( int i = 0 ; i < siz ; i ++ ) bel[pos ++] = V;
}

inline void solve(){
	for( int i = 1 ; i <= q ; i ++ ){
		if( opt[i] == 2 ){
			vari ele; ele.nam = nams[i],ele.typ = M[typs[i]]; cnt ++;
			if( ele.typ <= 4 ) pushbase( ele );
			else{
				vector<vari> sp;
				while( pos % S[ele.typ].req ) pos ++; ele.st = pos;
				for( elem inner : S[ele.typ].eles ){
					vari ele2; ele2.up = cnt,ele2.typ = inner.typ,ele2.nam = inner.nam;
					pushbase( ele2 );
					//printf("fast %d\n",ele2.st);
					sp.emplace_back( ele2 );
				} Vs.emplace_back( sp ); fc[cnt] = Vs.size() - 1;
			} varid[nams[i]] = cnt,id[cnt] = ele;
			Ans[i][0] = ele.st;
		}
		else if( opt[i] == 3 ){
			int len = qrys[i].length(); //printf("len %d\n",len);
			int pts = 0; while( pts < len && qrys[i][pts] != '.' ) pts ++;
			if( pts == len ) Ans[i][0] = id[varid[qrys[i]]].st;
			else{
				string pre = qrys[i].substr( 0 , pts );
				string aft = qrys[i].substr( pts + 1 , len - pts - 1 );
				int out = varid[pre],typ = id[out].typ;
				vector<vari> V = Vs[fc[out]];
				//printf("ars %d\n",S[typ].eid[aft]);
				Ans[i][0] = V[S[typ].eid[aft]].st;
			}
		}
		else if( opt[i] == 4 ){
			vari here = bel[adrq[i]];
			if( !here.typ ) Ans2[i] = "ERR";
			else{
				int up = here.up;
				if( !up ) Ans2[i] = here.nam;
				else Ans2[i] = id[up].nam + "." + here.nam;
			}
		}
	}
}

signed main(){
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	S.resize( 205 ); init(); cin >> q;
	for( int i = 1 ; i <= q ; i ++ ){
		cin >> opt[i];
		if( opt[i] == 1 ){
			flag1 ++;
			string s; int k; cin >> s >> k;
			int pos = 0;
			stru nnew; nnew.nam = s,M[s] = ++tycnt;
			for( int j = 1 ; j <= k ; j ++ ){
				string t,nam; cin >> t >> nam;
				elem ele; ele.nam = nam,ele.typ = M[t];
				while( pos % req[ele.typ] ) pos ++;
				pos += req[ele.typ];
				nnew.eles.emplace_back( ele );
				nnew.eid[nam] = nnew.eles.size() - 1;
				chkmax( nnew.req , req[ele.typ] );
			} req[tycnt] = nnew.req,S[tycnt] = nnew;
			while( pos % nnew.req ) pos ++; Ans[i][0] = pos,Ans[i][1] = nnew.req;
		}
		else if( opt[i] == 2 ) cin >> typs[i] >> nams[i];
		else if( opt[i] == 3 ) cin >> qrys[i];
		else if( opt[i] == 4 ) cin >> adrq[i];
	}
	solve();
	//for( int i = 0 ; i < pos ; i ++ ) printf("q %d %d\n",i,bel[i].st);
	for( int i = 1 ; i <= q ; i ++ ){
		if( opt[i] == 1 ) cout << Ans[i][0] << " " << Ans[i][1] << "\n";
		else if( opt[i] <= 3 ) cout << Ans[i][0] << "\n";
		else if( opt[i] == 4 ) cout << Ans2[i] << "\n";
	}
	return 0;
}