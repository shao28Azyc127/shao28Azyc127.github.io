#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10],c[10],d[10],e[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    std::ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int aaa,bbb,ccc,ddd,eee,aa,bbbb,cc,dd,ee;
    cin >> aa >> bbbb >> cc >> dd >> ee;
    a[1] = aa;
    b[1] = bbbb;
    c[1] = cc;
    d[1] = dd;
    e[1] = ee;
    bool ba = 0,bb = 0,bc = 0,bd = 0,be = 0;
    
    for(int i = 2;i <= n;i++){
        cin >> aaa >> bbb >> ccc >> ddd >> eee;
        a[i] = aaa;
        b[i] = bbb;
        c[i] = ccc;
        d[i] = ddd;
        e[i] = eee;
        if(aaa != aa)ba = 1;
        if(bbb != bbbb)bb = 1;
        if(ccc != cc)bc = 1;
        if(ddd != dd)bd = 1;
        if(eee != ee)be = 1;
    }
    if(ba+bb+bc+bd+be >= 3){
        cout << "0" << endl;
        return 0;
    }
    else if(ba+bb+bc+bd+be == 2){
        if((ba == 1 and bb == 1) or (bb == 1 and bc == 1) or (bc == 1 and bd == 1) or (bd == 1 and be == 1)){
            int cnt = 0,sum = 0;
            for(int i = 1;i <= n;i++){
                int ans;
                if(ba == 1 and bb == 1){
                    ans = a[i] - b[i];
                    if(ans != cnt){
                        cnt = ans;
                        sum++;
                    }
                }
                else if(bb == 1 and bc == 1){
                    ans = b[i] - c[i];
                    if(ans != cnt){
                        cnt = ans;
                        sum++;
                    }
                }
                else if(bc == 1 and bd == 1){
                    ans = c[i] - d[i];
                    if(ans != cnt){
                        cnt = ans;
                        sum++;
                    }
                }
                else{
                    ans = d[i] - e[i];
                    if(ans != cnt){
                        cnt = ans;
                        sum++;
                    }
                }
            }
            if(sum > 1){
                cout << "0";
            }
            else{
                cout << 10 - n;
            }
            
        }
        else{
            cout << "0" << endl;
            return 0;
        }
        
    }
    if(ba+bb+bc+bd+be == 1){
        cout << 12 - n << endl;
    }
    else{
        cout << "81" << endl;
    }
    
    return 0;
}
