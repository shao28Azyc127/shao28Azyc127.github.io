#include <bits/stdc++.h>
using namespace std;
long long ans;
char a[200001];
stack<char> s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >>n;
    cin >>a;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j+=2){
            for(int l=i;l<=j;l++){
                if(s.size()>0 && s.top()==a[l]){
                    s.pop();
                    if(s.size()>1){
                        char q=s.top();
                        s.pop();

                        while(q==s.top()){
                            s.pop();
                            if(!s.empty()) q=s.top(),s.pop();
                            else q='!';
                        }
                        if(q!='!') s.push(q);
                    }

                }else s.push(a[l]);

            }
            //cout <<s.size() <<" ";
            if(s.empty()) ans++;
            else{
                while(!s.empty()) s.pop();
            }
        }
    }
    cout <<ans;
    return 0;
}
