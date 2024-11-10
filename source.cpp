#include <bits/stdc++.h>

using namespace ::std;

#define int long long
#define ll long long
#define YES "YES\n"
#define NO "NO\n"
#define end "\n"

const ll MAX_N = 100000;
const ll MAX_DEPTH = 19;
const ll MOD = 998244353;

// Функция для предподсчета
void prepare()
{
}

// Алгебра
#pragma region
// Быстрое возведение в степень
ll fastPower(ll a, ll b)
{
  if (b == 0)
    return 1;
  if (b % 2 == 0)
    return power(a * a % MOD, b / 2);
  return a * power(a, b - 1) % MOD;
}

// НОД
ll gcd(ll a, ll b)
{
  if (b < a)
    swap(a, b);
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

// НОК
ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}
#pragma endregion

// Комибинаторика
#pragma region
// Найти обратное по модулю
ll inv(ll a)
{
  return power(a, MOD - 2);
}

// C из n по k
ll c(ll n, ll k)
{
  return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}
#pragma endregion

// Графы
#pragma region
vector<vector<int>> binup(MAXN, vector<int>(MAX_DEPTH));
vector<vector<int>> graph(MAXN);
vector<int> depth(MAXN);

// Нахождение наименьшего общего предка
int lca(int v, int u)
{
  if (v == u)
    return v;
  if (depth[v] > depth[u])
    swap(v, u);
  for (int i = MAX_DEPTH - 1; i >= 0; --i)
  {
    if (d[binup[u][i]] >= d[v])
      u = binup[u][i];
  }
  if (v == u)
    return v;
  for (int i = MAX_DEPTH - 1; i >= 0; --i)
  {
    if (binup[v][i] != binup[u][i])
    {
      v = binup[v][i];
      u = binup[u][i];
    }
  }
  return binup[u][0];
}

// Нахождение наименьшего общего предка
ll la(ll v, ll k)
{
  if (k == 0)
    return v;
  for (ll i = MAX_DEPTH - 1; i >= 0; --i)
  {
    if ((1 << i) <= k)
    {
      k -= (1 << i);
      v = binup[v][i];
    }
  }
  return v;
}
#pragma endregion

// Геометрия
#pragma region
// Точка
struct Point{
    int x, y;
 
    Point(){}
    Point(int x0, int y0){
        x = x0;
        y = y0;
    }
 
    int operator*(Point other){
        return x * other.x + y * other.y;
    }
 
    int operator^(Point other){
        return x * other.y - y * other.x;
    }
 
    Point operator+(Point &other){
        return Point(x + other.x, y + other.y);
    }
 
    Point operator-(Point &other){
        return Point(x - other.x, y - other.y);
    }
};
 
ostream &operator<<(ostream &output, const Point &p) {
    output << p.x << " " << p.y;
    return output;
}
 
istream &operator>>(istream &input, Point &p) {
    input >> p.x >> p.y;
    return input;
}
#pragma endregion

// Структуры данных
#pragma region
// СНМ
struct Dsu
{
  ll n;
  vector<ll> p, sz;

  dsu(int n0)
  {
    n = n0;
    p.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; i++)
      p[i] = i;
  }

  // Получить группу по номеру элемента
  int get(int v)
  {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }

  // Объединить два элемента в группу
  void unite(int v, int u)
  {
    v = get(v);
    u = get(u);
    if (v == u)
      return;
    if (sz[v] < sz[u])
      swap(v, u);
    sz[v] += sz[u];
    p[u] = v;
  }
};


#pragma endregion

void solveA()
{
}

void solveB()
{
}

void solveC()
{
}

void solveD()
{
}

void solveE()
{
}

void solveF()
{
}

void solveG()
{
}

void solveH()
{
}

void solveI()
{
}

void solveJ()
{
}

void solveK()
{
}

void solveL()
{
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  prepare();

  int tt = 1;
  cin >> tt;

  while (tt--)
  {
    solveA();
  }
}