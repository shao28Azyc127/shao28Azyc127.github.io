#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n, d;
int v[10001], a[10001];

//���վ��1���ͼ���� ֱ����1������n����

//һ���ж�Զ��
int Far(){
    int f_cnt = 0;
    for (int i = 1; i < n; i++){
        f_cnt += v[i];
    }
    return f_cnt;
}

int first_low(){
    int min = 114514, id = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] < min){
            min = a[i];
            id = i;
        }
    }
}

/*
���� 1 - n���ͼ���͵� ���Ϊflag 1
���� 1 - flag 1���ͼ���͵� ���Ϊflag 2
�ظ� ֱ���ͼ���͵�Ϊ1 ����1 - flag x����
��ʽ��
1.�����flag X�ľ��룺
f = v[1] + v[2] + ... + v[flag x]
2.�����flag X�ļ۸�
ans = f * a[k] ���״�k = 1�� k��ʾ��ǰλ�ã�
3.���k = flag x
4.x-- ��һ�μ���flag x-1

*/

//�����ҵ�1 - flag x���ͼ���͵�վ�� ����¼ flag��ʼΪn
//��ÿ���ҵ���ǰ������˵��ͼ�
//��ǰ����һ���ͼ���͵�����յ�

int cnt = 0;//һ���ļ۸�
int k = 1;//��ǰ��λ��
void Low(int flag){
    //k��ʾ��ǰλ��
    //flag��ʾ���������ǰ��վ���� ��ʼΪn
    int min = 114514, id = 0;

    //min��ʾ����ͼ�
    //id��ʾ����ͼ۵�վ����

    for (int i = 1; i <= flag; i++){
        if (a[i] < min){
            min = a[i];
            id = i;
        }
    }




    //�������������ǰ��վ����ΪID������������С��
    //m����1 - ID֮�����Сվ����
    //int m = Low(id, k);
    //F�������1 - id֮�����
    //for (int j = m; j <= flag; j++) f += v[j];
    if (id != 1) Low(id);

    //�Ѿ���֤վ��1��С����ʼ����1 ��flag x֮��ļ۸�
    //f = v[1] + v[2] + ... + v[flag x]
    //������һ��վ����,flag
    //int next_flag = flag;
    //f��ʾ1 - flag x֮��ľ���
    //b��ʾҪ����͵�����
    int f = 0;
    double b = 0.0;
    for (int i = k; i < flag; i++) f += v[i];
    //cout << f << endl;

    b = (double)f / (double)d;
    b = ceil(b);
    cnt += (int)b * a[id];

    k = flag;
    return;


}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n] = 1919810;
    int l = first_low(), f = Far();
    if (l == 1){
        //·�� / ÿ�����ߵ�·�� = ������
        //���ĵ����� * ���� = �ܼ�
        cout << f / d * a[1] << endl;
        return 0;
    }

    Low(n);

    cout << cnt << endl;

    return 0;
}
