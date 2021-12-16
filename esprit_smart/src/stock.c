#include "stock.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>



//////////////////////////////////////////////////////////////////////

void ajout (stockage s)
{

	FILE *f;
	f=fopen("stock.txt","a");
if(f!=NULL)
{
	fprintf(f,"%d %s %s \n",s.id,s.produit,s.quantite);
	fclose(f);
}
}
/////////////////////////////////////////////////////////////////////

enum
{
        EID,
	EPRODUIT,
	EQUANTITE,
	
	
  COLUMNS_STOCK
};


void affichage (GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char produit[30];
	int identifiant;
	char quantite[30];
	store=NULL;

FILE *f;


if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("produit", renderer, "text", EPRODUIT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


}
store=gtk_list_store_new(COLUMNS_STOCK, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
   f = fopen("stock.txt", "r");
   if(f==NULL)
 	 {
 		return;
 	  }
    else
  	{
		f = fopen("stock.txt", "a+");
		while(fscanf(f,"%d %s %s \n",&identifiant,produit,quantite)!=EOF)
{
  			gtk_list_store_append (store, &iter);
  			gtk_list_store_set (store, &iter,EID,identifiant,EPRODUIT,produit,EQUANTITE,quantite,-1);
  		}
      fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
    }
   
}



/////////////////////////////////////////////////////////////////////

void supprission(stockage s)



{
	stockage tmp;
	FILE*f;
  FILE*ftemp;
  f=fopen("stock.txt","r");
	ftemp=fopen("stock.tmp","w");

  while(fscanf(f,"%d %s %s  \n",&tmp.id,tmp.produit,tmp.quantite)!=EOF)
  {
  if((s.id!=tmp.id) || strcmp(s.produit,tmp.produit)!=0 || strcmp(s.quantite,tmp.quantite)!=0)
    		{
			fprintf(ftemp,"%d %s %s  \n",tmp.id,tmp.produit,tmp.quantite);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("stock.txt");
	rename("stock.tmp","stock.txt");
}

//////////////////////////////////////////////////////////////

void modifier(stockage s)
{

stockage tmp;
FILE *f=NULL;
FILE *fich=NULL;
f=fopen("stock.txt","r");
fich=fopen("tmp.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%d %s %s",&tmp.id,tmp.produit,tmp.quantite)!=EOF)
{
if(s.id!=tmp.id)
{
fprintf(fich,"%d %s %s\n",tmp.id,tmp.produit,tmp.quantite);
}
else
fprintf(fich,"%d %s %s\n",s.id,s.produit,s.quantite);
}
}
fclose(fich);
fclose(f);
remove("stock.txt");
rename("tmp.txt","stock.txt");
}


//////////////////////////////////////////////////////////////////////////////

void chercher_s(stockage s)  
{
FILE *f=NULL; 
FILE *f1=NULL;
	
	int identifiant;
	char quantite[30];
	char nom[30];

f=fopen("stock.txt","r");
f1=fopen("tmp.txt","w");
while(fscanf(f,"%d %s %s \n",&identifiant,nom,quantite)!=EOF)
	{
		if (s.id==identifiant)
		{
		fprintf(f1,"%d %s %s \n",identifiant,nom,quantite);
		}
	}
	fclose(f);
	fclose(f1);
}

/////////////////////////////////////////////////////////////////////////////

void afficher_s_chercher (int tr,GtkWidget *treeview)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char produit[30];
	int id;
	char quantite[30];
	
	FILE *f;
	store=NULL;

store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (treeview), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("produit", renderer, "text", EPRODUIT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);



        
   }
   store=gtk_list_store_new (COLUMNS_STOCK,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
   f = fopen("stock.txt", "r");
   if(f ==NULL)
 	 {
 		return;
 	  }
    else
  	{
	f = fopen("stock.txt", "a+");
  		while(fscanf(f,"%d %s  %s ",&id,produit,quantite)!=EOF)
  		{
  		if(tr==id)
{
	gtk_list_store_append (store, &iter);
  			gtk_list_store_set (store, &iter,EID,id,EPRODUIT,produit,EQUANTITE,quantite,-1);
}

  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}


////////////////////////////////////////////////////////////////////////

int verif(stockage s)
{
FILE *f;
	char produit[30];
	int identifiant1;
	char quantite[30];
	int t,test=0;

f=fopen("stock.txt","r");
if (f!=NULL)
    {
while(fscanf(f,"%d %s %s \n",&identifiant1,produit,quantite)!=EOF)
	{
		if(s.id==identifiant1)
		{
		test++;
		}
	}
		if(test!=0)
		{
		t=1;
		}
		if(test==0)
		t=2;
    }
return t;
}

////////////////////////////////////////////////////////////////////////////


void alert_stock(stockage s)
{
FILE* f;
FILE* f2;
	char produit[30];
	int identifiant1;
	char quantite[30];
	
f=fopen("stock.txt","r");
f2=fopen("alerte.txt","w");
	while(fscanf(f,"%d %s %s \n",&identifiant1,produit,quantite)!=EOF)
	{  if (quantite==0)
		{
		fprintf(f2,"%d %s %s \n",identifiant1,produit,quantite);
		}
	}
	fclose(f);
	fclose(f2);
}

////////////////////////////////////////////////////////////////////////////

void afficher_alert_stock(GtkWidget *treeview)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char produit[30];
	int identifiant;
	int quantite;
	store=NULL;

FILE *f;
store = gtk_tree_view_get_model(treeview);

if (store==NULL)
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("produit", renderer, "text", EPRODUIT, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


}
store=gtk_list_store_new(COLUMNS_STOCK, G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT);
f=fopen("stock.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("stock.txt","a+");
		while(fscanf(f,"%d %s %d \n",&identifiant,produit,&quantite)!=EOF)
{
if (quantite==0)
{

  gtk_list_store_append (store, &iter);
  gtk_list_store_set (store, &iter,EID,identifiant,EPRODUIT,produit,EQUANTITE,quantite,-1);
}
  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}



