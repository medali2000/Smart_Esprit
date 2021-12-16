#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "smart.h"
#include "reclamation.h"
#include "capteur.h"
#include "stock.h"

int x1;
int x2;
int check=0;


char tmp[15]={"temporaire.txt"};
capteur cz;
capteur C,R ;
int x;
int xa;
int euop;


/////////////////////////////////////////////////////////////////////

void
on_button1_administration_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_gererlescapteurs_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *interface_capteur;
interface_capteur=create_interface_capteur();
gtk_widget_show(interface_capteur);
}


void
on_button3_reclamation_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu_reclam;
menu_reclam=create_menu_reclam();
gtk_widget_show(menu_reclam);
}


void
on_button5_gererlestocks_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_stock;
gestion_stock=create_gestion_stock();
gtk_widget_show(gestion_stock);
}


void
on_button6_gererlesmenus_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7_arreter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *login ;
GtkWidget *menu;

login=create_login();
gtk_widget_show(login);

menu=lookup_widget(button,"menuglobale");
gtk_widget_destroy(menu);
}


void
on_button1_dali_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char nom[100],pw[100];
GtkWidget *input1,*input2;
GtkWidget *menu ;
GtkWidget *output ;
GtkWidget *fenetre_login;

input1=lookup_widget(button,"entry1_admin");
input2=lookup_widget(button,"entry2_pw");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(pw,gtk_entry_get_text(GTK_ENTRY(input2)));


output=lookup_widget(button,"label__admin");


if(verif_login(nom,pw)==1)
	{
	menu=create_menuglobale();
	gtk_widget_show(menu);
	gtk_label_set_text(GTK_LABEL(output),"bonjour!");

	
	fenetre_login=lookup_widget(button,"login");
	gtk_widget_destroy(fenetre_login);
	}

else
	gtk_label_set_text(GTK_LABEL(output),"nom ou mot de passe incorrecte!");
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////// Tache dali ///////////////////////////////////////////

void
on_plusreclame_reclam_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *plusreclam_reclam;
GtkWidget *treeview_plusreclame_reclam;
reclamation r;


service_plus_reclamee(r);




plusreclam_reclam=lookup_widget(button,"plusreclam_reclam");
plusreclam_reclam=create_plusreclam_reclam();

gtk_widget_show(plusreclam_reclam);

treeview_plusreclame_reclam=lookup_widget(plusreclam_reclam,"treeview_plusreclame_reclam");

afficher_Plusreclame(treeview_plusreclame_reclam);

}


void
on_recherche_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche_reclam;
recherche_reclam=create_recherche_reclam ();
gtk_widget_show(recherche_reclam);
}


void
on_modifier_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_reclam;
modif_reclam=create_modif_reclam();
gtk_widget_show(modif_reclam);
}


void
on_ajouter_reclam_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_reclam;
ajout_reclam=create_ajout_reclam();
gtk_widget_show(ajout_reclam);
}


void
on_afficher_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
GtkWidget *treeview_afficher_reclam;

afficher_reclam=lookup_widget(button,"afficher_reclam");
afficher_reclam=create_afficher_reclam();

gtk_widget_show(afficher_reclam);

treeview_afficher_reclam=lookup_widget(afficher_reclam,"treeview_afficher_reclam");

afficher_reclamation(treeview_afficher_reclam);
}


void
on_supprimer_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
GtkWidget *treeview_afficher_reclam;

afficher_reclam=lookup_widget(button,"afficher_reclam");
afficher_reclam=create_afficher_reclam();

gtk_widget_show(afficher_reclam);

treeview_afficher_reclam=lookup_widget(afficher_reclam,"treeview_afficher_reclam");

afficher_reclamation(treeview_afficher_reclam);
}


void
on_add_reclam_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
reclamation r;
GtkWidget *ajout_reclam;


GtkWidget *input1,*input2;
char texte1[100];
char texte2[100];

output=lookup_widget(button,"label27");
 
if (check==0)
  {
	
	gtk_label_set_text(GTK_LABEL(output),"caucher la case precedente!");
  }
 
else 
  {
	
	input1=lookup_widget(button,"entry1");
	input2=lookup_widget(button,"entry2");
	if(x1==1)
	strcpy(texte1,"Nutrition");
	else 
	strcpy(texte1,"Hebergement");

	if(x2==1)
	strcpy(texte2,"Validé");
	else
	strcpy(texte2,"non_validé");


	strcpy(r.msg,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(r.type,texte1);
	strcpy(r.etat,texte2);
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input2)));



	ajouter_reclamation( r);

	ajout_reclam=lookup_widget(button,"ajout_reclam");
	gtk_widget_destroy(ajout_reclam);
	

  	
	
  }
}


void
on_treeview_afficher_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		afficher_reclamation(treeview);
	}
}


void
on_retour_afficher_reclam_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
afficher_reclam=lookup_widget(button,"afficher_reclam");
gtk_widget_destroy(afficher_reclam);
}


void
on_recherche1_reclam_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche_reclam;
GtkWidget *recherche2_reclam;
GtkWidget *treeview_recherche_reclam;
GtkWidget *input1;
reclamation r;
FILE *f1;
FILE *f2;

int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100];
reclamation rec[100];


input1=lookup_widget(button,"entry3");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

// rechercher
f1=fopen("reclamation.txt","r+");
while((c=fgetc(f1)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f1);

f1=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f1,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
strcpy(msg,rec[i].msg);
strcpy(type,rec[i].type);
strcpy(etat,rec[i].etat);
}
}
if (strcmp(id,ident)==0)
	{
	strcpy(r.id,id);
	strcpy(r.msg,msg);
	strcpy(r.type,type);
	strcpy(r.etat,etat);

	ajouter_recherche(r);
	}
else
	{
	strcpy(r.id,"introuvable!");
	strcpy(r.msg,"introuvable!");
	strcpy(r.type,"introuvable!");
	strcpy(r.etat,"introuvable!");
	
	ajouter_recherche(r);

	
	}
	

recherche2_reclam=lookup_widget(button,"recherche2_reclam");
recherche2_reclam=create_recherche2_reclam();

gtk_widget_show(recherche2_reclam);

treeview_recherche_reclam=lookup_widget(recherche2_reclam,"treeview_recherche_reclam");

chercher_reclamation(treeview_recherche_reclam);


recherche_reclam=lookup_widget(button,"recherche_reclam");
gtk_widget_destroy(recherche_reclam);
}


void
on_treeview_recherche_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		chercher_reclamation(treeview);

	}
}


void
on_retour_recherche2_reclame_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *recherche2_reclam;
recherche2_reclam=lookup_widget(button,"recherche2_reclam");
gtk_widget_destroy(recherche2_reclam);
}


void
on_treeview_plusreclame_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* msg;
	gchar* type;
	gchar* etat;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&type,2,&etat,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.type,type);
		strcpy(r.etat,etat);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		afficher_Plusreclame(treeview);
	}
}


void
on_retour_plusreclame_reclam_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *plusreclam_reclam;
plusreclam_reclam=lookup_widget(button,"plusreclam_reclam");
gtk_widget_destroy(plusreclam_reclam);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=1;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x1=2;}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=1;}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x2=2;}
}


void
on_robo_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{check=1;}

}




void
on_note_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *note;
GtkWidget *output;
int valeur;

note=lookup_widget(button,"spinbutton1");
valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(note));

output=lookup_widget(button,"label40");

if (valeur<3)
	{
	gtk_label_set_text(GTK_LABEL(output)," Désolé, nous allons travailler sur le développement du programme");
	}
else
	gtk_label_set_text(GTK_LABEL(output),"merci enormement !");


}


void
on_modifier_reclamation_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
GtkWidget *input1,*input2,*combobox1,*combobox2;
FILE *f;

reclamation r;
int d=0,i;
char c,msg[100],type[100],etat[100],id[100],ident[100],message[100];
char text1[100],text2[100];
reclamation rec[100];

/// collect donné ////

input1=lookup_widget(button,"entry4");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(button,"entry5");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input2)));

combobox1=lookup_widget(button,"combobox1");
if(strcmp("Nutrition",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))))

	strcpy(text1,"Nutrition");
else
	strcpy(text1,"Hebergement");


combobox2=lookup_widget(button,"combobox2");

if(strcmp("Validé",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))))

	strcpy(text2,"Validé");
else
	strcpy(text2,"non_Validé");

strcpy(r.msg,message);
strcpy(r.type,text1);
strcpy(r.etat,text2);
strcpy(r.id,ident);



output=lookup_widget(button,"label37");

/// rechercher////

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f);

f=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
}
}

if  (strcmp(id,ident)==0)
	{
	modifier_reclamation(r) ;// modifier 
	gtk_label_set_text(GTK_LABEL(output),"Modification terminer !");
	}





else
	
	gtk_label_set_text(GTK_LABEL(output),"Identifiant introuvable !");
	
}


void
on_noterservice_reclamation_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *noter_reclam ;
noter_reclam=create_noter_reclam();
gtk_widget_show(noter_reclam);
}




/////////////////////////////tache ahmed////////////////////////////////////////////////////

void
on_ajoutajout_capt_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ref, *type, *local, *vmin, *vmax, *etat,*et;




ref=lookup_widget(button,"refajout_capt");
type=lookup_widget(button,"combobox3");
local=lookup_widget(button,"locajout_capt");
vmin=lookup_widget(button,"vmin_capt");
vmax=lookup_widget(button,"vmax_capt");


strcpy(C.Reference,gtk_entry_get_text(GTK_ENTRY(ref)));

strcpy(C.Valeur_Min,gtk_entry_get_text(GTK_ENTRY(vmin)));
strcpy(C.Valeur_Max,gtk_entry_get_text(GTK_ENTRY(vmax)));
strcpy(C.Localisation,gtk_entry_get_text(GTK_ENTRY(local)));
if(x==1)
strcpy(C.Etat,"1");
else if (x==2)
strcpy(C.Etat,"0");
if(strcmp("Temperature",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Temperature");
if(strcmp("Gaz",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Gaz");
if(strcmp("Humiditer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Humiditer");
if(strcmp("Fumer",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
strcpy(C.Type,"Fumer");

ajouter(C);
}


void
on_radiobutton_ajoutcapt_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=1;
}


void
on_radiobutton_ajoutcapt2_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
x=2;
}


void
on_retour_ajoutcapt_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_capteur;
ajouter_capteur=lookup_widget(button,"ajouter_capteur");
gtk_widget_destroy(ajouter_capteur);
}


void
on_treeview_interfacecapt_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Reference;
	gchar* Type;
	gchar* Vocalisation;
	gchar* Valmin;
	gchar* Valmax;
	gchar* Etat;
	capteur c;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	
	if (gtk_tree_model_get_iter(model, &iter, path))	
{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Reference, 1, &Type, 2,&Vocalisation, 3,&Valmin, 4,&Valmax, 5,&Etat, -1);
	strcpy(c.Reference,Reference);
	strcpy(c.Type,Type);
	strcpy(c.Localisation,Vocalisation);
	strcpy(c.Valeur_Min,Valmin);
	strcpy(c.Valeur_Max,Valmax);
	strcpy(c.Etat,Etat);

	supprimer_capteur(c.Reference);
	afficher_capteur_deff(treeview);
}

}


void
on_ajouter_interfacecapt_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_capteur;
ajouter_capteur=create_ajouter_capteur();
gtk_widget_show(ajouter_capteur);
}


void
on_modifier_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ahmed_modifier;
ahmed_modifier=create_ahmed_modifier();
gtk_widget_show(ahmed_modifier);
}


void
on_afficher_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_interfacecapt;
treeview_interfacecapt=lookup_widget(button,"treeview_interfacecapt");
afficher_capteur(treeview_interfacecapt);
}


void
on_recherche_interfacecapt_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
GtkWidget *ref,*treeview_interfacecapt;

ref=lookup_widget(button,"entry_recherchecapt");
strcpy(x.Reference,gtk_entry_get_text(GTK_ENTRY(ref)));
recherche_capteur(tmp,x.Reference);

treeview_interfacecapt=lookup_widget(button,"treeview_interfacecapt");
afficher_capteur_rechercher(tmp,treeview_interfacecapt);
}


void
on_supprimer_interfacecapt_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ahmed_supprimer;
ahmed_supprimer=create_ahmed_supprimer();
gtk_widget_show(ahmed_supprimer);
}


void
on_captdeff_interfacecapt_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ahmed_captdef;
ahmed_captdef=create_ahmed_captdef();
gtk_widget_show(ahmed_captdef);
}


void
on_checkbutton_ouisupp_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)) 
xa=1;
}


void
on_ok_ahmedsupp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
if(xa==1) 
supprimer_capteur(cz.Reference);
else if(xa!=1)
{
GtkWidget *modif;

modif=lookup_widget(button,"ahmed_supprimer");

gtk_widget_hide(modif);
}
}


void
on_ok_modifiercapt_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *reference, *type, *localisation, *vmax, *vmin, *etat;

reference=lookup_widget(button,"entry_refmodcapt");
type=lookup_widget(button,"entry_typemodcapt");
localisation=lookup_widget(button,"entry_localmodcapt");
vmin=lookup_widget(button,"entry_minmodcapt");
vmax=lookup_widget(button,"entry_maxmodcapt");
etat=lookup_widget(button,"entry_etatmodcapt");

strcpy(R.Reference,gtk_entry_get_text(GTK_ENTRY(reference)));
strcpy(R.Type,gtk_entry_get_text(GTK_ENTRY(type)));
strcpy(R.Localisation,gtk_entry_get_text(GTK_ENTRY(localisation)));
strcpy(R.Valeur_Min,gtk_entry_get_text(GTK_ENTRY(vmin)));
strcpy(R.Valeur_Max,gtk_entry_get_text(GTK_ENTRY(vmax)));
strcpy(R.Etat,gtk_entry_get_text(GTK_ENTRY(etat)));
modifier_capteur(R);
}


void
on_retour_modifiercapt_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ahmed_modifier;
ahmed_modifier=lookup_widget(button,"ahmed_modifier");
gtk_widget_destroy(ahmed_modifier);
}


void
on_treeview_captdef_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* Reference;
	gchar* Type;
	gchar* Vocalisation;
	gchar* Valmin;
	gchar* Valmax;
	gchar* Etat;
	
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	
	if (gtk_tree_model_get_iter(model, &iter, path))	
{
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &Reference, 1, &Type, 2,&Vocalisation, 3,&Valmin, 4,&Valmax, 5,&Etat, -1);
	strcpy(cz.Reference,Reference);
	strcpy(cz.Type,Type);
	strcpy(cz.Localisation,Vocalisation);
	strcpy(cz.Valeur_Min,Valmin);
	strcpy(cz.Valeur_Max,Valmax);
	strcpy(cz.Etat,Etat);
	
	
}
}


void
on_afficher_captdef_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_captdef;
treeview_captdef=lookup_widget(button,"treeview_captdef");

affichercpadef(treeview_captdef);
}


void
on_retour_captdef_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ahmed_captdef;
ahmed_captdef=lookup_widget(button,"ahmed_captdef");
gtk_widget_destroy(ahmed_captdef);
}



/////////////////////////tache youssef////////////////////////////





void
on_nouvprod_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
stockage s;

GtkWidget *gestion_stock;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;


input1= lookup_widget(button,"spinbutton_stock");
input2= lookup_widget(button,"nomprod_stock");
input3 = lookup_widget(button,"qprod_stock");


gestion_stock=lookup_widget(button,"gestion_stock");




s.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
strcpy(s.produit,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));
ajout (s);
}


void
on_prodrept_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_fiche_stock_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview_fichestock;
GtkWidget *gestion_stoc;
GtkWidget *fiche_stock,*fiche_stock1;

gestion_stoc=lookup_widget(button,"gestion_stock");
gtk_widget_destroy(gestion_stoc);
fiche_stock=create_fiche_stock();
fiche_stock1=lookup_widget(button,"fiche_stock");


gtk_widget_show(fiche_stock);
treeview_fichestock=lookup_widget(fiche_stock,"treeview_fichestock");
affichage (treeview_fichestock);

}


void
on_suppprod_stock_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
stockage s;
GtkWidget *input1 ;
input1= lookup_widget(button,"suppprod_stock");
supprission(s);
GtkWidget *gestion_stock;
GtkWidget *fiche_stock;
GtkWidget *treeview1;

gestion_stock=lookup_widget(button,"gestion_stock");
gtk_widget_destroy(gestion_stock);
fiche_stock=lookup_widget(button,"fiche_stock");
fiche_stock=create_fiche_stock();

gtk_widget_show(fiche_stock);

treeview1=lookup_widget(fiche_stock, "treeview_fichestock");

affichage(treeview1);
}


void
on_rechercheprod_stock_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
int tr;
GtkWidget *gestion_stock;
GtkWidget *recherche_stock;
GtkWidget *identifiant;
GtkWidget *treeview_recherchestock;
stockage s;

identifiant=lookup_widget(button,"spinbutton_stock");
tr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (identifiant));

int y;

GtkWidget *input1 ;
input1= lookup_widget(button,"rechercheprod_stock");
GtkWidget *treeview2;
gestion_stock=lookup_widget(button,"gestion_stock");
gtk_widget_destroy(gestion_stock);
recherche_stock=lookup_widget(button,"recherche_stock");
recherche_stock=create_recherche_stock();

gtk_widget_show(recherche_stock);

treeview_recherchestock=lookup_widget(recherche_stock,"treeview_recherchestock");
afficher_s_chercher(tr,treeview_recherchestock);

}


void
on_treeview_fichestock_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* prod;
gchar* quant;
gint* identifiant;
stockage s;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&identifiant,1,&prod,2,&quant,-1);
s.id=identifiant;
strcpy(s.produit,prod);
strcpy(s.quantite,quant);
supprission(s);
affichage (treeview);
}
}


void
on_modif_fichestock_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
stockage s;
GtkWidget *input1 ;
input1= lookup_widget(button,"modif_fichestock");
GtkWidget *fiche_stock;
GtkWidget *modif_stock;


fiche_stock=lookup_widget(button,"fiche_stock");
gtk_widget_destroy(fiche_stock);
modif_stock=lookup_widget(button,"modifier_stock");
modif_stock=create_modifier_stock();

gtk_widget_show(modif_stock);

}


void
on_retour_fichestock_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_stock, *fiche_stock;
fiche_stock=lookup_widget(button,"fiche_stock");
gtk_widget_destroy(fiche_stock);
gestion_stock=create_gestion_stock();
gtk_widget_show(gestion_stock);
}


void
on_ok_modifstock_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
stockage s;
GtkWidget *sortie;
GtkWidget *fiche_stock;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;

sortie=lookup_widget(button,"label91");
input1 = lookup_widget(button,"spinbutton_modifstock");
input2 = lookup_widget(button,"nomprofmodif_stock");
input3 = lookup_widget(button,"qprodmodif_stock");
fiche_stock=lookup_widget(button,"fiche_stock");

s.id=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
strcpy(s.produit,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(s.quantite,gtk_entry_get_text(GTK_ENTRY(input3)));


GdkColor color;
gdk_color_parse("green",&color);
gtk_widget_modify_fg(sortie,GTK_STATE_NORMAL,&color);
gtk_label_set_text(GTK_LABEL(sortie),"Modification réuissie");

modifier(s);
}


void
on_retourmodif_stock_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_stock, *modif_stock;
modif_stock=lookup_widget(button,"modifier_stock");
gtk_widget_destroy(modif_stock);
gestion_stock=create_gestion_stock();
gtk_widget_show(gestion_stock);
}


void
on_treeview_recherchestock_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* prod;
gchar* quant;
gint* identifiant;
stockage s;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&identifiant,1,&prod,2,&quant,-1);
s.id=identifiant;
strcpy(s.produit,prod);
strcpy(s.quantite,quant);
affichage (treeview);
}
}


void
on_retour_recherchestock_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestion_stock, *recherche_stock;
recherche_stock=lookup_widget(button,"recherche_stock");
gtk_widget_destroy(recherche_stock);
gestion_stock=create_gestion_stock();
gtk_widget_show(gestion_stock);
}

