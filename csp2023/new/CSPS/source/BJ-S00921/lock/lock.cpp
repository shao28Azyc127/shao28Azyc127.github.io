#include <iostream>
#include <cstdio>

using namespace std;

int n, a[10][5], res, b[10];

bool check(){
	for(int i = 1, j; i <= n; ++i){
		j = 1;
		while(a[i][j] == b[j] && j <= 5) ++j;
		if(j == 6) return false;
		if((a[i][j] - b[j] + 10) % 10 == (a[i][j + 1] - b[j + 1] + 10) % 10 && j < 5){
			j = j + 2;
			while(a[i][j] == b[j] && j <= 5) ++j;
			if(j != 6) return false;
		}else{
			++j;
			while(a[i][j] == b[j] && j <= 5) ++j;
			if(j != 6) return false;
		}
	}
	return true;
}

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= 5; ++j)
			scanf("%d", &a[i][j]);
	for(b[1] = 0; b[1] <= 9; ++b[1])
		for(b[2] = 0; b[2] <= 9; ++b[2])
			for(b[3] = 0; b[3] <= 9; ++b[3])
				for(b[4] = 0; b[4] <= 9; ++b[4])
					for(b[5] = 0; b[5] <= 9; ++b[5])
						if(check()){
							++res;
						}
	printf("%d\n", res);
	
	return 0;
}
