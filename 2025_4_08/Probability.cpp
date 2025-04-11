// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <math.h>
// #include <assert.h>

// #define P 1000000007

// //最大公因数
// long long gcd(long long x, long long y)
// {
//     long long div = 0;
//     while(!div)
//     {
//         div = x % y;
//         x = y;
//         y = div;
//     }
//     return x;
// }

// //分数取模
// long long remainder(long long Numerator, long long Denominator)
// {
//     int x = 0;
//     while(Numerator != (Denominator * x) % P);
//     return x;
// }

// //公式
// int main()
// {
//     int T = 0;
//     scanf("%d", &T);
//     int i = 0;
//     int j = 0;
//     long long N = 0;
//     long long MAX = 0;
//     getchar();
//     for(i = 0; i < T; i++)
//     {
//         scanf("%lld %lld", &N, &MAX);
//         getchar();
//         double expetation_candy = 0;
//         for(j = 1; j < (long long)sqrt(MAX); j++)
//         {
//             expetation_candy += (long long)log(N - 1) + (long long)log(MAX) + (long long)log(2 * MAX / i - (long long)(sqrt(MAX) * sqrt(MAX)));
//         }



        

//     }
//     return 0;

// }

#include <stdio.h>
#include <math.h>

const long long Mod = (long long)1E9 + 7;

long long quickpow(long long a, long long n) {
    a %= Mod;
	long long ret = 1;
	while(n) {
		if(n & 1) ret = (ret * a) % Mod;
		a = (a * a) % Mod, n >>= 1;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		long long N, M;
		scanf("%lld %lld", &N, &M);
		if(N == 1) {puts("0"); continue;}
		long long sum = 0;
		for(long long i = 1; i * i <= M; i++)
			sum = (sum + (M / i)) % Mod;
		sum = (sum * 2 % Mod - ((long long)(sqrt(M)) * (long long)(sqrt(M)) % Mod) + Mod) % Mod;
		sum = ((sum * ((N - 1) % Mod)) % Mod) * quickpow(M, N - 2) % Mod;
		printf("%lld\n", sum * quickpow(quickpow(M, N), Mod - 2) % Mod);
	}
	return 0;
}
