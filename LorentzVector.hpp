#include <iostream>
#include <cmath>

class LorentzVector {
	double m_ct, m_x, m_y, m_z;
	const double m_c = 1;
public:
	// constructors
	LorentzVector();
	LorentzVector(double, double, double, double);
	~LorentzVector() = default;
	
	// setter & getter
	void setVector(double t, double x, double y, double z);
	void getVector() const;
	
	// component modification
	void t(double t);
	void x(double x);
	void y(double y);
	void z(double z);

	// component writing	
	double t() const;
	double x() const;
	double y() const;
	double z() const;

	
	// operations with LorenzVector
	double norm() const;
	LorentzVector mlt(double a) const;
	void ztransform(double beta);
	LorentzVector add(const LorentzVector &other) const;
	LorentzVector sub(const LorentzVector &other) const;
	double dot(const LorentzVector &other) const;
};