#include <bits/stdc++.h>
using namespace std;
const int N = 10e9 + 1;
int n,sum, x = 2, ans, xn;
bool q[1000000000];
bool b = 0;
int main() {
    freopen("apple.in", "r", stdin);
    
    freopen("apple.out", "w", stdout);
    
    cin >> n;
    memset(q, 0, sizeof(q));
    while(ans != n)///��һ������ȡ���˶��ٸ�ƻ������ȡ�ߵ�ƻ����һ����ƻ����ȵ�ʱ�򣬴���ѭ������
    {///�˴�����ÿһ��
       x = 2;
        sum ++ ;///ֱ�ӽ��������ٴ�ѭ���Ӽ�
        for(int i = 1; i <= n ;i ++) {

            if(q[i] == 0 && x == 2) {
				q[i] = 1;//ȡ��ƻ��
				//cout << i << " ";
				ans ++ ;
				x = 0;
            }
            if(q[i] == 0)
                x ++ ;
        }
        //cout << endl;
        if(q[n] == 1 && b == 0) {
                xn = sum;
                b = 1;
        }
    }
    cout << sum << " " << xn;
    return 0;
}
