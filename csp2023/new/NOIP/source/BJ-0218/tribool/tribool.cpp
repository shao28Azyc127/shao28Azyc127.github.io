#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int rel[100010];
int certain[100010];
int visit1[100010];
int visit2[100010];
vector <int> pretend[100010];
int unknown_sum[100010];
int pretend_T_F[100010];
int n,m;

void dfs(int sum,int pos,int level,int T_F){
    if (certain[pos] == 2){
        unknown_sum[sum] = 1;
    }
    if (level == 0){
        for (int i = 0;i < pretend[pos].size();i++){
            if (visit2[abs(pretend[pos][i])] == 0){
                visit2[abs(pretend[pos][i])] = sum;
                if (pretend[pos][i] > 0){
                    pretend_T_F[abs(pretend[pos][i])] = T_F;
                    dfs(sum,abs(pretend[pos][i]),1,T_F);
                }
                else{
                    pretend_T_F[abs(pretend[pos][i])] = -T_F;
                    dfs(sum,abs(pretend[pos][i]),1,-T_F);
                }
            }
            else{
                if (pretend[pos][i] > 0 && pretend_T_F[abs(pretend[pos][i])] == -T_F){
                    unknown_sum[sum] = 1;
                }
                if (pretend[pos][i] < 0 && pretend_T_F[abs(pretend[pos][i])] == T_F){
                    unknown_sum[sum] = 1;
                }
            }
        }
    }
    if (level == 1){
        if (visit1[abs(rel[pos])] == 0){
            visit1[abs(rel[pos])] = sum;
            if (rel[pos] > 0){
                pretend_T_F[abs(rel[pos])] = T_F;
                dfs(sum,abs(rel[pos]),0,T_F);
            }
            else{
                pretend_T_F[abs(rel[pos])] = -T_F;
                dfs(sum,abs(rel[pos]),0,-T_F);
            }
        }
        else{
            if (rel[pos] > 0 && pretend_T_F[abs(rel[pos])] == -T_F){
                unknown_sum[sum] = 1;
            }
            if (rel[pos] < 0 && pretend_T_F[abs(rel[pos])] == T_F){
                unknown_sum[sum] = 1;
            }
        }
        if (visit1[pos] == 0){
            visit1[pos] = sum;
            pretend_T_F[pos] = T_F;

            dfs(sum,pos,0,T_F);
        }
        else{
            if (pretend_T_F[pos] == -T_F){
                unknown_sum[sum] = 1;
            }
        }
    }
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for (int i = 1;i <= t;i++){
        cin>>n>>m;
        for (int j = 1;j <= n;j++){
            rel[j] = j;
            certain[j] = 0;
            visit1[j] = 0;
            visit2[j] = 0;
            while(!pretend[j].empty()){
                pretend[j].pop_back();
            }
            unknown_sum[j] = 0;
            pretend_T_F[j] = 0;
        }
        for (int j = 1;j <= m;j++){
            char c;
            cin>>c;
            if (c == 'T'){
                int r;
                cin>>r;
                certain[r] = 1;
            }
            if (c == 'U'){
                int r;
                cin>>r;
                certain[r] = 2;
            }
            if (c == 'F'){
                int r;
                cin>>r;
                certain[r] = 3;
            }
            if (c == '+'){
                int r1,r2;
                cin>>r1>>r2;
                if (certain[r2] != 0){
                    certain[r1] = certain[r2];
                }
                rel[r1] = rel[r2];
            }
            if (c == '-'){
                int r1,r2;
                cin>>r1>>r2;
                if (certain[r2] != 0){
                    certain[r1] = 4 - certain[r2];
                }
                rel[r1] = -rel[r2];
            }
        }
        for (int j = 1;j <= n;j++){
            if (rel[j] > 0){
                pretend[abs(rel[j])].push_back(j);
            }
            else{
                pretend[abs(rel[j])].push_back(-j);
            }
            pretend[j].push_back(j);
        }
        int sum = 1;
        for (int j = 1;j <= n;j++){
            if (visit1[j] == 0){
                visit1[j] = sum;
                pretend_T_F[j] = 1;
                dfs(sum,j,0,1);
                sum++;
            }
            if (visit2[j] == 0){
                visit2[j] = sum;
                pretend_T_F[j] = 1;
                dfs(sum,j,1,1);
                sum++;
            }
        }
        int total = 0;
        for (int j = 1;j <= n;j++){
            if (unknown_sum[visit1[j]] == 1){
                total++;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
