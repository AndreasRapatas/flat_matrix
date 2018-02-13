#ifndef INFI_MATRIX_H
#define INFI_MATRIX_H

#include <vector>

template<typename T>
class Matrix {

	std::vector<unsigned> dimentions;
	std::vector<T> data;

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

		std::vector<unsigned> temp;
		temp = { static_cast<unsigned>(dimz)... };

		unsigned index = 0;

		for (unsigned i = 0; i < size(); ++i) {

			unsigned multiplier = 1;
			for (unsigned dimention_index = 0; dimention_index < i; ++dimention_index) {
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

};

#endif /* end of include guard: INFI_MATRIX_H */
