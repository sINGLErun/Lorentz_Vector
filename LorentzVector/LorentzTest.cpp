#include "LorentzVector.hpp"

int main(int argc, char const *argv[])
{
	LorentzVector v1 = {1, 2, 3, 4};
	LorentzVector v2 = {-1, -2, -3, -4};
	LorentzVector v3 = {4, 3, 2, 1};

	std::cout << "\n";
	std::cout << v1;
	std::cout << v2;
	std::cout << v3;
	std::cout << (v1 + v2 + v3);

	return 0;
}