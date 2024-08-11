#include <iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int i=0;
    int n1=n;
    for(;n1;i++){
        if(n1%3==0)n1-=n1/3;
        else{
            n1-=n1/3;
            n1--;
        }
    }
    cout<<i<<' ';
    int ans=0;
    int cnt=0;
    while(n){
        cnt++;
        if(n%3==1)break;
        if(n%3==0)n-=n/3;
        else{
            n-=n/3;
            n--;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}