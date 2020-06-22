#include <stdio.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map< int,int> mArr;
int n, m, k;


void add() {
	int key, value;
	cin >> key >> value;

	mArr[key] = value;
}
void mod() {
	int key, value;
	cin >> key >> value;

	auto low = mArr.lower_bound(key);
	auto up = mArr.upper_bound(key);
	low--;
	auto end = mArr.end();

	if (mArr.find(key) != mArr.end()) mArr[key] = value;
	else {
		if ( ( low == end || low->first < key - k ) && ( up == end || key + k < up->first) ) return;
		else if( low == end  ){
			if (up->first < key + k) mArr[up->first] = value;
		}
		else if( up == end){
			if (low->first > key - k) mArr[low->first] = value;
		}
		else {
			if (low == up) mArr[low->first] = value;
			else if (abs(key - low->first) > abs(key - up->first)) mArr[up->first] = value;
			else if (abs(key - low->first) < abs(key - up->first)) mArr[low->first] = value;
		}
	}
}

void print() {
	int key;
	cin >> key;

	auto end = mArr.end();

	if (mArr.find(key) != mArr.end()) cout << mArr[key] << endl;
	else {
		auto low = mArr.lower_bound(key);
		auto up = mArr.upper_bound(key);
		low--;

		if ( ( low == end || low->first < key - k )  && ( up == end || key + k < up->first ) ) cout << "-1" << endl;
		else if (low == end) {
			if (up->first < key + k) cout << mArr[up->first] << endl;
		}
		else if (up == end) {
			if (low->first > key - k) cout << mArr[low->first] << endl;
		}
		else {
			if (low == up) cout << mArr[low->first] << endl;
			else if (abs(key - low->first) > abs(key - up->first)) cout << mArr[up->first] << endl;
			else if (abs(key - low->first) < abs(key - up->first)) cout << mArr[low->first] << endl;
			else cout << "?" << endl;
		}
	}

}


int main() {
	scanf("%d %d %d", &n, &m, &k);

	while (n--) {
		int key, value;
		scanf("%d %d", &key, &value);
		mArr.insert(make_pair(key, value));
	}

	while (m--) {
		int term;

		cin >> term;

		switch (term) {
			case 1: add();  break;
			case 2: mod(); break;
			case 3: print();  break;
		}
	}

	return 0;
}
