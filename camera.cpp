#include "camera.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"
#include "rayon.hpp"
#include <stdio.h>

void Camera::Haut(const Vecteur3D & h) {

	haut = h - (dir * (dir * h));
	if (!haut.Nul())
		haut.Normaliser();
}

void Camera::Calculer_image(Pixelmap & pm, Liste<Objet3D> & lo, Liste<Lumiere> & ll, int complexite) const {

	Point3D foyer;
	Vecteur3D droite;
	float dx, dy;
	int x, y;
	Point3D hg;
	Point3D pt;
	Rayon ray;
	Vecteur3D vect;
	int index;
	foyer = centre - (dir * dist);
	droite = dir.Cross(haut);
	dx = largeur / pm.Largeur();
    dy = hauteur / pm.Hauteur();
	hg = centre + (droite * ((dx / 2) - (largeur / 2))) + (haut * ((hauteur / 2) - (dy / 2)));
	index = 0;
	for (y = 0; y<pm.Hauteur();y++)
	{
		for (x = 0;x < pm.Largeur();x++)
		{
            pt = hg + (droite * (dx * x)) - (haut * (dy * y));
                ray.Orig(pt);
                vect = pt - foyer;
                vect.Normaliser();
                ray.Vect(vect);
                ray.Milieu(1);
                pm.Map(index++, ray.Lancer(lo, ll, complexite));
		}
	}
}
