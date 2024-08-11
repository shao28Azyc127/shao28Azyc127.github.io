#include<bits/stdc++.h>
using namespace std;
const int MAX=1e7;
int n,apple[MAX];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    long long cou=0,aday=-1,cnt=0,j;
    queue<int>q;
    for(int i=0;i<n;i++){
        apple[i]=i+1;
    }
    for(j=1;cnt<n;j++){
        int c=0;
        for(int i=0;i<n;i++){
            if(apple[i]==-1){
                continue;
            }
            else{
                if(c%3==0){
                    if(apple[i]==n){
                        aday=j;
                    }
                    cnt++;
                    apple[i]=-1;
                }
                c++;
            }
        }
    }
    cout<<j-1<<" "<<aday;
    return 0;
}
