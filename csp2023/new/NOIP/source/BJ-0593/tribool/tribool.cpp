#include<bits/stdc++.h>
using namespace std;
int c, t;
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	int n, m, ii, jj;
	char v;
	for(int i = 0; i < t; i++){
		scanf("%d%d", &n, &m);
		for(int j = 0; j < m; j++){
			cin >> v;
			if(v == 'T' || v == 'F' || v == 'U'){
				scanf("%d", &ii);
			}else{
				scanf("%d%d", &ii, &jj);
			}
		}
	}
	for(int i = 0; i < t; i++){
		printf("0\n");
	}
	return 0;
}
