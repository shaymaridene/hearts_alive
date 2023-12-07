#include "RDV.h"
#include<string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <config.h>
enum{
	ERDVID ,
	EJOUR ,
	EMOIS ,
	EANNEE, 
	ECIN,
	ECRE,
	EIDETS,
	COLUMNS,
};

enum{
	EDON ,
	ESANG ,
	EJOURD ,
	EMOISD ,
	EANNEED,
	ECIND,
	COLUMNSD,
};


int controlleD(char CIN[9])
{
int count=0, not =0;
for (int i = 0 ; i < 8 ; i ++){
	if (CIN[i]>47 && CIN[i]<58)
	count ++;
}

for (int i = 1 ; i < 8 ; i ++){
	if (CIN[i]==CIN[i-1])
	not++;
}
if (count == 8 && not != 7 )
{          
              return 1;}
else{
return 2;
}}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int pull( int rdvid,char cin[9]){
   FILE *f = fopen("add.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%d",&rdvid);
        fclose(f);
    }
	remove("add.txt");
	return rdvid;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
void add( int rdvid,char cin[9]){
   FILE *f = fopen("add.txt", "w");
    if (f != NULL)
    {
        fprintf(f, "%d",rdvid);
        fclose(f); 
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////
int controlle(char *filename, rdv d,char CIN[9],char ch[])
{
int count=0, not =0;
for (int i = 0 ; i < 8 ; i ++){
	if (CIN[i]>47 && CIN[i]<58)
	count ++;
}

for (int i = 1 ; i < 8 ; i ++){
	if (CIN[i]==CIN[i-1])
	not++;
}
if (count == 8 && not != 7 )
{
 FILE *f = fopen(filename, "a+");
    if (f != NULL)
    { rdv te;
     rewind(f);
     while (fscanf(f, "%d %d %d %d %s %s %s %s\n",&te.rdvid, &te.date.jour, &te.date.mois, &te.date.annee, te.cin, te.cre, te.idets,ch) != EOF)
        {
            if (te.date.jour == d.date.jour && te.date.mois == d.date.mois && te.date.annee == d.date.annee && strcmp(te.cin, d.cin) == 0 )
            {
              fclose(f);
              return 1; 
            }
        }      
    }
}
else{
return 2;}
return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

int max(char *filename, rdv d,char ch[],int n)
{
    FILE *f = fopen(filename, "a+");
    if (f != NULL)
    {	
        rdv temp;
        int  count =0;
	        rewind(f);
        while (fscanf(f, "%d %d %d %d %s %s %s %s\n",&temp.rdvid, &temp.date.jour, &temp.date.mois, &temp.date.annee, temp.cin, temp.cre, temp.idets,ch) != EOF)
        {
            if (temp.date.jour == d.date.jour && temp.date.mois == d.date.mois && temp.date.annee == d.date.annee && strcmp(temp.idets,d.idets) == 0 && strcmp(temp.cre, d.cre) == 0)
            {
                count++;
                if (count >= n)
                {
                    fclose(f);
                    return 1; 
                }
            }
        }

    }
        fclose(f);
        return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

int id (char *filename, rdv d,char ch[])
{
    FILE *f1 = fopen(filename, "r");
    if (f1 != NULL)
    { rdv f;
     int m=0;
     while (fscanf(f1, "%d %d %d %d %s %s %s %s\n",&f.rdvid, &f.date.jour, &f.date.mois, &f.date.annee, f.cin, f.cre, f.idets,ch) != EOF)
        {
         m=1;
 	}
        if(m==0)
        d.rdvid=0;
        else
        d.rdvid = f.rdvid;
        
	fclose(f1); 
	return d.rdvid;   
     }
return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

int ajouter(char *filename, rdv d,int choix[],char ch[])
{	strcpy(ch,"");
	if (choix[0]==1)
		strcat(ch,"/Matin/");
	if (choix[1]==1)
		strcat(ch,"/Milieu-de-journée/");
	if (choix[2]==1)
		strcat(ch,"/Après-midi/"); 
	if (choix[3]==1)
		strcat(ch,"/Soirée/"); 

    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
	++d.rdvid;
	
        fprintf(f, "%d %d %d %d %s %s %s %s\n",d.rdvid, d.date.jour, d.date.mois, d.date.annee, d.cin, d.cre, d.idets,ch);
        fclose(f);
        return 1; 
    }
    else
       return 0; 
   
}



////////////////////////////////////////////////////////////////////////////////////////////////////////

int modifier(char *filename, char cin[],int rdvid, rdv nouv,char cha[] ,char ch[],int choix2[])
 {	
	strcpy(cha,"");
	if (choix2[0]==1)
		strcat(cha,"/Matin/");
	if (choix2[1]==1)
		strcat(cha,"/Milieu-de-journée/");
	if (choix2[2]==1)
		strcat(cha,"/Après-midi/"); 
	if (choix2[3]==1)
		strcat(cha,"/Soirée/"); 

        rdv t; 
	int tr =0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f,"%d %d %d %d %s %s %s %s\n",&t.rdvid, &t.date.jour, &t.date.mois, &t.date.annee, t.cin, t.cre, t.idets,ch) != EOF)
        {
            if ( rdvid==t.rdvid){
                fprintf(f2, "%d %d %d %d %s %s %s %s\n",t.rdvid, nouv.date.jour, nouv.date.mois, nouv.date.annee, nouv.cin, nouv.cre, nouv.idets,cha);
                tr=1;
                }
              else
                fprintf(f2, "%d %d %d %d %s %s %s %s\n",t.rdvid, t.date.jour, t.date.mois, t.date.annee, t.cin, t.cre, t.idets,ch);
        }

        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

int supprimer(char * filename, char cin[], int rdvid,char ch[])
{
    int tr=0;
    rdv d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %s %s\n",&d.rdvid, &d.date.jour, &d.date.mois, &d.date.annee, d.cin, d.cre, d.idets,ch)!=EOF)
        {
            if( rdvid==d.rdvid)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %s %s\n",d.rdvid,d.date.jour,d.date.mois,d.date.annee,d.cin,d.cre,d.idets,ch);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

rdv chercher(char * filename, char cin[],int rdvid,char ch[])
{
    rdv d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {    
        while(tr==0&& fscanf(f,"%d %d %d %d %s %s %s %s\n",&d.rdvid, &d.date.jour, &d.date.mois, &d.date.annee, d.cin, d.cre, d.idets,ch)!=EOF)
        {
            if(strcmp(d.cin,cin)==0 && rdvid == d.rdvid)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(d.cin,"-1");
    return d;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_rdv (GtkWidget *liste,char ch[]){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
    	

	int rdvid; 
    	int jour;  
   	int mois;  
    	int annee; 
    	char cin[9] , cre[6];
    	char idets[5];
	store =NULL;


	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID rdv",renderer,"text",ERDVID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("crénaux",renderer,"text",ECRE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID ets",renderer,"text",EIDETS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	
	}
	store=gtk_list_store_new (COLUMNS ,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("RDV.txt", "r");
	if (f==NULL){
		return;
	}
	else {
		f=fopen("RDV.txt", "a+");
		while (fscanf(f,"%d %d %d %d %s %s %s %s\n",&rdvid, &jour, &mois, &annee,cin,cre,idets,ch)!=EOF){

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store ,&iter ,ERDVID ,rdvid ,EJOUR, jour ,EMOIS,mois,EANNEE ,annee ,ECIN, cin ,ECRE,cre,EIDETS,idets,-1);
	}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);


}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////



void supprimer_tre(rdv r,char ch[])
{

	int rdvid;
    	int jour;
   	int mois;
    	int annee;
    	char cin[9] , cre[6];
    	char idets[5];


	rdv r2;
	FILE *f,*g;
	f=fopen("RDV.txt","r");
	g=fopen("dumb.txt","w");
	if (f==NULL || g==NULL){
		return;
	}
	else {
		while(fscanf(f,"%d %d %d %d %s %s %s %s\n",&r2.rdvid,&r2.date.jour,&r2.date.mois,&r2.date.annee,r2.cin,r2.cre,r2.idets,ch)!=EOF){
			if (r.rdvid != r2.rdvid ||r.date.jour != r2.date.jour ||r.date.mois != r2.date.mois ||r.date.annee != r2.date.annee || strcmp(r.cin,r2.cin)!=0|| strcmp(r.cre,r2.cre)!=0 || strcmp(r.idets,r2.idets)!=0)
				fprintf(g,"%d %d %d %d %s %s %s\n",r2.rdvid,r2.date.jour,r2.date.mois,r2.date.annee,r2.cin,r2.cre,r2.idets,ch);
		}

	} 
	fclose(f);
	fclose(g);
	remove("RDV.txt");
	rename("dumb.txt","RDV.txt");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_rdv1 (GtkWidget *liste,char CIN[9]){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
    	
	char cin[9];
	gestion_dons gest;
	store = NULL;


	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("numero_don",renderer,"text",EDON,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("type_de_sang",renderer,"text",ESANG,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOURD,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOISD,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEED,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin_donneur",renderer,"text",ECIND,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	
	}
	store=gtk_list_store_new (COLUMNSD ,G_TYPE_INT,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	f=fopen("dons.txt", "r");
	if (f==NULL){
		return;
	}
	else {
		f=fopen("dons.txt", "a+");
		while (fscanf(f, "%d %s %d %d %d %d\n", &gest.numero_don, gest.type_de_sang, &gest.dt_don.jour, &gest.dt_don.mois, &gest.dt_don.annee, &gest.cin_donneur)!=EOF){
sprintf(cin,"%d",gest.cin_donneur);
	if(strcmp(CIN,cin)==0){
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store ,&iter ,EDON ,gest.numero_don ,ESANG, gest.type_de_sang ,EJOURD,gest.dt_don.jour,EMOISD ,gest.dt_don.mois ,EANNEED, gest.dt_don.annee ,ECIND,gest.cin_donneur,-1);
	}}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);


}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void supprimer_tre1(gestion_dons r)
{

	gestion_dons gest;
	FILE *f,*g;
	f=fopen("dons.txt","r");
	g=fopen("dumb.txt","w");
	if (f==NULL || g==NULL){
		return;
	}
	else {
		while(fscanf(f, "%d %s %d %d %d %d\n", &gest.numero_don, gest.type_de_sang, &gest.dt_don.jour, &gest.dt_don.mois, &gest.dt_don.annee, &gest.cin_donneur)!=EOF){
			if (gest.numero_don != r.numero_don ||gest.dt_don.jour != r.dt_don.jour ||gest.dt_don.mois != r.dt_don.mois ||gest.dt_don.annee != r.dt_don.annee || strcmp(gest.type_de_sang,r.type_de_sang)!=0||gest.cin_donneur != r.cin_donneur)
				fprintf(g, "%d %s %d %d %d %d\n", gest.numero_don, gest.type_de_sang, gest.dt_don.jour, gest.dt_don.mois, gest.dt_don.annee, gest.cin_donneur);
		}

	} 
	fclose(f);
	fclose(g);
	remove("dons.txt");
	rename("dumb.txt","dons.txt");
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void afficher_rdv2 (GtkWidget *liste,char ch[],dates d){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
    	

	int rdvid; 
    	int jour;  
   	int mois;  
    	int annee; 
    	char cin[9] , cre[6];
    	char idets[5];
	store =NULL;


	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID rdv",renderer,"text",ERDVID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",ECIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("crénaux",renderer,"text",ECRE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("ID ets",renderer,"text",EIDETS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	

	
	}
	store=gtk_list_store_new (COLUMNS ,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("RDV.txt", "r");
	if (f==NULL){
		return;
	}
	else {
		f=fopen("RDV.txt", "a+");
		while (fscanf(f,"%d %d %d %d %s %s %s %s\n",&rdvid, &jour, &mois, &annee,cin,cre,idets,ch)!=EOF){
if(jour==d.jour && mois==d.mois && annee==d.annee){
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store ,&iter ,ERDVID ,rdvid ,EJOUR, jour ,EMOIS,mois,EANNEE ,annee ,ECIN, cin ,ECRE,cre,EIDETS,idets,-1);
	}}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);


}
}


/////////////////////////////////////////////////////////////////////////////////////////////////


void supprimer_tre2(rdv r,char ch[])
{

	int rdvid;
    	int jour;
   	int mois;
    	int annee;
    	char cin[9] , cre[6];
    	char idets[5];


	rdv r2;
	FILE *f,*g;
	f=fopen("RDV.txt","r");
	g=fopen("dumb.txt","w");
	if (f==NULL || g==NULL){
		return;
	}
	else {
		while(fscanf(f,"%d %d %d %d %s %s %s %s\n",&r2.rdvid,&r2.date.jour,&r2.date.mois,&r2.date.annee,r2.cin,r2.cre,r2.idets,ch)!=EOF){
			if (r.rdvid != r2.rdvid ||r.date.jour != r2.date.jour ||r.date.mois != r2.date.mois ||r.date.annee != r2.date.annee || strcmp(r.cin,r2.cin)!=0|| strcmp(r.cre,r2.cre)!=0 || strcmp(r.idets,r2.idets)!=0)
				fprintf(g,"%d %d %d %d %s %s %s %s\n",r2.rdvid,r2.date.jour,r2.date.mois,r2.date.annee,r2.cin,r2.cre,r2.idets,ch);
		}

	} 
	fclose(f);
	fclose(g);
	remove("RDV.txt");
	rename("dumb.txt","RDV.txt");
}

