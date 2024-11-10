#include<bits/stdc++.h>

#define int long long
#define ll long long
#define YES "YES\n"
#define NO "NO\n"
#define end "\n"
 
using namespace::std;

const ll MAX_N = 100000;
const ll MAX_DEPTH = 19;
const ll MOD = 998244353;

// Функция для предподсчета
void prepare() {

}

// Алгебра
#pragma region
//Быстрое возведение в степень
ll fastPower(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) return power(a * a % MOD, b / 2);
    return a * power(a, b - 1) % MOD;
}

// НОД
ll gcd(ll a, ll b) {
  if (b < a) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}

//НОК
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}
#pragma endregion 

// Комибинаторика
#pragma region
// Найти обратное по модулю
ll inv(ll a) {
    return power(a, MOD - 2);
}
 
// C из n по k
ll c(ll n, ll k) {
    return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}
#pragma endregion 


vector<vector<int>> binup(MAXN, vector<int>(MAX_DEPTH));
vector<vector<int>> graph(MAXN);
vector<int> depth(MAXN);
// Графы
#pragma region


// Нахождение наименьшего общего предка
int lca(int v, int u) {
  if (v == u) return v;
  if (depth[v] > depth[u]) swap(v, u);
  for (int i = MAX_DEPTH-1; i >= 0; --i) {
    if (d[binup[u][i]] >= d[v]) u = binup[u][i];
    
  }
  if (v == u) return v;
  for (int i = MAX_DEPTH-1; i >= 0; --i) {
    if (binup[v][i] != binup[u][i]) {
      v = binup[v][i];
      u = binup[u][i];
    }
  }
  return binup[u][0];
}

// Нахождение наименьшего общего предка
ll la(ll v, ll k) {
  if (k == 0) return v;
  for (ll i = MAX_DEPTH-1; i >= 0; --i) {
    if ((1 << i) <= k) {
      k -= (1 << i);
      v = binup[v][i];
    }
  }
  return v;
}
#pragma endregion 





void solveA() {

}

void solveB() {
    
}

void solveC() {
    
}

void solveD() {
    
}

void solveE() {
    
}

void solveF() {
    
}

void solveG() {
    
}

void solveH() {
    
}

void solveI() {
    
}

void solveJ() {
    
}

void solveK() {
    
}

void solveL() {
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prepare();

    int tt = 1;
    cin >> tt;

    while (tt--) {
        solveA();
    }
}