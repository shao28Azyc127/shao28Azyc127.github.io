#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i,k,j,a=-2,x=0,y;
    cin>>n;
    k=n;
    for(i=1;i<=n;i++){
        if(k==0){
            break;
        }
        a+=3;
        if(a>n){
            x++;
            a=i+1;
        }
        else if(a==n){
            x++;
            k-=1;
            y=x;
        }
        else k-=1;
    }
    cout<<x<<" "<<y;
}
