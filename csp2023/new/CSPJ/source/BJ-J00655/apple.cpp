#include <bits/stdc++.h>
using namespace std;
int n,sum,ans,k,p,i;
vector<int> v;
bool book[1000000100];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ans=n;
    while(ans>0){
        i=1;
        while(book[i]==true)
            i++;
        v.push_back(i);
        while(i<=n){
            p=0;
            while(p<=4){
                if(book[i]==false){
                    p++;
                }
                if(p<4)
                    i++;

            }
            v.push_back(i);
        }
        for(int j=0;j<v.size();j++){
            if(v[j]<=n){
                book[v[j]]=true;
                ans--;
            }
        }
        while(v.size())
            v.pop_back();
        k++;
        if(book[n]==false)
            sum++;
    }
    cout<<k<<' '<<sum+1;
    return 0;
}
