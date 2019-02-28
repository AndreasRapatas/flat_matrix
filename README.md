# Flat Matrix
An Infinite Dimension Matrix, stored in a flattened state as an array for faster access.

# Usage
```cpp
flat_matrix<std::string> my_matrix(
	width,
	height,
	depth,
	time,
	universe_id,
	// anything
);

// Sequential Access
for (unsigned i = 0; i < my_matrix.size(); ++i) {
	my_matrix[i] = "Sad";
}

// Random Access
my_matrix(
	808,  // Width
	69,   // Height
	9000, // Depth
	1337, // Time
	42    // Universe ID
) = "Happy";

```

# Installation
```bash
git clone https://github.com/Rapatas/flat_matrix
mkdir flat_matrix/build
cd flat_matrix/build
cmake ..
make install # As root
```
