#include<bits/stdc++.h>
using namespace std;
char a[101];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin>>n;
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    int cnt = 0;
    int i = 2;
    int m = n;
    while(m!=0){

        if(a[i]==a[i-1]){
            cnt++;
            for(int j = i+1;j<=sizeof(a);j++){
                a[j-2] = a[j];
            }
            i--;
        }
        else if(i == 0){
            i++;
        }
        else if(a[i] != a[i-1]){
            i++;
        }

        m--;

    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
