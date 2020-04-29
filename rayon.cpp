#include "rayon.hpp"
#include "objet3D.hpp"
#include "lumiere.h"


int Rayon::Intersections(C_Liste_Intersection & li, Liste<Objet3D> & lo) const {
	// Il n'y a pas d'intersection au depart
	li.Vider();

	// Pour chaque objet 3D
	for (lo.Premier(); lo.Courant() != 0; lo.Suivant())
		lo.Courant()->Intersection(*this, li);

	return !(lo.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
	RVB res;
	C_Liste_Intersection li;
	Intersection3D imp;
	Point3D pos;
	Rayon ray;
	res = RVB(0,0,0);
	

	if(Intersections(li, lo))
	{
		if (li.Premier() != nullptr)
		{
			imp = *li.Premier();
			pos = orig + vect * imp.Dist();
			li.Vider();
			if (imp.Objt()->Kr() > 0)
			{
				ray.Orig(pos);
				ray.Vect(this->Vect());
				ray.Vect().Normaliser();
				ray.Vect(ray.Vect().Reflechir(imp.Norm()));
				res = res + ray.Lancer(lo, ll, recur--) * imp.Objt()->Kr();
			}
				for (ll.Premier();ll.Courant();ll.Suivant())
				{
					res = res + ll.Courant()->Illumination(ray, imp, pos, lo);
				}

				
		}
	}
	return res;
}

