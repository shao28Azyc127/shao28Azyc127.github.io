#include<bits/stdc++.h>
using namespace std;
bool a[100005];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int out = 0,nout = 0;
    int i = 0;
    while(out != n){
        i++;
        int k = 1;
        int jian = 0;
        for(int j = 1;k <= n;j += 0){
            if(a[k] == 0 and jian == 0)
            {
                j++;
                a[k] = 1;
                //cout << k << " ";
                jian = 2;
                if(k == n)nout = i;
            }
            if(a[k] == 0 and jian != 0){
				jian--;
			}
            k++;
        }
        //cout << endl;
        out += ((n - out) - ((n - out - 1) % 3) - 1) / 3 + 1;
    }
    cout << i << " " << nout;
    return 0;
}
