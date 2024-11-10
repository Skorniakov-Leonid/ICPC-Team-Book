#include<bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int a, int b) {
  if (b < a) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}