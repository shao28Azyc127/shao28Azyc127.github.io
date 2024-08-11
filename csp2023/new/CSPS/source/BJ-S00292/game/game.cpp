#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 8010;
const int INF = 0x3f3f3f3f;
const int b = 103;

ull h1[MAXN], h2[MAXN], bn[MAXN];
bool d[MAXN][MAXN];
int n;
string s;

bool ishui(int l, int r)
{    
    //cout << bn[l] << " | ";
    while(l <= r){
        if(s[l - 1] != s[r - 1]) return 0;
        ++l, --r;
    }
    return 1;
}
/*
void Bn()
{
    bn[0] = 1;
    for(int i = 1; i <= n; i++){
        bn[i] = bn[i - 1] * b;
    }
}
void hashh(string s)
{
    int sz = s.size();
    int ans = 0;
    for(int i = 0; i < sz; i++){
        ans = ans * b + (ull)s[i];
        h1[i + 1] = ans, s2 = s[i] + s2; 
    }
    
    cout << s2 << endl;
    ans = 0;
    for(int i = 0; i < sz; i++){
        ans = ans * b + (ull)s2[i];
        h2[i + 1] = ans; 
    }
    //for(int i = 1; i <= sz; i++) 
    //    h1[i] += h1[i - 1], h2[i] += h2[i - 1];
    //for(int i = 1; i <= sz; i++)
    //    cout << h1[i] << " " << h2[i] << endl;
}
*/
//bool vis[MAXN][MAXN];
ull work()
{
    ull ans = 0;
    for(int i = n; i >= 1; i--){
        for(int j = i; j <= n; j++){
            //cout << i << " " << j << endl;
            if((j - i + 1) % 2 == 0 && ishui(i, j)){
                //cout << i << " " << j << endl;
                d[i][j] = 1, ans++;
                continue;
            }
            for(int k = i + 1; k <= j; k++){
                if(d[i][k] && d[k + 1][j]){
                    d[i][j] = 1, ans++;
                    break;
                }
            }
        }
        //cout << endl;
    }
    return ans;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    //hashh(s);
    //Bn();
    cout << work();
    return 0;
}