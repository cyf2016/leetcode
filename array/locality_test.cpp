#include <boost/timer/timer.hpp>
#include <iostream>

#define N 1000
#define M 1000

struct Point {
  int vel[M];
  int acc[M];
};

void clear1 (Point *p, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < M; j++) {
      p[i].vel[j] = 0;
    }
    for (int j = 0; j < M; j++) {
      p[i].acc[j] = 0;
    }
  }
}

void clear2 (Point *p, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < M; j++) {
      p[i].vel[j] = 0;
      p[i].acc[j] = 0;
    }
  }
}

int main() {
  boost::timer::cpu_timer t0;
  Point *p = new Point[N];
  {
    boost::timer::cpu_timer t1;
    clear1(p, N);
    t1.stop();
    std::cout << "T1: "<< t1.format() << '\n';
  }

  Point *p2 = new Point[N];
  {
    boost::timer::cpu_timer t2;
    clear2(p2, N);
    t2.stop();
    std::cout << "T2: " << t2.format() << '\n';
  }

  delete[] p;
  delete[] p2;
  return 0;
}
