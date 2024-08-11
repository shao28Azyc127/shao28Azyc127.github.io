#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
const int N=1e4;
bool node[N][N];
string s;
void find_near(int a,int b,int cnt,int* step);
void find_twin(int a,int b)
{
    int i=1;
    int step[N]={};
        while(s[a-i]==s[b+i]){
            ans++;
            i++;
            node[a-i][b+i]==true;
            find_near(a-i,b+i,0,step);
        }

}
void find_near(int a,int b,int cnt,int* step)
{
    int st[N];
    for(int i=1;i<=cnt;i++)st[i]=step[i];
    for(int i=1;i<a;i++)
    {
        if(node[i][a]){

            st[++cnt]=b;
            for(int j=1;j<=cnt;j++)
            {
                node[i][step[j]]=true;
            }
            find_near(i,a,cnt,st);
            find_twin(i,a);
        }
    }

    ans+=(cnt*(cnt+1))/2;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i+1]){
            ans++;
            node[i][i+1]=true;
            find_twin(i,i+1);
        }
    }
    cout<<ans;

}
