#include<bits/stdc++.h>
using namespace std;
int apple[100000001];
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i ++) apple[i] = 1;
	int day,na;
	bool na_flag = true;
	while(true){
		bool flag = true;
		for(int i = 0;i < n;i ++) if(apple[i] == 1) flag = false; 
		if(flag) break;
		bool flag2 = false;
		int cnt = 0;
		for(int i = 0;i < n;i ++){
			if(cnt == 2){
				cnt = 0;
				apple[i] = 0;
				//flag2 = false;
			}
			if(flag2){
				if(apple[i] == 1){
					cnt ++;
				}
			}else{
				if(apple[i] == 1){
					apple[i] = 0;
					flag2 = true;
				}
			}
		}
		day ++;
		if(na_flag && apple[n - 1] == 0){
			na_flag = false;
			na = day;
		}
		//for(int i = 0;i < n;i ++) cout << apple[i] << " ";
		//cout << endl;
		cnt = 0;
	}
	cout << day << " " << na;
	fclose(stdin);
	fclose(stdout);
	return 0;
}