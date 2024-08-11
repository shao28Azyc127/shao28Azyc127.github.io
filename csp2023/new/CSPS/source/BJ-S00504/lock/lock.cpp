#include<bits/stdc++.h>
using namespace std;
struct number{
    int a,b,c,d,e;
}num[10];
int cnt[5],look[5];
bool check(int a1,int b1,int c1,int d1,int e1,int a2,int b2,int c2,int d2,int e2){
    int flag = 0;
    for(int i = 0;i<5;i++){
        cnt[i] = 0;
        look[i] = 0;
    }
    if(a1 != a2){
        look[flag] = 1;
        cnt[flag] = a1-a2;
        flag++;
    }
    if(b1 != b2){
        look[flag] = 2;
        cnt[flag] = b1-b2;
        flag++;
    }
    if(c1 != c2){
        look[flag] = 3;
        cnt[flag] = c1-c2;
        flag++;
    }
    if(d1 != d2){
        look[flag] = 4;
        cnt[flag] = d1-d2;
        flag++;
    }
    if(e1 != e2){
        look[flag] = 5;
        cnt[flag] = e1-e2;
        flag++;
    }
    if(flag > 2 || flag == 0) return false;
    else if(flag==1){
        return true;
    }
    else if(abs(look[0]-look[1]) != 1){
        return false;
    }
    else{
        if((10+cnt[0])%10 == (10+cnt[1])%10){
            return true;
        }
        else{
            return false;
        }
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,h,all = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>num[i].a>>num[i].b>>num[i].c>>num[i].d>>num[i].e;
    }
    for(int k1 = 0;k1<10;k1++){
        for(int k2 = 0;k2<10;k2++){
            for(int k3 = 0;k3<10;k3++){
                for(int k4 = 0;k4<10;k4++){
                    for(int k5 = 0;k5<10;k5++){
                        h = 0;
                        for(int i = 1;i<=n;i++){
                            bool g = check(k1,k2,k3,k4,k5,num[i].a,num[i].b,num[i].c,num[i].d,num[i].e);
                            if(g == false){
                                h = 1;
                            }
                        }
                        if(h == 0){
                            all++;
                        }
                    }
                }
            }
        }
    }
    cout<<all;
    return 0;
}
