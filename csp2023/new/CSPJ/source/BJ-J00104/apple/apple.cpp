#include <iostream>
using namespace std;
int n,a,b;
bool flag=false;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int s=n;
    while(s!=0){
        a+=1;
        if((s+2)%3==0&&flag==false){
            b=a;
            flag=true;
        }
        s-=(s+2)/3;

    }
    cout << a << " "<<b;
    return 0;
}
