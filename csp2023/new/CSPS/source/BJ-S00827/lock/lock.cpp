#include <bits/stdc++.h>
using namespace std;
int n;
int a[15][6];
long long sum = 0;
bool pd(int x1,int x2,int x3,int x4,int x5){
    for(int i = 1; i <= n; i++){
        if(x1 == a[i][1] && x2 == a[i][2] && x3 == a[i][3] && x4 == a[i][4] && x5 == a[i][5]) return false;
    }
    int tt = 0;
    for(int i = 1; i <= n; i++){
        int fg=0;
        if(x1 == a[i][1])fg++;
        if(x2 == a[i][2])fg++;
        if(x3 == a[i][3])fg++;
        if(x4 == a[i][4])fg++;
        if(x5 == a[i][5])fg++;
        if(fg < 3) return false;
        if(fg == 4){
            tt++;
            continue;
        }
        else if(fg == 3){
            int s1=0,s2=0,ss1=0,ss2=0;
            int flag=0;
            if(x1!=a[i][1]&&x2!=a[i][2]){
                s1=x1;
                s2=x2;
                ss1=a[i][1];
                ss2=a[i][2];
                flag++;
            }
            else if(x3!=a[i][3]&&x2!=a[i][2]){
                s1=x3;
                s2=x2;
                ss1=a[i][3];
                ss2=a[i][2];
                flag++;
            }
            else if(x3!=a[i][3]&&x4!=a[i][4]){
                s1=x3;
                s2=x4;
                ss1=a[i][3];
                ss2=a[i][4];
                flag++;
            }
            else if(x5!=a[i][5]&&x4!=a[i][4]){
                s1=x5;
                s2=x4;
                ss1=a[i][5];
                ss2=a[i][4];
                flag++;
            }
            if(flag==0)continue;
            if(s1>s2&&ss1<ss2&&s1-s2==ss1-ss2+10){
                tt++;
                continue;
            }
            else if(s1<s2&&ss1>ss2&&s1-s2+10==ss1-ss2){
                tt++;
                continue;
            }
            else{
                if(s1-s2==ss1-ss2){
                    tt++;
                    continue;
                }
            }
        }
    }
    if(tt==n)return true;
    return false;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++) cin >> a[i][j];
    }
    for(int i1 = 0; i1 <= 9; i1++){
        for(int i2 = 0; i2 <= 9; i2++){
            for(int i3 = 0; i3 <= 9; i3++){
                for(int i4 = 0; i4 <= 9; i4++){
                    for(int i5 = 0; i5 <= 9; i5++){
                        if(pd(i1,i2,i3,i4,i5) == true){
                            sum++;
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
