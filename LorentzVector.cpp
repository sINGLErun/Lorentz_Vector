#include "LorentzVector.hpp"

LorentzVector::LorentzVector
	() {
		LorentzVector::setVector(0, 0, 0, 0); }

LorentzVector::LorentzVector
	(double t, double x, double y, double z) {
		LorentzVector::setVector(t, x, y, z); }

void LorentzVector::setVector
	(double t, double x, double y, double z) {
		m_ct = m_c*t;
		m_x = x;
		m_y = y;
		m_z = z;
	}

void LorentzVector::getVector() const {
	std::cout << "\t(" << m_ct << ", "
					   << m_x << ", "
					   << m_y << ", "
					   << m_z << ")\n";
}

void LorentzVector::t(double t) { m_ct = m_c*t; }
void LorentzVector::x(double x) { m_x = x; }
void LorentzVector::y(double y) { m_y = y; }
void LorentzVector::z(double z) { m_z = z; }

double LorentzVector::t() const { return m_ct; }
double LorentzVector::x() const { return m_x; }
double LorentzVector::y() const { return m_y; }
double LorentzVector::z() const { return m_z; }

double LorentzVector::norm () const {
	double norm = sqrt(   pow(m_ct, 2)
			     		- pow(m_x, 2)
			     		- pow(m_y, 2)
			     		- pow(m_z, 2));
	if (norm >= 0) {
		return norm;
	} else {
		std::cout << "your vector have a complex norm! ";
		return 0;
	}
}

LorentzVector LorentzVector::mlt(double a) const {
	LorentzVector v_temp = {a*m_ct/m_c, a*m_x, a*m_y, a*m_z};
	return v_temp;
}

void LorentzVector::ztransform(double beta) {
	if (beta < 1) {
		double gamma = sqrt(1/(1 - beta*beta));

		//     Lorentz-transform according to this lambda-matrix:
		m_ct = gamma*(m_ct - beta*m_z);   	//  |  y  0  0  -yb |
		m_x = m_x;							//	|  0  1  0   0  |
		m_y = m_y;							//	|  0  0  1   0  |
		m_z = gamma*(-beta*m_ct + m_z); 	//	| -yb 0  0   y  | 
	} else {
		std::cout << "that's imposible, try another beta!\n";
	}

}

LorentzVector LorentzVector::add
	(const LorentzVector &other) const {
		LorentzVector v_temp = { (m_ct + other.m_ct)/(m_c),
								 m_x + other.m_x,
								 m_y + other.m_y,
								 m_z + other.m_z };
		return v_temp;
	}

LorentzVector LorentzVector::sub
	(const LorentzVector &other) const {
		LorentzVector v_temp = { (m_ct - other.m_ct)/(m_c),
								 m_x - other.m_x,
								 m_y - other.m_y,
								 m_z - other.m_z };
		return v_temp;	
	}

double LorentzVector::dot
	(const LorentzVector &other) const {
		return 	  m_ct * other.m_ct
				- m_x * other.m_x
				- m_y * other.m_y 
				- m_z * other.m_z;
	}
