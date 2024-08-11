#include<bits/stdc++.h>
using namespace std;
int n,m;
bool flag=true;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdin);
    cin>>n;
    for(int i=1;;i++){
        if(n%3==1&&flag){
            m=i;
            flag=false;
        }
        if(n%3!=0) n-=n/3+1;
        else n-=n/3;
        if(n==0){
            cout<<i<<' '<<m<<endl;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
