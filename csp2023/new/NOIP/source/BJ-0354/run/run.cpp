

#include <bits/stdc++.h>
#define int long long

using namespace std;

int c , T , n , m , k , d;
int dou[20];
int res = 0;
int curres;
int sche[20];
int totrun;
struct goal{
	int lim;
	int req;
	int val;
} G[100009];
int currun;

signed main(){
	freopen("run.in" , "r" , stdin);
	freopen("run.out", "w", stdout);
	
	dou[0] = 1;
	cin >> c >> T;
	if(c == 1 || c == 2){
		while(T --){
			cin >> n >> m >> k >> d;
			for(int i = 1; i <= m ; i++){
				cin >> G[i].lim >> G[i].req >> G[i].val;
			}
			for(int i = 1; i <= 18; i++){
				dou[i] = dou[i - 1] * 2;
			}
			for(int i = 0; i <= dou[n] - 1; i ++){
				curres = 0;
				memset(sche , 0 , sizeof(sche));
				int curi = i;
				for(int j = n - 1; j >= 0; j --){
					if(curi / dou[j] == 1){
						curi = curi - dou[j];
						sche[j + 1] = 1; 
					}
				}
				bool flag = true;
				currun = 0;
				totrun = 0;				
				for(int j = 1; j <= n; j ++){
					if(sche[j] == 1){
						currun ++;
						totrun ++;
						if(currun > k){
							flag = false;
							j = n + 1;
						}
					}else if(sche[j] = 0){
						currun = 0;
					}
				}
				if(flag){
					for(int j = 1; j <= m; j++){
						bool gr = true;
						for(int k = G[j].lim; k >= G[j].lim - G[j].req + 1; k --){
							if(sche[k] == 0){
								gr = false;
							}
						}
						if(gr){			
							curres += G[j].val;
						}
					}
					res = max(res , curres - (totrun) * d);
				}
			}
			cout << res << endl;
		}
	}else{
		while(T --){
			cout << '0' << endl;
		}
	}
	
	return 0;
}

//There is still 45 minutes. But I can't get anything, I think I will get 195, which is awful.
/*
When I was 10, I was addicted to Minecraft , I want to write minecraft plugins.
Then, I asked my mom to learn programming. Sadly, I still don't know how to write plugins now.
During my 5/6 years journey, I want to thank Ms./Mrs. Zhang(my middle school math teacher and my present OI coach).
I think I won't do OI anymore, but I may still learn programming.
That's the spirit of Computer Science isn't it
Thanks to OI bring me to this beautiful world
I have graduated from a not - that good middle school. Seeing other people around me, I felt embarased, they are all so clever, I'm stupid.
I think the education distribution is like uh welp everyone knows that.
Second problem, maybe transfer it into a graph and do DFS / SPFA stuff or just simulate the rings. But I don't know how to write it.
Third problem, Maybe use two pointers and then let it move foward/backwards. Sadly , I still don't know how to write it.
Last problem , a DP, I used to like DP but. I am not passioned at OI anymore.
		|_ Can't dp at N , we can use M as a factor of DP
DP[i][0/1] means at Goal Mi , you have / not have 
I think Im going to do math research. Im at intl department, hope you guys can see me on yau-awards! Number Theory is much more attractive than OI now... sorry OI.
Math is beautiful. So do OI.
Hello, World.
*/