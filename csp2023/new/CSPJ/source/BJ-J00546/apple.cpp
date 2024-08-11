#include<bits/stdc++.h>
using namespace std;
int n,day = 1,b,cur,j = 1;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin >> n;
	int a[n] = {0};
	int w[n] = {0};
	while(b < n){  
		while(j <= n){
			if(w[j] == 0){
				w[j] = 1;
				b++;
				a[j] = day;
				
				while(cur < 3 && j + 1 <= n){
					j += 1;
					if(w[j] == 0){
						cur++;
					}
				}
				cur = 0;
				if(j + 1 > n){
					j = 1;
					day++;
				}
			}
			else{
				j += 1;
			}
		}
	}
	day = 0;
	if(n%3==1){
		a[n]=1;
	}
	for(int i = 1; i <= n; i++){
		day = max(a[i],day);
	}
		cout << day << " " << a[n] << endl;
	return 0;
}
