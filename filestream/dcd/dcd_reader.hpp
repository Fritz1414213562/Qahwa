// This class can read the coordinates in a snapshot.
#ifndef QAHWA_DCD_READER_HPP
#define QAHWA_DCD_READER_HPP

#include<Qahwa/filestream/dcd/dcd_parser.hpp>
#include<Qahwa/filestream/dcd/snapshot.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<array>

namespace Qahwa {

class DCDReader : public DCDParser {

public :
	DCDReader(const std::string& input_file_name) : DCDParser(input_file_name) {}
	DCDReader() : DCDParser() {}
	~DCDReader() = default;

	Snapshot<float, 3> read_SnapShot_at(const std::size_t& frame_in_snapshot) {

		read_num_frame_and_atom();
		Snapshot<float, 3> result(atom_num);

		if (frame_in_snapshot > frame_num) {
			std::cerr << "The frame " << frame_in_snapshot << " is out of range." << std::endl;
			std::exit(1);
		}

		for (std::size_t iframe = 0; iframe < frame_in_snapshot; ++iframe) {
			result = Snapshot<float, 3>(read_xyz());
		}

		close();

		return result;
	}


	std::vector<Snapshot<float, 3>> read_Trajectory() {

		read_num_frame_and_atom();
		std::vector<Snapshot<float, 3>> result(frame_num, Snapshot<float, 3>(atom_num));

		for (std::size_t iframe = 0; iframe < frame_num; ++iframe) {
			result[iframe] = Snapshot<float, 3>(read_xyz());
		}

		close();

		return result;
	}

};

}

#endif /* QAHWA_DCD_READER_HPP */
