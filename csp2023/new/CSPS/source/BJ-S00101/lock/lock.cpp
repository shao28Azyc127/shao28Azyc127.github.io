#include <iostream>
using namespace std;
const int maxn=1e6;
int n,ans;
int lock[20][20];
int stt[maxn];
int turn(int p[]){
    int ret=0;
    for(int i = 1;i <= 5;i++){
        ret=ret*10+p[i];
    }
    return ret;
}
// void opt(int p[]){
//     cout << endl;
//     for(int i = 1;i <= 5;i++) cout << p[i] << ' ';
//     cout << endl;
// }
void sch(int p[]){
    for(int i = 1;i <= 5;i++){
        int now=p[i];
        for(int j = 0;j <= 9;j++){
            if(j!=now){
                p[i]=j;
                stt[turn(p)]++;
                // opt(p);
                if(stt[turn(p)]>=n) ans++;
                p[i]=now;
            }
        }
        if(i<=4){
            int now2=p[i+1];
            for(int j = 1;j <= 9;j++){
                p[i]+=j;p[i+1]+=j;
                p[i]%=10;p[i+1]%=10;
                stt[turn(p)]++;
                // opt(p);
                if(stt[turn(p)]>=n) ans++;
                p[i]=now;p[i+1]=now2;
            }
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        int tmp=0;
        for(int j = 1;j <= 5;j++){
            cin >> lock[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        sch(lock[i]);
    }
    cout << ans;
    return 0;
}