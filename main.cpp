#include <iostream>
#include <vector>
#include <string>


using namespace std;

template<typename T>
class Matrix {

	vector<unsigned> dimentions;
	vector<T> data;

public:

	template<typename... T_dim>
	Matrix(T_dim... dimz) {

		dimentions = { static_cast<unsigned>(dimz)... };

		unsigned size = 1;
		for (auto d : dimentions) {
			size *= d;
		}
		data.reserve(size);
	}

	unsigned size() const { return dimentions.size(); }

	template<typename... T_dim>
	unsigned find_index(T_dim... dimz) const {

		vector<unsigned> temp;
		temp = { static_cast<unsigned>(dimz)... };

		unsigned index = 0;

		for (size_t i = 0; i < size(); ++i) {

			unsigned multiplier = 1;
			for (size_t dimention_index = 0; dimention_index < i; ++dimention_index) {
				multiplier *= dimentions[dimention_index];
			}

			index += multiplier * temp[i];
		}

		return index;
	}

	template<typename... T_dim>
	T const& operator()(T_dim... dimz) const {

		return data[find_index(dimz...)];
	}

	template<typename... T_dim>
	T &operator()(T_dim... dimz) {

		return data[find_index(dimz...)];
	}

	void list_dimentions() {

		for (auto n : dimentions) {
			cout << n << ", ";
		}
		cout << '\n';
	}
};


int main() {

	unsigned width = 4;
	unsigned height = 3;
	unsigned depth = 4;
	unsigned time = 20;

	Matrix<char> a(width, height, depth, time);

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
