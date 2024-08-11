#include<bits/stdc++.h>
using namespace std;
bool a[1000000005];
int n, sum, d, c=-1, s;
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(sum!=n){
        d++;
        s=0;
        for(int i=0;i<n;i++){
            if(!a[i]){
                s++;
                if(s%3==1){
                    a[i]=1;
                    sum++;
                    if(i==n-1){
                        c=d;
                    }
                }
            }
        }
    }
    printf("%d %d", d, c);
    return 0;
}
