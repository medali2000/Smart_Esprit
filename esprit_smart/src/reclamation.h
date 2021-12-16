#include<gtk/gtk.h>

typedef struct
{

char msg[100];
char type[100];
char etat[100];
char id[100];

}reclamation;

void ajouter_reclamation(reclamation r);

void afficher_reclamation(GtkWidget *liste);

void supprimer_reclamation(reclamation r);

void chercher_reclamation(GtkWidget *liste);

void modifier_reclamation(reclamation r);


void afficher_Plusreclame(GtkWidget *liste);
void service_plus_reclamee(reclamation r);


