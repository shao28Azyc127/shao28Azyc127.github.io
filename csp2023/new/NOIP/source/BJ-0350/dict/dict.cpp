#include<bits/stdc++.h>
using namespace std;
int n, l;
char cur;
int a[30][4000];
bool cmp(int amin, int amax){
	int lp = 0, rp = 26;
	while(a[lp][amin] == 0){
		lp ++;
	}
	while(a[rp][amax] == 0){
		rp --;
	}
	if(lp < rp){
		return true;
	}
	if(lp > rp || lp == rp){
		return false;
	}
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	scanf("%d%d", &n, &l);
	if(n == 1){
		printf("1\n");
	}
	else{
		for(int i = 0; i < n; i ++){
			scanf("%c", &cur);
			for(int j = 0; j < l; j ++){
				scanf("%c", &cur);
				a[cur-'a'][i]++;
			}
		}
		for(int i = 0; i < n; i ++){
			bool flag = true;
			for(int j = 0; j < n; j ++){
				if(j == i) continue;
				if(!cmp(i, j)){
					flag = false;
					break;
				}
			}
			printf("%d", flag);
		}
	}
	fcloseall();
	return 0;
}
