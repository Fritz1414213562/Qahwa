#ifndef QAHWA_PSF_CHAIN_RANGE_HPP
#define QAHWA_PSF_CHAIN_RANGE_HPP
#include<array>
#include<initializer_list>


namespace Qahwa {


struct PSF_ChainRange {

public:
	PSF_ChainRange() = default;
	PSF_ChainRange(const int& lhs, const int& rhs) : chain_range{lhs, rhs} {}
	~PSF_ChainRange() = default;

	int begin_index() const {return chain_range[0];}
	int& begin_index() {return chain_range[0];}
	int end_index() const {return chain_range[1];}
	int& end_index() {return chain_range[1];}

	std::size_t size() const {return chain_range[1] - chain_range[0] + 1;}

private:
	std::array<int, 2> chain_range;

};


}


#endif /* QAHWA_PSF_CHAIN_RANGE_HPP */
