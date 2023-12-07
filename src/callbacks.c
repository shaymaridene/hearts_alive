#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "RDV.h"


int supp=1;
int choix[4]={0,0,0,0};
int choix2[4]={0,0,0,0};
char ch[70]="",cha[70]="";

void
on_AHD_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Affichageundon,*Espacedonneur ;


	Espacedonneur=lookup_widget(button,"Espacedonneur");
	gtk_widget_destroy(Espacedonneur);
	Affichageundon=create_Affichageundon();
	gtk_widget_show(Affichageundon); 

}


void
on_button_GRV_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionRDV,*Espacedonneur;

	Espacedonneur=lookup_widget(button,"Espacedonneur");
	gtk_widget_destroy(Espacedonneur);

	GestionRDV=create_GestionRDV();
	gtk_widget_show(GestionRDV);
	


}


void
on_button_M_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ModificationRDV,*GestionRDV;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	ModificationRDV=create_ModificationRDV();
	gtk_widget_show(ModificationRDV); 
}


void
on_button_Ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AjouterRDV,*GestionRDV;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	AjouterRDV=create_AjouterRDV();
	gtk_widget_show(AjouterRDV); 

}


void
on_home1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*GestionRDV;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur);
}


void
on_return1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*GestionRDV;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 



}


void
on_button_Supp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *SuppRDV,*GestionRDV;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	SuppRDV=create_SuppRDV();
	gtk_widget_show(SuppRDV); 
}


void
on_return2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionRDV,*ModificationRDV;
	ModificationRDV=lookup_widget(button,"ModificationRDV");
	gtk_widget_destroy(ModificationRDV);
	GestionRDV=create_GestionRDV();
	gtk_widget_show(GestionRDV);
}


void
on_home2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*ModificationRDV;
	ModificationRDV=lookup_widget(button,"ModificationRDV");
	gtk_widget_destroy(ModificationRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 
}


void
on_button_rmod_clicked                 (GtkButton       *button,
                                       gpointer         user_data)
{

	GtkWidget *output,*output1,*output2;
	GtkWidget *ModificationRDV ,*Modificationundonneur;
	GtkWidget *input1, *input2;

	char vide[2] = "";
	char mot4[50] = "introuvable";
	char mot2[55] = "(INVALIDE)";
	
	char CIN[9];int RDVid;
	rdv r;

	ModificationRDV=lookup_widget(button,"ModificationRDV");
	output=lookup_widget(button,"label258_m4");
	output1=lookup_widget(button,"label259_m");
	output2=lookup_widget(button,"label257_mo");
	input1 = lookup_widget(button, "entry_cinRDV");
        input2 = lookup_widget(button, "spinbutton_rdvidM");

	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
	 RDVid =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));

	 r = chercher("RDV.txt", CIN,RDVid,ch);
	if(strcmp(r.cin,"-1")!=0){
        gtk_label_set_text(GTK_LABEL(output), vide);
        gtk_label_set_text(GTK_LABEL(output1), vide);
        gtk_label_set_text(GTK_LABEL(output2), vide);
	add(RDVid,CIN);
 	    Modificationundonneur=create_Modificationundonneur();
	    gtk_widget_show(Modificationundonneur);
		gtk_widget_destroy(ModificationRDV);
}

	else {
        gtk_label_set_text(GTK_LABEL(output), mot2);
        gtk_label_set_text(GTK_LABEL(output1), mot2);
        gtk_label_set_text(GTK_LABEL(output2), mot4);	
	}

}


void
on_home3_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*Modificationundonneur;
	Modificationundonneur=lookup_widget(button,"Modificationundonneur");
	gtk_widget_destroy(Modificationundonneur);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 
}


void
on_return3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Modificationundonneur,*ModificationRDV;
	Modificationundonneur=lookup_widget(button,"Modificationundonneur");
	gtk_widget_destroy(Modificationundonneur);
	ModificationRDV=create_ModificationRDV();
	gtk_widget_show(ModificationRDV);
}


void
on_button_Cmod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{


    
    char mot1[50] = "ECHEC de modification !!!";
    char mot2[55] = "(INVALIDE)";
    char mot3[55] = "Modification avec succés";
    char vide[2] = "";
    char mot6[50] = "Déjà modifier  ";
    char mot5[50] = "Max RDV atteint pour ce créneau";

	 int a,n;
	char cin[9];int rdvid;
	rdv v;
	rdvid=pull(rdvid,cin[9]);

	GtkWidget *input1, *input2, *input3, *input4, *input5 , *input8;
	GtkWidget *Modificationundonneur,*ModificationRDV;
	GtkWidget *output2,*output3,*output4,*output5,*output6,*output7,*output8;
	GtkWidget *ch1,*ch2,*ch3,*ch4;

	Modificationundonneur=lookup_widget(button,"Modificationundonneur");

        input1 = lookup_widget(button, "spinbutton_Jrdv");
        input2 = lookup_widget(button, "spinbutton_mrdv");
        input3 = lookup_widget(button, "spinbutton_ardv");
        input4 = lookup_widget(button, "combobox_creM");
        input5 = lookup_widget(button, "combobox_Midets");
	input8 = lookup_widget(button, "entry1_cinrdvnew");	


	ch1=lookup_widget(button,"checkbutton1_rdv_mod");
	ch2=lookup_widget(button,"checkbutton2_rdv_mod");
	ch3=lookup_widget(button,"checkbutton3_rdv_mod");
	ch4=lookup_widget(button,"checkbutton4_rdv_mod");

	output3=lookup_widget(button,"label260_daterdvm");
	output4=lookup_widget(button,"label261_crerdvm");
	output5=lookup_widget(button,"label262_idetsrdvm");
	output6=lookup_widget(button,"label263_confrdvmb");
	output7=lookup_widget(button,"label258_cinmrdv");
	output8=lookup_widget(button,"label259_chek_rdv_mod");


	strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(input8)));
	v.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input1));
	v.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
	v.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
	strcpy(v.cre,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input4)));
	strcpy(v.idets,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input5)));


    if ((strcmp(v.cre,vide) != 0) && (strcmp(v.idets,vide) != 0)&& (strcmp(v.cin,vide) != 0)&& ((choix2[0]!=0) ||(choix2[1]!=0)||(choix2[2]!=0)||(choix2[3]!=0))) {
               a = controlle("RDV.txt", v, v.cin,ch);
	if (a == 2) {
        gtk_label_set_text(GTK_LABEL(output3), vide);
        gtk_label_set_text(GTK_LABEL(output4), vide);
        gtk_label_set_text(GTK_LABEL(output5), vide);
        gtk_label_set_text(GTK_LABEL(output6), vide);
        gtk_label_set_text(GTK_LABEL(output7), "cin incorrect");
        gtk_label_set_text(GTK_LABEL(output8), vide);
		     }
	else{
        if (a == 1) {
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output4), vide);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
                    gtk_label_set_text(GTK_LABEL(output6), mot6);
		    gtk_label_set_text(GTK_LABEL(output7), vide);
       		    gtk_label_set_text(GTK_LABEL(output8), vide);
		     }

                  else {
		 n=capacite( "etablissement.txt",v.idets );
		    a=max("RDV.txt", v,ch,n);
		if(a==1){
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output4), mot5);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
                    gtk_label_set_text(GTK_LABEL(output6), vide);
		    gtk_label_set_text(GTK_LABEL(output7), vide);
       		    gtk_label_set_text(GTK_LABEL(output8), vide);
		     } 
     		  else {
     		a=modifier("RDV.txt", cin,rdvid,v,cha,ch,choix2);
		   if(a==1){
		choix2[0]=0;
		choix2[1]=0;
		choix2[2]=0;
		choix2[3]=0;
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output4), vide);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
                    gtk_label_set_text(GTK_LABEL(output6), mot3);
		    gtk_label_set_text(GTK_LABEL(output7), vide); 
       		    gtk_label_set_text(GTK_LABEL(output8), vide);	    
		}
		else{
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output4), vide);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
                    gtk_label_set_text(GTK_LABEL(output6), mot1);
		    gtk_label_set_text(GTK_LABEL(output7), vide);
       		    gtk_label_set_text(GTK_LABEL(output8), vide);
		      }}}}
	        						}
else {
                    gtk_label_set_text(GTK_LABEL(output3), mot2);
                    gtk_label_set_text(GTK_LABEL(output4), mot2);
                    gtk_label_set_text(GTK_LABEL(output5), mot2);
                    gtk_label_set_text(GTK_LABEL(output6), mot1);
		    gtk_label_set_text(GTK_LABEL(output7), mot2);
       		    gtk_label_set_text(GTK_LABEL(output8), mot2);
	}                                           

}


void
on_home4_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*AjouterRDV;
	AjouterRDV=lookup_widget(button,"AjouterRDV");
	gtk_widget_destroy(AjouterRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur);
}


void
on_return4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionRDV,*AjouterRDV;
	AjouterRDV=lookup_widget(button,"AjouterRDV");
	gtk_widget_destroy(AjouterRDV);
	GestionRDV=create_GestionRDV();
	gtk_widget_show(GestionRDV); 
}


void
on_button_A_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
    char vide[2] = "";
    GtkWidget *output;
    GtkWidget *output1;
    GtkWidget *output2;
    GtkWidget *output3;
    GtkWidget *output4,*output5;
	GtkWidget *ch1,*ch2,*ch3,*ch4;

    char mot1[50] = "Ajout avec succès";
    char mot2[50] = "ECHEC d'ajout  ";
    char mot3[50] = "Déjà ajoutée  ";
    char mot4[20] = "(INVALIDE)";
    char mot5[50] = "Il faut choisir un créneau ";

    output = lookup_widget(button, "label252");
    output1 = lookup_widget(button, "label253");
    output2 = lookup_widget(button, "label254");
    output3 = lookup_widget(button, "label255");
    output4 = lookup_widget(button, "label256");
    output5 = lookup_widget(button, "label261_rdv_A");
	ch1=lookup_widget(button,"checkbutton5_rdv_A");
	ch2=lookup_widget(button,"checkbutton6_rdv_A");
	ch3=lookup_widget(button,"checkbutton7_rdv_A");
	ch4=lookup_widget(button,"checkbutton8_rdv_A");


    int a,n;
    rdv v;
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
    GtkWidget *AjouterRDV;

    AjouterRDV = lookup_widget(button, "AjouterRDV");
    input1 = lookup_widget(button, "spinbutton_jjA");
    input2 = lookup_widget(button, "spinbutton_mmA");
    input3 = lookup_widget(button, "spinbutton_aaA");
    input4 = lookup_widget(button, "entry_cinA");
    input5 = lookup_widget(button, "combobox_Aidets");
    input6 = lookup_widget(button, "combobox_creA");
        


	strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
	v.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input1));
	v.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
	v.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
	strcpy(v.cre,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input6)));
	strcpy(v.idets,gtk_combo_box_get_active_text(GTK_COMBO_BOX (input5)));

    if ((strcmp(v.cin,vide) != 0) && (strcmp(v.cre,vide) != 0) && (strcmp(v.idets,vide) != 0)&&((choix[0]!=0) ||(choix[1]!=0)||(choix[2]!=0)||(choix[3]!=0))) {
               a = controlle("RDV.txt", v,v.cin,ch);
	if (a == 2) {
        gtk_label_set_text(GTK_LABEL(output), vide);
        gtk_label_set_text(GTK_LABEL(output1), vide);
        gtk_label_set_text(GTK_LABEL(output2), "cin incorrect");
        gtk_label_set_text(GTK_LABEL(output3), vide);
        gtk_label_set_text(GTK_LABEL(output4), vide);
        gtk_label_set_text(GTK_LABEL(output5), vide);
		     }
	else{
        if (a == 1) {
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output4), mot3);
                    gtk_label_set_text(GTK_LABEL(output), vide);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
		     }

                  else {	
		 n=capacite( "etablissement.txt",v.idets );
		    a=max("RDV.txt", v,ch,n);
		if(a==1){
                    gtk_label_set_text(GTK_LABEL(output4), vide);
                    gtk_label_set_text(GTK_LABEL(output1), "Max RDV atteint pour ce créneau");
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output), vide);
        	    gtk_label_set_text(GTK_LABEL(output5), vide);
		     } 
     		  else {
		v.rdvid =id ("RDV.txt", v,ch);
     		a=ajouter("RDV.txt", v,choix,ch);
		   if(a==1){
		choix[0]=0;
		choix[1]=0;
		choix[2]=0;
		choix[3]=0;
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output4), mot1);
                    gtk_label_set_text(GTK_LABEL(output), vide);
        	    gtk_label_set_text(GTK_LABEL(output5), vide);
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input1), 0);
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input2), 0);
		    gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3), 0);
                    gtk_entry_set_text(GTK_ENTRY(input4), vide);
                    gtk_combo_box_set_active(GTK_COMBO_BOX (input5),0);
                    gtk_combo_box_set_active(GTK_COMBO_BOX (input6),0);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch1),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch2),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch3),FALSE);
		    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ch4),FALSE);
   

		      }}}}
	        						}
	else {
        gtk_label_set_text(GTK_LABEL(output), mot4);
        gtk_label_set_text(GTK_LABEL(output1), mot5);
        gtk_label_set_text(GTK_LABEL(output2), mot4);
        gtk_label_set_text(GTK_LABEL(output3), mot4);
        gtk_label_set_text(GTK_LABEL(output4), mot2);
        gtk_label_set_text(GTK_LABEL(output5), mot4);
    }
}


void
on_home5_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*SuppRDV;
	SuppRDV=lookup_widget(button,"SuppRDV");
	gtk_widget_destroy(SuppRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 
}


void
on_return5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GestionRDV,*SuppRDV;
	SuppRDV=lookup_widget(button,"SuppRDV");
	gtk_widget_destroy(SuppRDV);
	GestionRDV=create_GestionRDV();
	gtk_widget_show(GestionRDV); 
}


void
on_button_supp1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{  
    char mot1[50] = "ECHEC de supp";
    char mot2[55] = "(INVALIDE)";
    char vide[2] = "";
	rdv r;
	char CIN[9];int RDVid;
	GtkWidget *input1,*input2,*output,*output1,*output2;
	GtkWidget *AssurerSuppRDV;
	GtkWidget *SuppRDV;

	SuppRDV=lookup_widget(button,"SuppRDV");
	input1=lookup_widget(button,"entry_cinS");
        input2 = lookup_widget(button, "spinbutton_rdvidS");

	output=lookup_widget(button,"label258_idrdvsup");
	output1=lookup_widget(button,"label257_cnisup");
	output2=lookup_widget(button,"label259_supp");

	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
	 RDVid = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
	 r = chercher("RDV.txt", CIN,RDVid,ch);
	if(strcmp(r.cin,"-1")!=0){
        gtk_label_set_text(GTK_LABEL(output), vide);
        gtk_label_set_text(GTK_LABEL(output1), vide);
        gtk_label_set_text(GTK_LABEL(output2), vide);
 	    AssurerSuppRDV=create_AssurerSuppRDV();
	    gtk_widget_show(AssurerSuppRDV);
	add(RDVid,CIN);}
	else {
        gtk_label_set_text(GTK_LABEL(output), mot2);
        gtk_label_set_text(GTK_LABEL(output1), mot2);
        gtk_label_set_text(GTK_LABEL(output2), mot1);	
	}


}


void
on_return6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AssurerSuppRDV,*SuppRDV;
	AssurerSuppRDV=lookup_widget(button,"AssurerSuppRDV");
	gtk_widget_destroy(AssurerSuppRDV);
	SuppRDV=create_SuppRDV();
	gtk_widget_show(SuppRDV); 
}


void
on_home6_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AssurerSuppRDV,*Espacedonneur;
	AssurerSuppRDV=lookup_widget(button,"AssurerSuppRDV");
	gtk_widget_destroy(AssurerSuppRDV);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur);
}


void
on_button_Csupp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *AssurerSuppRDV;
	GtkWidget *SuppRDV;
	char cin[9];int rdvid;
	rdvid=pull(rdvid,cin[9]);
	if(supp==1){
	supprimer("RDV.txt",cin[9],rdvid,ch);}
	AssurerSuppRDV=lookup_widget(button,"AssurerSuppRDV");
	gtk_widget_destroy(AssurerSuppRDV);
	supp =1;



}


void
on_button_adc_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{


	GtkWidget *input1,*input2,*input3;
	GtkWidget *Affichageundon,*Afficheur_don_RDV;
	Affichageundon = lookup_widget(button,"Affichageundon");

	input1=lookup_widget(button,"spinbutton_jjD");
        input2 = lookup_widget(button, "spinbutton_mmD");
        input3 = lookup_widget(button, "spinbutton_aaD");
	dates d ; 
	d.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input1));
	d.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input2));
	d.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (input3));


	Afficheur_don_RDV=lookup_widget(Affichageundon,"AfficheurdonRDV");
	 afficher_rdv2 (Afficheur_don_RDV,ch,d);
}


void
on_return7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*Affichageundon;
	Affichageundon=lookup_widget(button,"Affichageundon");
	gtk_widget_destroy(Affichageundon);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 
}


void
on_home7_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Espacedonneur,*Affichageundon;
	Affichageundon=lookup_widget(button,"Affichageundon");
	gtk_widget_destroy(Affichageundon);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur);
}


void
on_radiobutton_supp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
supp = 1;
}
}


void
on_radiobutton_A_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
supp = 2;
}

}


void
on_historique_RDV_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* rdvid;
	gchar* cre;
	gchar* idets;
	gchar* cin;
	gint* jour;
	gint* mois;
	gint* annee;


	rdv r;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview) ;

	if (gtk_tree_model_get_iter(model, &iter, path) ){

		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &rdvid, 1, &jour, 2,&mois,3,&annee,4,&cin,5,&cre,6,&idets,-1);
		r.rdvid = rdvid;
		r.date.jour = jour;
		r.date.mois = mois;
		r.date.annee = annee;
		strcpy(r.cin,cin) ;
		strcpy(r.cre,cre);
		strcpy(r.idets,idets) ;

		supprimer_tre(r,ch);
		afficher_rdv(treeview,ch) ;
}
}

void
on_AfficheurdonRDV_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint* rdvid;
	gchar* cre;
	gchar* idets;
	gchar* cin;
	gint* jour;
	gint* mois;
	gint* annee;

	dates d;
	rdv r;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview) ;

	if (gtk_tree_model_get_iter(model, &iter, path) ){

		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &rdvid, 1, &jour, 2,&mois,3,&annee,4,&cin,5,&cre,6,&idets,-1);
		r.rdvid = rdvid;
		r.date.jour = jour;
		r.date.mois = mois;
		r.date.annee = annee;
		strcpy(r.cin,cin) ;
		strcpy(r.cre,cre);
		strcpy(r.idets,idets) ;

		supprimer_tre(r,ch);
		afficher_rdv2(treeview,ch,d) ;
}
}
void
on_button1_hist_rdv_gest_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *GestionRDV,*historique_RDV;
	GestionRDV = lookup_widget(button,"GestionRDV");
	historique_RDV=lookup_widget(GestionRDV,"historique_RDV");
	 afficher_rdv (historique_RDV,ch);
}


void
on_checkbutton4_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix2[3]=1;
}
}


void
on_checkbutton2_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix2[1]=1;
}
}


void
on_checkbutton1_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix2[0]=1;
}
}


void
on_checkbutton3_rdv_mod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix2[2]=1;
}
}


void
on_checkbutton6_rdv_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[1]=1;
}
}


void
on_checkbutton5_rdv_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[0]=1;
}
}


void
on_checkbutton7_rdv_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[2]=1;
}
}


void
on_checkbutton8_rdv_A_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
choix[3]=1;
}
}


void
on_button1_stat_rdv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *rdv_stat,*GestionRDV ;
	GestionRDV=lookup_widget(button,"GestionRDV");
	gtk_widget_destroy(GestionRDV);
	rdv_stat=create_rdv_stat();
	gtk_widget_show(rdv_stat); 
}


void
on_button2_rdv_home_stat_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *rdv_stat,*GestionRDV ;
	rdv_stat=lookup_widget(button,"rdv_stat");
	gtk_widget_destroy(rdv_stat);
	GestionRDV=create_GestionRDV();
	gtk_widget_show(GestionRDV);          

}


void
on_button3_rdv_home_stat_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *rdv_stat,*Espacedonneur ;
	rdv_stat=lookup_widget(button,"rdv_stat");
	gtk_widget_destroy(rdv_stat);
	Espacedonneur=create_Espacedonneur();
	gtk_widget_show(Espacedonneur); 

}


void
on_button4_rdv_stat_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{



    char vide[2] = "";
    GtkWidget *output;
    GtkWidget *output1;
    GtkWidget *output2;
    GtkWidget *output3;
    GtkWidget *output4,*output5,*output6;

    char mot1[50] = "introuvable";
    char mot2[20] = "(INVALIDE)";
 
    output = lookup_widget(button, "label271_rdv_jjmmaa_stat");
    output1 = lookup_widget(button, "label270_rdv_cin_stat");
    output2 = lookup_widget(button, "label269_rdv_idets_stat");
    output3 = lookup_widget(button, "label268_rdv_cre_stat");
    output4 = lookup_widget(button, "label261_rdv_stat_count");
    output5 = lookup_widget(button, "label262_rdv_stat_capacite");
    output6 = lookup_widget(button, "label263_rdv_stat_dispo");

    int a,n; char b [150],c[150],d[150];char s [50];
    rdv v;
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6;
    GtkWidget *rdv_stat;

    rdv_stat = lookup_widget(button, "rdv_stat");
    input1 = lookup_widget(button, "spinbutton1_rdv_stat_jj");
    input2 = lookup_widget(button, "spinbutton2_rdv_stat_mm");
    input3 = lookup_widget(button, "spinbutton3rdv_stat_aa");
    input4 = lookup_widget(button, "entry1_rdv_stat_cin");
    input5 = lookup_widget(button, "entry2_rdv_stat_idest");
    input6 = lookup_widget(button, "entry3_rdv_stat_cre");
        


	strcpy(v.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
	v.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input1));
	v.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input2));
	v.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
	strcpy(v.cre,gtk_entry_get_text(GTK_ENTRY (input6)));
	strcpy(v.idets,gtk_entry_get_text(GTK_ENTRY (input5)));

    if ((strcmp(v.cin,vide) != 0) && (strcmp(v.cre,vide) != 0) && (strcmp(v.idets,vide) != 0)) {
              a = controlleD(v.cin);
	if (a == 2) {
        gtk_label_set_text(GTK_LABEL(output), vide);
        gtk_label_set_text(GTK_LABEL(output1), vide);
        gtk_label_set_text(GTK_LABEL(output2), "cin incorrect");
        gtk_label_set_text(GTK_LABEL(output3), vide);
        gtk_label_set_text(GTK_LABEL(output4), vide);
        gtk_label_set_text(GTK_LABEL(output5), vide);
        gtk_label_set_text(GTK_LABEL(output6), vide);
		     }
	else{
		a = historique ("dons.txt", v.cin );

        if (a == 0) {
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output4), mot1);
                    gtk_label_set_text(GTK_LABEL(output), vide);
                    gtk_label_set_text(GTK_LABEL(output5), vide);
       		    gtk_label_set_text(GTK_LABEL(output6), vide);
		     }

                  else if (a!=0){
		sprintf(s,"%d",a);
		strcpy (b , "Mr/Mme de cin : ");
		strcat (b , v.cin);
		strcat (b," a donné(e) : ");
		strcat (b,s);
		strcat (b," Fois");

		n=capacite( "etablissement.txt",v.idets );
		if(n==0){
                    gtk_label_set_text(GTK_LABEL(output4), b);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output), vide);
        	    gtk_label_set_text(GTK_LABEL(output5), mot1);
       		    gtk_label_set_text(GTK_LABEL(output6), vide);
		     } 
     		  else if (n!=0) {
		sprintf(s,"%d",n);
		strcpy (c,"La capacité d'etablissement d'identifiant ");
		strcat (c,v.idets);
		strcat (c," est : ");
		strcat (c,s);

		a=HoraireDispo("RDV.txt",v.idets,n, v.date.jour,v.date.mois  ,v.date.annee , v.cre,ch);
		   if(a==0){
		    strcpy (d,"C et établissement est complet.");

                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output4), b);
                    gtk_label_set_text(GTK_LABEL(output), vide);
        	    gtk_label_set_text(GTK_LABEL(output5), c);
       		    gtk_label_set_text(GTK_LABEL(output6), d);
		      }
		   else{
		sprintf(s,"%d",a);
		strcpy (d,"L'espace disponnible dans cette etablissement est : ");
		strcat (d,s);
                    gtk_label_set_text(GTK_LABEL(output3), vide);
                    gtk_label_set_text(GTK_LABEL(output1), vide);
                    gtk_label_set_text(GTK_LABEL(output2), vide);
                    gtk_label_set_text(GTK_LABEL(output4), b);
                    gtk_label_set_text(GTK_LABEL(output), vide);
        	    gtk_label_set_text(GTK_LABEL(output5), c);
       		    gtk_label_set_text(GTK_LABEL(output6), d);
		      }}}}
	        						}
	else {
        gtk_label_set_text(GTK_LABEL(output), mot2);
        gtk_label_set_text(GTK_LABEL(output1), mot2);
        gtk_label_set_text(GTK_LABEL(output2), mot2);
        gtk_label_set_text(GTK_LABEL(output3), mot2);
        gtk_label_set_text(GTK_LABEL(output4), vide);
        gtk_label_set_text(GTK_LABEL(output5), vide);
        gtk_label_set_text(GTK_LABEL(output6), vide);
    }


}




void
on_treeview1_tree_don_cin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gint numero_don;
	gchar* type_de_sang;
	gint jour;
	gint mois;
	gint annee;
	gint cin_donneur;

	char d[9];
	gestion_dons r;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview) ;

	if (gtk_tree_model_get_iter(model, &iter, path) ){

		gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &numero_don, 1, &type_de_sang, 2,&jour,3,&mois,4,&annee,5,&cin_donneur,-1);
		r.numero_don = numero_don;
		strcpy(r.type_de_sang,type_de_sang) ;
		r.dt_don.jour = jour;
		r.dt_don.mois = mois;
		r.dt_don.annee = annee;
		r.cin_donneur= cin_donneur;

		supprimer_tre1(r);
		afficher_rdv1(treeview,d) ;}
}


void
on_button1_tree_don_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;
	GtkWidget *Affichageundon,*treeview1_tree_don_cin;
	Affichageundon = lookup_widget(button,"Affichageundon");
	input1=lookup_widget(button,"entry1_cin_tree_don");
	output=lookup_widget(button,"label259_tree_cin_don");
	int a;

	char CIN[9];
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
if (strcmp(CIN,"")!=0){
              a = controlleD(CIN);
	if(a!=2){
         gtk_label_set_text(GTK_LABEL(output), "");
	treeview1_tree_don_cin=lookup_widget(Affichageundon,"treeview1_tree_don_cin");
	 afficher_rdv1 (treeview1_tree_don_cin,CIN);}
	else{
         gtk_label_set_text(GTK_LABEL(output), "cin incorrect");
}
}else{
         gtk_label_set_text(GTK_LABEL(output), "(INVALIDE)");

}
}


