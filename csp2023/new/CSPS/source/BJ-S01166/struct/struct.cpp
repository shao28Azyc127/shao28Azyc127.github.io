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
struct str{
    int l,r;
    string b;
}s[200];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    n = rd();
    int now = 0;
    int cnt = 0;
    while(n--){
        int op = rd();
        if(op == 2){
           string c;
           string na;
           cin >> c >> na;
           if(c == "byte"){
                s[++cnt].l = now;
                s[cnt].r = now + 1;
                s[cnt].b = na;
                cout << now << endl;
                now += 1;

           }
           if(c == "short"){
                s[++cnt].l = now;
                s[cnt].r = now + 2;
                s[cnt].b = na;
                cout << now << endl;
                now += 2;
           }
           if(c == "int"){
                s[++cnt].l = now;
                s[cnt].r = now + 4;
                s[cnt].b = na;
                cout << now << endl;
                now += 4;
           }
           if(c == "long"){
                s[++cnt].l = now;
                s[cnt].r = now + 8;
                s[cnt].b = na;
                cout << now << endl;
                now += 8;
           }

        }
        if(op == 3){
            string c;
            cin >>c;
            for(int i =1; i <= cnt; i ++){
                if(s[i].b == c){
                    cout << s[i].l << endl;
                    break;
                }
            }

        }
        if(op == 4){
            int r =rd();
            for(int i = 1; i <= cnt; i ++){
                if(s[i].l <= r &&s[i].r >= r){
                    cout << s[i].b << endl;
                    break;
                }
            }

        }
    }

    //cout << endl << endl << s[2].b;
    return 0;
}
