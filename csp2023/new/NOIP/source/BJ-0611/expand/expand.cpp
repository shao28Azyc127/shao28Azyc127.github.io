#include<bits/stdc++.h>

using namespace std;

long long c,n,m,q;
long long x[500005],y[500005],kx[65],ky[65],px[500005],py[500005],vx[500005],vy[500005],copyx[500005],copyy[500005];
bool xin[500005],yout[500005];
string s;

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin >> c >> n >> m >> q;
    s = "";
    for(int i = 1;i<=n;i++){
        cin >> x[i];
    }
    for(int i = 1;i<=m;i++){
        cin >> y[i];
    }
    for(int i = 1;i<=q;i++){
        cin >> kx[i] >> ky[i];
        for(int j = 1;j<=kx[i];j++){
            cin >> px[j] >> vx[j];
        }
        for(int j = 1;j<=ky[i];j++){
            cin >> py[j] >> vy[j];
        }
    }
    if(c == 1){
        if(x[1]<=y[1]){
            s+="0";
        }
        else{
            s+="1";
        }
        for(int i = 1;i<=q;i++){
            if(kx[i]!=0){
                if(ky[i]!=0){
                    if(vx[kx[i]]<=vy[ky[i]]){
                        s+="0";
                    }
                    else{
                        s+="1";
                    }
                }
                else{
                    if(vx[kx[i]]<=y[1]){
                        s+="0";
                    }
                    else{
                        s+="1";
                    }
                }
            }
            else{
                if(ky[i]!=0){
                    if(x[1]<=vy[ky[i]]){
                        s+="0";
                    }
                    else{
                        s+="1";
                    }
                }
                else{
                    if(x[1]<=y[1]){
                        s+="0";
                    }
                    else{
                        s+="1";
                    }
                }
            }
        }
    }
    else{
        for(int i = 1;i<=q+1;i++){
            for(int j = 1;j<=n;j++){
                xin[j] = false;
                copyx[j] = x[j];
            }
            for(int j = 1;j<=m;j++){
                yout[j] = false;
                copyy[j] = y[j];
            }
            if(i != 1){
                for(int j = 1;j<=kx[i-1];j++){
                    copyx[px[j]] = vx[j];
                }
                for(int j = 1;j<=ky[i-1];j++){
                    copyy[py[j]] = vy[j];
                }
            }
            //for(int j = 1;j<=n;j++){
            //    cout << copyx[j] << " ";
            //}
            //cout << endl;
            //for(int k = 1;k<=m;k++){
            //    cout << copyy[k] << " ";
            //}
            //cout << endl;
            for(int j = 1;j<=n;j++){
                if(xin[j] == true){
                    continue;
                }
                for(int k = 1;k<=m;k++){
                    if(yout[k] == true){
                        continue;
                    }
                    if(copyx[j] > copyy[k]){
                        xin[j] = true;
                        yout[k] = true;
                    }
                }
            }
            bool flag = true;
            for(int j = 1;j<=n;j++){
                if(!xin[j]){
                    flag = false;
                    break;
                }
            }
            for(int j = 1;j<=m;j++){
                if(!flag){
                    break;
                }
                if(!yout[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){s+="1";}
            else{s+="0";}
        }
    }
    cout << s << endl;
    return 0;
}
