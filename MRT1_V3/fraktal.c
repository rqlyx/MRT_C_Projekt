/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"

/*--- Interne Funktion: Analyse der Iterationsanzahl -----------------------*/
int get_itera(struct complex_t c,struct complex_t z, struct param_t* parameter){
	int Iter=0;
	while((z.x*z.x+z.y*z.y)<pow(parameter->radiusG,2)&&Iter <= parameter->imax){
		iterstep(&Iter,z,&z,c);
	};
	return Iter;
};

void iterstep(int *i, struct complex_t zi, struct complex_t* ziplus1, struct complex_t c){
	ziplus1->x += c.x+zi.x*zi.x-zi.y*zi.y;
	ziplus1->y += c.y+2*zi.x*zi.y;
	*i+=1;
};

/*--- Interne Funktion: Farbwert bestimmen ---------------------------------*/
color_name_t get_color_value(int i, int imax){
	color_name_t Color;
	if(i>imax) return Color=Black;
	return Color=i%32;
};

/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/
void fraktal(struct complex_t c,struct complex_t z, struct param_t* parameter){
	grafik_create_paint_area(parameter->xmin, parameter->xmax, parameter->ymin, parameter->ymax, parameter->xpoints, parameter->ypoints);
	color_name_t Grafik[parameter->xpoints][parameter->ypoints][3];
	create_Grafik(c,z,parameter,Grafik);
	grafik_lock_for_painting();
	for(int yG=0; yG<=parameter->ypoints; yG+=1){
		for(int xG=0; xG<=parameter->ypoints; yG+=1){
//			grafik_lock_for_painting();
			grafik_paint_point(Grafik[xG][yG][1],Grafik[xG][yG][2], Grafik[xG][yG][0]);
//			grafik_unlock_and_show();
		};
	};
	grafik_unlock_and_show();
};
void create_Grafik(struct complex_t c,struct complex_t z, struct param_t* parameter, color_name_t Grafik[parameter->xpoints][parameter->ypoints][3]){
	double xstep=(double)(parameter->xmax-parameter->xmin)/(double)(parameter->xpoints);
	double ystep=(double)(parameter->ymax-parameter->ymin)/(double)(parameter->ypoints);
	int xG=0;
	int yG=0;
	int Iteration;
	color_name_t Color;
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
				Grafik[xG][yG][0]=Color;
				Grafik[xG][yG][1]=x;
				Grafik[xG][yG][2]=y;
	//			grafik_unlock_and_show();
				if(xG<parameter->xpoints)xG+=1;
			};
			if(yG<parameter->ypoints)yG+=1;
		};

};



/*---------In die Fraktal-Figur Zoomen ----------------------------------------*/
void fraktal_zoom(struct complex_t* c,struct complex_t* z, struct param_t* parameter, struct complex_t dz, double zoom){
	parameter->center.x+= dz.x;
	parameter->center.y+=dz.y;
	parameter->zoom*=zoom;
	parameter->xmax=(parameter->center.x+parameter->view)/parameter->zoom;
	parameter->xmin=(parameter->center.x-parameter->view)/parameter->zoom;
	parameter->ymax=(parameter->center.y+parameter->view)/parameter->zoom;
	parameter->ymin=(parameter->center.x-parameter->view)/parameter->zoom;
	fraktal(*c,*z,parameter);
};
/* EOF FRAKTAL_C */
