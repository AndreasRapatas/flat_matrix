#include <iostream>
#include <vector>
#include <string>

#include "flat_matrix.h"

using namespace std;


int main() {

	unsigned width = 4;
	unsigned height = 3;
	unsigned depth = 4;
	unsigned time = 20;

	flat_matrix<char> a(width, height, depth, time);

	for (size_t t = 0; t < time; ++t) {
		for (size_t z = 0; z < depth; ++z) {
			for (size_t y = 0; y < height; ++y) {
				for (size_t x = 0; x < width; ++x) {

					a(x, y, z, t) = '#';
				}
			}
		}
	}

	a(2, 1, 3, 18) = '_';

	for (size_t t = 0; t < time; ++t) {
		for (size_t z = 0; z < depth; ++z) {
			for (size_t y = 0; y < height; ++y) {
				for (size_t x = 0; x < width; ++x) {

					cout << a(x, y, z, t) << ' ';
				}
				cout << '\n';
			}
			cout << "=======\n";
		}
		cout << "\n\n\n";
	}

	return 0;
}
