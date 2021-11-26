#include "BigNum.h"
namespace bn {

	BigNum BigNum::operator+(BigNum const& that) const{
			BigNum res(false, (this->_data.size() >= that._data.size() ? 1 + this->_data.size() : 1 + that._data.size()), 0);
			if (!(this->_sign ^ that._sign)) { // -this -that or +this +that
				if (this->_sign) res._sign = true;

				if (this->_data.size() > that._data.size()) { res._data.resize(this->_data.size(), 0); }
				else { res._data.resize(that._data.size(), 0); }

				auto this_iter = this->_data.cbegin();
				auto that_iter = that._data.cbegin();
				std::vector<uint64_t> big_num_tmp((this->_data.size() >= that._data.size() ? 1 + this->_data.size() : 1 + that._data.size()), 0);
				auto tmp_iter = big_num_tmp.begin();

				if (this->_data.size() >= that._data.size()) {
					//copy from bigger num
					for (; this_iter != this->_data.cend(); ++this_iter, ++tmp_iter) {
						*tmp_iter = *this_iter;
					}

					// this + that
					tmp_iter = big_num_tmp.begin();
					for (; that_iter != that._data.cend(); ++that_iter, ++tmp_iter) {
						*tmp_iter += *that_iter;
					}
				}
				else {
					//copy from bigger num
					for (; that_iter != that._data.cend(); ++that_iter, ++tmp_iter) {
						*tmp_iter = *that_iter;
					}

					// that + this
					tmp_iter = big_num_tmp.begin();
					for (; this_iter != this->_data.cend(); ++this_iter, ++tmp_iter) {
						*tmp_iter += *this_iter;
					}
				}
				//normalize for uint32_t base
				tmp_iter = big_num_tmp.begin();
				for (; (tmp_iter != big_num_tmp.end()); ++tmp_iter) {
					if ((*tmp_iter) > (_base - 1)) {
						++(*std::next(tmp_iter));
						*tmp_iter %= _base;
					}
				}

				// finding appropriate size for std::vector<uint32_t> _data in the tmp object
				auto i = big_num_tmp.crbegin();
				bool is_null_beginning_ended = false;
				bool is_null = false;
				while ((!is_null_beginning_ended)) {
					if ((i == big_num_tmp.crend())) { is_null = true; break; }
					else {
						if (*i != 0) {
							is_null_beginning_ended = true;
							break;
						}
						else {
							++i;
						}
					}
				};
				if (is_null) { res._data = { 0 }; return res; }
				else {
					res._data.resize(std::distance(i.base(), big_num_tmp.cbegin()), 0);
				}

				// copy to BigNum object
				tmp_iter = big_num_tmp.begin();
				for (auto tmp_it = res._data.begin(); (tmp_iter != big_num_tmp.end()); ++tmp_iter, ++tmp_it) {
					*tmp_it = static_cast<uint32_t>(*tmp_iter);
				}


			}
			else { // this - that or that - this

				auto this_iter = this->_data.cbegin();
				auto that_iter = that._data.cbegin();
				//BigNum big_num_tmp(false, this->_data.size() >= that._data.size() ? 1 + this->_data.size() : 1 + that._data.size(), 0);
				auto res_iter = res._data.begin();

				std::strong_ordering result_of_compare = this->CompareByAbs(that);
				if (std::strong_ordering::greater == result_of_compare) {
					res._sign = this->_sign;

					// copy from bigger number to res
					for (; this_iter != this->_data.cend(); ++this_iter, ++res_iter) {
						*res_iter = *this_iter;
					}

					//this - that
					res_iter = res._data.begin();
					uint_fast8_t tmp = 0;
					for (; (that_iter != that._data.cend()) || (std::next(res_iter) != res._data.end()); ++that_iter, ++res_iter) {
						if (*(res_iter) < static_cast<uint64_t>(*(that_iter)) + tmp) {
							*(res_iter) = static_cast<uint32_t>(_base - (static_cast<uint64_t>(*(that_iter)) + tmp - static_cast<uint64_t>(*(res_iter)) ));
							tmp = 1;
						}
						else {
							
							*(res_iter) -= tmp;
							*(res_iter) -= (*(that_iter));
							tmp = 0;
						}
						//*res_iter += *that_iter;
					}

				}
				else if (std::strong_ordering::less == result_of_compare) {					// copy from bigger number to res
					res._sign = that._sign;

					for (; that_iter != that._data.cend(); ++that_iter, ++res_iter) {
						*res_iter = *that_iter;
					}

					//this - that
					res_iter = res._data.begin();
					uint_fast8_t tmp = 0;
					for (; (this_iter != this->_data.cend()) || (std::next(res_iter) != res._data.end()); ++this_iter, ++res_iter) {
						if (*(res_iter) < static_cast<uint64_t>(*(this_iter)) + tmp) {
							*(res_iter) = static_cast<uint32_t>(_base - (static_cast<uint64_t>(*(this_iter)) + tmp - static_cast<uint64_t>(*(res_iter))));
							tmp = 1;
						}
						else {

							*(res_iter) -= tmp;
							*(res_iter) -= (*(this_iter));
							tmp = 0;
						}
						//*res_iter += *that_iter;
					}
				}
				else { res._data = { 0 }; }
			}


			return res; // RVO ?
		}

	std::strong_ordering BigNum::operator<=>(BigNum const& that) const {
		//this code is not written in structural programming way ( multiple returns )
		if (this->_sign && !that._sign) return std::strong_ordering::less;
		if (!this->_sign && that._sign) return std::strong_ordering::greater;

		auto i = _data.crbegin();
		bool is_null_beginning_ended = false;
		bool is_null = false;
		while ((!is_null_beginning_ended)) {
			if ((i == _data.crend())) { is_null = true; break; }
			else {
				if (*i != 0) {
					is_null_beginning_ended = true;
					break;
				}
				else {
					++i;
				}
			}
		};
		auto i2 = that._data.crbegin();
		bool is_null_beginning_ended2 = false;
		bool is_null2 = false;
		while ((!is_null_beginning_ended2)) {
			if ((i2 == that._data.crend())) { is_null2 = true; break; }
			else {
				if (*i2 != 0) {
					is_null_beginning_ended2 = true;
					break;
				}
				else {
					++i2;
				}
			}
		};
		if (is_null && is_null2) { return std::strong_ordering::equal; }
		if (std::distance(_data.cbegin(), i.base()) > std::distance(that._data.cbegin(), i2.base())) {
			if (_sign) return std::strong_ordering::less;
			else return std::strong_ordering::greater;
		}
		if (std::distance(_data.cbegin(), i.base()) < std::distance(that._data.cbegin(), i2.base())) {
			if (_sign) return std::strong_ordering::greater;
			else return std::strong_ordering::less;
		}

		for (; i != _data.crend(); ++i, ++i2) {
			if (*i > *i2) {
				if (_sign) return std::strong_ordering::less;
				else return std::strong_ordering::greater;
			}
			if (*i < *i2) {
				if (_sign) return std::strong_ordering::greater;
				else return std::strong_ordering::less;
			}
		}
		return std::strong_ordering::equal;
	}

	std::string BigNum::to_str(uint32_t base) const {

		if (base < 2) {
			std::string excp_str = "Wrong base in method to_str. Current base is " + std::to_string(base) + ".Should be 2 or more.\n ";
			throw WrongBase(excp_str.c_str());
		};

		std::string res = "";
		res += (_sign ? "-" : "");

		//find not 0 beginning from 'significant' side of num 
		auto i = _data.crbegin();
		bool is_null_beginning_ended = false;
		bool is_null = false;
		while ((!is_null_beginning_ended)) {
			if ((i == _data.crend())) { is_null = true; break; }
			else {
				if (*i != 0) {
					is_null_beginning_ended = true;
					break;
				}
				else {
					++i;
				}
			}
		};
		if (is_null) { res = "0"; }
		else {
			switch (base) {
#if __cpp_lib_format
			case 2: {
				for (; i != _data.crend(); ++i) {
					res += std::format("{:b}", *i);
				}
			}
				  break;
			case 8: {
				size_t quantity_not_putted_in_res_bits_in_loop = (2 * std::distance(i, _data.crend())) % 32;
				uint32_t some_temporary_bits = (*i) >> (32 - quantity_not_putted_in_res_bits_in_loop);
				if (some_temporary_bits != 0)
					res += std::format("{:o}", (*i) >> (32 - quantity_not_putted_in_res_bits_in_loop));
				for (size_t index = (32 * std::distance(i, _data.crend())) - quantity_not_putted_in_res_bits_in_loop; index != 0; index -= 30) {
					res += std::format("{:o}", 0x3fffffff & this->GetSlice(index - 30));
				}
				//res += std::format("{:o}", some_temporary_bits);
			}
				  break;
			case 16: {
				for (; i != _data.crend(); ++i) {
					res += std::format("{:x}", *i);
				}
			}
				   break;
#endif
			default:
				// actually it should be another class but i'm lazy to do a lot of useless things
				std::vector<unsigned char> binary_coded_by_base_num(std::distance(i, _data.crend()) * 32, 0);
				auto most_significant_digit_index = binary_coded_by_base_num.begin();
				for (; i != _data.crend(); ++i)
				{
					uint32_t big_binary_digit = *i;
					for (int u = 31; u >= 0; --u)
					{
						// *2
						auto k = binary_coded_by_base_num.begin();
						for (; (k != binary_coded_by_base_num.end()) && !(k == std::next(most_significant_digit_index)); ++k) {
							*k *= 2;
						}

						// normalization
						auto kk = binary_coded_by_base_num.begin();
						for (; (kk != binary_coded_by_base_num.end()) && !(kk == std::next(most_significant_digit_index)); ++kk) {
							if ((*kk) > (base - 1)) {
								++(*std::next(kk));
								*kk %= base;
							}
						}
						if (*kk != 0) ++most_significant_digit_index;

						//get value 1 or 0 from _data
						unsigned char bit_from_big_binary_digit = ((big_binary_digit & (1 << u)) >> u);

						// + 1 and normalize or nothing
						if (bit_from_big_binary_digit != 0) {
							++(*binary_coded_by_base_num.begin());
							auto kkk = binary_coded_by_base_num.begin();
							for (; (kkk != binary_coded_by_base_num.end()) && !(kkk == std::next(most_significant_digit_index)); ++kkk) {
								if ((*kkk) > (base - 1)) {
									++(*std::next(kkk));
									*kkk %= base;
								}
							}
							if (*kkk != 0) ++most_significant_digit_index;
						}

					}
				}
				//find not 0 beginning from 'significant' side of num but for bcd num
				auto u = binary_coded_by_base_num.crbegin();
				bool is_null_beginning_ended_bcd = false;
				bool is_null_bcd = false;
				while ((!is_null_beginning_ended_bcd)) {
					if ((u == binary_coded_by_base_num.crend())) { is_null_bcd = true; break; }
					else {
						if (*u != 0) {
							is_null_beginning_ended_bcd = true;
							break;
						}
						else {
							++u;
						}
					}
				};
				if (is_null_bcd) { res += '0'; }
				else {
					for (; u != binary_coded_by_base_num.crend(); ++u) {
						res += (*u) + '0';
					}
				}
				break;
			}
		}
		return res; // RVO ?
	}

	std::strong_ordering BigNum::CompareByAbs(BigNum const& that) const {
		auto i = _data.crbegin();
		bool is_null_beginning_ended = false;
		bool is_null = false;
		while ((!is_null_beginning_ended)) {
			if ((i == _data.crend())) { is_null = true; break; }
			else {
				if (*i != 0) {
					is_null_beginning_ended = true;
					break;
				}
				else {
					++i;
				}
			}
		};
		auto i2 = that._data.crbegin();
		bool is_null_beginning_ended2 = false;
		bool is_null2 = false;
		while ((!is_null_beginning_ended2)) {
			if ((i2 == that._data.crend())) { is_null2 = true; break; }
			else {
				if (*i2 != 0) {
					is_null_beginning_ended2 = true;
					break;
				}
				else {
					++i2;
				}
			}
		};
		if (is_null && is_null2) { return std::strong_ordering::equal; }
		if (std::distance(_data.cbegin(), i.base()) > std::distance(that._data.cbegin(), i2.base())) {
			if (_sign) return std::strong_ordering::less;
			else return std::strong_ordering::greater;
		}
		if (std::distance(_data.cbegin(), i.base()) < std::distance(that._data.cbegin(), i2.base())) {
			if (_sign) return std::strong_ordering::greater;
			else return std::strong_ordering::less;
		}

		for (; i != _data.crend(); ++i, ++i2) {
			if (*i > *i2) {
				if (_sign) return std::strong_ordering::less;
				else return std::strong_ordering::greater;
			}
			if (*i < *i2) {
				if (_sign) return std::strong_ordering::greater;
				else return std::strong_ordering::less;
			}
		}
		return std::strong_ordering::equal;
	}

}