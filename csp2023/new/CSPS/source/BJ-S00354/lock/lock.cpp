#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct lock{
    int a[6];
}l[9],can[9][90];
void build(int p){
    int last = 0;
    for(int i = 1; i <= 5; i++){
        for(int j = 0; j <= 9; j++){
            if(l[p].a[i] == j) continue;
            can[p][++last] = l[p];
            can[p][last].a[i] = j;
        }
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 9; j++){
            can[p][++last] = l[p];
            can[p][last].a[i] += j;
            can[p][last].a[i] %= 10;
            can[p][last].a[i+1] += j;
            can[p][last].a[i+1] %= 10;
        }
    }
}
void print(lock x){
    for(int i = 1; i <= 5; i++){
        cout<<x.a[i];
    }
    printf(" \n");
}
int cmp(lock x,lock y){
    for(int i = 1; i <= 5; i++){
        if(x.a[i] > y.a[i]){
            return 1;
        }
        if(x.a[i] < y.a[i]){
            return 0;
        }
    }
    return 2;
}
int n;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        char ch;
        for(int j = 1; j <= 5; j++){
            cin>>ch;
            //cout<<(j-1)*2<<endl;
            l[i].a[j] = ch - '0';
        }
        //print(l[i]);
        build(i);
    }
    lock ans[90];
    for(int i = 1; i < 90; i++){
        ans[i] = can[1][i];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < 90; j++){
            if(cmp(ans[j],ans[89]) == 2){
                continue;
            }
            bool flag = 0;
            for(int k = 1; k < 90; k++){
                if(cmp(ans[j],can[i][k]) == 2){
                    flag = 1;
                }
            }
            if(flag == 0){
                memset(ans[j].a,0,sizeof(ans[j].a));
            }
        }
    }

    int answer = 0;
    lock zero;
    memset(zero.a,0,sizeof(zero.a));
    for(int j = 1; j < 90; j++){
        if(cmp(ans[j],zero) == 2) continue;
        //print(ans[j]);
        answer++;
    }
    cout<<answer<<endl;
    return 0;
}
