#ifndef QAHWA_PSF_BOND_PAIR_HPP
#define QAHWA_PSF_BOND_PAIR_HPP


namespace Qahwa {

struct PSF_BondPair {

public:

	PSF_BondPair(const int& input_lhs, const int& input_rhs) :
	pair_lhs(input_lhs),
	pair_rhs(input_rhs) {}

	~PSF_BondPair() = default;

	int lhs() const {return pair_lhs;}
	int& lhs() {return pair_lhs;}
	int rhs() const {return pair_rhs;}
	int& rhs() {return pair_rhs;}

//	PSF_BondPair operator=(const PSF_BondPair& input_bond_pair) const {
//		return PSF_BondPair(input_bond_pair.lhs(), input_bond_pair.rhs());
//	}

private:
	int pair_lhs;
	int pair_rhs;

};

}


#endif /* QAHWA_PSF_BOND_PAIR_HPP */
