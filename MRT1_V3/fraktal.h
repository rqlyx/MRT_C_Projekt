/* BOF FRAKTAL_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#ifndef FRAKTAL_H
#define FRAKTAL_H
#include "graphic.h"
/*--- Datentypvereinbarungen -----------------------------------------------*/
typedef enum{			// defines an enum containing the two types of fractals that can be calculated. Defines type
	Mandelbrot,
	Juliamenge
}fraktal_t;
struct param_t{			// a structure that contains all different parameters needed to define the fraktal beeing calculated
	int radiusG;
	int imax;
	fraktal_t fraktal;
	int xmin, xmax, ymin, ymax;
	int xpoints, ypoints;
};
struct complex_t{		// a structure defining complex numbers
	double x;
	double y;
};
/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

int get_itera(struct complex_t c,struct complex_t z, struct param_t* parameter);
color_name_t get_color_value(int i, int imax);
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter);
#endif /* FRAKTAL_H */
/* EOF FRAKTAL_H */
