/* BOF FRAKTAL_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Fraktal-Analyse"
 */

#include "fraktal.h"
#include "graphic.h"

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


/*--- Fraktal-Figur analysieren und zeichnen -------------------------------*/


/* EOF FRAKTAL_C */
