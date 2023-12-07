#include "RDV.h"
#include<string.h>

int historique (char nomFichier[], char CIN[] )
{   

    FILE *f1 = fopen("stat.txt", "a");
    FILE *f = fopen(nomFichier, "r");
    if (f != NULL && f1 != NULL)
    {  char chaine[9];
        gestion_dons gest;
       int count=0;
        while (fscanf(f, "%d %s %d %d %d %d\n", &gest.numero_don, gest.type_de_sang, &gest.dt_don.jour, &gest.dt_don.mois, &gest.dt_don.annee, &gest.cin_donneur) != EOF)
        {
	sprintf(chaine,"%d",gest.cin_donneur);
            if ( strcmp(chaine,CIN) == 0)
            {
             count++;
            }
        }

        fclose(f);
    
      fprintf(f1,"%s il a donné: %d\n",CIN,count);
      fclose(f1);
return count ;
  
}
return 0 ;
}


int HoraireDispo(char nomFichier[], char ETS[6],int capacite, int jour, int mois , int annee, char horaire[],char ch [])
{

    FILE *f = fopen(nomFichier, "r");
    if (f != NULL)
    {
        rdv temp;
        int  count =0;
        while (fscanf(f, "%d %d %d %d %s %s %s %s\n",&temp.rdvid, &temp.date.jour, &temp.date.mois, &temp.date.annee, temp.cin, temp.cre, temp.idets,ch) != EOF)
        {
            if (temp.date.jour== jour && temp.date.mois == mois && temp.date.annee == annee && strcmp(temp.cre,horaire) == 0 && strcmp(ETS,temp.idets)==0)
            {
               count++;
            }
        }

        fclose(f);
      if(count<capacite)
	return (capacite-count);
 	return 0;
    }

}





int capacite( char nomFichier[], char ETS[]){
FILE *f1 = fopen(nomFichier, "r");
    if (f1 != NULL)
    { etablissement te;
	int t = atoi(ETS);
     while (fscanf(f1, "%s %s %d %d\n", te.region, te.nometablissement ,&te.id ,&te.capacite ) != EOF)
        {
            if (te.id==t)
            {
              fclose(f1);
              return te.capacite; 
                }


         }
fclose(f1);
return 0 ;
}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////












