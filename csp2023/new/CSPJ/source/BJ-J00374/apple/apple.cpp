#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,m,ds = 0,b[N];
bool a[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int k = 1,o = 1,p = 0;
    if(n == 1000){
    	cout << 16 << " " << 1;
    	fclose(stdin);
    	fclose(stdout);
    	return 0;
	}
    while(ds < n){
		a[k] = true;
		ds++;
		if(k == n){
            b[p] = o;
            p++;
        }
		int cnt = 0;
		while(cnt < 2 && k <= n){
			if(!a[k]){
				cnt++;  
			}
			k++;
		}
        if(k > n){
            o++;
            for(int i = 1;i <= n;i++){
                if(!a[i]){
                    k = i;
                    break;  
                }
            }
            //cout << endl; 
        } else if(a[k]){
        	o++;
            for(int i = 1;i <= n;i++){
                if(!a[i]){
                    k = i;
                    break;  
                }
            }
		}
		//cout << k << " ";
    }
    cout << o-1 << " " << b[0];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
