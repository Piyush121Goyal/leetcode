class Solution {
public:
long long modpow(long long base, long long exp, long long mod) {
  long long result = 1;
base %= mod;
while (exp > 0) {
if (exp & 1) result = result * base % mod;
base = base * base % mod;
exp >>= 1;
}
return result;
}

int numberOfSets(int n, int k) {
  const long long MOD = 1000000007;
int N = n + k;
vector<long long> fact(N + 1), invFact(N + 1);
fact[0] = 1;
for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
invFact[N] = modpow(fact[N], MOD - 2, MOD);
for (int i = N; i > 0; i--) invFact[i - 1] = invFact[i] * i % MOD;

int top = n + k - 1;
int bottom = 2 * k;
if (bottom > top) return 0;
long long res = fact[top] * invFact[bottom] % MOD * invFact[top - bottom] % MOD;
return (int)res;
}
};
