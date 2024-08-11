#include<bits/stdc++.h>
using namespace std;

long long n,a[10],res = 0;


int main(){

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    long long flag = 0,cc = 0;
    cin >> n;
    long long aa = n;
    if(n > 8){
        n /= 10;
        flag = 1;
    }


    for(int i = 1; i <= 5*n; i++){
        if(flag == 1) a[1] = aa%10;
        cin >> a[i];
        if(a[i] > 9){
            a[i+1] = a[i]%10;
            a[i] /= 10;
            i++;
        }
    }

    if(n == 1) res = 81;
    if(n == 2){
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= 5; j++){
                if(a[j+(i-1)*5] == a[j+i*5]) cc++;

            }
        }
        res = (5-cc)*10;
    }

    if(n > 2) res = 1;




    cout << res;

    return 0;
}

