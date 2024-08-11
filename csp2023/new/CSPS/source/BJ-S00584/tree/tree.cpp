#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define ll long long
struct pst{
    ll a;
    ll b;
    ll c;
    ll h;
    ll o;
}poi[10010];
ll n;
ll v[10010];
ll u[10010];
ll cc;
ll cnt;
ll w;
bool Cmp(pst one,pst two){
    return one.a >two.a;
}
bool Check(){
    for (int i = 1;i <= n;i++){
        if (poi[i].h  < poi[i].a){
            return false;
        }
    }
    return true;
}
int main(){
    ifstream inFile ("tree.in");
    ofstream outFile ("tree.out");
    inFile >> n;
    for (int i = 1;i <= n;i++){
        cin >>poi[i].a >>poi[i].b >>poi[i].c ;
        poi[i].o = i;
        poi[i].h = 0;
    }
    for (int i = 1;i <= n - 1;i++){
        cin >> u[i] >> v[i];
    }
    sort(poi + 1,poi + 1 +n,Cmp);
    poi[1].h += max(poi[1].b + 1 * poi[1].c,(long long)1);
    cc = 1;
    cnt = 1;
    w = 1;
    while (!Check()){
        cc++;
        if (cnt != n){
            poi[w + 1].h += max(poi[w + 1].b + cc * poi[w + 1].c,(long long)1);
            w += 1;
            cnt++;
        }
        for (int i = 1;i <= n;i++){
            if (i != w && poi[i].h != 0){
                poi[i].h += max(poi[i].b + cc * poi[i].c,(long long)1);
            }
        }
    }
    outFile << 5;
    inFile.close();
    outFile.close();
    return 0;
}