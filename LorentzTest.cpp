#include "LorentzVector.hpp"

int main(int argc, char const *argv[])
{
	LorentzVector v1 = {1, 2, 3, 4};
	LorentzVector v2 = {-1, -2, -3, -4};

	std::cout << "\n";
	std::cout << "\tv1:\t"; v1.getVector();
	std::cout << "\tv1 (comp):\t" << "(" << v1.t() << ", "
									   << v1.x() << ", "
									   << v1.y() << ", "
									   << v1.z() << ")\n"; 
	std::cout << "\tv2:\t"; v2.getVector();
   	std::cout << "\t||v1||:\t\t" << v1.norm(); // ||{1, 2e8, 2e8, 1e8}|| = 0
   	std::cout << "\n\tv1 + v2:"; v1.add(v2).getVector();
   	std::cout << "\tv1 - v2:"; v1.sub(v2).getVector();
   	std::cout << "\t(v1, v2):\t" << v1.dot(v2) << "\n";
   	std::cout << "\tv1-transformed (beta = " << 0.0001 << ")";
   	v1.ztransform(0.0001);
   	v1.getVector(); 

	return 0;
}