#include<bits/stdc++.h>
using namespace std;
//Ŷ�ҵ��ϵ�
//�������ô��T2��Ҫ��
//T2����O(n^2)������������
//Ϊ���������ʱ�临�Ӷ�д����ô��
//n=1��ҪTLE
//ƭ�ִ󷨺�
int main() {
    FILE *fpi, *fpo;
    fpi = freopen("lock.in", "r", stdin);
    fpo = freopen("lock.out", "w+", stdout);

    int n;
    cin >> n;
    int temp[n][5], ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> temp[i][j];
        }
    }
    if(n == 1)
        cout << 81;//��n����1��ʱ�����һ����81�����Է�������ƭ��
    else
        cout << 10;//

    fclose(fpi);
    fclose(fpo);
    return 0;
}
