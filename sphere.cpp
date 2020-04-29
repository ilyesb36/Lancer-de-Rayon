#include <math.h>
#include "sphere.hpp"


Vecteur3D Sphere::Normale(const Point3D & t) const {
	Vecteur3D res(centre, t);
	res.Normaliser();
	return res;
}


int Sphere::Intersection(const Rayon & r, C_Liste_Intersection & l) {
	double a = 1;
	double b = (r.Orig() - this->Centre()) * 2.0 * r.Vect();
	double c = (r.Orig() - this->Centre()) * (r.Orig() - this->Centre()) - this->SphereRayon() * this->SphereRayon();
	double delta = b * b - 4 * a * c;
	double racine1;
	double racine2;
	Point3D vecteur1;
	Point3D vecteur2;
	Intersection3D i1;
	Intersection3D i2;
	if (delta < 0) {
		return 0;
	}
	else {
		if (delta == 0) {

			racine1 = (-b) / (2 * a);
			vecteur1 = r.Orig() + (r.Vect() * racine1);
			i1 = Intersection3D(racine1, this, 0);
			i1.Norm(Normale(vecteur1));
			l.Ajouter(i1);
			return 1;
		}
		else {
			racine1 = (-b + sqrt(delta)) / (2 * a);
			racine2 = (-b - sqrt(delta)) / (2 * a);
			vecteur1 = r.Orig() + (r.Vect() * racine1);
			vecteur2 = r.Orig() + (r.Vect() * racine2);
			i1 = Intersection3D(racine1, this, 0);
			i1.Norm(Normale(vecteur1));
			i2 = Intersection3D(racine2, this, 0);
			i2.Norm(Normale(vecteur2));
			l.Ajouter(i1);
			l.Ajouter(i2);
			return 1;
		}
	}
}
