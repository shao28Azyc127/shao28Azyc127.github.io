#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int readui(){
    char c=getchar();
    int f=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){f=f*10+(c-48);c=getchar();}
    return f;
}

inline int solve2(int n){
    int ans=0;
    while(n) n-=(n-1)/3+1,ans++;
    return ans;
}

inline void solve(int n){
    int ans1=0,ans2;
    for(int i=1;i<=n;i++) v.push_back(i);
    while(!v.empty()){
        for(int i=0;i<v.size();i+=2){
            if(v[i]==n) ans2=ans1+1;
            v.erase(v.begin()+i);
        }
        ans1++;
    }
    printf("%d %d",ans1,ans2);
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n=readui();
    if(n%3==1) printf("%d 1",solve2(n));
    else if(n%9==2||n%9==6) printf("%d 2",solve2(n));
    else if(n%27==3||n%27==9||n%27==17||n%27==23) printf("%d 3",solve2(n));
    else solve(n);
    puts("");
    return 0;
}