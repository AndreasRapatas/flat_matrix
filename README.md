# Infinite Dimension Matrix
An Infinite Dimension Matrix, stored in a flattened state as a vector for faster access.

# Usage
```cpp
infi_matrix<std::string> my_matrix(
	width,
	height,
	depth,
	time,
	universe_id,
	// anything
);

for (unsigned i = 0; i < my_matrix.size(); ++i) {
	my_matrix[i] = "Sad";
}

my_matrix(808, 69, 9000, 1337, 42) = "Happy";

```

# TODO:
- Remove vector, allocate array manually.
- Offer iterators.
