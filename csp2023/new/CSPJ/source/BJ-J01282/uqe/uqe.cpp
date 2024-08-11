

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Dual {
  double a;
  double b;
  double c;
};

int _num = 0;
int _maxi = 0;
vector<Dual> _myList;
int _nowP = 0;
int _nowQ = 0;
double _nowQ1 = 0;
double _nowQ2 = 0;

double Maxi (double a, double b) {
  if (a > b) {
    return a;
  }
  return b;
}

void ParseIn () {
  Dual solo;

  ifstream inFile("uqe.in");

  inFile >> _num >> _maxi;

  for (int i = 0; i < _num; i++) {
    inFile >> solo.a >> solo.b >> solo.c;
    _myList.push_back(solo);
  }
  
  inFile.close();
}

int Gcd (int a, int b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

bool CheckYouLi(double v) {
  double resP = 0;
  double resQ = 0;
  double p = 0;
  double q = 0;
  int cc = 0;
  bool flag = false;
  
  if (v < 0) {
    flag = true;
  }
  
  v = abs(v);
  //cout << v << "->" << endl;
  
  //q->i
  for (double i = 1; i < _maxi; i++) {
    q = i;
    p = v * q;

    if (p != (int)p) {
      continue;
    }

    //cout << p << " " << q << endl;
    
    if (Gcd(p, q) == 1) {
      cc++;
      resP = p;
      resQ = q;
    }

    if (cc != 1) {
      return false;
    }
  }

  if (cc != 1) {
    return false;
  }

  _nowP = resP;
  _nowQ = resQ;
  if (flag) {
    _nowP = -_nowP;
  }
  return true;
}

void FindQ1Q2 (double x) {
  bool flag = false;
  
  for (double q1 = 0; q1 < 100; q1 += 0.1) {
    for (double q2 = 0; q2 < 100; q2 += 0.1) {
      if (q2 == 0) {
	continue;
      }
      
      double r = ((x - q1) / q2) * ((x - q1) / q2);
      if (r <= 1) {
	continue;
      }

      if (r != (int)r) {
	continue;
      }

      r = (int)r;
      int solo = r;
      
      for (int i = 2; i < sqrt(_maxi) + 1; i++) {
	if ((i * i) % solo == 0) {
	  flag = true;
	}
      }

      if (flag) {
	flag = false;
	continue;
      }

      flag = false;
      _nowQ1 = q1;
      _nowQ2 = q2;
      return;
    }

    if (flag) {
      flag = false;
      continue;
    }
  }
  
}

//what: no root->true
bool CalcDerta (double a,double b, double c) {
  double solo = 0;
  solo = b * b - 4 * a * c;
  if (solo < 0) {
    return true;
  }
  return false;
}

double GetRoot (double a, double b, double c) {
  double res = 0;
  res = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  res = Maxi(res, ((-b - sqrt(b * b - 4 * a *c)) / (2 * a)));
  return res;
}

void CoreWriteOut () {
  double a;
  double b;
  double c;

  ofstream outFile("uqe.out");
  
  for (int i = 0; i < _myList.size(); i++) {
    Dual solo = _myList[i];
    a = solo.a;
    b = solo.b;
    c = solo.c;

    if (CalcDerta(a, b, c)) {
      outFile << "NO" << endl;
      continue;
    }

    double root = GetRoot(a, b, c);
    //cout << root << endl;
    
    if (CheckYouLi(root)) {
      if (_nowQ == 1) {
	outFile << _nowP << endl;
	continue;
      }
      outFile << _nowP << "/" << _nowQ << endl;
      continue;
    }
    outFile << "0 0" << endl;
  }

  outFile.close();
}

int main () {

  ParseIn();
  CoreWriteOut();

  return 0;
}
