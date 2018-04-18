#include <catch/catch.hpp>

#include "../include/flat_matrix.h"

SCENARIO ("Basic") {

	unsigned width = 10;
	unsigned height = 5;
	unsigned depth = 8;

	GIVEN ("1D bool flat_matrix") {


		flat_matrix<bool> arr(width);

		WHEN ("setting each one to false in a for loop using operator[]") {

			for (unsigned i = 0; i < arr.size(); ++i) {
				arr[i] = false;
			}

			THEN ("Each one should be false") {

				for (unsigned i = 0; i < arr.size(); ++i) {
					REQUIRE(arr[i] == false);
				}
			}
		}

		WHEN ("setting each one to false in a for loop using operator()") {

			for (unsigned i = 0; i < width; ++i) {
				arr(i) = false;
			}

			THEN ("Each one should be false") {

				for (unsigned i = 0; i < width; ++i) {
					REQUIRE(arr(i) == false);
				}
			}
		}
	}

	GIVEN ("2D bool flat_matrix") {

		flat_matrix<bool> matrix(height, width);

		WHEN ("Setting each one to false in a for loop using operator[]") {

			for (unsigned i = 0; i < matrix.size(); ++i) {
				matrix[i] = false;
			}

			THEN ("Each one should be false") {

				for (unsigned i = 0; i < matrix.size(); ++i) {
					REQUIRE(matrix(i) == false);
				}
			}
		}

		WHEN ("Setting each one to false in 2 for loops using operator()") {

			for (unsigned y = 0; y != height; ++y) {
				for (unsigned x = 0; x != width; ++x) {
					matrix(y, x) = false;
				}
			}

			THEN ("Each one should be false") {

				for (unsigned y = 0; y != height; ++y) {
					for (unsigned x = 0; x != width; ++x) {
						REQUIRE(matrix(y, x) == false);
					}
				}
			}
		}
	}

	GIVEN ("3D bool flat_matrix") {

		flat_matrix<bool> matrix(depth, height, width);

		WHEN ("Setting each one to false in a for loop using operator[]") {

			for (unsigned i = 0; i < matrix.size(); ++i) {
				matrix[i] = false;
			}

			THEN ("Each one should be false") {

				for (unsigned i = 0; i < matrix.size(); ++i) {
					REQUIRE(matrix(i) == false);
				}
			}
		}

		WHEN ("Setting each one to false in 3 for loops using operator()") {

			for (unsigned z = 0; z != depth; ++z) {
				for (unsigned y = 0; y != height; ++y) {
					for (unsigned x = 0; x != width; ++x) {
						matrix(z, y, x) = false;
					}
				}
			}

			THEN ("Each one should be false") {

				for (unsigned z = 0; z != depth; ++z) {
					for (unsigned y = 0; y != height; ++y) {
						for (unsigned x = 0; x != width; ++x) {
							matrix(z, y, x) = false;
							REQUIRE(matrix(z, y, x) == false);
						}
					}
				}
			}
		}
	}
}

