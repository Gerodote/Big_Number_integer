#ifndef BIGNUMTESTS_H
#define BIGNUMTESTS_H

#include <sstream>
#include <utility>
#include <vector>

#include "BigNum.h"

#if __cpp_lib_format

std::pair<bool, std::string> uint32_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint32_t ui32_0 = 0;
	uint32_t ui32_1 = 1;
	uint32_t ui32_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum t1(ui32_0);
	mylog << (std::format("{:b}", ui32_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", ui32_0) == t1.to_str(2));
	bn::BigNum t2(ui32_1);
	mylog << std::format("{:b}", ui32_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui32_1) == t2.to_str(2));
	bn::BigNum t3(ui32_m1);
	mylog << std::format("{:b}", ui32_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui32_m1) == t3.to_str(2));
	bn::BigNum t4(ui32_m1);
	mylog << std::format("{:o}", ui32_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", ui32_m1) == t4.to_str(8));
	bn::BigNum t5(ui32_m1);
	mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", ui32_m1) == t5.to_str(16));
	try {
		bn::BigNum t6(ui32_m1);
		mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", ui32_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum t7(ui32_m1);
		mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", ui32_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> int32_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int32_t i32_0 = 0;
	int32_t i32_1 = 1;
	int32_t i32_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum t1(i32_0);
	mylog << (std::format("{:b}", i32_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", i32_0) == t1.to_str(2));
	bn::BigNum t2(i32_1);
	mylog << std::format("{:b}", i32_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i32_1) == t2.to_str(2));
	bn::BigNum t3(i32_m1);
	mylog << std::format("{:b}", i32_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i32_m1) == t3.to_str(2));
	bn::BigNum t4(i32_m1);
	mylog << std::format("{:o}", i32_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", i32_m1) == t4.to_str(8));
	bn::BigNum t5(i32_m1);
	mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", i32_m1) == t5.to_str(16));
	try {
		bn::BigNum t6(i32_m1);
		mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", i32_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum t7(i32_m1);
		mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", i32_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constuint32_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint32_t ui32_0 = 0;
	uint32_t ui32_1 = 1;
	uint32_t ui32_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(ui32_0);
	mylog << (std::format("{:b}", ui32_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", ui32_0) == t1.to_str(2));
	bn::BigNum const t2(ui32_1);
	mylog << std::format("{:b}", ui32_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui32_1) == t2.to_str(2));
	bn::BigNum const t3(ui32_m1);
	mylog << std::format("{:b}", ui32_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui32_m1) == t3.to_str(2));
	bn::BigNum const t4(ui32_m1);
	mylog << std::format("{:o}", ui32_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", ui32_m1) == t4.to_str(8));
	bn::BigNum const t5(ui32_m1);
	mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", ui32_m1) == t5.to_str(16));
	try {
		bn::BigNum const t6(ui32_m1);
		mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", ui32_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum const t7(ui32_m1);
		mylog << std::format("{:x}", ui32_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", ui32_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constint32_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int32_t i32_0 = 0;
	int32_t i32_1 = 1;
	int32_t i32_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(i32_0);
	mylog << (std::format("{:b}", i32_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", i32_0) == t1.to_str(2));
	bn::BigNum const t2(i32_1);
	mylog << std::format("{:b}", i32_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i32_1) == t2.to_str(2));
	bn::BigNum const  t3(i32_m1);
	mylog << std::format("{:b}", i32_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i32_m1) == t3.to_str(2));
	bn::BigNum const  t4(i32_m1);
	mylog << std::format("{:o}", i32_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", i32_m1) == t4.to_str(8));
	bn::BigNum  const t5(i32_m1);
	mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", i32_m1) == t5.to_str(16));
	try {
		bn::BigNum  const t6(i32_m1);
		mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", i32_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum const  t7(i32_m1);
		mylog << std::format("{:x}", i32_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", i32_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> uint64_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint64_t ui64_0 = 0;
	uint64_t ui64_1 = 1;
	uint64_t ui64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum t1(ui64_0);
	mylog << (std::format("{:b}", ui64_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", ui64_0) == t1.to_str(2));
	bn::BigNum t2(ui64_1);
	mylog << std::format("{:b}", ui64_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui64_1) == t2.to_str(2));
	bn::BigNum t3(ui64_m1);
	mylog << std::format("{:b}", ui64_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui64_m1) == t3.to_str(2));
	bn::BigNum t4(ui64_m1);
	mylog << std::format("{:o}", ui64_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", ui64_m1) == t4.to_str(8));
	bn::BigNum t5(ui64_m1);
	mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", ui64_m1) == t5.to_str(16));
	try {
		bn::BigNum t6(ui64_m1);
		mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", ui64_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum t7(ui64_m1);
		mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", ui64_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> int64_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int64_t i64_0 = 0;
	int64_t i64_1 = 1;
	int64_t i64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum t1(i64_0);
	mylog << (std::format("{:b}", i64_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", i64_0) == t1.to_str(2));
	bn::BigNum t2(i64_1);
	mylog << std::format("{:b}", i64_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i64_1) == t2.to_str(2));
	bn::BigNum t3(i64_m1);
	mylog << std::format("{:b}", i64_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i64_m1) == t3.to_str(2));
	bn::BigNum t4(i64_m1);
	mylog << std::format("{:o}", i64_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", i64_m1) == t4.to_str(8));
	bn::BigNum t5(i64_m1);
	mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", i64_m1) == t5.to_str(16));
	try {
		bn::BigNum t6(i64_m1);
		mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", i64_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum t7(i64_m1);
		mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", i64_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constuint64_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint64_t ui64_0 = 0;
	uint64_t ui64_1 = 1;
	uint64_t ui64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(ui64_0);
	mylog << (std::format("{:b}", ui64_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", ui64_0) == t1.to_str(2));
	bn::BigNum const t2(ui64_1);
	mylog << std::format("{:b}", ui64_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui64_1) == t2.to_str(2));
	bn::BigNum const t3(ui64_m1);
	mylog << std::format("{:b}", ui64_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", ui64_m1) == t3.to_str(2));
	bn::BigNum const t4(ui64_m1);
	mylog << std::format("{:o}", ui64_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", ui64_m1) == t4.to_str(8));
	bn::BigNum const t5(ui64_m1);
	mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", ui64_m1) == t5.to_str(16));
	try {
		bn::BigNum const t6(ui64_m1);
		mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", ui64_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum const t7(ui64_m1);
		mylog << std::format("{:x}", ui64_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", ui64_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constint64_t_test_reprbinary() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int64_t i64_0 = 0;
	int64_t i64_1 = 1;
	int64_t i64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(i64_0);
	mylog << (std::format("{:b}", i64_0)) << " => " << std::endl << t1.to_str(2).c_str() << std::endl;
	res_ &= (std::format("{:b}", i64_0) == t1.to_str(2));
	bn::BigNum const t2(i64_1);
	mylog << std::format("{:b}", i64_1) << " => " << std::endl << t2.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i64_1) == t2.to_str(2));
	bn::BigNum const  t3(i64_m1);
	mylog << std::format("{:b}", i64_m1) << " => " << std::endl << t3.to_str(2) << std::endl;
	res_ &= (std::format("{:b}", i64_m1) == t3.to_str(2));
	bn::BigNum const  t4(i64_m1);
	mylog << std::format("{:o}", i64_m1) << " => " << std::endl << t4.to_str(8) << std::endl;
	res_ &= (std::format("{:o}", i64_m1) == t4.to_str(8));
	bn::BigNum  const t5(i64_m1);
	mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t5.to_str(16) << std::endl;
	res_ &= (std::format("{:x}", i64_m1) == t5.to_str(16));
	try {
		bn::BigNum  const t6(i64_m1);
		mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t6.to_str(0) << std::endl;
		res_ &= (std::format("{:x}", i64_m1) == t6.to_str(0));
	}
	catch (bn::WrongBase&) {
		mylog << "base 0 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	try {
		bn::BigNum const  t7(i64_m1);
		mylog << std::format("{:x}", i64_m1) << " => " << std::endl << t7.to_str(1) << std::endl;
		res_ &= (std::format("{:x}", i64_m1) == t7.to_str(1));
	}
	catch (bn::WrongBase&) {
		mylog << "base 1 catched" << std::endl;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> slice_test() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint64_t ui64_mine = 11794537904770359415; /* just a specific number: 1010 0011 1010 1110  1001 1101 1011 1011  1111 0111 10110111 1010 0000 0111 0111*/
	bn::BigNum const t1(ui64_mine);
	uint32_t res1 = t1.GetSlice(12);
	mylog << std::format("{:X}", res1) << " =? " << std::format("{:X}", 3686759290);
	res_ &= (res1 == static_cast<uint32_t>(3686759290));
	uint32_t res2 = t1.GetSlice(36);
	mylog << std::format("{:X}", res2) << " =? " << std::format("{:X}", 171633115);
	res_ &= (res2 == static_cast<uint32_t>(171633115));
	try {
		uint32_t res3 = t1.GetSlice(65);
	}
	catch (std::out_of_range&) {
		mylog << "bad slice index catched" << std::endl;
		res_ &= 1;
	}
	catch (std::exception&) {
		mylog << "Sth really stranged happened" << std::endl;
		res_ &= false;
	}
	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> int_compare_test() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int64_t i64_0 = 0;
	int64_t i64_1 = 1;
	int64_t i64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(i64_0);
	bn::BigNum const t2(i64_1);
	bn::BigNum const t3(i64_m1);
	mylog << "0 == 0 : " << (t1 == t1) << std::endl;
	res_ &= (t1 == t1);
	mylog << "0 < 1 : " << (t1 < t2) << std::endl;
	res_ &= (t1 < t2);
	mylog << "1 > -1 : " << (t2 > t3) << std::endl;
	res_ &= (t2 > t3);
	mylog << "1 >= -1 : " << (t2 >= t3) << std::endl;
	res_ &= (t2 >= t3);
	mylog << "-1 < 0 : " << (t3 <= t1) << std::endl;
	res_ &= (t3 <= t1);
	mylog << "-1 != 1 : " << (t3 != t2) << std::endl;
	res_ &= (t3 != t2);


	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> uint64_compare_test() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	uint64_t ui64_0 = 0;
	uint64_t ui64_1 = 1;
	uint64_t ui64_m1 = -1; // -1 == FFFF FFFF |=> uint32_t FFFF FFFF = 4,294,967,295
	bn::BigNum const t1(ui64_0);
	bn::BigNum const t2(ui64_1);
	bn::BigNum const t3(ui64_m1);
	bn::BigNum const t4(-15);
	mylog << "0 == 0 : " << (t1 == t1) << std::endl;
	res_ &= (t1 == t1);
	mylog << "0 < 1 : " << (t1 < t2) << std::endl;
	res_ &= (t1 < t2);
	mylog << "!1 > ffff ffff ffff ffff : " << !(t2 > t3) << std::endl;
	res_ &= !(t2 > t3);
	mylog << "!1 >= ffff ffff ffff ffff : " << !(t2 >= t3) << std::endl;
	res_ &= !(t2 >= t3);
	mylog << "!ffff ffff ffff ffff < 0 : " << !(t3 <= t1) << std::endl;
	res_ &= !(t3 <= t1);
	mylog << "ffff ffff ffff ffff != 1 : " << (t3 != t2) << std::endl;
	res_ &= (t3 != t2);
	mylog << "ffff ffff ffff ffff == ffff ffff ffff ffff : " << (t3 == t3) << std::endl;
	res_ &= (t3 == t3);
	mylog << "ffff ffff ffff ffff > ffff ffff ffff fff0 : " << (t3 > t4) << std::endl;
	res_ &= (t3 > t4);

	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constint64_t_test_reprdecimal() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int64_t i64_0 = 0;
	int64_t i64_1 = 1;
	int64_t i64_m1 = -1;
	bn::BigNum const t1(i64_0);
	mylog << (std::format("{}", i64_0)) << " => " << std::endl << t1.to_str(10).c_str() << std::endl;

	res_ &= (std::format("{}", i64_0) == t1.to_str(10));
	bn::BigNum const t2(i64_1);
	mylog << std::format("{}", i64_1) << " => " << std::endl << t2.to_str(10) << std::endl;
	res_ &= (std::format("{}", i64_1) == t2.to_str(10));
	bn::BigNum const  t3(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t3.to_str(10) << std::endl;
	res_ &= (std::format("{}", i64_m1) == t3.to_str(10));
	bn::BigNum const  t4(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t4.to_str(10) << std::endl;
	res_ &= (std::format("{}", i64_m1) == t4.to_str(10));
	bn::BigNum  const t5(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t5.to_str(10) << std::endl;
	res_ &= (std::format("{}", i64_m1) == t5.to_str(10));


	int64_t i64_123 = 124;
	bn::BigNum const t6(i64_123);
	mylog << (std::format("{}", i64_123)) << " => " << std::endl << t6.to_str(10).c_str() << std::endl;
	res_ &= (std::format("{}", i64_123) == t6.to_str(10));

	int64_t i64_big = 1231231231233;
	bn::BigNum const t7(i64_big);
	mylog << (std::format("{}", i64_big)) << " => " << std::endl << t7.to_str(10).c_str() << std::endl;
	res_ &= (std::format("{}", i64_big) == t7.to_str(10));


	return std::make_pair(res_, mylog.str());
}

std::pair<bool, std::string> constint64_t_test_reprdecimal_op_ostream() {
	bool res_ = true;
	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	int64_t i64_0 = 0;
	int64_t i64_1 = 1;
	int64_t i64_m1 = -1;
	std::stringstream str_for_test;


	bn::BigNum const t1(i64_0);
	mylog << (std::format("{}", i64_0)) << " => " << std::endl << t1 << std::endl;
	str_for_test << t1;
	res_ &= (std::format("{}", i64_0) == str_for_test.str());
	str_for_test.str(std::string());

	bn::BigNum const t2(i64_1);
	mylog << std::format("{}", i64_1) << " => " << std::endl << t2 << std::endl;
	str_for_test << t2;
	res_ &= (std::format("{}", i64_1) == str_for_test.str());
	str_for_test.str(std::string());

	bn::BigNum const  t3(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t3 << std::endl;
	str_for_test << t3;
	res_ &= (std::format("{}", i64_m1) == str_for_test.str());
	str_for_test.str(std::string());

	bn::BigNum const  t4(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t4 << std::endl;
	str_for_test << t4;
	res_ &= (std::format("{}", i64_m1) == str_for_test.str());
	str_for_test.str(std::string());

	bn::BigNum  const t5(i64_m1);
	mylog << std::format("{}", i64_m1) << " => " << std::endl << t5 << std::endl;
	str_for_test << t5;
	res_ &= (std::format("{}", i64_m1) == str_for_test.str());
	str_for_test.str(std::string());


	int64_t i64_124 = 124;
	bn::BigNum const t6(i64_124);
	mylog << (std::format("{}", i64_124)) << " => " << std::endl << t6.to_str(10).c_str() << std::endl;
	str_for_test << t6;
	res_ &= (std::format("{}", i64_124) == str_for_test.str());
	str_for_test.str(std::string());


	return std::make_pair(res_, mylog.str());
}

#endif

std::pair<bool, std::string> int64_t_test_operator_plus() {

	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	bool result = true;

	bn::BigNum(*plus)(int64_t, int64_t) = [](int64_t left, int64_t right) -> bn::BigNum { return left + right; };

	std::pair< bn::BigNum(*)(int64_t, int64_t), std::vector< std::tuple<int64_t, int64_t, int64_t> > > tests =
	{ plus,
		{
			{1,1,2},
			{0xFFFFFFFF, 1, 0x100000000},
			{0xFFFFFFFF, 0xFF, 0x1000000FE},
			{1, -1, 0},
			{2, -1, 1},
			{-1, 1, 0},
			{ -2, 1, -1},
			{-2, -2, -4},
			{-8589934591, -4294967296, -12884901887},
			{-4294967296, -8589934591, -12884901887},
			{-8589934591, 4294967296, -4294967295},
			{-8589934592, 4294967296, -4294967296},
			{4294967296 ,-8589934592,  -4294967296},
			{8589934592, -4294967296, 4294967296},
			{-4294967296 ,8589934592,  4294967296}
			
		}
	};

	try {
		for (const auto& test_it : tests.second) {
			bool result_of_current_test = true;
			result_of_current_test &= (tests.first(std::get<0>(test_it), std::get<1>(test_it)) == std::get<2>(test_it));
			mylog << " function(" << std::get<0>(test_it) << ", " << std::get<1>(test_it) << ") => " << std::endl <<
				tests.first(std::get<0>(test_it), std::get<1>(test_it)) << std::endl
				<< "Expected answer:" << std::get<2>(test_it) << std::endl
				<< "Is this test passed ? : " << (result_of_current_test ? "yes" : "no  <<<<<<<<<<<<<<<<<<<<<< FAILED") << std::endl << std::endl;
			result &= result_of_current_test;
		}

	}
	catch (std::exception&) {
		return std::make_pair(false, mylog.str() + "\nUnexpected exception catched, CRITICAL");
	}
	return std::make_pair(result, mylog.str());
}


std::pair<bool, std::string> int64_t_test_operator_plus_assignment() {

	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	bool result = true;

	bn::BigNum(*plus)(int64_t, int64_t) = [](int64_t left, int64_t right) -> bn::BigNum { return (left += right); };

	std::pair< bn::BigNum(*)(int64_t, int64_t), std::vector< std::tuple<int64_t, int64_t, int64_t> > > tests =
	{ plus,
		{
			{1,1,2},
			{0xFFFFFFFF, 1, 0x100000000},
			{0xFFFFFFFF, 0xFF, 0x1000000FE},
			{1, -1, 0},
			{2, -1, 1},
			{-1, 1, 0},
			{ -2, 1, -1},
			{-2, -2, -4},
			{-8589934591, -4294967296, -12884901887},
			{-4294967296, -8589934591, -12884901887},
			{-8589934591, 4294967296, -4294967295},
			{-8589934592, 4294967296, -4294967296},
			{4294967296 ,-8589934592,  -4294967296},
			{8589934592, -4294967296, 4294967296},
			{-4294967296 ,8589934592,  4294967296}
		}
	};

	try {
		for (const auto& test_it : tests.second) {
			bool result_of_current_test = true;
			result_of_current_test &= (tests.first(std::get<0>(test_it), std::get<1>(test_it)) == std::get<2>(test_it));
			mylog << " function(" << std::get<0>(test_it) << ", " << std::get<1>(test_it) << ") => " << std::endl <<
				tests.first(std::get<0>(test_it), std::get<1>(test_it)) << std::endl
				<< "Expected answer:" << std::get<2>(test_it) << std::endl
				<< "Is this test passed ? : " << (result_of_current_test ? "yes" : "no  <<<<<<<<<<<<<<<<<<<<<< FAILED") << std::endl << std::endl;
			result &= result_of_current_test;
		}

	}
	catch (std::exception&) {
		return std::make_pair(false, mylog.str() + "\nUnexpected exception catched, CRITICAL");
	}
	return std::make_pair(result, mylog.str());
}

std::pair<bool, std::string> int64_t_test_operator_minus() {

	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	bool result = true;

	bn::BigNum(*minus)(int64_t, int64_t) = [](int64_t left, int64_t right) -> bn::BigNum { return left - right; };

	std::pair< bn::BigNum(*)(int64_t, int64_t), std::vector< std::tuple<int64_t, int64_t, int64_t> > > tests =
	{ minus,
		{
			{1,1,0},
			{0xFFFFFFFF, 1, 0xFFFFFFFE},
			{0xFFFFFFFF, 0xFF, 0xFFFFFF00},
			{1, -1, 2},
			{2, -1, 3},
			{-1, 1, -2},
			{ -2, 1, -3},
			{-2, -2, 0},
			{-8589934591, -4294967296, -4294967295},
			{-4294967296, -8589934591, 4294967295},
			{-8589934591, 4294967296, -12884901887},
			{-8589934592, 4294967296, -12884901888},
			{4294967296 ,-8589934592,  12884901888},
			{8589934592, -4294967296, 12884901888},
			{4294967296, -8589934592, 12884901888},
			{-4294967296 ,8589934592,  -12884901888}

		}
	};

	try {
		for (const auto& test_it : tests.second) {
			bool result_of_current_test = true;
			result_of_current_test &= (tests.first(std::get<0>(test_it), std::get<1>(test_it)) == std::get<2>(test_it));
			mylog << " function(" << std::get<0>(test_it) << ", " << std::get<1>(test_it) << ") => " << std::endl <<
				tests.first(std::get<0>(test_it), std::get<1>(test_it)) << std::endl
				<< "Expected answer:" << std::get<2>(test_it) << std::endl
				<< "Is this test passed ? : " << (result_of_current_test ? "yes" : "no  <<<<<<<<<<<<<<<<<<<<<< FAILED") << std::endl << std::endl;
			result &= result_of_current_test;
		}

	}
	catch (std::exception&) {
		return std::make_pair(false, mylog.str() + "\nUnexpected exception catched, CRITICAL");
	}
	return std::make_pair(result, mylog.str());
}

std::pair<bool, std::string> int64_t_test_operator_minus_assign() {

	std::stringstream mylog;
	mylog << "Test name: " << __FUNCTION__ << std::endl;
	bool result = true;

	bn::BigNum(*minus)(int64_t, int64_t) = [](int64_t left, int64_t right) -> bn::BigNum { return left -= right; };

	std::pair< bn::BigNum(*)(int64_t, int64_t), std::vector< std::tuple<int64_t, int64_t, int64_t> > > tests =
	{ minus,
		{
			{1,1,0},
			{0xFFFFFFFF, 1, 0xFFFFFFFE},
			{0xFFFFFFFF, 0xFF, 0xFFFFFF00},
			{1, -1, 2},
			{2, -1, 3},
			{-1, 1, -2},
			{ -2, 1, -3},
			{-2, -2, 0},
			{-8589934591, -4294967296, -4294967295},
			{-4294967296, -8589934591, 4294967295},
			{-8589934591, 4294967296, -12884901887},
			{-8589934592, 4294967296, -12884901888},
			{4294967296 ,-8589934592,  12884901888},
			{8589934592, -4294967296, 12884901888},
			{4294967296, -8589934592, 12884901888},
			{-4294967296 ,8589934592,  -12884901888}

		}
	};

	try {
		for (const auto& test_it : tests.second) {
			bool result_of_current_test = true;
			result_of_current_test &= (tests.first(std::get<0>(test_it), std::get<1>(test_it)) == std::get<2>(test_it));
			mylog << " function(" << std::get<0>(test_it) << ", " << std::get<1>(test_it) << ") => " << std::endl <<
				tests.first(std::get<0>(test_it), std::get<1>(test_it)) << std::endl
				<< "Expected answer:" << std::get<2>(test_it) << std::endl
				<< "Is this test passed ? : " << (result_of_current_test ? "yes" : "no  <<<<<<<<<<<<<<<<<<<<<< FAILED") << std::endl << std::endl;
			result &= result_of_current_test;
		}

	}
	catch (std::exception&) {
		return std::make_pair(false, mylog.str() + "\nUnexpected exception catched, CRITICAL");
	}
	return std::make_pair(result, mylog.str());
}



#endif // BIGNUMTESTS_H