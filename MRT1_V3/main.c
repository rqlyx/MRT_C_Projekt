/* BOF MAIN_C
 Praktikumsversuch: Einführung in die Sprache C
 Haupt-Programm
 */

#include "fraktal.h"
#include "graphic.h"
#include "dialog.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Forwarddeklaration der später definierten Hilfsfunktionen:
void goodbye_msg(void);
static void init_exit(void);


/* Hauptprogramm, Einstiegspunkt für eigene Programmierlösung.
 * Kommentarzeichen vor Funktionsaufrufen entfernen und
 * Programmrahmen ausfüllen.
 */
int main (void)
{
        /*--- Variablendeklaration -----------------------------------------*/
		struct complex_t c;
		struct param_t parameter;
		struct complex_t z;
        /*--- Initialwerte -------------------------------------------------*/

		parameter.fraktal = Mandelbrot;
		parameter.radiusG =2;
		parameter.imax=75;
		parameter.xmax=2;
		parameter.xmin=-2;
		parameter.ymax=2;
		parameter.ymin=-2;
		parameter.xpoints=1000;
		parameter.ypoints=1000;

		c.x=0.4;
		c.y=0.4;

		z.x=0;
		z.y=0;

        init_exit();
        
        /*--- Parameter über Dialog abfragen -------------------------------*/
        param_dialog(&parameter, &c,&z);

        /* Initialisierung des Grafikausgabefensters */
        grafik_init_window();

        /* Erzeugen einer virtuellen Leinwand um darauf zu zeichnen: */
        grafik_create_paint_area(parameter.xmin, parameter.xmax, parameter.ymin, parameter.ymax, parameter.xpoints, parameter.ypoints);
        /* virtuelle Leinwand vor dem Zeichnen aktivieren */
        grafik_lock_for_painting();

        fraktal(c,z,&parameter);

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
        		"MRT 1 - V3 - Information",
				"              MRT 1 - V3 - Farbdemonstration\n\n"
				"Den Dialog bitte schließen, um das Programm zu beenden.\n"
				"     (Das Grafikfenster wird nicht aktualisiert.)",
				NULL);

         /* virtuelle Leinwand deaktivieren und im Grafikfenster ausgeben. */
        grafik_unlock_and_show();

        /* Aufrufen von InputChar() um das Programm nach dem öffnen der
         Graphik anzuhalten. Erst wenn in der Konsole eine Taste gedrückt
         wird, schließt sich das Fenster wieder. */
        input_char();

         /* Aufräumen und freigeben der benutzten Grafikressourcen */
        grafik_close_window();
        
        return 0;
}


// -- Hilfsfunktionen ---
static void init_exit(void)
{
        if(atexit(goodbye_msg)){
                fprintf(stderr, "Fehler bei Registrierung der Exitfunktion\n");
                exit(-1);
        }
}

void goodbye_msg(void)
{
        printf("MRT1, V3, Programm beendet.\n");
}

/* EOF MAIN_C */
