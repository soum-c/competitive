#include <bits/stdc++.h>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void ran() {
	srand(chrono::steady_clock::now().time_since_epoch().count());
}
long long get_rand() {
	long long a = rand();
	long long b = rand();
	return a * (RAND_MAX + 1ll) + b;
}
void usaco() {
	freopen("problem.in", "r", stdin); 
	freopen("problem.out", "w", stdout);
}
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
#define endl '\n'
#define double long double
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
// const int MOD = 998244353;
// #define cerr if(0) cerr
#define debug(x) cerr << #x << ": " << x << endl;

const long long TOO_LARGE = 1000000000ll * 1000000000ll * 4ll + 1;
const long long FIT_INT = 1000000000ll;

vector<int> generate_powers(int base, int upto) {
	upto = min(upto, TOO_LARGE);
	vector<int> result;
	if (base == 1) {
		if (1 <= upto) result.push_back(1);
	}
	else {
		for (int i=1; i<=upto; i*=base) {
			result.push_back(i);
		}
	}
	return result;
}
int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int lcm(int a, int b) {
	if (a == TOO_LARGE || b == TOO_LARGE) return TOO_LARGE;
	int g = gcd(a, b);
	return min(a / g * b, TOO_LARGE);
}
bool prime(int n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	for (int i=2; i*i<=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
vector<bool> generate_primes(int n) {
	vector<bool> result(n+1, true);
	result[0] = result[1] = false;
	for (int p=2; p<=n; p++) {
		if (result[p]) {
			for (int i=p*2; i<=n; i+=p) {
				result[i] = false;
			}
		}
	}
	return result;
}
vector<int> generate_factorisations(int n) {
	vector<int> result(n+1, -1);
	vector<bool> x = generate_primes(n);
	result[0] = result[1] = 1;
	for (int p=2; p<=n; p++) {
		if (x[p]) {
			for (int i=p*2; i<=n; i+=p) {
				result[i] = p;
			}
		}
	}
	return result;
}
vector<int> factors(int n) {
	vector<int> result;
	for (int i=1; i*i<=n; i++) {
		if (n % i == 0) {
			result.push_back(i);
			if (i * i != n) result.push_back(n/i);
		}
	}
	sort(result.begin(), result.end());
	return result;
}
vector<int> prime_factorise(int n, bool distinct=false) {
	vector<int> result;
	for (int i=2; i*i<=n; i++) {
		if (distinct) {
			result.push_back(i);
			while (n % i == 0) {
				n /= i;
			}
		}
		else {
			while (n % i == 0) {
				n /= i;
				result.push_back(i);
			}
		}
	}
	if (n > 1) {
		result.push_back(n);
	}
	return result;
}
int factorial(int x, int mod=MOD) {
	if (x == 0) return 1;
	return (x * factorial(x - 1)) % mod;
}
vector<int> calculate_factorials(int n, int mod=MOD) {
	vector<int> result(n+1);
	result[0] = 1;
	for (int i=1; i<=n; i++) {
		result[i] = result[i-1] * i;
		result[i] %= mod;
	}
	return result;
}
int power(int b, int e, int mod=MOD) {
	if (e == 0) return 1;
	if (e == 1) return b;
	int h = power(b, e/2, mod);
	h *= h;
	h %= mod;
	if (e % 2 == 1) h *= b;
	h %= mod;
	return h;
}
int mod_inverse(int x, int mod=MOD) {
	return power(x, mod-2, mod);
}
vector<int> calculate_inverses(vector<int> source, int mod=MOD) {
	vector<int> result(source.size());
	for (int i=0; i<source.size(); i++) {
		result[i] = power(source[i], mod-2, mod);
	}
	return result;
}
int ncr(int n, int r, vector<int> &factorials, vector<int> &inverses, int mod=MOD) {
	if (r < 0 || r > n) return 0;
	int ans = (factorials[n] * inverses[r]) % mod;
	return (ans * inverses[n-r]) % mod;
}
vector<vector<int>> generate_ncr(int n, int r, int mod=MOD) {
	vector<vector<int>> result(n+1, vector<int>(r+1));
	for (int i=0; i<=n; i++) {
		result[i][0] = 1;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=r; j++) {
			result[i][j] = (result[i-1][j-1] + result[i-1][j]) % mod;
		}
	}
	return result;
} 
int sum(vector<int> input, int mod=TOO_LARGE) {
	int result = 0;
	for (auto x: input) {
		result = (result + x) % MOD;
	}
	return result;
}
int sum_unrestricted(vector<int> input) {
	int result = 0;
	for (auto x: input) {
		result += x;
	}
	return result;
}
int product(vector<int> input, int mod=FIT_INT) {
	int result = 1;
	for (auto x: input) {
		result = (result * x) % MOD;
	}
	return result;
}
int product_unrestricted(vector<int> input) {
	int result = 1;
	for (auto x: input) {
		result *= x;
	}
	return result;
}

// END TEMPLATE


signed main() {

	ran(); fast();
	
	
	
	
}
