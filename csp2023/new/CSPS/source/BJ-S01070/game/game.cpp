#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
char str[N];
int n;
vector<int> pile;
int judge(int l, int r){
    pile.clear();
    int index_=l;
    while(index_<=r){
        if(pile.empty()){
            pile.push_back(str[index_]);
        }
        else if(str[index_]==pile.back()){
            pile.pop_back();
        }
        else{
            pile.push_back(str[index_]);
        }
        index_++;
    }
    if(pile.empty()) return 1;
    return 0;
}
int main(){
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    long long res=0;
    for(int i=1;i<=n-1;i++){
        int l=i;
        for(int j=i+1;j<=n;j++){
            if(j<=l) continue;
            if(j==l+1 && str[l]==str[j]){

                res++;
                l=j+1;
            }
            else if((j-l)%2==0) continue;
            else{
                if(judge(l, j)){
                    l=j+1;
                    res++;
                }
            }
        }
    }
    cout<<res;
    return 0;
}
