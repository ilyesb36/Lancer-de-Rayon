#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <stdlib.h>
#include "const.hpp"
#include "bases3d.hpp"
#include "couleurRVB.hpp"

struct S_RVB {
	byte r;
	byte v;
	byte b;
};

//////////////////////////////////////////////////////////////////// C_BITMAP

class Image {
protected:

	int largeur; // Largeur de l'image
	int hauteur; // Hauteur de l'image
	S_RVB * map; // Ensemble des couleurs contenues dans l'image

public:

	// Constructeur
	Image(int l = 320, int h = 200) {
		largeur = l;
		hauteur = h;
		map = (S_RVB *) malloc(sizeof(S_RVB) * largeur * hauteur);
	}
	~Image() {
		free(map);
	}

	int Largeur() const {
		return largeur;
	}
	int Hauteur() const {
		return hauteur;
	}
	S_RVB Map(int i) const {
		return map[i];
	} // ATTENTION!!! : 0 <= i < largeur*hauteur
	S_RVB Map(int x, int y) const {
		return map[(y * largeur) + x];
	} // ATTENTION!!! : (0,0) <= (x,y) < (largeur,hauteur)

	void Map(int i, const S_RVB & c) {
		map[i] = c;
	} // ATTENTION!!! : 0 <= i < largeur*hauteur
	void Map(int x, int y, const S_RVB & c) {
		map[(y * largeur) + x] = c;
	} // ATTENTION!!! : (0,0) <= (x,y) < (largeur,hauteur)
	void Map(int, const RVB &); // ATTENTION!!! : 0 <= i < largeur*hauteur
	void Map(int, int, const RVB &); // ATTENTION!!! : (0,0) <= (x,y) < (largeur,hauteur)

	// Methodes
	void Enregistrer(char *) const;
	void Redimensionner(int l, int h) {
		free(map);
		largeur = l;
		hauteur = h;
		map = (S_RVB *) malloc(sizeof(S_RVB) * largeur * hauteur);
	}
};

#endif
