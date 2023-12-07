#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <ctype.h>
#include <gtk/gtk.h>

typedef struct 
{
    char region [20];
    char nometablissement [20]; 	
    int id, capacite;
} etablissement;

typedef struct
{
    int jour;
    int mois;
    int annee;

}dates;
typedef struct
{
    int rdvid;
    dates date; 
    char cin[9] , cre[7];
    char idets[5];
}rdv;
typedef struct 
{
int numero_don;
char type_de_sang[10];
dates dt_don;
int cin_donneur;
} gestion_dons ;




int pull( int rdvid,char cin[9]);
void add( int rdvid,char cin[9]);

void afficher_rdv1 (GtkWidget *liste,char CIN[9]);
void supprimer_tre2(rdv r,char ch[]);
void afficher_rdv2 (GtkWidget *liste,char ch[],dates d);
void afficher_rdv (GtkWidget *liste,char ch[]);
void supprimer_tre(rdv,char ch[] );
void vider(GtkWidget *liste,char ch[]);
void supprimer_tre1(gestion_dons r);


int id (char *filename, rdv,char ch[] );
int controlle(char *filename, rdv,char CIN[9],char ch[] );
int max(char *filename, rdv,char ch[],int );
int ajouter(char *,rdv ,int choix[],char ch[]);
int modifier( char *, char*,int, rdv,char cha[] ,char ch[],int choix2[]);
int supprimer(char *, char* ,int,char ch[]);
rdv chercher(char *, char*,int,char ch[]);


int historique (char nomFichier[], char CIN[]);
int capacite( char nomFichier[], char ETS[6]); 
int HoraireDispo(char nomFichier[], char ETS[6],int capacite, int jour, int mois , int annee, char horaire[],char ch []);

int controlleD(char CIN[9]);
#endif // POINT_H_INCLUDED
