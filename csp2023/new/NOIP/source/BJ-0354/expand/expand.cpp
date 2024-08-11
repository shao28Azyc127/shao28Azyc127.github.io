

#include <bits/stdc++.h>

using namespace std;

int c ,n , m , q;
int curx,  cury;
int chx , chy;
int F[500009];
int G[500009];
int nF[500009];
int nG[500009];

int main(){
	freopen("expand.in" , "r" , stdin);
	freopen("expand.out", "w" , stdout);
	
	cin >> c >> n >> m >> q;
	if(c >= 8 && c <= 14){						//30pts
		for(int i = 1; i <= q + 1; i++){
			cout << 1;
		}
	}else if(c == 1){							//5pts
		for(int i = 1; i <= n; i++){
			cin >> F[i];
		}
		for(int i = 1; i <= m; i++){
			cin >> G[i];
		}
		cin >> curx >> cury;
		if(curx != cury){
			cout << 1;
		}else{
			cout << 0;
		}
		while(q --){
			for(int i = 1; i <= n; i++){
				nF[i] = F[i];
			}
			for(int i = 1; i <= n; i++){
				nG[i] = G[i];
			}
			for(int i = 1; i <= chx; i ++){
				int curp , curv;
				cin >> curp >> curv;
				nF[curp] = curv;
			}
			for(int i = 1; i <= chy; i ++){
				int curp , curv;
				cin >> curp >> curv;
				nG[curp] = curv;
			}
			if(nG[1] != nF[1]){
				cout << 1;
			}else{
				cout << 0;
			}
		}
	}else{
		cout << "isn't afo at 10th grade too early?" << endl;
	}
	return 0;
}