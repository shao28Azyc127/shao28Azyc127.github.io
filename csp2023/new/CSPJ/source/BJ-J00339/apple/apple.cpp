#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int i,b=0;
    for(i=1;n>0;i++){
        int ans=n%3;
        if(ans==1){
            if(b==0) b=i;
            int x=n/3+1;
            n-=x;

        }
        else if(ans==2){
            int x=n/3+1;
            n-=x;
        }
        else{
            int x=n/3;
            n-=x;
        }
    }
    cout<<i-1<<' '<<b;
    fclose(stdin);
    fclose(stdout);
}
