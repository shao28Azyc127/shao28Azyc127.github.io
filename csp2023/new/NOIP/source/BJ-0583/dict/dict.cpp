#include<bits/stdc++.h>

using namespace std;
const int N = 3333;

//string alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p, q, r, s, t, u, v, w, x, y, z};

int alp[N][N];
int n, m;
bool vis[N];
void op(int i){
    int cnt = 0;
    int arr[N];
    for(int j = 0; j < m; j++){
        int x = getchar();
        arr[cnt++] =  x-96;
    }
    sort(arr, arr+m);
    for(int j = 0; j < m; j++){
        //cout << arr[j] <<" ";
        alp[i][j] = arr[j];
    }
    /*
    cout << endl;
    for(int j = 0; j < m; j++){
        cout << alp[i][j] <<" ";
    }
    cout << endl;
    */
}

bool all(){
    for(int i = 1; i <= n; i++){
        if(!vis[i]) return false;
    }
    return true;
}

bool check(int i){
    memset(vis, 0, sizeof(vis));
    vis[i] = true;
    for(int j = 0; j < m; j++){
        for(int k = 1; k <= n; k++, k != i){
            if(vis[k]) continue;
            if(alp[i][j] < alp[k][m-j-1]){
                vis[k] = true;
            }
            if(alp[i][j] > alp[k][m-j-1]){
                return false;
            }
        }
        if(all()) return true;
    }
    return false;
}

/*
4 7
abandon
bananaa
baannaa
notnotn
*/

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1;i <= n; i++){
        getchar();
        op(i);
    }
    for(int i = 1; i <= n; i++){
        if(check(i)) cout << "1";
        else cout << "0";
    }
    return 0;
}
