#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stack>
#include <algorithm>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <limits.h>
#include <map>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <future>
using namespace std;

using LL = long long int;
#define debug(x) cout<<#x<<": "<<(x)<<endl;

struct Random {
public:
	using Generator = std::mt19937;

	Random(LL seed) : rgen(seed) {}
	Random() : rgen(generateSeed()) {}

	static LL generateSeed() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

		return static_cast<LL>(seed);
	}

	Generator::result_type operator()() { return rgen(); }

	// pick with probability of (numerator / denominator).
	bool isPicked(unsigned numerator, unsigned denominator) {
		return ((rgen() % denominator) < numerator);
	}

	// pick from [min, max).
	LL pick(LL min, LL max) {
		return ((rgen() % (max - min)) + min);
	}
	// pick from [0, max).
	LL pick(LL max) {
		return (rgen() % max);
	}

	Generator rgen;
} myRand;


LL a1 = 10;
LL a2 = 10;
LL mod = 20;

LL sub(LL a,LL b){
    a -= b%mod;
    if (a < 0) {
        a %= mod;
        if (a < 0) {
            a += mod;
        }
    }
    return a;
}

int main()
{
    vector<LL> arr = {1,12,10,2,5,6,9,15,100,200};

    for(LL i=0;i<arr.size();i++){
        LL b = arr[i];
        a1 = a1 + (b%mod);
        a1 %= mod;
        debug(a1)
    }
    a2 = a1;

    for(LL i=0;i<arr.size();i++){
        LL b = arr[i];
        a1 = a1 + mod - (b%mod);
        a1 %= mod;
        a2 = sub(a2,b);

        debug(a1)
        debug(a2)
        debug(b)
    }
    debug(a1)
    debug(a2)
    return 0;
}
