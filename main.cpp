#include <iostream>
#include <vector>
#include <string>


using namespace std;

template<typename T>
class Matrix {

	vector<unsigned> dimentions;
	vector<unsigned> temp;
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
	T const& operator()(T_dim... dimz) const {
		temp = { static_cast<unsigned>(dimz)... };

		unsigned index = 0;

		for (size_t i = 0; i < size(); ++i) {

			unsigned multiplier = 1;
			for (size_t dimention_index = 0; dimention_index < i; ++dimention_index) {
				multiplier *= dimentions[dimention_index];
			}

			index += multiplier * temp[i];
		}

		return data[index];
	}

	template<typename... T_dim>
	T &operator()(T_dim... dimz) {
		temp = { static_cast<unsigned>(dimz)... };

		unsigned index = 0;

		for (size_t i = 0; i < size(); ++i) {

			unsigned multiplier = 1;
			for (size_t dimention_index = 0; dimention_index < i; ++dimention_index) {
				multiplier *= dimentions[dimention_index];
			}

			index += multiplier * temp[i];
		}

		return data[index];
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

	Matrix<char> a(width, height, depth);

	a.list_dimentions();

	for (size_t z = 0; z < depth; ++z) {
		for (size_t y = 0; y < height; ++y) {
			for (size_t x = 0; x < width; ++x) {
				a(x, y, z) = '#';
			}
		}
	}

	a(2, 1, 3) = '_';

	for (size_t z = 0; z < depth; ++z) {
		for (size_t y = 0; y < height; ++y) {
			for (size_t x = 0; x < width; ++x) {
				cout << a(x, y, z) << ' ';
			}
			cout << '\n';
		}
		cout << "====\n";
	}


	return 0;
}
