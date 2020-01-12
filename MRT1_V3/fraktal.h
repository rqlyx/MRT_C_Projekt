/* BOF FRAKTAL_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#ifndef FRAKTAL_H
#define FRAKTAL_H

/*--- Datentypvereinbarungen -----------------------------------------------*/
typedef enum{
	Mandelbrot,
	Juliamenge
}fraktal_t;
struct param_t{
	int radiusG;
	int imax;
	fraktal_t fraktal;
	int xmin, xmax, ymin, ymax;
	int xpoints, ypoints;
};
struct complex_t{
	double x;
	double y;
};
/*--- Fraktal analysieren und grafisch darstellen --------------------------*/

int get_itera(struct complex_t c,struct complex_t z);
#endif /* FRAKTAL_H */
/* EOF FRAKTAL_H */
