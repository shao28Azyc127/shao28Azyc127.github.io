#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,T=0.94*CLOCKS_PER_SEC;
struct path{int val,end;};
int c,t,n,m,x,y,res,ans[N],memcnt[N];
char v;
bitset<N> pre,vis;
vector<path> ch[N];
inline void file(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    //��ʲôˮƽ������ zhouyuhang �� �ҳ��������� �� jincy2008 ���� KarlPeter һ����������
    //�����t1�ü򵥡�ϣ���ܳ��С�
    //t2�����ڰ�ƽ��������c=4��ֱ�Ӽ���ƴ����һ�´��70pts.
    //������Ҳ��������2=����
    //��ϧ [����ɾ��] csps���ò���������ֻ���ڼ�vp������Ҳû�����������ġ�
    //������д󲿷ֶ�����sdsz������ս����ȷʵ��û��ϣ������ylq��ʦ�ˡ�
    //���ȵȼ�һ�ǲ���ֻ�� zhouyuhang ��rdfz��������
    //��ô���������Լ��������ѡ�ǰ������ܵ�rp�൱���ð�(x
    //by BJ-0363,2023.11.18 10:10
}
inline int chg(char k){
    if(k=='U') return 0;
    if(k=='F') return -1;
    return 1;
}
bool drewclr(int k,int cnt){
    if(pre[k]){vis[k]=1;return 1;}
    if(vis[k]){
        if((cnt-memcnt[k])&1){pre[k]=1;return 1;}
        return 0;
    }
    vis[k]=1,memcnt[k]=cnt;
    for(int i=0;i<ch[k].size();++i) if(drewclr(ch[k][i].end,cnt+ch[k][i].val)){pre[k]=1;return 1;}
    vis[k]=0;return 0;
}
void dfs(int k){
    for(int i=0;i<ch[k].size();++i) if(!pre[ch[k][i].end]) pre[ch[k][i].end]=1,dfs(ch[k][i].end);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> t;
    if(c!=4){
        while(t--){
            cin >> n >> m;
            pre.reset(),vis.reset();
            for(int i=1;i<=n;++i) ans[i]=i+1,ch[i].clear();
            while(m--){
                cin >> v;
                if(v=='T'||v=='F'||v=='U'){
                    cin >> x;
                    ans[x]=chg(v);
                } 
                else{
                    cin >> x >> y;
                    if(v=='+') ans[x]=ans[y];
                    else ans[x]=-ans[y];
                }
            }
            for(int i=1;i<=n;++i){
                if(ans[i]==0) pre[i]=1;
                if(ans[i]!=0&&ans[i]!=1&&ans[i]!=-1){
                    if(ans[i]>0) ch[i].push_back((path){0,ans[i]-1}),ch[ans[i]-1].push_back((path){0,i});
                    else ch[i].push_back((path){1,-ans[i]-1}),ch[-ans[i]-1].push_back((path){1,i});
                }
            }
            for(int i=1;i<=n;++i) if(!vis[i]) drewclr(i,0);
            for(int i=pre._Find_first();i<=n;i=pre._Find_next(i)) dfs(i);
            cout << pre.count() << '\n';
        }
        return 0;
    }
    else{
        while(t--){
            res=0;
            cin >> n >> m;
            while(m--){
                cin >> v >> x;
                if(v=='U') ++res;
            }
            cout << res << '\n';
        }
        return 0;
    }
    return 0;
}