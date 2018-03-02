#ifndef INFI_MATRIX_H
#define INFI_MATRIX_H

template<typename T>
class infi_matrix {

	unsigned *dimentions;
	unsigned dimention_count;
	T *data;
	unsigned data_size;

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

	template<typename... T_dim>
	infi_matrix(T_dim... dimz) :
		dimention_count(sizeof...(T_dim))
	{
		dimentions = array_from_variadic(dimz...);

		unsigned size = 1;
		for (unsigned i = 0; i < dimention_count; ++i) {
			size *= dimentions[i];
		}
		data = new T[size];
	}

	~infi_matrix() {

		delete[] dimentions;
		delete[] data;
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
		return data[find_index(dimz...)];
	}

	template<typename... T_dim>
	T &operator()(T_dim... dimz) {
		return data[find_index(dimz...)];
	}

	T const& operator[](unsigned index) const {
		return data[index];
	}

	T &operator[](unsigned index) {
		return data[index];
	}
};

#endif // INFI_MATRIX_H
