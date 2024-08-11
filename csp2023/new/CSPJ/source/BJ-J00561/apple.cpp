#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=0;
    int x=n;
    while(x){
        a++;
        if((x-1)%3==0&&!b){
            b=a;
        }
            x=x-ceill(x/3.0);
    }
    cout<<a<<" "<<b<<endl;
return 0;
}
