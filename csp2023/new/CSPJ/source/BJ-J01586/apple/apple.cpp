#include<iostream>
using namespace std;
long long n,n2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    n2=n;
    long long sum=0;
    long long last=0;
    bool isget=false;
    for(long long i=1;i<=n2;i++){
        long long a=n/3;
        if(n%3!=0){
            a++;
        }
        if(n<=0){
            break;
        }
        sum++;
        if(n%3==1&&isget==false){
            isget=true;
            last=sum;

        }
         n-=a;
    }
    if(isget==false){
        last=sum;
    }
   cout<<sum<<" "<<last;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
