#include <iostream>
using namespace std;

const int MAXN = 3005;

string arr[MAXN];
char str_min[MAXN], str_max[MAXN];
int n, m;

int main(int argc, char const *argv[])
{
  freopen("dict.in", "r", stdin);
  freopen("dict.out", "w", stdout);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    str_min[i] = 0x7f;
    str_max[i] = 0;
    for (char ch : arr[i]) {
      str_min[i] = min(str_min[i], ch);
      str_max[i] = max(str_max[i], ch);
    }
  }
  for (int i = 0; i < n; i++) {
    char str_max_min = 0x7f;
    for (int j = 0; j < n; j++)
      if (j != i)
        str_max_min = min(str_max_min, str_max[j]);
    if (str_max_min > str_min[i])
      printf("1");
    else
      printf("0");
  }
  puts("");
  return 0;
}
