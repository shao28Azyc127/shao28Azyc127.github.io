#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x = 0, w = 1;
    char ch = getchar();
    while(ch > '9' || ch < '0'){if(ch == '-') w *= -1; ch = getchar();}
    while(ch <= '9' && ch >= '0'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * w;
}
int states[10][6];
//bool used[10];
//bool location[6][10];
bool checksingle(int a, int b, int c, int d, int e, int checka, int checkb, int checkc, int checkd, int checke){
    int cnt = 0;
    if(a != checka) cnt ++;
    if(b != checkb) cnt ++;
    if(c != checkc) cnt ++;
    if(d != checkd) cnt ++;
    if(e != checke) cnt ++;
    return cnt == 1;
}
bool checkdoublerotate(int a, int checka, int b, int checkb){
    return checka - a != 0 && checkb - b != 0 && (checka - a == checkb - b || checka - a - checkb + b == -10 || checka - a - checkb + b == 10);//(checka - a + 10) % 10 == (checkb - b + 10) % 10;
}
bool checkdouble(int a, int b, int c, int d, int e, int checka, int checkb, int checkc, int checkd, int checke){
    int cnt = 0;
    if(checkdoublerotate(a, checka, b, checkb) && c == checkc && d == checkd && e == checke) cnt ++;
    if(checkdoublerotate(b, checkb, c, checkc) && a == checka && d == checkd && e == checke) cnt ++;
    if(checkdoublerotate(c, checkc, d, checkd) && a == checka && b == checkb && e == checke) cnt ++;
    if(checkdoublerotate(d, checkd, e, checke) && c == checkc && b == checkb && a == checka) cnt ++;
    return cnt == 1;
}
bool check(int a, int b, int c, int d, int e, int checka, int checkb, int checkc, int checkd, int checke){
    return checksingle(a, b, c, d, e, checka, checkb, checkc, checkd, checke) || checkdouble(a, b, c, d, e, checka, checkb, checkc, checkd, checke);
}
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n = read();
    for(int i=0;i<n;i++){
        for(int j=1;j<=5;j++){
            states[i][j] = read();
            //cout<<states[i][j]<<endl;
            //used[states[i][j]] = true;
            //location[j][states[i][j]] = true;
        }
    }
    if(n == 1){
        printf("%d", 81);
        return 0;
    }
    int ans = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    for(int m=0;m<10;m++){
                        bool found = true;
                        for(int ii=0;ii<n;ii++){
                            if(!check(i, j, k, l, m, states[ii][1], states[ii][2], states[ii][3], states[ii][4], states[ii][5])){
                                found = false;
                                break;
                            }
                        }
                        if(found){
                            //cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<endl;
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
