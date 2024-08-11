#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

long long cei(long long a, long long b){
        if((a / b) * b < a) return a / b + 1;
        return a / b;
}

int n, d;
long long sum, l;
int v[N], a[N];

int main(){
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);

        scanf("%d%d", &n, &d);
        for(int i = 1; i < n; i++) scanf("%d", &v[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

        sum += cei(v[1], d) * a[1];
        l = cei(v[1],  d) * d - v[1];
        
        //cout << cei(v[1], d)<< endl;
        //cout <<l << endl;     
        
        for(int i = 2; i <= n;){
//              cout << i << ' ';
                long long road = 0;
                int j = i;
                while(a[i] <= a[j] && j <= n){
                        j++;
                        road += v[j - 1];
                }
                
                road -= l;
                sum += cei(road, d) * a[i];
                l = cei(road, d) * d - road;
                
//              cout << j << ' ' << road << ' ' << l << endl;
                i = j;
        }

        cout << sum << endl;
        return 0;
}
