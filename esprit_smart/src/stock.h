#include<gtk/gtk.h>

typedef struct stockage {
	char produit[100];
	char quantite[100];
	int id;
	} stockage;

int verif(stockage s);

void ajout (stockage s);

void supprission(stockage s);

void affichage (GtkWidget *treeview);

void modifier(stockage s);


void chercher_s (stockage s);
void alert_stock(stockage s);
void afficher_alert_stock(GtkWidget *treeview);
void afficher_s_chercher (int tr,GtkWidget *treeview);
