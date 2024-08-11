#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long p = 0, pn = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') pn = -1;
		ch = getchar();
	}
	while(ch <= '9' && ch >= '0'){
		p = (p << 3) + (p << 1) + ch - '0';
		ch = getchar();
	}
	return p * pn;
}
const int maxn = 1e3+3;
int c, t, n, m, cur1, cur2;
char v;
struct node{
	int father;
	short sta; // t or f = 1, u = 2, no = 0
	short sons[maxn];
	int sonnum = 0;
}nodes[maxn];

void expanding(int x){
	for(int i = 0; i < nodes[x].sonnum; i ++){
		int alpha = nodes[x].sons[i];
		if(nodes[alpha].sta == 2 || nodes[alpha].father != x) continue;
		nodes[alpha].sta = 2;
		expanding(alpha);
	}
	return;
}
int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	c = read();
	t = read();
	if(c == 3 || c == 4){
		while(t--){
			n = read();
			m = read();
			int ans = 0;
			while(m--){
				scanf("%c", &v);
				if(v == 'T' || v == 'F'){
					cur1 = read();
				}
				else if(v == 'U'){
					cur1 = read();
					ans ++;
				}
			}
			printf("%d\n", ans);
		}
	}
	
	else{
		while(t--){
			n = read();
			m = read();
			while(m--){
				memset(nodes, 0, sizeof(nodes));
				scanf("%c", &v);
				if(v == 'T' || v == 'F'){
					cur1 = read();
					nodes[cur1].sta = 1;
				}
				else if(v == 'U'){
					cur1 = read();
					nodes[cur1].sta = 2;
					for(int i = 0; i < nodes[cur1].sonnum; i ++){
						if(nodes[nodes[cur1].sons[i]].father == cur1)
							nodes[nodes[cur1].sons[i]].sta = 2;
					}
				}
				else if(v == '+' || v == '-'){
					cur1 = read();
					cur2 = read();
					if(nodes[cur2].sta == 0){
						nodes[cur1].father = cur2;
						nodes[cur1].sta = 0;
						nodes[cur2].sons[nodes[cur2].sonnum] = cur1;
						nodes[cur2].sonnum ++;
					}
					else{
						nodes[cur1].sta = nodes[cur2].sta;
					}
				}
			}
			for(int i = 1; i <= n; i ++){
				if(nodes[i].sta == 2){
					expanding(i);
				}
			}
			int ans = 0;
			for(int i = 1; i <= n; i ++){
				if(nodes[i].sta == 2) ans ++;
			}
			printf("%d\n", ans);
		}
	}
	fcloseall();
	return 0;
}
