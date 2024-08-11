#include <iostream>
#include <cstdio>
using namespace std;
bool f[1000000100];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out", "w", stdout);
    int n, daynum = 0, nnum = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        f[i] = false;
    }
    int j = 1, a= 0;
    while(sum < n){
        if(j == n){
            nnum = daynum + 1;
        }
        f[j] = true;
        sum++;
        a = 0;
        for (int i = j; i <= n; i++){
            if(f[i] == false){
                a++;
            }
            if(a==3){
                j = i;
                break;
            }
        }
        if(a < 3){
            daynum++;
            for (int i = 1; i <= n; i++){
                if(f[i] == false){
                    j = i;
                    break;
                }
            }
        }
    }
    cout << daynum << " "<<nnum ;
    return 0;
}
