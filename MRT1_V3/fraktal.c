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
	while((z.x*z.x+z.y*z.y)<(parameter->radiusG * parameter->radiusG) &&Iterationszahl <= parameter->imax){ //tests whether z has left the Area or the Itterations have reached theire maximum Value
		Iterationszahl +=1;			
		ztemp.x = c.x+z.x*z.x-z.y*z.y;		// z(i+1)= c+zi²
		z.y = c.y+2*z.x*z.y;
		z.x=ztemp.x;
	};
	return Iterationszahl;
};

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax){
	color_name_t Color;				
	if(i>imax) return Color=Black;		// if the pixel has been iterated for imax times without leaving the Area color is defined as Black
	return Color=i%32;			//sets the Color to one of 32 possible Values that cycle through
};

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter){
	double xstep=(double)(parameter->xmax-parameter->xmin)/(double)(parameter->xpoints);		//devides the axes into as xpoints many steps
	double ystep=(double)(parameter->ymax-parameter->ymin)/(double)(parameter->ypoints);
	color_name_t Color;
	int Iteration;
	grafik_lock_for_painting();
	for(double y=parameter->ymin; y<parameter->ymax; y+= ystep){				// two for loops go through the two dimensional grid of xpoints X ypoints
		for(double x=parameter->xmin; x<parameter->xmax; x+= xstep){
			if(parameter->fraktal==Mandelbrot){				// at each point the fraktal type defines which Variable (c or z) is dependent on the picturepoint coordinates and sets it accordingly
				c.x=x;																// change default c to current pixel
				c.y=y;
				Iteration = get_itera(c,z, parameter);		//having the Variable set the loop calls for the iterationnumber to be calculated									//Call get_itera with c as the variable number				//
			}
			if(parameter->fraktal==Juliamenge){
				z.x=x;																// change default z to current pixel
				z.y=y;
				Iteration = get_itera(c,z, parameter);											//Call get_itera with z as the variable number
			}

			Color = get_color_value(Iteration, parameter->imax);		// Calculates the colorvalue depending of numbers of iterations
//			grafik_lock_for_painting();
			grafik_paint_point(x, y, Color);			// the Point at coordinates X,Y is painted with the Color
//			grafik_unlock_and_show();
		};
	};
	grafik_unlock_and_show();
};

/* EOF FRAKTAL_C */
