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
#define debug(x) cout<<#x<<": "<<x<<endl;


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


vector<LL> getRand(LL range, LL len) {
    vector<LL> ve(range,0);

    for (LL i = 0; i < range; i++) {
        ve[i] = i;
    }

    vector<LL> ret;
    ret.reserve(len);
    while (ret.size() < len) {
        LL index = myRand.pick(range - ret.size());
        ret.push_back(ve[index]);
        swap(ve[index],ve[ve.size()-1]);
    }

    return ret;
    //return vector<LL>(ve.begin(), ve.begin() + len);
}

vector<LL> getRand1(LL range, LL len) {

    if (range < len) {
        debug("len out of range")
            vector<LL> temp;
        return temp;
    }

    LL index = myRand.pick(range);
    vector<LL> ret;
    ret.reserve(len);
    LL step = range / len;
    ret.reserve(len);

    for (LL i = index; ret.size() < len; i += myRand.pick(step) + 1) {
        ret.push_back(i%range);
    }
    return ret;
    //return vector<LL>(ve.begin(), ve.begin() + len);
}

int main()
{
    vector<LL> nums = {1,2,3,4,5,6,7,8,9};
    swap(nums[2],nums.back());
    for(auto i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
    //debug(ret)
    return 0;        //最终的结果是：608.100000
}
