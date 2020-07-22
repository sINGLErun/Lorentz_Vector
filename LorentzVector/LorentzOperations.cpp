#include "LorentzVector.hpp"

void LorentzVector::operator += (const LorentzVector &other) {
	m_ct += other.m_ct;
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
}
void LorentzVector::operator -= (const LorentzVector &other) {
	m_ct -= other.m_ct;
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
}
void LorentzVector::operator *= (double a) {
	m_ct *= a;
	m_x *= a;
	m_y *= a;
	m_z *= a;
}

LorentzVector& LorentzVector::operator = (const LorentzVector &other) {
	m_ct = other.m_ct;
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	return *this;
}

LorentzVector LorentzVector::operator * (double a) {
	LorentzVector v_temp;
	v_temp.m_ct = a*m_ct;
	v_temp.m_x = a*m_x;
	v_temp.m_y = a*m_y;
	v_temp.m_z = a*m_z;
	return v_temp;
}

double LorentzVector::operator * (const LorentzVector &other) {
	return 	  m_ct * other.m_ct
				- m_x * other.m_x
				- m_y * other.m_y 
				- m_z * other.m_z;
}

LorentzVector LorentzVector::operator + (const LorentzVector &other) const {
	LorentzVector v_temp;
	v_temp.m_ct = m_ct + other.m_ct;
	v_temp.m_x = m_x + other.m_x;
	v_temp.m_y = m_y + other.m_y;
	v_temp.m_z = m_z + other.m_z;
	return	v_temp;
}

LorentzVector LorentzVector::operator - (const LorentzVector &other) const {
	LorentzVector v_temp;
	v_temp.m_ct = m_ct - other.m_ct;
	v_temp.m_x = m_x - other.m_x;
	v_temp.m_y = m_y - other.m_y;
	v_temp.m_z = m_z - other.m_z;
	return	v_temp;
}

bool LorentzVector::operator == (const LorentzVector &other) {
	return (   m_ct == other.m_ct
			&& m_x == other.m_x
			&& m_y == other.m_y
			&& m_z == other.m_z );
}

bool LorentzVector::operator != (const LorentzVector &other) {
	return !(   m_ct == other.m_ct
			&& m_x == other.m_x
			&& m_y == other.m_y
			&& m_z == other.m_z );
}

std::ostream& operator<<(std::ostream &os, const LorentzVector &v) {
	os << "\t(" << v.m_ct << ", "
				<< v.m_x << ", "
				<< v.m_y << ", "
				<< v.m_z << ")\n";
	return os;
}