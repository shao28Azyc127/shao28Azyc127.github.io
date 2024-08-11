#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
char s[N];
bool tp[N];
stack<int> stk;
vector<int> v;
long long dfs(int st,int fn){
    int flag1 = 0;
    for(int i = st; i <= st+fn>>1; i++){
        if(tp[i]){
            flag1 = 1;
            break;
        }
    }
    if(!flag1)return (fn-st+1)>>1;
    long long res = 0;
    int j = 0;
    long long cnt = 0;
    int s1=st;
    for(int i = st; i <= fn;i++){
        if(!tp[i])j++;
        else j--;
        if(!j){
            res += dfs(s1,i);
            s1 = i+1;
            cnt++;
        }
    }
    return res+cnt*(cnt-1)/2;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",&s);
    stk.push(s[0]);

    for(int i = 1; i < n; i++){

        if(stk.size()&&stk.top()==s[i])tp[i] = true,stk.pop();
        else stk.push(s[i]);

    }
    printf("%lld\n",dfs(0,n-1));
    return 0;
}
