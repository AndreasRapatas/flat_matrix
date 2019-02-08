#ifndef FLAT_MATRIX_H
#define FLAT_MATRIX_H

#include <stdexcept>

template<typename T>
class flat_matrix {

	unsigned *dimentions = nullptr;
	unsigned dimention_count = 0;
	T *data = nullptr;
	unsigned data_size = 0;

	template<typename... Type>
	unsigned *array_from_variadic(Type... args) const {

		unsigned *ret = new unsigned[sizeof...(args)];

		unsigned i = 0;
		for (const unsigned& num : {args...}) {
			ret[i] = num;
			++i;
		}

		return ret;
	}

public:

	flat_matrix() {}

	template<typename... T_dim>
	flat_matrix(T_dim... dimz) {
		resize(dimz...);
	}

	template<typename... T_dim>
	void resize(T_dim... dimz) {

		if (dimention_count) {
			delete [] dimentions;
		}
		if (data_size) {
			delete [] data;
		}

		dimention_count = sizeof...(T_dim);
		dimentions = array_from_variadic(dimz...);

		unsigned size = 1;
		for (unsigned i = 0; i < dimention_count; ++i) {
			size *= dimentions[i];
		}
		data = new T[size];
		data_size = size;
	}

	~flat_matrix() {

		delete[] dimentions;
		delete[] data;
	}

	flat_matrix(const flat_matrix &other) {

		dimention_count = other.dimention_count;
		data_size       = other.data_size;
		dimentions      = new unsigned[dimention_count];
		data            = new T[data_size];

		for (unsigned i = 0; i != data_size; ++i) {
			data[i] = other.data[i];
		}

		for (unsigned i = 0; i != dimention_count; ++i) {
			dimentions[i] = other.dimentions[i];
		}
	}

	flat_matrix& operator=(const flat_matrix &other) {

		if (this == &other) { return *this; }

		dimention_count = other.dimention_count;
		data_size       = other.data_size;
		delete[] dimentions;
		delete[] data;
		dimentions      = new unsigned[dimention_count];
		data            = new T[data_size];

		for (unsigned i = 0; i != data_size; ++i) {
			data[i] = other.data[i];
		}

		for (unsigned i = 0; i != dimention_count; ++i) {
			dimentions[i] = other.dimentions[i];
		}

		return *this;
	}

	flat_matrix(flat_matrix &&other) {

		dimention_count = other.dimention_count;
		data_size       = other.data_size;
		dimentions      = other. dimentions;
		data            = other.data;

		other.dimention_count = 0;
		other.dimentions      = nullptr;
		other.data_size       = 0;
		other.data            = nullptr;
	}

	flat_matrix& operator=(flat_matrix &&other) {

		dimention_count = other.dimention_count;
		data_size       = other.data_size;
		dimentions      = other.dimentions;
		data            = other.data;

		other.dimention_count = 0;
		other.dimentions      = nullptr;
		other.data_size       = 0;
		other.data            = nullptr;

		return *this;
	}

	unsigned size() const { return data_size; }

	template<typename... T_dim>
	unsigned find_index(T_dim... dimz) const {

		unsigned *provided_dimz = array_from_variadic(dimz...);

		unsigned index = 0;

		for (unsigned i = 0; i < sizeof...(T_dim); ++i) {

			unsigned multiplier = 1;
			for (
				unsigned dimention_index = 0;
				dimention_index < i;
				++dimention_index
			) {
				multiplier *= dimentions[dimention_index];
			}

			index += multiplier * provided_dimz[i];
		}

		delete[] provided_dimz;

		return index;
	}

	template<typename... T_dim>
	T const& operator()(T_dim... dimz) const {
		if (data_size == 0) {
			throw std::out_of_range("operator() called on empty flat_matrix");
		}
		return data[find_index(dimz...)];
	}

	template<typename... T_dim>
	T &operator()(T_dim... dimz) {
		if (data_size == 0) {
			throw std::out_of_range("operator() called on empty flat_matrix");
		}
		return data[find_index(dimz...)];
	}

	T const& operator[](unsigned index) const {
		if (data_size == 0) {
			throw std::out_of_range("operator[] called on empty flat_matrix");
		}
		return data[index];
	}

	T &operator[](unsigned index) {
		if (data_size == 0) {
			throw std::out_of_range("operator[] called on empty flat_matrix");
		}
		return data[index];
	}
};

#endif // FLAT_MATRIX_H
