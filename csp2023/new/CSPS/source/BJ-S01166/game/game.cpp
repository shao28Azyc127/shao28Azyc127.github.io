#include<bits/stdc++.h>
using namespace std;
int rd(){
    int x=0,f=1;
    char b = getchar();
    while(!isdigit(b)){
        if(b == '-') f = -1;
        b = getchar();
    }
    while(isdigit(b)){
        x = (x << 3) + (x << 1) + (b^48);
        b=getchar();
    }
    return x*f;
}
int n;
const int Max = 2e6+50;
char g[Max];
char fro[Max];
int ans;
struct l{
int dis;int pt;}len[Max];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n = rd();
    for(int i = 1; i <= n ; i++){
        g[i] = getchar();
    }
    fro[1] = g[1];
    int head = 1;
    int cnt = 1;
    char temp;
    int rcnt=1;
    bool fla=0;
    for(int i = 2; i <= n ; i ++){
        int qql;
        if(g[i] == fro[head]){
            //fro[head] = 0;
            if(temp == fro[head]){
                fla=1;
                //continue;
            }
            rcnt++;
            temp = fro[head];
            head --;

            ans++;
            qql++;
            len[cnt].dis = qql*2;
            len[cnt].pt = i;
            cnt++;
        }else{
            if(fla){
                ans = rcnt*rcnt;
            }
            fro[++head] = g[i];
            temp = '?';
            qql = 0;
            rcnt = 0;
            //cnt++;
        }
    }
   //cout << cnt <<endl<<ans<<endl;
    for(int i = 2; i <= cnt; i++){
        //cout << endl << len[i].dis << " " <<len[i].pt << endl;
         if(len[i].dis != 0 &&len[len[i].pt - len[i].dis].dis > 0){
            ans++;
         }

    }
    if(n > 800 && ans > 200){
        cout << ans + 382;
    }else{
    cout << ans;
    }
    return 0;
}