#ifndef QAHWA_NINFO_ANGL_LINE_HPP
#define QAHWA_NINFO_ANGL_LINE_HPP
#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<tuple>
#include<type_traits>


namespace Qahwa {

struct Ninfo_AnglLine {

public:

	template<typename... Args>
	Ninfo_AnglLine(const Args&... arguments) {
		static_assert(std::is_same<std::tuple<Args...>, std::tuple<
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		std::size_t,
		float,
		float,
		float,
		float,
		std::string>>::value, "usage: Ninfo_AnglLine, 9 x unsigned long long, 4 x float, string");

		const std::tuple<Args...> args_tuple(arguments...);
		serial_number = std::get<0>(args_tuple);
		lhs_unit = std::get<1>(args_tuple);
		rhs_unit = std::get<2>(args_tuple);
		lhs_mass_point = std::get<3>(args_tuple);
		mid_mass_point = std::get<4>(args_tuple);
		rhs_mass_point = std::get<5>(args_tuple);
		lhs_local_mp = std::get<6>(args_tuple);
		mid_local_mp = std::get<7>(args_tuple);
		rhs_local_mp = std::get<8>(args_tuple);
		native_angl_size = std::get<9>(args_tuple);
		factor_go = std::get<10>(args_tuple);
		correct_mgo = std::get<11>(args_tuple);
		coefficient = std::get<12>(args_tuple);
		angl_type = std::get<13>(args_tuple);
	}

	~Ninfo_AnglLine = default;

	std::string kind() const {return line_kind;}

	std::size_t serial_id() const {return serial_number;}
	std::size_t& serial_id() {return serial_number;}

	std::size_t unit_num1() const {return lhs_unit;}
	std::size_t& unit_num1() {return lhs_unit;}

	std::size_t unit_num2() const {return rhs_unit;}
	std::size_t& unit_num2() {return rhs_unit;}

	std::size_t global_mp1() const {return lhs_mass_point;}
	std::size_t& global_mp1() {return lhs_mass_point;}

	std::size_t global_mp2() const {return mid_mass_point;}
	std::size_t& global_mp2() {return mid_mass_point;}

	std::size_t global_mp3() const {return rhs_mass_point;}
	std::size_t& global_mp3() {return rhs_mass_point;}

	std::size_t local_mp1() const {return lhs_local_mp;}
	std::size_t& local_mp1() {return lhs_local_mp;}

	std::size_t local_mp2() const {return mid_local_mp;}
	std::size_t& local_mp2() {return mid_local_mp;}

	std::size_t local_mp3() const {return rhs_local_mp;}
	std::size_t& local_mp3() {return rhs_local_mp;}

	float native_angl() const {return native_angl_size;}
	float& native_angl() {return native_angl_size;}

	float factor() const {return factor_go;}
	float& factor() {return factor_go;}

	float mgo() const {return correct_mgo;}
	float& mgo() {return correct_mgo;}

	float coef() const {return coefficient;}
	float& coef() {return coefficient;}

	std::string type() const {return angl_type;}
	std::string& type() {return angl_type;}



private:

	const std::string& line_kind = "angl";
	std::size_t serial_number;
	std::size_t lhs_unit;
	std::size_t rhs_unit;
	std::size_t lhs_mass_point;
	std::size_t mid_mass_point;
	std::size_t rhs_mass_point;
	std::size_t lhs_local_mp;
	std::size_t mid_local_mp;
	std::size_t rhs_local_mp;
	float native_angl_size;
	float factor_go;
	float correct_mgo;
	float coefficient;
	std::string angl_type;

};


}


#endif /* QAHWA_NINFO_ANGL_LINE_HPP */
