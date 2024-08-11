

#include <bits/stdc++.h>

using namespace std;

int T;
int c;
int n , m;
char op;
char trib[100009];
int status[100009];
int pos;
int res;
struct edge{
	int v;
	int w;
};
int from , to , worth;
vector<edge> ma[100009];
int tmp[100009];
bool visit[100009];
int before[19];
int after[19];
struct operat{
	char op;
	int u;
	int v;
};
operat greed[19];
int tri[19];
int cc = 0;

int main(){
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out", "w" , stdout);
	
	cin >> c >> T;
	if(c == 3 || c == 4){							// + 20 points
		while(T --){
			int ans = 0;
			cin >> n >> m;
			for(int i = 0; i <= 100000; i++){
				trib[i] = ' ';
			}
			for(int i = 1; i <= n; i++){
				cin >> op >> pos;
				if(op == 'U'){
					if(trib[pos] != 'U'){
						ans ++;
					}
					trib[pos] = 'U';
				}else{
					if(trib[pos] == 'U'){
						ans --;
					}
					trib[pos] = op;
				}
			}
			cout << ans << endl;
		}
	}else if(c == 5 || c == 6){			//only U and + - 
		while(T --){
			cin >> n >> m;
			memset(visit , 0 , sizeof(visit));
			for(int i = 0; i <= 100000; i ++){
				trib[i] = 'T';
			}
			int ans = 0;
			for(int i = 1; i <= m; i++){
				cin >> op;
				if(op == '+'){
					cin >> from >> to;
					trib[from] = trib[to];
//					cout << "xianzai from = " << from << " , to = " << to << " , fuzhiweile " << trib[to] << endl;
				}else if(op == 'U'){
					cin >> from;
					trib[from] = 'U';
//					cout << "xian zai trib[from] = " << from << endl;
//3 987 142 296 121 915 2
				}
			}
			for(int i = 1; i <= n; i ++){
				if(trib[i] == 'U'){
					ans ++;	
				}
			}
			cout << ans << endl;
		}
	}else if(c == 1 || c == 2){			//BaO lI cHU QiJI	+20 points
		while(T --){
			cin >> n >> m;
			for(int i = 1; i <= m; i++){
				cin >> op;
				if(op == 'T' || op == 'F' || op == 'U'){
					greed[i].op = op;
					cin >> from;
					greed[i].u = from;
				}else{
					greed[i].op = op;
					cin >> from >> to;
					greed[i].u = from;
					greed[i].v = to;
				}
			}
			tri[1] = 1;
			int ans = n;
			for(int j = 2; j <= n; j ++){
				tri[j] = tri[j - 1] * 3;
			}									// 1 --> T 2 --> F 3 --> 0
			for(int j = 0; j <= tri[n] * 3 - 1; j ++){
				memset(before , 0 , sizeof(before));
				memset(after , 0 , sizeof(after));
				int curint = j;
				for(int k = n; k >= 1; k --){
					if(curint / tri[k] == 1){
						before[k] = 1;
						after[k] = 1;
						curint = curint % tri[k];
					}else if(curint / tri[k] == 2){
						before[k] = -1;
						after[k] = -1;
						curint = curint % tri[k];
					}else{
						before[k] = 0;
						after[k] = 0;
					}
				}
				for(int k = 1; k <= m; k++){
					if(greed[k].op == 'T'){
						after[greed[k].u] = 1;
					}else if(greed[k].op == 'U'){
						after[greed[k].u] = 0;
					}else if(greed[k].op == 'F'){
						after[greed[k].u] = -1;
					}else if(greed[k].op == '+'){
						after[greed[k].u] = after[greed[k].v];
					}else if(greed[k].op == '-'){
						after[greed[k].u] = after[greed[k].v] * -1;
					}
				}
				
//				for(int i = 1; i <= n; i++){
//					cout << before[i] << ' ';
//				}
//				cout << endl;
//				for(int i = 1; i <= n; i++){
//					cout << after[i] << ' ';
//				}
//				cout << endl;
				bool flag = true;
				for(int k = 1; k <= n; k ++){
					if(after[k] != before[k]){
						flag = false;
					}
				}
				int curres = 0;
				if(flag){
					for(int i = 1; i <= n; i ++){
						if(before[i] == 0){
							curres ++;
						}
					}
					ans = min(ans , curres);
				}
			}
			cout << ans << endl;
		}
	}else{
		cout << "No, Commander" << endl;
	}
	
	return 0;
}
//first time to see constant 'c' in the question..
/*
Pretty interesting
Tuopu? idk

1:1 <_-1_> 2:-1
   \         ^
    \__1_   -1
         \   |
          \  v
            3:1

F--+--T
|-    |-
F--+--F
WO MEI DAI BI AAAAAAAAAAAAAAAA
ok so for each ring , we know that if it there is a result
!result is also a result, and also, the tribool in the look will always be "U" or "T/F"
there won't be a ring including both U and TF(why not change U to W so its wtf....)
wait.. oh for linear stuff...
T--+--T-----F--+--F-----T
switching only 1 to U -> the chain will all change to U
so? what?
for(i = 1 ~ n){
	goto -> Find(fa);
	if(fa[x] == U){
		status=U
	}
}
what about map? or tree?
t-----t------f
      |      |
     f/t------f
1 2 +
2 3 -
3 5 +
4 5 -
2 4 +
Dian quan zhi he?
f -> -1 -> 1    1 -> -1    0 -> 0    sum remains the same
t -> -1 -> -1   1 -> 1     0 -> 0    sum changes.
everytime there is a + sign , the sum will always +1 / -1
so what about U? U is 0, a visit array -> if !visit - > 0 but value can be V
I hate graph theory
I do not belong to OI, I belong to Math.
*/