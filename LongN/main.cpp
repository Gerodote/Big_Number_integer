// LongN.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

#include "BigNumTests.h"

template <typename T, size_t N>
size_t myCompileTimeSize(T(&)[N]) {
	return N;
}

std::pair<bool, std::string>(*arrayOfTests[])() = {
#if __cpp_lib_format
	uint32_t_test_reprbinary,
	int32_t_test_reprbinary,
	constuint32_t_test_reprbinary,
	constint32_t_test_reprbinary,
	uint64_t_test_reprbinary,
	int64_t_test_reprbinary,
	constuint64_t_test_reprbinary,
	constint64_t_test_reprbinary,
	slice_test,
	int_compare_test,
	uint64_compare_test,
	constint64_t_test_reprdecimal,
	constint64_t_test_reprdecimal_op_ostream, 
#endif // _cpp_lib_format
	int64_t_test_operator_plus,
	int64_t_test_operator_plus_assignment,
	int64_t_test_operator_minus,
	int64_t_test_operator_minus_assign
};

int main()
{
	std::cout << "Program started" << std::endl;


	for (size_t i = 0; i < myCompileTimeSize(arrayOfTests); ++i) {
		std::pair<bool, std::string> res = (*arrayOfTests[i])();
		std::cout << (res.first ? "Test passed" : "Test failed, details : \n" + res.second) << std::endl;
	}

}
