#include <bits/stdc++.h>
using namespace std;

int n,sum,d,cnt,pos;
short a[1000000000];
bool flag = false;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    sum = n;
    while(sum){
        cnt = 2;
        for(int i = 0;i < n;i++){
            if(!a[i]){
                if(cnt == 2){
                    cnt = 0;
                    sum--;
                    a[i] = 1;
                    if(i == n-1)pos = d+1;
                }
                else cnt++;
            }
        }
        d++;
    }
    printf("%d %d",d,pos);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
