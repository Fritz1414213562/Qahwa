// This class is a parser class for dcd binary file.
//-------------------------------------------------------------------------------
// include guard
#ifndef QAHWA_DCD_PARSER_HPP
#define QAHWA_DCD_PARSER_HPP

//-------------------------------------------------------------------------------
// includes

#include<Qahwa/filestream/base/Parser.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdint>
#include<cstring>
#include<array>

//-------------------------------------------------------------------------------
// namespace
namespace Qahwa {
//-------------------------------------------------------------------------------
// header


class DCDParser : public FileParser {

public :
	DCDParser() : FileParser() {}
	DCDParser(const std::string& input_file_name) : FileParser(input_file_name) {}
	~DCDParser() = default;


protected :

	std::size_t frame_num = 0;
	std::size_t atom_num = 0;

	std::vector<std::string> headers;
	

	std::array<std::vector<float>, 3> read_xyz() {
		const std::string& x_block = read_block();
		const std::string& y_block = read_block();
		const std::string& z_block = read_block();
		std::array<std::vector<float>, 3> xyz;
		xyz[0] = read_coordinates(x_block);
		xyz[1] = read_coordinates(y_block);
		xyz[2] = read_coordinates(z_block);

		return xyz;
	}


	void read_num_frame_and_atom() {

		open();
		const std::string& first_block = read_block();
		headers.push_back(first_block);
		read_frame_num(first_block);

		const std::string& second_block = read_block();
		headers.push_back(second_block);

		const std::string& third_block = read_block();
		headers.push_back(third_block);
		read_atom_num(third_block);
		std::cout << "frame number = " << frame_num << std::endl;
		std::cout << "atom number = " << atom_num << std::endl;

	}



private:


	template<typename T>
	T read_binary_as(const char *str) {
	    T result;
	    std::memcpy(std::addressof(result), str, sizeof(T));
	    return result;
	}
	
	const std::string read_block() {
		std::int32_t block_size;
		std::vector<char> buffer;
	
		constexpr int int32_size = sizeof(float);
		input_file.read(reinterpret_cast<char*>(&block_size), int32_size);
		buffer.resize(block_size);
		input_file.read(buffer.data(), block_size);
	
		std::int32_t check_block_size;
		input_file.read(reinterpret_cast<char*>(&check_block_size), int32_size);
	
		if (block_size != check_block_size) {
			std::cerr << "Error: Left Block size is not consistent with Right one" << std::endl;
			std::exit(1);
		}
	
		const std::string result(buffer.begin(), buffer.end());
	
		return result;
	}
	
	
	
	void read_frame_num(const std::string& first_block) {
		constexpr int frame_num_index = 4;
		frame_num = read_binary_as<int>(&first_block.at(frame_num_index));
	}


	void read_atom_num(const std::string& third_block) {
		constexpr int atom_num_index = 0;
		atom_num = read_binary_as<int>(&third_block.at(atom_num_index));
	}



	const std::vector<float> read_coordinates(const std::string& block) {
		std::vector<float> coordinates(atom_num);
		for (std::size_t i_atom = 0; i_atom < atom_num; ++i_atom) {
			constexpr int float_size = sizeof(float);
			std::size_t pos_of_atom = i_atom * float_size;
			coordinates[i_atom] = read_binary_as<float>(&block.at(pos_of_atom));
		}
		return coordinates;
	}


};

}

#endif /* QAHWA_DCD_PARSER_HPP */
