#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, m, s = 0, mininum = 100000;
    cin >> n >> d;
    int v[n];
    int a[n];
    for (int i = 1; i <= n-1; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] <= mininum)
            mininum = a[i];
    }
    if (mininum == a[1]){
        for (int i = 1; i <= n-1; i++)
            s += v[i];
        if (s % d == 0)
            m = mininum*(s/d);
        else
            m = mininum*(s/d + 1);
    }
    else{
        mininum = a[1];
        int i = 1;
        while (i <= n){
            if (a[i] >= mininum){
                s += v[i];
            }
            else{
                mininum = a[i];
                continue;
            }
            if (s % d == 0)
                    m = mininum*(s/d);
                else
                    m= mininum*(s/d + 1);
            i++;
        }
    }
    cout << m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}