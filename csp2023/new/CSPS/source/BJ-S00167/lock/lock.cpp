#include <iostream>
#include <cstdio>
using namespace std;
int n,l[8][5],ls[100001][5],etop=0;

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>l[i][j];
        }
    }
    //special kind:
    if(n==1){
        cout<<(10-1)*5+(10-1)*4;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}