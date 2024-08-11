#include <iostream>
using namespace std;

int M[20005][3];
int N[10005];
int n,m,k;

int time(int pos,int time){
	int get,ans = 999999;
	if (pos == n - 1){
		if (time % k == 0){
			return time;
		}else{
			return -1;
		}
	}else{
		for (int i = 0,wait = 0;i < M;i++){
			wait = 0;
			if (M[i][0] == pos){
				while(time + wait < M[i][2]){
					wait += k;
				}
				get = time(M[i][1],time + wait + 1);
				if (get != -1){
					if (ans > (get + time + wait)){
						ans = get + time + wait;
					}
				}
			}
		}
	}
	if (ans == 999999){
		return -1;
	}
	return ans;
}

int main(){
	cin >> n >> m >> k;
	for (int i = 0,a,b;i < M;i++){
		cin >> a >> b;
		M[i][0] = a - 1;
		M[i][1] = b - 1;
		cin >> M[i][2];
	}
	cout << time(0,0);
}