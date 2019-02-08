#include <utility>

#include <catch2/catch.hpp>

#include "../include/flat_matrix.h"

SCENARIO ("copy_move") {

	unsigned width = 10;
	unsigned height = 5;
	unsigned depth = 8;

	GIVEN ("1D bool flat_matrix initialized to false") {

		flat_matrix<bool> arr(width);

		for (unsigned i = 0; i < arr.size(); ++i) {
			arr[i] = false;
		}

		WHEN ("Copy constructor") {

			flat_matrix<bool> new_one(arr);

			THEN ("The new flat_matrix should match") {

				for (unsigned i = 0; i < arr.size(); ++i) {
					REQUIRE(new_one[i] == arr[i]);
				}
			}
		}

		WHEN ("Copy assigment operator on a 1D flat_matrix initialized to true") {

			flat_matrix<bool> new_one(width - 5);

			for (unsigned i = 0; i < arr.size(); ++i) {
				new_one[i] = true;
			}

			new_one = arr;

			THEN ("The new flat_matrix should match") {

				for (unsigned i = 0; i < arr.size(); ++i) {
					REQUIRE(new_one[i] == arr[i]);
				}
			}
		}

		WHEN ("move constructor") {

			flat_matrix<bool> new_one(std::move(arr));

			THEN ("The new matrix should be all false") {

				for (unsigned i = 0; i < arr.size(); ++i) {
					REQUIRE(new_one[i] == false);
				}
			}

			THEN ("The old flat_matrix should be empty") {

				REQUIRE(arr.size() == 0);
			}
		}

		WHEN ("move assigment operator on a 1D flat_matrix initialized to true") {

			flat_matrix<bool> new_one(width - 4);


			for (unsigned i = 0; i < arr.size(); ++i) {
				new_one[i] = true;
			}

			new_one = std::move(arr);

			THEN ("The new matrix should be all false") {

				for (unsigned i = 0; i < arr.size(); ++i) {
					REQUIRE(new_one[i] == false);
				}
			}

			THEN ("The old flat_matrix should be empty") {

				REQUIRE(arr.size() == 0);
			}
		}
	}
}
