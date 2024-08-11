#include<bits/stdc++.h>//helloworld
using namespace std;
int n, m, w[3010][3010], f[3010][3010], fl[3010];
char ch;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ch;
			w[i][j] = int(ch - 'a');
		}
	}
	for(int i = 0; i < n; i++){
		sort(w[i], w[i] + m);
		for(int j = 0; j < m; j++){
			f[i][j] = w[i][m - j - 1];
		}
	}
	int nn = 0, flag = 1, c = 0, cc = n;
	if(n == 1){
		printf("1");
	}else if(m == 1){
		int minn = 10000000, biaoji = 100000, same = 9090909;
		for(int i = 0; i < n; i++){
			if(minn > w[i][0]){
				biaoji = i;
				minn = w[i][0];
			}
			if(minn == w[i][0]){
				same = minn;
			}
		}
		for(int i = 0; i < n; i++){
			if(i == biaoji && same != minn){
				printf("1");
			}else{
				printf("0");
			}
		}
	}else if(m == 2){
		int minn = 10000000, biaoji = 100000, same = 9090909, biao[3010] = {};
		for(int i = 0; i < n; i++){
			if(minn > w[i][0]){
				biaoji = i;
				minn = w[i][0];
			}
			if(minn == w[i][0]){
				same = minn;
			}
		}
		for(int i = 0; i < n; i++){
			if(w[i][0] == minn){
				biao[i] = 1;
			}
		}
		minn = 10000000;
		biaoji = 100000;
		same = 9090909;
		for(int i = 0; i < n; i++){
			if(biao[i] != 0){
				if(minn > w[i][1]){
					biaoji = i;
					minn = w[i][1];
				}
				if(minn == w[i][1]){
					same = minn;
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(i == biaoji && same != minn){
				printf("1");
			}else{
				printf("0");
			}
		}
	}else{
		while(nn < n){
			for(int i = 0; i < n; i++){
				fl[i] = i;
			}
			for(int i = 0; i < m; i++){
				c = 0;
				/*cout << endl;
				for(int i = 0; i < n; i++){
					cout << fl[i] << "()";
				}
				cout << cc << endl;*/
				for(int j = 0; j < cc; j++){
					if(nn == fl[j]){
						continue;
					}
					//cout << fl[j] << " " << f[fl[j]][i] << endl;
					if(w[nn][i] > f[fl[j]][i]){
						flag = 0;
						printf("0");
						break;
					}
					//cout << w[nn][i] << " ** " << f[fl[j]][i] << "number" << i << "no" << nn << endl;
					if(w[nn][i] < f[fl[j]][i]){
						fl[c] = j;
						c++;
						//cout << w[nn][i] << " * " << f[fl[j]][i] << endl;
					}
				}
				//cout << endl << cc << "@" << c << endl;
				if(!flag){
					break;
				}
				if(cc == n){
					cc--;
				}
				if(c == cc){
					//cout << endl << "*()" << i + 1 << endl;
					printf("1");
					break;
				}
				cc = c;
			}
			nn++;
		}
		/*cout << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << w[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << f[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	return 0;
}
//cout << endl;
//for(int i = 0; i < n; i++){
//	for(int j = 0; j < m; j++){
//		cout << w[i][j] << " ";
//	}
//	cout << endl;
//}
//cout << endl;
//for(int i = 0; i < n; i++){
//	for(int j = 0; j < m; j++){
//		cout << f[i][j] << " ";
//	}
//	cout << endl;
//}
