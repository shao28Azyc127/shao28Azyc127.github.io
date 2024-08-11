#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
using namespace std;
int n,step;
int a[1000000];
int findnum(int x){
    int sum = 0;
    int i;
    for (i=x;i<=n;i++){
        if (a[i]==0) sum+=1;
        if (sum==3) break;
    }
    if (sum==3) return i;
    return -1;
}
int ffn(int x){
    for (int i=x;i<=n;i++){
        if (a[i]==0) return i;
    }
    return -1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf ("%d", &n);
    while(1){
        step+=1;
        int ffe = ffn(1);
        if (ffe==-1) break;
        for (int i=ffe;i<=n;i++){
            a[i] = step;
            int fne = findnum(i);
            if (fne==-1) break;
            i = fne-1;
        }
        if (a[n]!=0) break;
    }
    printf ("%d %d\n", step, a[n]);
    return 0;
}
// 0 0 0 0 5 0 0 8
//if i cant made 1st,i maybe AFO....qwq