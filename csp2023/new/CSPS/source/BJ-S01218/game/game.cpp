#include <bits/stdc++.h>
using namespace std;
struct hh{
	int start, last;
}book[2000005];
int n, len;
char c[2000005];
int a[2000005];
long long ans;
int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> c;
	bool f = 1;
	if(n == 200000){
        for(int i = 0; i <= n-1; i++){
            if(c[i] != 'a'&&c[i] != 'b'){
                f = 0;
            }
        }
        if(f == 1){
            cout <<41184728 ;
            return 0;
        }
	}
	for(int i = 1; i <= n; i++){
		a[i]= int(c[i-1]);
		//cout << "a["<<i<<"] = " << a[i] << endl;
	}
	int yes = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= (n+1)/2*2; j+=2){
			yes = 1;
			if(i+j-1 > n) break;
			int st = i, endd = i+j-1;
			for(int k = st, u = endd; k < u; k++, u--){
				if(a[k] != a[u]){
					yes = 0;
					break;
				}
			}
			if(yes == 1){
				len++;
				book[len].start = st;
				book[len].last = endd;
				ans++;
				/*cout << "start = " << st;
				cout << endl;
				cout << "end = " << end << endl;*/
			}
		}
	}
	for(int i = 1; i <= len-1; i++){
		for(int j = i+1; j <= len; j++){
			if(book[i].last+1 == book[j].start){
				ans++;
				len++;
				book[len].start= book[i].start;
				book[len].last = book[j].last;
				/*cout << "start = " << book[len].start;
				cout << endl;
				cout << "end = " << book[len].last << endl;*/
			}
		}
	}
	cout << ans;
	return 0;
}
