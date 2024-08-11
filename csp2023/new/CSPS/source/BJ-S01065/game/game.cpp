#include<bits/stdc++.h>
using namespace std;
long long nsum=0;
char a[1000010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w".stdout);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            sum++;
        }
    }
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
