#include<bits/stdc++.h>
using namespace std;
struct node{
	int f,g,h,j,k,m;
}vis[10000000];
int cnt1,a,b,c,d,e,ans9,ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans,cnt = 1;
void dfs(int f,int g,int h,int j,int k){
	for(int m = 1; m <= 9;m++){
		int t = f + m,y = g + m,u = h + m,o = j + m,p = k + m;
		if(t >= 10) t -= 10;
		if(y >= 10) y -= 10;
		if(u >= 10) u -= 10;
		if(o >= 10) o -= 10;
		if(p >= 10) p -= 10;
		ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0,ans5 = 0,ans6 = 0,ans7 = 0,ans8 = 0,ans9 = 0;
		for(int i = 1; i <= cnt; i++){
			if(t == vis[i].f && g == vis[i].g && h == vis[i].h && j == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans1 = 1;
			}
			if(f == vis[i].f && y == vis[i].g && h == vis[i].h && j == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans2 = 1;
			}
			if(f == vis[i].f && g == vis[i].g && u == vis[i].h && j == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans3 = 1;
			}
			if(f == vis[i].f && g == vis[i].g && h == vis[i].h && o == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans4 = 1;
				
			}
			if(f == vis[i].f && g == vis[i].g && h == vis[i].h && j == vis[i].j && p == vis[i].k){
				vis[i].m++;
				ans5 = 1;
				
			}
			if(t == vis[i].f && y == vis[i].g && h == vis[i].h && j == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans6 = 1;
				
			}
			if(f == vis[i].f && y == vis[i].g && u == vis[i].h && j == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans7 = 1;
				
			}
			if(f == vis[i].f && g == vis[i].g && u == vis[i].h && o == vis[i].j && k == vis[i].k){
				vis[i].m++;
				ans8 = 1;
				
			}
			if(f == vis[i].f && g == vis[i].g && h == vis[i].h && o == vis[i].j && p == vis[i].k){
				vis[i].m++;
				ans9 = 1;
				
			}
		}
		if(ans1 == 0){
			vis[cnt].f = t;
			vis[cnt].g = g;
			vis[cnt].h = h;
			vis[cnt].j = j;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans2 == 0){
			vis[cnt].f = f;
			vis[cnt].g = y;
			vis[cnt].h = h;
			vis[cnt].j = j;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans3 == 0){
			vis[cnt].f = f;
			vis[cnt].g = g;
			vis[cnt].h = u;
			vis[cnt].j = j;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans4 == 0){
			vis[cnt].f = f;
			vis[cnt].g = g;
			vis[cnt].h = h;
			vis[cnt].j = o;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans5 == 0){
			vis[cnt].f = f;
			vis[cnt].g = g;
			vis[cnt].h = h;
			vis[cnt].j = j;
			vis[cnt].k = p;
			vis[cnt++].m++;
		}
		if(ans6 == 0){
			vis[cnt].f = t;
			vis[cnt].g = y;
			vis[cnt].h = h;
			vis[cnt].j = j;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans7 == 0){
			vis[cnt].f = f;
			vis[cnt].g = y;
			vis[cnt].h = u;
			vis[cnt].j = j;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans8 == 0){
			vis[cnt].f = f;
			vis[cnt].g = g;
			vis[cnt].h = u;
			vis[cnt].j = o;
			vis[cnt].k = k;
			vis[cnt++].m++;
		}
		if(ans9 == 0){
			vis[cnt].f = f;
			vis[cnt].g = g;
			vis[cnt].h = h;
			vis[cnt].j = o;
			vis[cnt].k = p;
			vis[cnt++].m++;
		}
	}
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin >> n;
	for(int z = 1; z <= n; z++){
		cin >> a >> b >> c >> d >> e;
		cnt1++;
		dfs(a,b,c,d,e);
	}
	for(int i = 1; i <= cnt; i++){
		if(vis[i].m == n) ans++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
