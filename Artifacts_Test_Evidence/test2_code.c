static long cubic(double C, double RTT, double p) {
  double w = pow(RTT, 0.75);
  w = w / pow(p, 0.75);
  w = w * pow(C * 3.7 / 1.2, 0.25);
  const long cwnd = lround(w);

  const long tcp_friend = p;

  return 1;
}

int main() {
  double a;
  make_symbolic(&a, sizeof(a), "a");
  double b;
  make_symbolic(&b, sizeof(b), "b");
  double c;
  make_symbolic(&c, sizeof(c), "c");
  return cubic(a, b, c);
}