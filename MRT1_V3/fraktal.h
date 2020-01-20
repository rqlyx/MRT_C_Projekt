/* BOF FRAKTAL_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#ifndef FRAKTAL_H
#define FRAKTAL_H
#include "graphic.h"
/*--- Datentypvereinbarungen -----------------------------------------------*/
typedef enum{
	Mandelbrot,
	Juliamenge
}fraktal_t;
struct complex_t{
	double x;
	double y;
};
struct param_t{
	int radiusG;
	int imax;
	fraktal_t fraktal;
	double xmin, xmax, ymin, ymax;
	int xpoints, ypoints;
	struct complex_t center;
	double view;
	double zoom;
};

/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

int get_itera(struct complex_t c,struct complex_t z, struct param_t* parameter);
void iterstep(int *i, struct complex_t zi, struct complex_t* ziplus1, struct complex_t c);
color_name_t get_color_value(int i, int imax);
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter);
void create_Grafik(struct complex_t c,struct complex_t z, struct param_t* parameter, color_name_t Grafik[parameter->xpoints][parameter->ypoints][3]);
/*---------In die Fraktal-Figur Zoomen ----------------------------------------*/
void fraktal_zoom(struct complex_t* c,struct complex_t* z, struct param_t* parameter, struct complex_t dz, double zoom);

#endif /* FRAKTAL_H */
/* EOF FRAKTAL_H */
