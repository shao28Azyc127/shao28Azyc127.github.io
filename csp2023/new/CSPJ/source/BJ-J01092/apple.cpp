#include<bits/stdc++.h>
using namespace std;
int xsqz(int x,int c){
    if(x%c==0) return x/c;
    else return x/c+1;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans2=1;
    int i=n;
    while(i%3!=1){
        ans2++;
        i-=xsqz(i,3);
    }
    int ans1=0;
    i=n;
    while(i>0){
        ans1++;
        i-=xsqz(i,3);
    }
    cout<<ans1<<" "<<ans2<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
