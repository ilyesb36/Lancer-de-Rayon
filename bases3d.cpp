// ce Fichier entier en TODO ?

#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;
	res.X(this->X()+v.X());
	res.Y(this->Y()+v.Y());
	res.Z(this->Z()+v.Z());
	return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;
	res.X(this->X()-v.X());
	res.Y(this->Y()-v.Y());
	res.Z(this->Z()-v.Z());
	return res;
}

Vecteur3D Point3D::operator -(const Point3D & p) const {
	Vecteur3D v(p, *this);

	return v;
}


// --------------------------------------------------------------------------

float Vecteur3D::Longueur() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vecteur3D::Normaliser() {
	float longeur = this->Longueur();
	this->x = x / longeur;
	this->y = y / longeur;
	this->z = z / longeur;
}

Vecteur3D Vecteur3D::operator +(const Vecteur3D & v) const {
	Vecteur3D res;
	res.X(this->X()+v.X());
	res.Y(this->Y()+v.Y());
	res.Z(this->Z()+v.Z());
	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;
	res.X(this->X()-v.X());
	res.Y(this->Y()-v.Y());
	res.Z(this->Z()-v.Z());
	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;
	res.X(this->X()*-1);
	res.Y(this->Y()*-1);
	res.Z(this->Z()*-1);
	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;
	res.X(this->X()*m);
	res.Y(this->Y()*m);
	res.Z(this->Z()*m);
	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;
	res.X(this->Y()*v.Z()-this->Z()*v.Y());
	res.Y(this->Z()*v.X()-this->X()*v.Z());
	res.Z(this->X()*v.Y()-this->Y()*v.X());
	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}


Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const { 
	Vecteur3D res;

	float cos1 = norm * (-*this);;
	float m = m1 / m2;
	float cos2 = sqrt(1 - m * m * (1 - cos1 * cos1));
	if (cos1 > 0)
		res = Vecteur3D(*this * m + norm * (m * cos1 - cos2));
	else
		res = Vecteur3D(*this * m + norm * (m * cos1 + cos2));


	return res;
}

