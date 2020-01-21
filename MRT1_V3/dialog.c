/* BOF DIALOG_C
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>

/*--- Definitionen ---------------------------------------------------------*/
enum bool {FALSE, TRUE};
static char* enumName[] = {"Mandelbrot", "Juliamenge"};

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

/*--- Check Funktion für Integer--------------------------------------*/
/*Prüft ob der eingegebe Wert im Definitionsbereich liegt*/

	void input_check_i(int *wert, int ob_gw, int un_gw){
		int i = 0;
		while (i == 0 ){
		input_int(wert);
		if (*wert < un_gw || *wert > ob_gw) printf("Der Wert liegt außerhalb des Definitionsbereichs!\n");
		else i = 1;
		}
	}
/*--- Check Funktion für Double--------------------------------------*/
/*Prüft ob der eingegebe Wert im Definitionsbereich liegt*/

	void input_check_d(double* wert, double ob_gw, double un_gw){
		int i = 0;
		while (i == 0 ){
		input_double(wert);
		if (*wert < un_gw || *wert > ob_gw) printf("Der Wert liegt außerhalb des Definitionsbereichs!\n");
		else i = 1;
		}
	}
/*--- Input Parameter Funktion --------------------------------------*/

void input_param(struct param_t* parameter){

//Textoutput for switch case
	printf("Was wollen sie verändern?\n");
	printf("------------------------------------------\n");
	printf("1 = Fraktalart\n2 = Radius\n3 = Interationszahl\n4 = Definitionsbereich von x\n5 = Definitionsbereich von y\n6 = Anzahl der Linien\n");


//Erstellung des Untermenüs mit switch case und Aufrufen der Eingabefunktion
	int param_frage = 0;
	input_check_i(&param_frage,6,1);

	switch (param_frage){
	case 1:
		printf("Geben sie die Fraktalart(Mandelbrot = 0 |Juliamenge = 1) ein:\n");
		input_check_i((int*)&(parameter->fraktal),1,0);break;
	case 2:
		printf("Geben sie den Radius ein(0 < r < 10):\n");
		input_check_i(&parameter->radiusG,10, 0);break;
	case 3:
		printf("Geben sie die Iterationszahl(0 < i < 300) ein:\n");
		input_check_i(&parameter->imax,300, 0);break;
	case 4:
		printf("Untere Grenze Definitionsbereich(-10 < x < 0):\n");
		input_check_i(&parameter->xmin,0, -10);

		printf("Obere Grenze Definitionsbereich(0 < x < 10):\n");
		input_check_i(&parameter->xmax,10, 0);break;
	case 5:
		printf("Untere Grenze Definitionsbereich(-10 < Y < 0):\n");
		input_check_i(&parameter->ymin,0,-10);

		printf("Obere Grenze Definitionsbereich(0 < y < 10):\n");
		input_check_i(&parameter->ymax,10, 0);break;
	case 6:
		printf("Anzahl der Linien für x(0 < xpoints < 3000):\n");
		input_check_i(&parameter->xpoints,3000, 0);

		printf("Anzahl der Linien für y(0 < ypoints < 3000):\n");
		input_check_i(&parameter->ypoints,3000, 0);break;
	}
}

/*--- Input c Funktion --------------------------------------*/

void input_c(struct complex_t* c){

	printf("Geben sie den Realteil von c ein(-10 < x < 10):\n");
	input_check_d(&(c->x), 10, -10);

	printf("Geben sie den Imaginärteil von c ein(-10 < y < 10):\n");
	input_check_d(&c->y, 10, -10);
}

/*--- Parameter Dialog -----------------------------------------------------*/

int param_dialog(struct param_t* parameter, struct complex_t* c,struct complex_t* z){

/*--- Ausgabe der aktuellen Parameter-----------------------------------------------------*/
	printf("Die aktuellen Parameter sind:\n");
	printf("------------------------------------------\n");
	printf("Fraktalart:                 %s\n", enumName[(int)parameter->fraktal]);
	printf("Radius:                     %d\n", parameter->radiusG);
	printf("Iterationszahl:             %d\n", parameter->imax);
	printf("Definitionsbereich von x:  (%d < x < %d)\n", parameter->xmin, parameter->xmax);
	printf("Definitionsbereich von y:  (%d < y < %d)\n", parameter->ymin, parameter->ymax);
	printf("Anzahl der Linien (x | y): (%d | %d)\n", parameter->xpoints, parameter->ypoints);
	printf("------------------------------------------\n");
	printf("Die komplexe Zahle C hat die Werte:\n [Re(c)= %f | Im(c)= %f]\n", c->x, c->y);
	printf("------------------------------------------\n");

/*--- Parameter verändern?-----------------------------------------------------*/
	printf("Was wollen sie tun?\n");
	printf("------------------------------------------\n");
	printf("1 = Grafik zeichnen\n2 = Parameter verändern\n3 = Komplexe Zahl C verändern\n4 = Programm beenden\n");

/*--- "Menü" Realisierung in der Konsole mit switch case -----------------------------------------------------*/

	int input_frage = 0;
	input_check_i(&input_frage,4,1);

		switch (input_frage){

		case 1: return 0;
		case 2:	input_param(parameter);
				param_dialog(parameter, c, z);break;
		case 3: input_c(c);
				param_dialog(parameter, c, z);break;
		case 4: exit(-1); break;
	}
	return 0;
}

/* EOF DIALOG_C */
