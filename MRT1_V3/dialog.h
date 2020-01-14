/* BOF DIALOG_H
 Praktikumsversuch: Einführung in die Sprache C
 Programm-Modul "Parameterdialog"
 */

#ifndef DIALOG_H
#define DIALOG_H

#include "fraktal.h"

/*--- Parameter Dialog Prototyp --------------------------------------------*/
int param_dialog(struct param_t* parameter, struct complex_t* c,struct complex_t* z);
/*--- Funktion zum einlesen des ersten Characters einer getchar() Eingabe --*/
char input_char();

#endif /* DIALOG_H */

/* EOF DIALOG_H */
