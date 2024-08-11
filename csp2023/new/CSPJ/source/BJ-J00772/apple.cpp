#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    int p=0;
    while(n!=0){
        sum++;
        if(((n-1)%3==0||n==1)&&p==0)
        {
            p=sum;
        }
        if(n%3!=0)
        {
            n-=n/3+1;
        }else
        {
            n-=n/3;
        }
    }
    cout<<sum<<" "<<p<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
