#include <bits/stdc++.h>
using namespace ::std;

#define int long long
#define ll long long
#define YES "YES\n"
#define NO "NO\n"

// Утилити
#pragma region
void print(string txt, bool isEndl = false) {
    cout << txt << isEndl ? '\n' : endl;
}

void printYes() {
    cout << 'YES';
}

void printNo() {
    cout << 'NO';
}
#pragma endregion

const ll INF = (1ll << 60);
const ll MAX_N = 500001;
const ll MAX_DEPTH = 19;
const ll MOD = 998244353;
const ll MAX_FACT_N = 1000000;
vector<long long> FACT(MAX_FACT_N);

// Функция для предподсчета
void prepare() {
    FACT[0] = 1;
    for (int i = 1; i < MAX_FACT_N; ++i)
        FACT[i] = FACT[i - 1] * i % MOD;
}

// Алгебра
#pragma region
// Быстрое возведение в степень
ll fastPower(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return fastPower(a * a % MOD, b / 2);
    return a * fastPower(a, b - 1) % MOD;
}

// НОД
ll gcd(ll a, ll b) {
    if (b < a)
        swap(a, b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// НОК
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

// n-ое число Фибоначчи
ll fibonacci(int n) {
    ll a = 1, ta, b = 1, tb, c = 1, rc = 0, tc, d = 0, rd = 1;
    while (n) {
        if (n & 1) {
            tc = rc;
            rc = rc * a + rd * c;
            rd = tc * b + rd * d;
        }
        ta = a;
        tb = b;
        tc = c;
        a = a * a + b * c;
        b = ta * b + b * d;
        c = c * ta + d * c;
        d = tc * tb + d * d;
        n >>= 1;
    }
    return rc;
}
#pragma endregion

// Комибинаторика
#pragma region
// Найти обратное по модулю
ll inv(ll a) {
    return fastPower(a, MOD - 2);
}

// C из n по k
ll c(ll n, ll k) {
    return FACT[n] * inv(FACT[k] * FACT[n - k] % MOD) % MOD;
}
#pragma endregion

vector<vector<ll> > binup(MAX_N, vector<ll>(MAX_DEPTH));
vector<vector<ll> > graph(MAX_N);
vector<bool> was(MAX_N, false);
vector<ll> topSort(MAX_N);
vector<ll> depth(MAX_N);
// Графы
#pragma region
// Нахождение наименьшего общего предка
int lca(int v, int u) {
    if (v == u)
        return v;
    if (depth[v] > depth[u])
        swap(v, u);
    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if (depth[binup[u][i]] >= depth[v])
            u = binup[u][i];
    }
    if (v == u)
        return v;
    for (int i = MAX_DEPTH - 1; i >= 0; --i) {
        if (binup[v][i] != binup[u][i]) {
            v = binup[v][i];
            u = binup[u][i];
        }
    }
    return binup[u][0];
}

// Нахождение наименьшего общего предка
ll la(ll v, ll k) {
    if (k == 0)
        return v;
    for (ll i = MAX_DEPTH - 1; i >= 0; --i) {
        if ((1 << i) <= k) {
            k -= (1 << i);
            v = binup[v][i];
        }
    }
    return v;
}

// Топологическая сортировка
void topsort(ll v) {
    auto dfs_ = [&](int v, auto &&dfs_) -> void {
        was[v] = 1;
        for (auto u: graph[v]) {
            if (was[u])
                continue;
            dfs_(u, dfs_);
        }
        topSort.push_back(v);
    };
    dfs_(v, dfs_);
    reverse(topSort.begin(), topSort.end());
}
#pragma endregion

// Геометрия
#pragma region
// Точка
struct Point {
    int x, y;

    Point() {
    }

    Point(int x0, int y0) {
        x = x0;
        y = y0;
    }

    int operator*(Point other) {
        return x * other.x + y * other.y;
    }

    int operator^(Point other) {
        return x * other.y - y * other.x;
    }

    Point operator+(Point &other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(Point &other) {
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
struct Dsu {
    ll n;
    vector<ll> p, sz;

    Dsu(int n0) {
        n = n0;
        p.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    // Получить группу по номеру элемента
    int get(int v) {
        return (p[v] == v ? v : p[v] = get(p[v]));
    }

    // Объединить два элемента в группу
    void unite(int v, int u) {
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

// Дерево отрезков
struct SegmentTree {
    struct Node {
        int x;

        Node() {
            x = 0;
        }
    };

    Node merge(Node a, Node b) {
        Node res;
        res.x = min(a.x, b.x);
        return res;
    }

    int n;

    vector<int> a;
    vector<Node> t;
    vector<int> push;

    SegmentTree(const vector<int> &data) {
        a = data;
        n = (int) a.size();
        t.resize(4 * n);
        push.resize(4 * n);
        build(0, 0, n);
    }

    void build(int v, int l, int r) {
        if (l + 1 == r) {
            t[v].x = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }

    void makePush(int v) {
        if (push[v] == 0) {
            return;
        }

        push[2 * v + 1] += push[v];
        push[2 * v + 2] += push[v];

        t[2 * v + 1].x += push[v];
        t[2 * v + 2].x += push[v];

        push[v] = 0;
    }

    Node get(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) {
            Node res;
            res.x = INF;
            return res;
        }
        if (ql <= l && r <= qr) {
            return t[v];
        }

        makePush(v);
        int m = (l + r) / 2;
        return merge(get(2 * v + 1, l, m, ql, qr), get(2 * v + 2, m, r, ql, qr));
    }

    void add(int v, int l, int r, int ql, int qr, int d) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            push[v] += d;
            t[v].x += d;
            return;
        }

        makePush(v);
        int m = (l + r) / 2;
        add(v * 2 + 1, l, m, ql, qr, d);
        add(v * 2 + 2, m, r, ql, qr, d);

        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }

    int get(int ql, int qr) {
        return get(0, 0, n, ql, qr).x;
    }

    void add(int ql, int qr, int d) {
        add(0, 0, n, ql, qr, d);
    }
};

#pragma endregion

// Очистить структуры данных
void clearAllStructures() {
    was.clear();
    topSort.clear();
}

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
        clearAllStructures();
        solveA();
    }
}
