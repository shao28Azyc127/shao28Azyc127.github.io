#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5;
ll c, t;
ll n, m;
char v;
ll iinx, iiny;

char ans[N];
bool vis[N];
ll cnt;

ll ians[N];
bool iif;
bool invis[N];
bool outvis[N];
ll iqlt;
void find(ll f){
	if(ians[f] == f || ians[f] == 999999){
		vis[f] = 1;
		if(ians[f] == 999999){
			outvis[f] = 1;
			for(int i = 1; i <= n; i++){
				if(invis[i] == 1){
					outvis[i] = 1;
					vis[i] = 1;
					invis[i] = 0;
				}
			}
		}
		for(int i = 1; i <= n; i++){
			if(vis[i] == 0){
				find(i);
			}
		}
		return ;
	}
	invis[f] = 1;
	vis[f] = 1;
	if(ians[f] > 0){
		find(ians[f]);
	} else {
		find(ians[f]-ians[f]-ians[f]);
	}
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	if(c == 3 || c == 4){
		for(int ict = 1; ict <= t; ict++){
			
			scanf("%lld %lld", &n, &m);
			for(int imn = 1; imn <= m; imn++){
				//cin >> v;
				scanf("%s %lld", &v, &iinx);
				//cout << imn << "-IM " << v << "-V " << iinx << "-IINX " << endl;
				if(v == 'T'){
					ans[iinx] = 'T';
					if(vis[iinx] == false && ans[iinx] == 'U'){
						vis[iinx] = true;
						cnt++;
					}
					
					if(vis[iinx] == true && (ans[iinx] == 'T' || ans[iinx] == 'F')){
						vis[iinx] = false;
						cnt--;
					}
				} else if(v == 'F'){
					ans[iinx] = 'F';
					if(vis[iinx] == false && ans[iinx] == 'U'){
						vis[iinx] = true;
						cnt++;
					}
					
					if(vis[iinx] == true && (ans[iinx] == 'T' || ans[iinx] == 'F')){
						vis[iinx] = false;
						cnt--;
					}
				} else if(v == 'U'){
					ans[iinx] = 'U';
					if(vis[iinx] == false && ans[iinx] == 'U'){
						vis[iinx] = true;
						cnt++;
					}
					
					if(vis[iinx] == true && (ans[iinx] == 'T' || ans[iinx] == 'F')){
						vis[iinx] = false;
						cnt--;
					}
				}
			}
			
			printf("%lld\n", cnt);
			/*for(int i = 1; i <= n; i++){
				cout << i << "-" << ans[i] << "\n";
			}*/
			cnt = 0;
			for(int i = 0; i <= 100000; i++){
				vis[i] = false;
				ans[i] = 'o';
			}
			
		}
	} else {
		for(int ict = 1; ict <= t; ict++){
			scanf("%lld %lld", &n, &m);
			for(int i = 1; i <= n; i++){
				ians[i] = i;
			}
			for(int imn = 1; imn <= m; imn++){
				scanf("%s %lld", &v, &iinx);
				if(v == 'T'){
					
					ians[iinx] = 111111;
					
				} else if(v == 'F'){
					
					ians[iinx] = 0;
					
				} else if(v == 'U'){
					
					ians[iinx] = 999999;
					
				} else if(v == '+'){
					
					scanf("%lld", &iiny);
					ians[iinx] = ians[iiny];
					
				} else if(v == '-'){
					
					scanf("%lld", &iiny);
					
					if(ians[iiny] == 111111){
						
						ians[iinx] = 0;
						
					} else if(ians[iiny] == 0){
						
						ians[iinx] = 111111;
						
					} else if(ians[iiny] == 999999){
						
						ians[iinx] = 999999;
						
					} else if(ians[iiny] == iiny){
						
						ians[iinx] = -iiny;
						
					} else {
						
						ians[iinx] = -ians[iiny];
						
					}
					
				}
			}
			for(int i = 1; i <= n; i++){
				if(ians[i] == -i){
					ians[i] = 999999;
					outvis[i] = 1;
					iqlt++;
				}
				if(ians[i] == i){
					iqlt++;
				}
				if(ians[i] == 999999 || ians[i] == -i){
					iif = true;
				}
			}
			//if(iif == true){//has 'U'
				iif = false;
				find(1);
				for(int i = 1; i <= n; i++){
					if(outvis[i] == 1){
						cnt++;
					}
				}
				printf("%lld\n", cnt);
				cnt = 0;
			/*} else {//doesn't have 'U'
				printf("0");
			}*/
			
			/*for(int i = 1; i <= n; i++){
				if(ians[i] == 0){
					cout << "F" << " ";
					continue;
				}
				if(ians[i] == 111111){
					cout << "T" << " ";
					continue;
				}
				if(ians[i] == 999999){
					cout << "U" << " ";
					continue;
				}
				cout << ians[i] << " ";
			}*/
			
			for(int i = 1; i <= n; i++){
				invis[i] = 0;
				outvis[i] = 0;
				vis[i] = 0;
			}
			iqlt = 0;
			
		}
	}
	
	return 0;
}
