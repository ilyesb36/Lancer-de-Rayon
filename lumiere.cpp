#include <math.h>

#include "lumiere.h"
#include "couleurRVB.hpp"
#include "objet3D.hpp"


RVB Lumiere_Ambiante::Illumination(const Rayon &, const Intersection3D & i, const Point3D &, Liste<Objet3D> &) const {
	RVB res;

	res = i.Objt()->Ambiante() * couleur;

	return res;
}


RVB Lumiere_Ponctuelle::Illumination(const Rayon & r, const Intersection3D & i, const Point3D & p, Liste<Objet3D> & lo) const {

	Rayon ray;
	Intersection3D imp;
	Point3D pos;
	RVB res;
	C_Liste_Intersection li;

	ray.Orig(p);
	ray.Milieu(1);
	ray.Vect(Vecteur3D(ray.Orig(), this->Pos()));

	if (ray.Intersections(li, lo)) {
		if (li.Premier() != 0) {
			imp = *li.Premier();
			pos = ray.Orig() + (ray.Vect() * imp.Dist());
			if (this->Pos().X() > pos.X()) {
				res = RVB(0,0,0);
			}
			li.Vider();
		}
		else {
			float cosAngle = (ray.Vect() * i.Norm()) / (ray.Vect().Longueur() * i.Norm().Longueur());
			res = res + i.Objt()->Couleur() * couleur * cosAngle;
		}
	}

    return res;

}

