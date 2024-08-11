/*
测试点1 2可拿暴力分

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;

enum Tribool {
  True,
  False,
  Unknown,
};
enum StmtType {
  AssignTrue = 'T', AssignFalse = 'F', AssignUnknown = 'U',
  Assign = '+', AssignNot = '-',
};

Tribool Not(Tribool val) {
  switch (val) {
  case True: return False;
  case False: return True;
  case Unknown: return Unknown;
  }
  return Unknown;
}

struct Stmt {
  StmtType tp;
  int arg1, arg2;

  Stmt() {}

  Stmt(StmtType _tp, int _arg1, int _arg2 = 0)
    : tp(_tp), arg1(_arg1), arg2(_arg2) {}
};

vector<Tribool> cur_vars;
vector<Tribool> res;
int res_cnt = INF;
vector<Stmt> program;

/*
O(n)
*/
bool eval(vector<Tribool> vars) {
  vector<Tribool> vars_cpy = vars;
  for (Stmt stmt : program) {
    StmtType tp = stmt.tp;
    switch (tp) {
    case AssignTrue:
      vars[stmt.arg1] = True;
    case AssignFalse:
      vars[stmt.arg1] = False;
    case AssignUnknown:
      vars[stmt.arg1] = Unknown;
    case Assign:
      vars[stmt.arg1] = vars[stmt.arg2];
    case AssignNot:
      vars[stmt.arg1] = Not(vars[stmt.arg2]);
    }
  }
  // cout << (vars == vars_cpy) << endl;
  return vars == vars_cpy;
}

int c, t;
int n, m;

int get_cnt(const vector<Tribool> &vars) {
  int cnt = 0;
  for (Tribool i : vars)
    cnt += i == Unknown;
  return cnt;
}

/*
O(3^n), 所以说只能过2个点
k从1开始
*/
void dfs(int k) {
  // printf("dfs %d %d\n", k, m);
  if (k == m + 1) {
    if (eval(cur_vars)) {
      int cnt = get_cnt(cur_vars);
      if (cnt < res_cnt) {
        res = cur_vars;
        res_cnt = cnt;
      }
    }
    return;
  }
  cur_vars[k] = True; dfs(k + 1);
  cur_vars[k] = False; dfs(k + 1);
  cur_vars[k] = Unknown; dfs(k + 1);
}

Stmt read_stmt() {
  char head;
  cin >> head;
  if (head == 'T' || head == 'F' || head == 'U') {
    int arg1;
    cin >> arg1;
    return Stmt((StmtType)head, arg1);
  } else {
    int arg1, arg2;
    cin >> arg1 >> arg2;
    return Stmt((StmtType)head, arg1, arg2);
  }
}

int main(int argc, char const *argv[])
{
  freopen("tribool.in", "r", stdin);
  freopen("tribool.out", "w", stdout);
  cin >> c >> t;
  while (t--) {
    cin >> n >> m;
    cur_vars = vector<Tribool>(n + 1);
    program = vector<Stmt>();
    for (int i = 0; i < m; i++) {
      program.push_back(read_stmt());
    }
    dfs(1);
    cout << res_cnt << endl;
  }
  return 0;
}
