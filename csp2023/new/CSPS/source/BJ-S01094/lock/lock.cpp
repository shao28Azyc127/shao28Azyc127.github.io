#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int NR = 10;
const int P = 10;
struct Node{
	int p[10];
}a[NR + 10];
vector<int> v;
int n;
bool check(int x1, int x2, int x3, int x4, int x5){
	Node tmp;
	tmp.p[1] = x1;
	tmp.p[2] = x2;
	tmp.p[3] = x3;
	tmp.p[4] = x4;
	tmp.p[5] = x5;
	for(int i = 1;i <= n;i++){
		v.clear();
		for(int j = 1;j <= 5;j++){
			if(tmp.p[j] != a[i].p[j]){
				v.emplace_back(j);
			}
		}
		if(v.size() != 1 && v.size() != 2){
			return false;
		}
		if(v.size() == 2){
			if(abs(v[0] - v[1]) != 1) return false;
			if((((a[i].p[v[0]] - tmp.p[v[0]]) % P) + P) % P
			!= (((a[i].p[v[1]] - tmp.p[v[1]]) % P) + P) % P) return false;
		}
	}
	return true;
}

int main(){
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 5;j++){
			scanf("%d", &a[i].p[j]);
		}
	}
	int cnt = 0;
	for(int num1 = 0;num1 <= 9;num1++){
		for(int num2 = 0;num2 <= 9;num2++){
			for(int num3 = 0;num3 <= 9;num3++){
				for(int num4 = 0;num4 <= 9;num4++){
					for(int num5 = 0;num5 <= 9;num5++){
						if(check(num1, num2, num3, num4, num5)){
							cnt++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
/*
1
0 0 1 1 5
*/
