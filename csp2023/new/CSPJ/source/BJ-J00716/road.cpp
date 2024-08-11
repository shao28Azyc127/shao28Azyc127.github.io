#include<bits/stdc++.h>
using namespace std;
int dis[100010],price[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m;
    long long num = 0;
    cin>>n>>m;
    for(int i = 0;i<n-1;i++){
        cin>>dis[i];
    }
    for(int i = 0;i<n;i++){
        cin>>price[i];
    }
    int left = 0;
    for(int i = 0;i<n-1;i++){
        int j,leng = 0;
        if (left>=dis[i]){
            left -= dis[i];
            continue;
        }
        for(j = i+1;j<n;j++){
            leng+=dis[j-1];
            if(j==n){
                j--;
                break;
            }
            if(price[j]<price[i]){
                break;
            }
        }
        if((leng-left) % m == 0){
            num += ((leng-left) / m) * price[i];
            left = 0;
        }
        else{
            num += ((leng-left) / m + 1) * price[i];
            left = (leng-left)%m;
        }
        i = j-1;
    }
    cout<<num;
    return 0;
}
