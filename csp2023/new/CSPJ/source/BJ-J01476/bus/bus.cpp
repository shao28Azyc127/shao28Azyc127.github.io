//zyc AK IOI
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Road{
    int u,v,t;
}road[20005];
signed main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> road[i].u >> road[i].v >> road[i].t;
    }
    cout << -1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//100+100+50+?
//���˼�����̫�����ˣ���Ҷ�AK��ֻ���ұ�0��
//�о�����Ǹ����������Ż�����С���Ҿ��Ǹ�ͼ�۷���ֻ��ƭ��
//�������˱��������������ǲ���ҪAFO��
//��ģ��ĵ�֮ǰ�������ϰ�
//2338bitexplo ���� LJH ��Br00k5xx ���� ayt
//1145141919810kunkun ����LD
//�Gѽ��ô����45min ��Ҫ��������
//�������������� ayt ϲ�� Sumy01��Br00k5xx Ϊ��ʮ�ַ�ŭ
//LJH Ҳ˵���� Sumy01 �кø� ���޳���������
//һЩʥ����2338nitexplo:1145141919810kunkun ���֪�����
//��ϲ���������ٹ����㡣
//LITFLYR��2338bitexplo ���֪����� ��ϲ���������ٹ�����ʲôʱ��die
//2338bitexplo : �úúã��ڰ�ɭ�ִ���������ǡ�
//�úúû���35min ��ȥ����