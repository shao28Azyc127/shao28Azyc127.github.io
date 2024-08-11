#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

bool a[1000000010]; //0 not-taken, 1 means taken

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, day, lastday;
    cin >> n;
    if(n%3 == 1){
        lastday = 1;
    }
    int i;
    for(i = 1;i <= n;i++){
        int j=i, cnt=0;
        while(j <= n)
            if(cnt == 2){
                cnt = 0;
                a[j]=1;
            }
            if(a[j] == 0){
                cnt++;
            }
            j++;
        }
        day++;
        if(a[i]==1){
            lastday = day;
        }
    }
    cout << day << " " << lastday << endl;
   return 0;
}
