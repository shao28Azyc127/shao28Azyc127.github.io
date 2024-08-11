//game.cpp
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> P;//F:len SFl SSr
queue<P> qu;
char ch[200005];
vector<int> ls[200005];
long long ans=0;
int len;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&len);
    scanf("%s",ch);
    for(int i=0;i<len-1;i++){
        if(ch[i]==ch[i+1]){
            P st;
            st.first=2;
            ls[st.second.first].push_back(st.second.second);
            st.second.first=i;
            st.second.second=i+1;
            qu.push(st);
            ans++;
        }
    }
    while(!qu.empty()){
        P fa=qu.front();
        qu.pop();
        if(fa.second.first>0 && fa.second.second<len-1 && ch[fa.second.first-1]==ch[fa.second.second+1]){
            P zi;
            zi.first=fa.first+2;
            zi.second.first=fa.second.first-1;
            zi.second.second=fa.second.second+1;
            ls[zi.second.first].push_back(zi.second.second);
            ans++;
            qu.push(zi);
        }
        int siz=ls[fa.second.second+1].size();
        for(int i=0;i<siz;i++){
            if(ls[fa.second.second+1][i]-fa.second.second==fa.first){
                P zi;
                zi.first=fa.first*2;
                zi.second.first=fa.second.first;
                zi.second.second=ls[fa.second.second+1][i];
                ans++;
                qu.push(zi);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
