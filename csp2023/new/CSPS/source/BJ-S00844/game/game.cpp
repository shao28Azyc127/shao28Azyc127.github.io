#include<bits/stdc++.h>
using namespace std;

struct X{
    int id;
    char c;
};
stack<X>st;
char s[1000010];
int n,cnt;
vector<pair<int,int> >v;
long long sum,num[100010];
bool ch(int l,int r){
    while(st.size())st.pop();
    for(int i=l;i<=r;i++){
        if(st.size()&&st.top().c==s[i]){
            st.pop();
        }
        else st.push({0,s[i]});
    }
    return st.empty();
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",s+1);
    if(n>=500){
        for(int i=1;i<=n;i++){
            if(st.size()&&st.top().c==s[i]){
                v.push_back({st.top().id,i});
                num[st.top().id]++;
                st.pop();
            }
            else st.push({i,s[i]});
        }
        for(int i=v.size()-1;i>=0;i--){
            num[v[i].first]+=num[v[i].second+1];
        }
        for(int i=1;i<=n;i++){
            sum+=num[i];
        }
        printf("%lld",sum);
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(ch(i,j))sum++;
            }
        }
        printf("%lld",sum);
    }
    return 0;
}
