#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,T=0.94*CLOCKS_PER_SEC;
struct cli{int x,y,v;};
cli init;
int c,t,n,m,k,d;
bitset<N> vis;
long long ans;
vector<cli> memcli;
inline void file(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    //���������ˡ��������ֵ��������������У�������һ��ʱ��дд��д�İա�
    //�ղſ���һ��t3�Լ���Դ���򳤶�Ϊ1.145KB���о�������˼��
    //t4Ŀǰд��̰�Ŀ�����ֻ�ܹ���һ���������ǳ�û��ǰ;�����ġ�
    //���� jincy2008 �������������û���٣�һֱ��д�����˼������������һ��һֱ�������ǡ�
    // �ҳ��������� ����������ߵ���ߵ���ߣ�������Ҳһֱ��˼����
    //���� zhouyuhang �� KarlPeter ������������������Ұ֮�ڡ�
    //�Ҽǵ�֮ǰ��mum˵�����NOIPֻ��3=��Ҫ�˹�����ô�����ƺ�ȷʵ���˹��ˡ�
    //t4��ǰ�����㿴�����ͺ���״ѹ������ϧû����д�����ˣ��������ġ�
    //����һ��ǰ�������������µ�OI���ģ��о��Լ�һֱ��loser������ÿ���඼�ᱻ��·���ɵ���
    //�����ڻ����౻����
    //Ȼ��ȥ�����P��ʱ�����ܳ����ͣ��������˺ܾá����˰���������ʼ�����ӵĵ��򡣣���Ϊ����һЩ���ˣ�
    //�ٺ���ȥP+֮��Tetris����1307���ǵ����֡�
    //��ٵ��˼�������ȫ����򣡣�
    //���켯ѵ��ʱ������401�����ֵ������������갢��csps�����ɣ��������������ɣ���������������ַ����򣡣�
    //��ĿǰΪֹ�Һ���Ҳһֱ�ǵ�״�ʦ����ô�죬������ҩ�ɾȡ�
    //��������OI���Ǵ����˺ܶ����û���İ���
    //�����Ǹо�������¥����Ĥ����ylq��ʦ�����ڸ�һʳ�������˳�������ѧ����λ�ã��ͣ��о����˺ܶఢ��
    //�����ĸ�����ѧУ�������ݽ����˳���30min�����Ρ�sdsz�Ĵ��ÿ�����������������������֮ǰ�Լ���ͬѧ����Ʒ�ء�
    //����о�1=������300+��2=�߹���Ҳ��200+�ա�����������ľ�3=�˹��ˡ�
    //t3�Һ����뵽һ�ָ�����ԣ����Ǹо����ǺܶԶ�����Ҫ�޴��ķַַ֡���ô�����Ҿ�Ҫ���ˣ���д��������д������
    //���£��������Լ�t3��һ���������ˡ����ڲ��ܵ�180pts���޿޿ޡ�
    //�����ء������� [����ɾ��] �����氮���������ء�
    //ϣ����������������ˮһЩ����
    //by BJ-0363,2023.11.18 12:46
}
inline bool cmp(cli a,cli b){return a.v>b.v;}
inline bool check(int p){
    int cnt=0;
    for(int i=memcli[p].x-memcli[i].y;i>=1;--i){
        if(vis[i]) ++cnt;
        else break;
    }
    if(cnt+memcli[p].y>k) return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> t;
    while(t--){
        cin >> n >> m >> k >> d;
        memcli.clear(),vis.reset(),ans=0;
        while(m--){
            cin >> init.x >> init.y >> init.v;
            if(init.y>k) continue;
            if(init.v<=init.y*d) continue;
            init.v-=init.y*d;
            memcli.push_back(init);
        }
        if(!memcli.size()){cout << "0\n";continue;}
        sort(memcli.begin(),memcli.end(),cmp);
        for(int i=0;i<memcli.size();++i){
            if(check(i)){
                ans+=memcli[i].v;
                for(int j=memcli[i].x;j>memcli[i].x-memcli[i].y;--j) vis[j]=1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}