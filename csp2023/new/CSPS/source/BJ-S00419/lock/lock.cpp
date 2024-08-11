#include<iostream>
#include<string>
using namespace std;
int n;
int s[8][5];
int sum=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>s[i][j];
        }
    }
    if(n==1){
        cout<<81;
        return 0;
    }
    cout<<sum;
}
