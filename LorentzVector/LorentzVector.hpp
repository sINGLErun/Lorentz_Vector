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

	
	double norm() const;
	void ztransform(double beta);
	double dot(const LorentzVector &other) const;


	void operator += (const LorentzVector &other);
	void operator -= (const LorentzVector &other);
	void operator *= (double a);
	LorentzVector& operator = (const LorentzVector &other);
	LorentzVector operator * (double a);
	LorentzVector operator + (const LorentzVector &other) const;
	LorentzVector operator - (const LorentzVector &other) const;
	double operator * (const LorentzVector &other);
	bool operator == (const LorentzVector &other);
	bool operator != (const LorentzVector &other);
	friend std::ostream& operator << (std::ostream&, const LorentzVector &other); 
	
};

std::ostream& operator << (std::ostream&, const LorentzVector&);