#ifndef QAHWA_NINFO_CONTACT__LINE_HPP
#define QAHWA_NINFO_CONTACT_LINE_HPP
#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<tuple>
#include<type_traits>


namespace Qahwa {

struct Ninfo_ContactLine {

public:

	template<typename... Args>
	Ninfo_ContactLine(const Args&... arguments) {
		static_assert(std::is_same<std::tuple<Args...>, std::tuple<
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		float,
		float,
		std::size_t,
		float,
		std::string>>::value, "usage: Ninfo_ContactLine, 7 x unsigned long long, 2 x float, unsigned long long, float, string");

		const std::tuple<Args...> args_tuple(arguments...);
		serial_number = std::get<0>(args_tuple);
		lhs_unit = std::get<1>(args_tuple);
		rhs_unit = std::get<2>(args_tuple);
		lhs_mass_point = std::get<3>(args_tuple);
		rhs_mass_point = std::get<4>(args_tuple);
		lhs_local_mp = std::get<5>(args_tuple);
		rhs_local_mp = std::get<6>(args_tuple);
		native_length = std::get<7>(args_tuple);
		factor_go = std::get<8>(args_tuple);
		dummy_number = std::get<9>(args_tuple);
		coefficient = std::get<10>(args_tuple);
		contact_type = std::get<11>(args_tuple);
	}

	~Ninfo_ContactLine() = default;

	std::string kind() const {return line_kind;}

	std::size_t serial_id() const {return serial_number;}
	std::size_t& serial_id() {return serial_number;}

	std::size_t unit_num1() const {return lhs_unit;}
	std::size_t& unit_num1() {return lhs_unit;}

	std::size_t unit_num2() const {return rhs_unit;}
	std::size_t& unit_num2() {return rhs_unit;}

	std::size_t global_mp1() const {return lhs_mass_point;}
	std::size_t& global_mp1() {return lhs_mass_point;}

	std::size_t global_mp2() const {return rhs_mass_point;}
	std::size_t& global_mp2() {return rhs_mass_point;}

	std::size_t local_mp1() const {return lhs_local_mp;}
	std::size_t& local_mp1() {return lhs_local_mp;}

	std::size_t local_mp2() const {return rhs_local_mp;}
	std::size_t& local_mp2() {return rhs_local_mp;}

	float native_contact_length() const {return native_length;}
	float& native_contact_length() {return native_length;}

	float factor() const {return factor_go;}
	float& factor() {return factor_go;}

	std::size_t dummy() const {return dummy_number;}
	std::size_t& dummy() {return dummy_number;}

	float coef() const {return coefficient;}
	float& coef() {return coefficient;}

	std::string type() const {return contact_type;}
	std::string& type() {return contact_type;}



private:

	const std::string& line_kind = "contact";
	std::size_t serial_number;
	std::size_t lhs_unit;
	std::size_t rhs_unit;
	std::size_t lhs_mass_point;
	std::size_t rhs_mass_point;
	std::size_t lhs_local_mp;
	std::size_t rhs_local_mp;
	float native_length;
	float factor_go;
	std::size_t dummy_number;
	float coefficient;
	std::string contact_type;

};


}


#endif /* QAHWA_NINFO_CONTACT_LINE_HPP */
