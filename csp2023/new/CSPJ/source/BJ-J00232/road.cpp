#include <bits/stdc++.h>
using namespace std;
int upget(int x,int y)
{
    if(x==0 || y==0){
        return 0;
    }
    int a=x/y;
    if(y*a==x){
        return a;
    }
    else{
        return a+1;
    }
}
struct info{
    int cost,tonext;
};
const int MAX=1e5;
info st[MAX];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;//վ����������ǰ������
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>st[i].tonext;
    }
    for(int i=1;i<=n;i++){
        cin>>st[i].cost;
    }
    int remain=0,allcost=0;//�ϴ�ʣ�࣬�ܻ���
    for(int i=1;i<=n;i++){
        if(remain<st[i].tonext){//��������һվ
            int disto=0;
            for(int j=i;j<=n;j++){//���㵽�ȵ�ǰվ���˵���һվ����վ����
                if(st[j].cost<st[i].cost){
                    break;
                }
                else{
                    disto+=st[j].tonext;
                }
            }
                int need=upget(disto-remain,d);//��Ҫ����L=����һվ���� ��ȥ�ϴ�ʣ��ľ���/��ǰ������,
                int have=remain+need*d;//��������:ʣ�����+���͵ľ���
                allcost+=need*st[i].cost;//��Ҫ�ӵ���*��վ����=�ܻ���
                remain=have-st[i].tonext;
                //cout<<i<<" "<<need<<" "<<have<<" "<<remain<<endl;
        }
        else{//��������һվ
            remain-=st[i].tonext;//�ķ�ʣ����
        }
    }
    cout<<allcost;
    return 0;
}
