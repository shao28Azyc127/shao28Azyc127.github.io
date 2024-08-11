#include <bits/stdc++.h>
using namespace std;

int N,M;
const int MAXN = 3006;

vector<vector<int>> strs;

// abcdefghijklmnopqrstuvwxyz


int order(int a,int b){
    return a>b;
}

vector<int> FastSort(vector<int> &v){
    int ss[100];
    memset(ss,0,sizeof(ss));
    vector<int> rslt;
    for(int i=0;i<v.size();i++){
        ss[v[i]]++;
    }
    for(int i=0;i<30;i++){
        if(ss[i]==0){
            continue;
        }
        else{
            for(int j=0;j<ss[i];j++){
                rslt.push_back(i);
            }
        }
    }
    return rslt;
}

// T1
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        char str[MAXN];
        cin>>str;
        strs.push_back(vector<int>());
        //Str2Int
        for(int j=0;j<M;j++){
            int x=str[j]-'a';
            strs[i].push_back(x);
            //cout<<x<<endl;
        }
        //cout<<endl;
    }


    for(int i=0;i<N;i++){
        //Spc judge
        if(N==1){
            cout<<1;
        }
        else if(N<=30){
            int ans=1;
            sort(strs[i].begin(),strs[i].end());
            for(int j=0;j<N;j++){
              if(j!=i){
                sort(strs[j].begin(), strs[j].end(), order);
                for(int k=0;k<M;k++){
                    if(strs[i][k]>strs[j][k]){
                            //cout<<strs[i][k]<<">"<<strs[j][k]<<endl;
                        ans=0;
                    break;
                    }
                    else if(strs[i][k]<strs[j][k]){
                        break;
                    }
                }
               }
            }
            cout<<ans;
        }
        else{
            int ans=1;
            vector<int> ii = FastSort(strs[i]);
            for(int j=0;j<N;j++){
                if(j!=i){
                    int jj[MAXN];
                    memset(jj,0,sizeof(jj));
                    int ss[100];
    int cnt=0;
    memset(ss,0,sizeof(ss));

    for(int b=0;b<strs[j].size();b++){
        ss[strs[j][b]]++;
    }
    for(int b=30;b>0;b--){
        if(ss[b]==0){
            continue;
        }
        else{
            for(int c=0;c<ss[b];c++){
                jj[cnt++] = b;
            }
        }
    }

                    for(int k=0;k<M;k++){
                        if(ii[k]>jj[k]){
                            //cout<<strs[i][k]<<">"<<strs[j][k]<<endl;
                            ans=0;
                        break;
                        }
                        else if(ii[k]<jj[k]){
                            break;
                        }
                    }
                }
            }
            cout<<ans;
        }
    }
    cout<<endl;
    return 0;
}
