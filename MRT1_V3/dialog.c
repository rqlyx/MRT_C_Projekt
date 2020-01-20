/* BOF DIALOG_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#define getVarName(var) #var

/*--- Definitionen ---------------------------------------------------------*/

enum bool {FALSE, TRUE};
int input_frage;

/*--- Tastatureingabe lesen und nur ersten Character beachten --------------*/

char input_char(void)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        return s[0];
}

/*--- Double-Zahl von der Tastatur lesen -----------------------------------*/

void input_double(double *value)
{
        char *endptr;
        char s[80];
        fgets(s,sizeof(s), stdin);
        if (s[0]!=10) *value=strtod (s, &endptr);
}


/*--- Int-Zahl von der Tastatur lesen --------------------------------------*/

void input_int(int *value)
{
        char s[80];
        fgets(s,sizeof(s), stdin);
        if (s[0]!=10) *value=atoi (s);
}


/*--- Parameter Dialog -----------------------------------------------------*/
int param_dialog(struct param_t* parameter, struct complex_t* c,struct complex_t* z){

	//Ausgabe der aktuellen Parameter//

	printf("Die aktuellen Parameter sind:\n");
	printf("Fraktalart: %s\n", &parameter->fraktal);
	printf("Radius: %d\n", parameter->radiusG);
	printf("Iterationszahl: %d\n", parameter->imax);
	printf("Definitionsbereich von x: (%d | %d)\n", parameter->xmin, parameter->xmax);
	printf("Definitionsbereich von y: (%d | %d)\n", parameter->ymin, parameter->ymax);
	printf("Anzahl der Linien (x | y): (%d | %d)\n", parameter->xpoints, parameter->ypoints);
	printf("------------------------------------------\n");
	printf("Die komplexe Zahle C hat die Werte: [Re(c)= %f | Im(c)= %f]\n", c->x, c->y);
	printf("------------------------------------------\n");

	
	/*--- Parameter verändern?-----------------------------------------------------*/
	
	printf("Wollen sie die Parameter verändern?(y=0/n=1)\n");
	scanf("%d", &input_frage);

	if (input_frage == 0){

		/*--- Parameter Eingabe -----------------------------------------------------*/

		printf("Geben sie die Fraktalart(0=Mandelbrot, 1=Juliamenge) ein:\n");
		scanf("%s",&parameter->fraktal);

		printf("Geben sie den Radius(INT) ein:\n");
		input_int(&parameter->radiusG);

		printf("Geben sie die Iterationszahl(INT) ein:\n");
		input_int(&parameter->imax);

		printf("Definitionsbereich:(xmin, xmax)\n");
		scanf("%d, %d", &parameter->xmin, &parameter->xmax);

		printf("Definitionsbereich:(ymin, ymax)\n");
		scanf("%d, %d", &parameter->ymin, &parameter->ymax);

		printf("Anzahl der Linien (xpoints , ypoints):\n");
		scanf("%d, %d", &parameter->xpoints, &parameter->ypoints);

		printf("Geben sie den Realteil von c ein:\n");
		input_double(&c->x);

		printf("Geben sie den Imaginärteil von c ein:\n");
		input_double(&c->y);

		return 0;
	}
	else{
		return 0;
	}
}

/* EOF DIALOG_C */
