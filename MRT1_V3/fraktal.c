/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int get_itera(struct complex_t c,struct complex_t z, struct param_t* parameter){
	int Iterationszahl=0;
	struct complex_t ztemp;
	ztemp.x=z.x;
	while((z.x*z.x+z.y*z.y)<(parameter->radiusG * parameter->radiusG) &&Iterationszahl <= parameter->imax){
		Iterationszahl +=1;
		ztemp.x = c.x+z.x*z.x-z.y*z.y;
		z.y = c.y+2*z.x*z.y;
		z.x=ztemp.x;
	};
	return Iterationszahl;
};

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax){
	color_name_t Color;
	if(i>imax) return Color=Black;
	return Color=i%32;
};

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter){
	double xstep=(double)(parameter->xmax-parameter->xmin)/(double)(parameter->xpoints);
	double ystep=(double)(parameter->ymax-parameter->ymin)/(double)(parameter->ypoints);
	color_name_t Color;
	int Iteration;
	grafik_lock_for_painting();
	for(double y=parameter->ymin; y<parameter->ymax; y+= ystep){
		for(double x=parameter->xmin; x<parameter->xmax; x+= xstep){
			if(parameter->fraktal==Mandelbrot){
				c.x=x;																// change default c to current pixel
				c.y=y;
				Iteration = get_itera(c,z, parameter);											//Call get_itera with c as the variable number				//
			}
			if(parameter->fraktal==Juliamenge){
				z.x=x;																// change default z to current pixel
				z.y=y;
				Iteration = get_itera(c,z, parameter);											//Call get_itera with z as the variable number
			}

			Color = get_color_value(Iteration, parameter->imax);
//			grafik_lock_for_painting();
			grafik_paint_point(x, y, Color);
//			grafik_unlock_and_show();
		};
	};
	grafik_unlock_and_show();
};

/* EOF FRAKTAL_C */
