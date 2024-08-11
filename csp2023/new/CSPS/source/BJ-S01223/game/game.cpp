#include<bits/stdc++.h>
using namespace std;
char a[2000000];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    cin>>a;
    int cnt = 0;
    bool flag = true;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((i-j+1)%2!=0){
                continue;
            }
            flag = true;
            for(int k=j;k<j+(i-j+1)/2;k++){

                if(a[k] != a[i+j-k]){
                    flag = false;
                }
            }

            if(flag){
                cnt++;
            }

        }
    }
    cout<<cnt;
    return 0;
}

