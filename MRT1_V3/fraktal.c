/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"

struct param_t Parameter;
/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int get_itera(struct complex_t c,struct complex_t z){
	int Iterationszahl=0;
	while((sqrt(z.x)+sqrt(z.y))<sqrt(Parameter.radiusG)){
		Iterationszahl +=1;
		z.x += c.x;
		z.y += c.y;
	};
	return Iterationszahl;
};

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax){
	color_name_t Color;
	if(i>imax) return Color=Black;
	return Color=i;
};

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter){
	double xstep=(parameter->xmax-parameter->xmin)/(parameter->xpoints);
	double ystep=(parameter->ymax-parameter->ymin)/(parameter->ypoints);
	double x=(parameter->xmin);
	double y=parameter->ymin;
	color_name_t Color;
	int Iteration;
	grafik_lock_for_painting();
	do{
		do{
			if(parameter->fraktal==Mandelbrot){
				c.x=x;
				c.y=y;
				Iteration = get_itera(c,z);
				Color = get_color_value(Iteration, parameter->imax);				//Call get_itera with c as the variable number
			}
			if(parameter->fraktal==Juliamenge){
				z.x=x;
				z.y=y;
				Iteration = get_itera(c,z);
				Color = get_color_value(Iteration, parameter->imax);				//Call get_itera with z as the variable number
			}
			grafik_paint_point(x, y, Color);
			x += xstep;
		}while(x<=parameter->ymax);

		y += ystep;
	}while(y<=parameter->ymax);
	grafik_unlock_and_show();
};

/* EOF FRAKTAL_C */
