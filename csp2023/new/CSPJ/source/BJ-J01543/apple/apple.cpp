#include<bits/stdc++.h>
using namespace std;
long long a[1000000000],n,day=0,i=1,j=1;
int b[1000000000];
int f(long long m){
    while(i<=m){
        if(i==1||i%3==0){
            continue;
            day++;
        }
        else{
            b[j]=i;
            f(m);
        }
        j++;
        i+=2;
    }
    return day;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cout<<f(n)<<" "<<f(n)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
