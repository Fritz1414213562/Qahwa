#ifndef QAHWA_PDB_WRITER_HPP
#define QAHWA_PDB_WRITER_HPP
#include<Qahwa/filestream/base/Writer.hpp>
#include<string>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<array>


namespace Qahwa {

class PDBWriter : public FileWriter {


public:
	
	PDBWriter() = default;
	~PDBWriter() = default;

};

}


#endif /* QAHWA_PDB_WRITER_HPP */
