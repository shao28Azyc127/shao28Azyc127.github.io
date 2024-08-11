#include<iostream>
#include<algorithm>
using namespace std;

int n;
string s;
long long cnt = 0;

struct node{
    int x,y;
};

node p[10000005];
bool vis[10000005];
int begi[2000005][2];

void ffind(int m, int q){
    for(int i = 1; i <= min(m,n-q-1); i++){
        if(s[m-i] == s[q+i]) {
            cnt++;
            p[cnt].x = m-i;
            p[cnt].y = q+i;
        }
    }
}

bool cmp(node x, node y){
    if(x.x != y.x) return x.x < y.x;
    else return x.y < y.y;
}

void dfs(int step, int nw){
    vis[nw] = true;
    int ed = p[nw].y+1;
    //cout << ed << " ";
    if(begi[ed][0] == 0 || begi[ed][1] == 0) return ;
    for(int i = begi[ed][0]; i <= begi[ed][1]; i++){
        if(!vis[i]){
            cnt += step;
            //cout << cnt << " ";
            dfs(step+1,i);
        }
    }
    return ;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            cnt++;
            p[cnt].x = i;
            p[cnt].y = i+1;
            ffind(i,i+1);
        }
    }
    sort(p+1,p+cnt+1,cmp);
    /*for(int i = 1; i <= cnt; i++){
        cout << p[i].x << " " << p[i].y << endl;
    }*/
    //cout << cnt;

    int last = p[1].x;
    begi[p[1].x][0] = 1;
    for(int i = 1; i <= cnt; i++){
        if(last == p[i].x) continue;
        else{
            begi[last][1] = i-1;
            last = p[i].x;
            begi[last][0] = i;
        }
    }
    begi[last][1] = cnt;
    for(int i = 1; i <= cnt; i++){
        if(!vis[i]) {
            dfs(1, i);
        }
    }
    cout << cnt;
    return 0;
}
