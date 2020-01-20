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
		struct param_t Parameter;
		struct complex_t z;
        /*--- Initialwerte -------------------------------------------------*/

		Parameter.fraktal = Mandelbrot;
		Parameter.radiusG =2;
		Parameter.center.x=-2;
		Parameter.center.y=0;
		Parameter.view=2;
		Parameter.zoom=1;
		Parameter.imax=64;
		Parameter.xmax=(Parameter.center.x+Parameter.view)/Parameter.zoom;
		Parameter.xmin=(Parameter.center.x-Parameter.view)/Parameter.zoom;
		Parameter.ymax=(Parameter.center.y+Parameter.view)/Parameter.zoom;
		Parameter.ymin=(Parameter.center.x-Parameter.view)/Parameter.zoom;
		Parameter.xpoints=1000;
		Parameter.ypoints=1000;

		c.x=0.4;
		c.y=0.4;

		z.x=0;
		z.y=0;

        init_exit();
        
        /*--- Parameter über Dialog abfragen -------------------------------*/
        //param_dialog(&Parameter, &c,&z);

        /* Initialisierung des Grafikausgabefensters */
        grafik_init_window();

        /* Erzeugen einer virtuellen Leinwand um darauf zu zeichnen: */
        //grafik_create_paint_area(/*x_min, x_max, y_min, y_max, x_points, y_points*/);
        /* virtuelle Leinwand vor dem Zeichnen aktivieren */
        //grafik_lock_for_painting();

        /* Bitte ersetzen Sie folgenden Funktionsaufruf durch ihre eigene
         * Implementation der Fraktalberechnung und -anzeige. */
        //farb_demonstration();





        fraktal(c,z,&Parameter);
        sleep(2);
        struct complex_t dz={.x=0,.y=0};
        fraktal_zoom(&c,&z,&Parameter,dz,2);
        sleep(5);


        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
        		"MRT 1 - V3 - Information",
				"              MRT 1 - V3 - Farbdemonstration\n\n"
				"Den Dialog bitte schließen, um das Programm zu beenden.\n"
				"     (Das Grafikfenster wird nicht aktualisiert.)",
				NULL);




         /* virtuelle Leinwand deaktivieren und im Grafikfenster ausgeben. */
        //grafik_unlock_and_show();

        /* Aufrufen von InputChar() um das Programm nach dem öffnen der
         Graphik anzuhalten. Erst wenn in der Konsole eine Taste gedrückt
         wird, schließt sich das Fenster wieder. */
        //input_char();

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
