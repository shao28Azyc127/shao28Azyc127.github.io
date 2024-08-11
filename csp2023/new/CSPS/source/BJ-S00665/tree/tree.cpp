//�Ե��ܲ�jp8������С����jbh����pvz�İ������
//��һ���������ĵ����磬jbh����������Ȱ��ġ�ֲ���ս��ʬ2������ҪΪѧУ��������Ѱ����С���Ϸ����������������һ���������룬���˵�������jb8��
//jp8˧����ͷ��ֹ�Ѹ��������jbh��jbhͨ����jp8�ĺ������롣���ǿ�ʼ���ģ����˽�Է���jbh���������Լ���ʼϲ��jp8��jp8Ҳ��ʼ��jbh������Ȥ��
//�����У�jbh��֪��jp8��ͬ�ǵ�һ��ѧ�����������Ǿ�����һ�档һ�����ں���һ������Ĺ㳡�ϣ����Ǽ����˶Է���
//Ϧ����ӳ�����Ƕ��˵ı�Ӱ�����ǵ�ͷ�ڲ�ϼ�ĳ�����Խ��Խ������
//�������ڴ�����棩
//    |
//    |
//    v
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100010;
int n;
struct point{
    int a,b,c;
}p[MAXN];
struct Edge{
    int v,nx;
}edge[MAXN];
int h[MAXN],CNT;
void init(){
    memset(h,-1,sizeof(h));
    CNT=0;
}
void add_side(int u,int v){
    edge[++CNT].v=v;
    edge[CNT].nx=h[u];
    h[u]=CNT;
    edge[++CNT].v=u;
    edge[CNT].nx=h[v];
    h[v]=CNT;
}
int d[MAXN],ans=1e18;
bool cs[MAXN];
bool check(int now,int x){
    if(p[now].c>=0){
        return (x-d[now]+1)*p[now].b+(d[now]+x)*(x-d[now]+1)*p[now].c/2>=p[now].a;
    }
    else{
        int stm=p[now].b/(-p[now].c);
        return (stm-d[now]+1)*p[now].b+(d[now]+stm)*(stm-d[now]+1)*p[now].c/2+x-stm+1>=p[now].a;
    }
}
void dfs(int now,int pt){
    if(now==1){
        d[now]=1;
        dfs(now+1,1);
        return;
    }
    if(now==n+1){
        int tmp=0;
        for(int i=1;i<=n;i++){
            if(p[i].c==0){
                tmp=max(tmp,(p[i].a-1)/p[i].b+1+d[i]-1);
            }
            else{
                int l=d[i],r=p[i].a;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(i,mid)){
                        r=mid;
                    }
                    else {
                        l=mid+1;
                    }
                }
                tmp=max(tmp,l);
            }
        }
        ans=min(ans,tmp);
        return;
    }
    for(int j=h[pt];j!=-1;j=edge[j].nx){
        cs[edge[j].v]=1;
    }
    for(int i=1;i<=n;i++){
        if(cs[i]&&!d[i]){
            d[i]=now;
            dfs(now+1,i);
            d[i]=0;

        }
    }
    for(int j=h[pt];j!=-1;j=edge[j].nx){
        cs[edge[j].v]=0;
    }
}
bool B=1;
signed main(){init();
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        add_side(u,v);
        if(u!=i||v!=i+1)B=0;
    }
    if(B){
        for(int i=1;i<=n;i++)d[i]=i;
        int tmp=0;
        for(int i=1;i<=n;i++){
            if(p[i].c==0){//zycakioi
                tmp=max(tmp,(p[i].a-1)/p[i].b+1+d[i]-1);
            }
            else{
                int l=d[i],r=p[i].a;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(i,mid)){
                        r=mid;
                    }
                    else {
                        l=mid+1;//lylakioi
                    }
                }
                tmp=max(tmp,l);
            }
        }
        printf("%lld",tmp);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    dfs(1,1);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//jbh�Ե���jp8��ͷ�����˳�����Ϸ
