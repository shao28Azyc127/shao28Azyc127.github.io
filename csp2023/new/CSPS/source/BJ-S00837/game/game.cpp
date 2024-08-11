#include <bits/stdc++.h>

using namespace std;

map<pair<int,int>,bool> mp;
vector<int> be[200003];
vector<int> en[200003];
queue<pair<int,int> > q;

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    string a;
    int l;
    cin>>l>>a;
    a=" "+a;
    int cnt=0;
    for(int i=2;i<=l;i++){
        if(a[i]==a[i-1]){
            q.push(make_pair(i-1,i));
            //be[i-1].push_back(i);
            en[i].push_back(i-1);
            mp[make_pair(i-1,i)]=true;
            cnt++;
            //cout<<i-1<<" "<<i<<endl;
        }
    }
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        if(a[p.first-1]==a[p.second+1]&&mp[make_pair(p.first-1,p.second+1)]==false){
            be[p.first-1].push_back(p.second+1);
            en[p.second+1].push_back(p.first-1);
            q.push(make_pair(p.first-1,p.second+1));
            mp[make_pair(p.first-1,p.second+1)]=true;
            cnt++;
            //cout<<p.first-1<<" "<<p.second+1<<endl;
        }
        for(int i=0;i<en[p.first-1].size();i++){
            if(mp[make_pair(en[p.first-1][i],p.second)]==false){
                be[en[p.first-1][i]].push_back(p.second);
                en[p.second].push_back(en[p.first-1][i]);
                q.push(make_pair(en[p.first-1][i],p.second));
                mp[make_pair(en[p.first-1][i],p.second)]=true;
                cnt++;
                //cout<<en[p.first-1][i]<<" "<<p.second<<endl;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
