#ifndef BIGNUM_H
#define BIGNUM_H

#include <vector>
#include <string>
#include <cstdint>
#include <compare>
#include <ostream>
#include <exception>
#include <algorithm>
#include <cmath>

#if __cpp_lib_format
#include <format>
#endif // __cpp_lib_format

namespace bn
{
	class WrongBase : public std::exception {
	public:
		explicit WrongBase(const char* message) : msg(message) {}
		WrongBase(WrongBase const&) noexcept = default;

		WrongBase& operator=(WrongBase const&) noexcept = default;
		~WrongBase() override = default;

		const char* what() const noexcept override { return msg; }
	private:
		const char* msg;
	};


	class BigNum
	{
		static uint64_t const _base = 4294967296; // don't change it
		// 1 0000 0000 0000 0000 0000 0000 0000 0000 in binary

		bool _sign;
		// 0 |=> this >= 0
		// 1 |=> this < 0

		std::vector<uint32_t> _data;
		// first elements are less important

		// private methods:
		inline explicit BigNum(bool sign, size_t count, uint32_t const& value) : _sign(sign), _data(count, value) {};
		inline explicit BigNum(bool sign, std::vector<uint32_t> data) : _sign(sign), _data(data) {};

		std::strong_ordering CompareByAbs(BigNum const& that) const;

	public:

		inline explicit BigNum() : _sign(0), _data(0) {};
		inline BigNum(int64_t const& num) : _sign((num < 0)) {
			uint64_t positive_num = static_cast<uint64_t>(num < 0 ? (-1) * num : num);
			_data = { static_cast<uint32_t>((positive_num)),static_cast<uint32_t>(positive_num >> 32) };
		};
		inline BigNum(uint64_t const& num) : _sign(0), _data({ static_cast<uint32_t>((num)),static_cast<uint32_t>(num >> 32) }) {};
		inline BigNum(int32_t const& num) : _sign((num < 0)), _data({ (num < 0) ? ((~static_cast<uint32_t>(num)) + 1) : static_cast<uint32_t>(num) }) {};
		inline BigNum(uint32_t const& num) : _sign(0), _data({ num }) {};



		//inline explicit BigNum(std::string const& str, uint32_t base = 10) {
		//	if (*(str.begin()) == '-') {
		//		_sign = true;
		//	}
		//	_data.resize((str.size())*(1+std::log2(base)),0);

		//	auto i = ++(str.cbegin());
		//	bool is_null_beginning_ended = false;
		//	bool is_null = false;
		//	while ((!is_null_beginning_ended)) {
		//		if ((i == str.cend())) { is_null = true; break; }
		//		else {
		//			if (*i != 0) {
		//				is_null_beginning_ended = true;
		//				break;
		//			}
		//			else {
		//				++i;
		//			}
		//		}
		//	};
		//	if (is_null) { _data = { 0 }; }
		//	else {
		//		
		//	}
		//	
		//};
		/*
		inline explicit BigNum(char const* carr, uint32_t base = 10);
		inline friend BigNum operator""_bn(char const*);
		*/
		inline ~BigNum() = default;
		inline BigNum(BigNum const&) = default;
		inline BigNum& operator=(BigNum const&) = default;
		inline BigNum(BigNum&&) = default;
		inline BigNum& operator=(BigNum&&) = default;

		inline BigNum operator-() const {
			BigNum tmp(*this);
			tmp._sign = !tmp._sign;
			return tmp;
		}
		inline BigNum Abs() const {
			BigNum tmp(*this);
			tmp._sign = false;
			return tmp;
		}

		BigNum operator+(BigNum const& that) const;

		
		inline BigNum operator-(BigNum const& that) const {
			return (*this) + (-that);
		};

		inline BigNum& operator+=(BigNum const& that) {
			*this = *this + that;
			return *this;
		};
		inline BigNum& operator-=(BigNum const& that) {
			*this = *this + (-that);
			return *this;
		};

		/*inline BigNum operator/(BigNum const&) const;
		inline BigNum operator%(BigNum const&) const;*/
		/*inline BigNum& operator/=(BigNum const&);
		inline BigNum& operator%=(BigNum const&);

		// multimethod operator*

		//bitwise operators:
		//inline BigNum& operator~();
		inline BigNum operator^ (BigNum const&) const;
		inline BigNum operator| (BigNum const&) const;
		inline BigNum operator& (BigNum const&) const;
		inline BigNum operator<< (size_t const&) const;
		inline BigNum operator>> (size_t const&) const;
		inline BigNum& operator^=(BigNum const&);
		inline BigNum& operator|=(BigNum const&);
		inline BigNum& operator&=(BigNum const&);
		inline BigNum& operator=<<(size_t const&);
		inline BigNum& operator=>>(size_t const&);
		inline size_t BitScanForward() const;

		*/

		// TODO: test for this
		inline BigNum operator^ (BigNum const& that) const {
			BigNum tmp(_sign ^ that._sign, std::max(_data.size(), that._data.size()), 0);

			auto it1 = _data.cbegin();
			auto ittmp = tmp._data.begin();
			for (auto it2 = that._data.cbegin(); (it1 != _data.cend()) && (it2 != that._data.cend()); ++it1, ++it2, ++ittmp) {
				*ittmp = (*it1) ^ (*it2);
			}
			return tmp; // RVO
		};


		// comparison operators:
		std::strong_ordering operator<=>(BigNum const& that) const;

		inline bool operator==(BigNum const&) const = default;

		// hash
		// multimethod check primeness

		//getters
		inline bool GetSign() const noexcept(true) {
			return _sign;
		}
		inline uint64_t GetBase() const noexcept(true)
		{
			return _base;
		}

		// useful
		inline uint32_t GetSlice(size_t from_which_bit_index) const {
			size_t div = from_which_bit_index / 32;
			size_t mod = from_which_bit_index % 32;
			uint32_t res = 0;
			if ((div + 1 < _data.size()) && (_data.size() != 1))
				res = ((_data[div + 1] << (32 - mod))) | (_data[div] >> mod);
			else if (div + 1 == _data.size())
				res = (_data[div] >> mod);
			else throw(std::out_of_range(std::format("Incorrect slice. std::vector size is {} , slice index is {}, slice index / 32 is {}", _data.size(), from_which_bit_index, div).c_str()));
			return res;
		};

		std::string to_str(uint32_t base = 10) const;

		friend inline std::ostream& operator<<(std::ostream& out, BigNum const& num) {
			out << num.to_str();
			return out;
		};
	};

}
#endif // !BIGNUM_H
