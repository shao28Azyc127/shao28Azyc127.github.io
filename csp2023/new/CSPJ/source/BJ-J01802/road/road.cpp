#include<bits/stdc++.h>
using namespace std;
int price[100001],s[100001];
double sumprice(int d,int from,int to){
    int i=1;
    if(to-from==1) return price[from]*s[from]/d;
    else{
        int minwh=from,minprice=price[from];
        for(;i<to-from-1;i++){
            if(price[from+i]<minprice){
                minprice=price[from+i];
                minwh=from+i;
            }
        }
        if(minprice==price[from]){
            int sum=0;
            for(int i=from;i<to;i++) sum+=s[from];
            return sum*price[from];
        }
        return sumprice(d,from,from+i)/d+sumprice(d,from+i,to)/d;
    }
}
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    int n,d,i=0,minprice,minpx=0;
    cin>>n>>d;
    for(;i<n-1;i++){
        cin>>s[i];
    }
    for(i=0;i<n;i++){
        cin>>price[i];
    }
    cout<<sumprice(d,0,n-1);
    return 0;
}
