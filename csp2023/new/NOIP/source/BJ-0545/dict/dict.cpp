#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 3e3 + 10, M = 30;
int n, m;
int a[N][M] = {};
bool cmp1(int x, int y){
    int posx = 26, posy = 26;
    while(!(posx == 0 && posy == 0)){
        posx--; posy--;
        while(a[x][posx] == 0 && posx >= 0) posx--;
        while(a[y][posy] == 0 && posy >= 0) posy--;
        if(posx < posy) return true;
        if(posx > posy) return false;
        if(posx == posy){
            if(a[x][posx] < a[y][posy]) return true;
            if(a[x][posx] > a[y][posy]) return false;
            continue;
        }
    }
    return true;
}
bool cmp2(int x, int y){
    /*int posx = -1, posy = 26;
    while(!(posx == 25 && posy == 0)){
        posx++; posy--;
        while(a[x][posx] == 0 && posx < 26) posx++;
        while(a[y][posy] == 0 && posy >= 0) posy--;
        //cout << posx << ' ' << posy << endl;
        if(posx < posy) return true;
        if(posx > posy) return false;
        if(posx == posy){
            if(a[x][posx] == a[y][posy] && a[x][posx] == m) return true;
            if(a[x][posx] < a[y][posy]) return true;
            if(a[x][posx] >= a[y][posy]) return false;
            continue;
        }
    }*/
    int posx = 0, posy = 25;
    while(a[x][posx] == 0 && posx < 26) posx++;
    while(a[y][posy] == 0 && posy >= 0) posy--;
    if(posx < posy) return true;
    else if(posx > posy) return false;
    else if(posx == posy){
        if(a[x][posx] == a[y][posy] && a[x][posx] == m) return true;
        else return false;
    }
}
int main(){
    //if(system("diff real.out dict.out")) cout << "WA" << endl;
    //else cout << "AC" << endl;
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    //cout << N * N * log2(N) << endl;
    scanf("%d %d", &n, &m);

    int minpos = 1;
    /*for(int j = 0; j < 26; j++){
        cout << char('a' + j) << ' ' ;
    }
    cout << endl;*/
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char ch; cin >> ch;
            a[i][ch - 'a']++;
        }
        /*for(int j = 0; j < 26; j++){
            cout << a[i][j] <<  ' ';
        }
        cout << endl;*/
        if(i == 1) continue;
        if(!cmp1(minpos, i)) minpos = i;
    }
    //cout << minpos << endl;
    for(int i = 1; i <= n; i++){
        //cmp2(i, minpos);
        //cout << endl;
        if(cmp2(i, minpos)) printf("1");
        else printf("0");
    }
    printf("\n");
    return 0;
}
