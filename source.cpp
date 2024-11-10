#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
 

#define int long long
#define ll long long
#define YES "YES\n"
#define NO "NO\n"
#define end "\n"
 
using namespace::std;

ll MOD = 998244353;

//Быстрое возведение в степень
ll fastPower(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) return power(a * a % MOD, b / 2);
    return a * power(a, b - 1) % MOD;
}

// Найти обратное по модулю
ll inv(ll a) {
    return power(a, MOD - 2);
}
 
// C из n по k
ll c(ll n, ll k) {
    return fact[n] * inv(fact[k] * fact[n - k] % MOD) % MOD;
}

// Функция для предподсчета
void prepare() {

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

    int n = 1;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        solveA();
    }
}