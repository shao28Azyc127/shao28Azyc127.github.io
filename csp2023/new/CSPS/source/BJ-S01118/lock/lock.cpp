#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e9+5;
struct fnum{
    int a[5];
};
bool near(fnum n,fnum m){
    int dif=0,d[5] = {0};
    for(int i = 0;i < 5;i++){
        if(n.a[i] != m.a[i]) dif++,d[i]=n.a[i]-m.a[i];
    }
    if(dif == 1) return 1;
    else if(dif ==2){
        for(int i = 0;i < 4;i++){
            if(d[i]==d[i+1]&&d[i]) return 1;
        }
    }
    return 0;
}
vector <fnum> pos;bool mark[maxn];
void add(int a1,int b1,int c1,int d1,int e1){
    fnum all;
    all.a[0] = a1,all.a[1] = b1,all.a[2] = c1,all.a[3] = d1,all.a[4] = e1;
    for (int i = 1; i <= 9; i++){
        for(int j = 0;j < 5;j++){
            all.a[j]+=i;all.a[j]%=10;
            pos.push_back(all);
            all.a[j]+=(10-i);all.a[j]%=10;
        }
    }
    for (int i = 1; i <= 9; i++){
        for (int j = 0; j < 4; j++){
            int k = j+1;
            all.a[j]+=i;all.a[k]+=i;all.a[j]%=10;all.a[k]%=10;pos.push_back(all);all.a[j]+=(10-i);all.a[k]+=(10-i);all.a[j]%=10;all.a[k]%=10;
        }

    }

}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin >> n;
    int r1,r2,r3,r4,r5;
    cin >> r1 >> r2 >> r3 >> r4 >>r5;
    add(r1,r2,r3,r4,r5);
    while(--n){
        fnum lve;
        for (int i = 0; i < 5; i++)
        {
            cin >> lve.a[i];
        }
        for(int i = 0;i < 81;i++){
            if(mark[i])continue;
            if(!near(lve,pos[i])) mark[i]=1;
        }
    }
    int ans = 0;
    for(int i = 0;i < 81;i++){
        if(!mark[i]){
            ans++;
  //          cout << pos[i].a[0] << pos[i].a[1] << pos[i].a[2] << pos[i].a[3] << pos[i].a[4]<<"\n";
        }
    }
    cout << ans;
    return 0;
}
