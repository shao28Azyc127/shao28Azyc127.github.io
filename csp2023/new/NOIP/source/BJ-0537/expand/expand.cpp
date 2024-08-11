#include <bits/stdc++.h>
using namespace std;
int c,n,m,q;
int x[10],y[10];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= m; i++) cin >> y[i];
    if(c == 1){
        if(x[1]==y[1]) cout <<"0";
        else cout << "1";
        for(int i = 1; i <= q; i++){
            int x1,y1;
            cin >> x1 >> y1;
            for(int j = 1; j <= x1; j++){
                int a,b;
                cin >> a >> b;
                x[a]=b;
            }
            for(int j = 1; j <= y1; j++){
                int a,b;
                cin >> a >> b;
                y[a]=b;
            }
            if(x[1]!=y[1]) cout << "1";
            else cout << "0";
        }
    }
    if(c == 2){
        if(x[1]==y[1]||x[1]==y[2]||x[2]==y[1]||x[2]==y[2]) cout <<"0";
        else if((x[1]-y[1]>0&&x[2]<y[2])||(x[1]<y[1]&&x[2]>y[2])) cout << "0";
        else cout << "1";
        for(int i = 1; i <= q; i++){
            int x1,y1;
            cin >> x1 >> y1;
            for(int j = 1; j <= x1; j++){
                int a,b;
                cin >> a >> b;
                x[a]=b;
            }
            for(int j = 1; j <= y1; j++){
                int a,b;
                cin >> a >> b;
                y[a]=b;
            }
            if(x[1]==y[1]||x[1]==y[2]||x[2]==y[1]||x[2]==y[2]) cout <<"0";
            else if((x[1]-y[1]>0&&x[2]<y[2])||(x[1]<y[1]&&x[2]>y[2])) cout << "0";
            else cout << "1";
        }
    }
    return 0;
}
