#include <iostream>
#include<queue>
#include<set>
using namespace std;
int cnt[26],pos[26];
deque<char >s;
string a;
bool game(int l,int r){
    int len=r-l+1;
    if(len%2!=0)
        return false;
    if(len==2){
        if(a[l]==a[r])
            return true;
        else
            return false;
    }
    else{
        for(int i=l;i<=r;i++){
            if(cnt[a[i]-'a']==0)
                cnt[a[i]-'a']++,pos[a[i]-'a']=i;
            else
                cnt[a[i]-'a']==0;
                return game(pos[a[i]-'a']+1,i-1);
        }
    }
}
int main(){
    int n,ans=0;
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        s.push_back(getchar());
    }
    for(int i=0;i<=n;i++){
        a=" ";
        for(int j=1;j<s.size();j++){
            a+=s[j];
            if(a.length()%2==0)
                continue;
            if(game(i,j)){
                cout<<a<<endl;
                ans++;
            }
        }
        s.pop_front();
    }
    cout<<ans;
    return 0;
}
