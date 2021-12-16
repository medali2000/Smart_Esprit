#ifdef HAVE_CONFIG_H
# include<config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
#include<gtk/gtk.h>


enum
{
	EMSG,
	ETYPE,
	EETAT,
	EID,
	COLUMNS,
};




//////////////AJOUTER RECLAMATION //////////////////


void ajouter_reclamation(reclamation r)
{

FILE *f;
f=fopen("reclamation.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
fclose(f);
}
}


////////////AFFICHER RECLAMATION /////////////////


void afficher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char msg[100];
	char type[100];
	char etat[100];
	char id[100];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("msg",renderer,"text",EMSG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("reclamation.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",msg,type,etat,id)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,EMSG,msg,ETYPE,type,EETAT,etat,EID,id,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}
}



///////////////////////SUPPRIMER RECLAMATION///////////////////


void supprimer_reclamation(reclamation r)

{
reclamation r2;
FILE *f , *g;
	
	f=fopen("reclamation.txt","r");
	g=fopen("reclamation2.txt","w");

	if(f==NULL || g==NULL )
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s \n",r2.msg,r2.type,r2.etat,r2.id)!=EOF)
		{
		  if(strcmp(r.msg,r2.msg)!=0 || strcmp(r.type,r2.type)!=0 ||
			 strcmp(r.etat,r2.etat)!=0 || strcmp(r.id,r2.id)!=0)
		   {
		     fprintf(g,"%s %s %s %s \n",r2.msg,r2.type,r2.etat,r2.id);
		    }
		}
		fclose(f);
		fclose(g);
remove("reclamation.txt");
rename("reclamation2.txt","reclamation.txt");
	}
}

/////////////////RECHERCHER RECLAMATION////////////////////


void chercher_reclamation(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char msg[100];
	char type[100];
	char etat[100];
	char id[100];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("msg",renderer,"text",EMSG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("recherche.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("recherche.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",msg,type,etat,id)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,EMSG,msg,ETYPE,type,EETAT,etat,EID,id,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}
	remove("recherche.txt");
        
	
}



void ajouter_recherche(reclamation r)
{

FILE *f;
f=fopen("recherche.txt","a");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
fclose(f);
}
}

///////////////MODIFIER RECLAMATION///////////////////////////

void modifier_reclamation(reclamation r)
{
int i,d=0;
char c;
reclamation rec[100];
FILE *f, *tempo;

f=fopen("recamation.txt","a+");
tempo=fopen("tempo.txt","a+");

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 	{
  	if(c=='\n')
  	d++;
 	}
fclose(f);

f=fopen("reclamation.txt","r");
tempo=fopen("tempo.txt","a+");
for (i=0;i<d;i++)
	{
	fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	if(strcmp(r.id,rec[i].id)==0)
		{
		strcpy(rec[i].msg,r.msg);
		strcpy(rec[i].type,r.type);
		strcpy(rec[i].etat,r.etat);
		strcpy(rec[i].id,r.id);
		}
	
	fprintf(tempo,"%s %s %s %s\n",rec[i].msg,rec[i].type,rec[i].etat,&rec[i].id);
	}
fclose(f);
fclose(tempo);
remove("reclamation.txt");
rename("tempo.txt","reclamation.txt");
}

////////////////////// LE PLUS RECLAMEE//////////////////////////



void afficher_Plusreclame(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char msg[100];
	char type[100];
	char etat[100];
	char id[100];
	store=NULL;

	FILE *f;
	if(store==NULL)
	{


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("msg",renderer,"text",EMSG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("plusreclame.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f=fopen("plusreclame.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",msg,type,etat,id)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set (store,&iter,EMSG,msg,ETYPE,type,EETAT,etat,EID,id,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);

	}

	remove("plusreclame.txt");
        
}





void service_plus_reclamee(reclamation r)
{

int i,n=0,h=0;

FILE *f1;
FILE *f2;



f1=fopen("reclamation.txt","r+");

while((fscanf(f1,"%s %s %s %s\n",r.msg,r.type,r.etat,&r.id)) !=EOF )
 	{
  	if(strcmp(r.type,"Nutrition")==0)
		n++;
	else 
		h++;
 	}



	
fclose(f1);

f2=fopen("plusreclame.txt","a+");
if (n>h)
  {
	strcpy(r.msg,"x");
	strcpy(r.type,"Nutrition");
	strcpy(r.etat,"x");
	strcpy(r.id,"x");

	
	if(f2!=NULL)
	{
	fprintf(f2,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
	
	}

  }
	
else if(n<h)
  {
	strcpy(r.msg,"x");
	strcpy(r.type,"Hebergement");
	strcpy(r.etat,"x");
	strcpy(r.id,"x");

	
	if(f2!=NULL)
	{
	fprintf(f2,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
	
	}
	
  }
else 
  {
	strcpy(r.msg,"x");
	strcpy(r.type,"les_deux");
	strcpy(r.etat,"x");
	strcpy(r.id,"x");

	
	if(f2!=NULL)
	{
	fprintf(f2,"%s %s %s %s \n",r.msg,r.type,r.etat,r.id);
	
	}	
  }

	
  
fclose(f2);
}













