#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++){
        l[i]=i+1;
    }
    int x=0;
    int ans=0;
    int an=1;
    if(n%3==1){
        ans==1;
    }
    for(int j=1;j<n+1000;j++){
            int di=0;
            an++;
        for(int i=0;i<n;i++){
            if((i+1)%3!=1){
                l[di]=l[i];
                di++;
            }
            else if(n%3==1){
                    if(x==0){
                                ans=j;
                                x++;
                    }
            }
        }
        n=di;
        if(n==1){

            cout<<an<<" ";
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}