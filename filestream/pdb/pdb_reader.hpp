#ifndef QAHWA_PDB_READER_HPP
#define QAHWA_PDB_READER_HPP
#include<Qahwa/filestream/pdb/pdb_parser.hpp>
#include<Qahwa/filestream/pdb/pdb_data_type/pdb_atom_line.hpp>
#include<vector>
#include<array>


namespace Qahwa {


class PDBReader : public PDBParser {

public:

	PDBReader() : PDBParser() {}
	PDBReader(const std::string& input_filename) : PDBParser(input_filename) {}

	~PDBReader() = default;

	std::vector<PDB_AtomLine> const read();


};



std::vector<PDB_AtomLine> PDBReader::read() const {

	open();
	std::string buffer;

	std::vector<PDB_AtomLine> retval;

	while (std::getline(input_file, buffer)) {

		if (buffer.empty()) continue;

		const std::string& record_name = read_RecordName(buffer);

		if (record_name != "ATOM  ") continue;

		const PDB_AtomLine& atom_line = PDB_AtomLine(
			read_SerialNum(buffer),
			read_AtomName(buffer),
			read_AltLoc(buffer),
			read_ResidueName(buffer),
			read_ChainID(buffer),
			read_ResiSeqNum(buffer),
			read_InsertCode(buffer),
			read_Coordinate(buffer),
			read_Occupancy(buffer),
			read_TemperatureFactor(buffer),
			read_Element(buffer),
			read_Charge(buffer)
		);

		retval.push_back(atom_line);
	}

	return retval;
}


}




#endif /* QAHWA_PDB_READER_HPP */
