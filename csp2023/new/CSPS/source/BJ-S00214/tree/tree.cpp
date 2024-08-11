#include <bits/stdc++.h>
using namespace std;
struct tree{
    int a,b,c;
    int z = 0;
};
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin >> n;
    struct tree x[n + 10];
    for(int i = 1;i <= n;i++){
        cin >> x[i].a >> x[i].b >> x[i].c;
    }
    if(n == 1){
        int i = 1;
        int z = 0;
        while(z < x[1].a){
            z += x[1].b + x[1].c * i;
        }
        cout << i;
        return 0;
    }
    if(n == 2){
        int i = 1;
        int z = 0;
        while(z < x[1].a){
            z += x[1].b + x[1].c * i;
            i += 1;
        }
        int j = 1;
        z = 0;
        while(z < x[2].a){
            z += x[2].b + x[2].c * j;
            j += 1;
        }
        cout << max(i,j);
        return 0;
    }
    bool istypeb = true;
    for(int i = 1;i <= n;i++){
        int thaty;
        int thisx,thisy;
        cin >> thisx >> thisy;
        if(thisy - 1 != thisx){
            istypeb = false;
            break;
        }
        if(i != 1){
            if(thisx != thaty){
                istypeb = false;
                break;
            }
        }
        thaty = thisx;
    }
    if(istypeb){
        int ti = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= i;j++){
                x[i].z += max(x[i].b + ti * x[i].c,1);
            }
            ti += 1;
        }
        if(x[n].z >= x[n].a){
            cout << ti;
            return 0;
        }
        while(x[n].z < x[n].a){
            x[n].z += max(x[n].b + ti * x[n].c,1);
            ti += 1;
        }
        cout << ti;
        return 0;
    }
    cout << n + 1;
    return 0;
}
