#include<bits/stdc++.h>
using namespace std;
bool live[1000000001];
bool isempty(int n){
    for(int i=0;i<n;i++){
        if(live[i]==true){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,day=1,i=0,lastapple;
    cin>>n;
    for(i=0;i<n;i++){
        live[i]=true;
    }
    while(!isempty(n)){
        int count1=0;
        for(int i=0;i<n;i++){
            if(live[i]==true){
                if(count1%3==0){
                    live[i]=false;
                    count1++;
                    if(i==n-1){
                        lastapple=day;
                    }
                }
                else{
                    count1++;
                }
            }
        }
        day++;
    }
    cout<<day-1<<' '<<lastapple<<endl;
    return 0;
}