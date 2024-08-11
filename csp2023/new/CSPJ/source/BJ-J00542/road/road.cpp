#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
long long n, m, res = 0, max_p = INF;

long long dist[N], oil[N], s[N];
int min_p = INF;

int main(){
    freopen("road.in", "r", stdin);
    freopen("road,out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> dist[i];
    }
    for(int i = 0; i < n; i++){
        cin >> oil[i];
        max_p = min(max_p, oil[i]);
    }
    for(int i = 0; i < n; i++) s[i] = oil[i];
    sort(s, s + n);
    if(max_p == oil[0]){
        for(int i = 0; i < n; i++){
            if(dist[i] % m){
                res += (dist[i] / m + 1) * oil[0];
            }
            else{
                res += dist[i] / m * oil[0];
            }
        }
        cout << res;
        return 0;
    }
    int prize = INF;
    for(int i = 0; i < n; i++)
    {
        prize = min(prize, oil[i]);
        if(dist[i] % m){
            res += (dist[i] / m + 1) * prize;
        }
        else{
            res += dist[i] / m * prize;
        }
    }
    cout << res;
    return 0;
}
