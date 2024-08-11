#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int a,b,c;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        int num=b*b-4*a*c;
        if(num<0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
