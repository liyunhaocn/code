#pragma once
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void disp1() {

	int a[5] = { 5,4,3,2,1 };

	sort(a, a + 5);
	do {
		for (auto i : a) {
			cout << i << " ";
		}
		cout << endl;
	} while (next_permutation(a, a + 5));


}