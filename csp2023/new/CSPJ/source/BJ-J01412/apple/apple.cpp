#include<iostream>
using namespace std;
const int M=1e9+5;
int m1,m2,num,n1;
bool a[M];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    int sum=2;
    cin>>n;
    while(1){
        sum=2;
        n1++;
        for(int i=1;i<=n;i++){
            if(!a[i]){
                sum++;
            }
            if(sum==3){
                a[i]=true;
                sum=0;
                num++;
                if(i==n) m2=n1;
            }
        }
        if(num==n){
            m1=n1;
            break;
        }
    }
    cout<<m1<<" "<<m2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}