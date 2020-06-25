#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED


#include<string.h>
#include<string.h>

typedef char chaine[20];

typedef struct{
    chaine nommaladie;
    int nbrannee;
}maladie;

typedef struct cellulemaladie{
    maladie m;
    struct cellulemaladie* suivant;
}cellulemaladie;

typedef cellulemaladie* ListeMaladie;

typedef struct {
    int jour;
    int mois;
    int annee;
}date;

typedef struct{
    chaine Cin;
    chaine Nom;
    chaine Prenom;
    chaine numTel;
    chaine nationalite;
    int age;
    date dateInfection;
    int Decede;
    cellulemaladie* maladies;
}PersonneInfecte;

typedef struct Cellule{
    PersonneInfecte pp;
    struct Cellule* suivant;
}Cellule;

typedef Cellule* ListePersonnesInfectees;

ListePersonnesInfectees chargerPersonnes (chaine  nomFichierPersonnes, chaine nomFichierMaladies){
    FILE* FichierPerso;
    FILE* FichierMal;
    ListePersonnesInfectees l=NULL;
    ListePersonnesInfectees nouveau=NULL;
    ListePersonnesInfectees courant =NULL;
    ListeMaladie nouveau1,courant1;
    PersonneInfecte pp;
    maladie m;
    chaine Cin;
    FichierPerso= fopen(nomFichierPersonnes, "r") ;
    if(FichierPerso==NULL)
        printf("Impossible d'ouvrir le fichier de personne");
    else{
        while(!feof(FichierPerso)){

            fscanf(FichierPerso,"%s %s %s %s %s ",pp.Cin, pp.Nom, pp.Prenom, pp.numTel, pp.nationalite);

            fscanf(FichierPerso,"%d %d %d %d %d ",&pp.age,&pp.dateInfection.jour,&pp.dateInfection.mois,&pp.dateInfection.annee ,&pp.Decede );

            pp.maladies=NULL;
            if(l==NULL){
                nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
                nouveau->pp=pp;
                nouveau->suivant=NULL;
                l=nouveau;
            }else{
                courant=l;
                while(courant->suivant!=NULL)
                    courant=courant->suivant;
                nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
                nouveau->pp=pp;
                courant->suivant=nouveau;
                nouveau->suivant=NULL;
            }
        }
    }
fclose(FichierPerso);

FichierMal=fopen(nomFichierMaladies,"r");
if(FichierMal==NULL)
    printf("Impossible d'ouvrir le fichier de maladies");
else{
    while(!feof(FichierMal)){
        fscanf(FichierMal,"%s",Cin);
        fscanf(FichierMal,"%s",m.nommaladie);
        fscanf(FichierMal,"%d\n",&m.nbrannee);
        courant=l;
        while(courant!=NULL && strcmp(Cin,courant->pp.Cin)!=0)
            courant=courant->suivant;
        if(courant!=NULL){
            courant1=courant->pp.maladies;
        if(courant->pp.maladies==NULL){
            nouveau1=(ListeMaladie)malloc(sizeof(cellulemaladie));
            nouveau1->m=m;
            nouveau1->suivant=NULL;
            courant->pp.maladies=nouveau1;
        }else{
            while(courant1->suivant!=NULL)
                courant1=courant1->suivant;
            nouveau1=(ListeMaladie)malloc(sizeof(cellulemaladie));
            nouveau1->m=m;
            nouveau1->suivant=NULL;
            courant1->suivant=nouveau1;
            }
        }
    }
  }fclose(FichierMal);
return l;
}


void AfficherPersonnesInfectees(ListePersonnesInfectees l){
    ListePersonnesInfectees courant=l;
    ListeMaladie cr1;
    if(l==NULL)
        printf("La liste est vide ");
    else
        while(courant!=NULL){
            printf("%s %s %s %s %s ",courant->pp.Cin,courant->pp.Nom,courant->pp.Prenom,courant->pp.numTel,courant->pp.nationalite);
            printf(" %d %d %d %d %d ",courant->pp.age,courant->pp.dateInfection.jour,courant->pp.dateInfection.mois,courant->pp.dateInfection.annee,courant->pp.Decede);
            cr1=courant->pp.maladies;
            while(cr1!=NULL){
                printf(" %s %d ",cr1->m.nommaladie,cr1->m.nbrannee);
                cr1=cr1->suivant;
            }
            printf("\n\n");
        courant=courant->suivant;
    }
}

ListePersonnesInfectees Ajouter (ListePersonnesInfectees l){
    PersonneInfecte p;
    ListePersonnesInfectees courant=l;
    ListePersonnesInfectees nouveau;
    ListeMaladie n,c;
    maladie m;
    int i,nm;

    printf(" Veuillez Insere le CIN : ");
    scanf("%s",p.Cin);
    printf(" Le Nom :");
    scanf("%s",p.Nom);
    printf(" Le Prenom :");
    scanf("%s",p.Prenom);
    printf("Numero de Tel : ");
    scanf("%s",p.numTel);
    printf("Nationalite EN MAJUSCULE : ");
    scanf("%s",p.nationalite);
    printf(" L'Age :");
    scanf("%d",&p.age);
    printf("Jour d'infection :");
    scanf("%d",&p.dateInfection.jour);
    printf("Mois d'infection : ");
    scanf("%d",&p.dateInfection.mois);
    printf("Anne d'infection : ");
    scanf("%d",&p.dateInfection.annee);
    printf("Decede ? 0 = Non, 1= Oui : ");
    scanf("%d",&p.Decede);

    p.maladies=NULL;
    printf("Nombre Total des maladies : ");
    scanf("%d",&nm);
    for(i=0;i<nm;i++){
            c=p.maladies;
            printf("Nom de la maladie : ");
            scanf("%s",m.nommaladie);
            printf("Nombre d'annee avec ce maladie : ");
            scanf("%d",&m.nbrannee);
            if(c==NULL){
                n=(ListeMaladie)malloc(sizeof(cellulemaladie));
                n->m=m;
                n->suivant=NULL;
                p.maladies=n;
            }else{
                while(c->suivant!=NULL)
                c=c->suivant;
                n=(ListeMaladie)malloc(sizeof(cellulemaladie));
                n->m=m;
                n->suivant=NULL;
                c->suivant=n;
            }
        }
        if(l==NULL){
            nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
            nouveau->pp=p;
            nouveau->suivant=NULL;
            l=nouveau;
        }else{
            while(courant->suivant!=NULL)
               courant=courant->suivant;

        nouveau=(ListePersonnesInfectees)malloc(sizeof(Cellule));
        nouveau->pp=p;
        nouveau->suivant=NULL;
        courant->suivant=nouveau;
    }
return l;
}


ListePersonnesInfectees supprimer (ListePersonnesInfectees l, chaine CIN){

    ListePersonnesInfectees courant=l;
    ListePersonnesInfectees precedant;
    if(l==NULL)
        printf("La liste est vide \n");
    else{
        if(strcmp(l->pp.Cin,CIN)==0){
            l=l->suivant;
            free(courant);
        }
        else{
            while(courant!=NULL&&(strcmp(courant->pp.Cin,CIN)!=0)){
                precedant=courant;
                courant=courant->suivant;
            }
            if(courant==NULL)
                printf("Personne n'existe pas");
            else{
                precedant->suivant=courant->suivant;
                free(courant);
                printf("Suppression effectuer avec succees\n");
            }
        }
    }
return l;
}

ListePersonnesInfectees AjouterMaladie ( ListePersonnesInfectees l, char* CIN, char* maladie, int annees){
    Cellule* courant = l;
    cellulemaladie* courantM;
    cellulemaladie* nouveauM;
    while ( (courant != NULL) && (strcmp(CIN, courant->pp.Cin)!= 0 ) )
        courant = courant->suivant;
    if (courant == NULL)
        printf("Cin n'existe pas");
    else{
        courantM = courant->pp.maladies;
        while ( (courantM->suivant != NULL) && (strcmp (maladie, courantM->m.nommaladie) != 0) ){
            courantM = courantM->suivant;
        }

        if (strcmp (maladie, courantM->m.nommaladie) != 0){
            nouveauM = (cellulemaladie*) malloc(sizeof(cellulemaladie));
            nouveauM->m.nbrannee = annees;
            strcpy(nouveauM->m.nommaladie, maladie);
            nouveauM->suivant = NULL;
            courantM->suivant = nouveauM;
        }
    }
  return l;
}

ListePersonnesInfectees modifierDeces(ListePersonnesInfectees l, chaine CIN){
    ListePersonnesInfectees courant=l;
    if(l==NULL)
        printf("La liste est vide \n");
    else{
        while(courant!=NULL&&(strcmp(courant->pp.Cin,CIN)!=0))
        courant=courant->suivant;
        if(courant==NULL)
        printf("Cin n'existe pas");

        else{
            courant->pp.Decede=1;
            printf("Modification effectuer avec succes\n");
        }
    }
    return l;
}

void afficherParNationalite(ListePersonnesInfectees l, char* Nationalite){
    ListePersonnesInfectees courant=l;
    ListeMaladie cr1;
    if(l==NULL)
        printf("La liste est vide");
    else
        do{
            if(strcmp(Nationalite,courant->pp.nationalite)==0){
                printf("%s %s %s %s %s",courant->pp.Cin,courant->pp.Nom,courant->pp.Prenom,courant->pp.numTel,courant->pp.nationalite);
                printf(" %d %d %d %d %d ",courant->pp.age,courant->pp.dateInfection.jour,courant->pp.dateInfection.mois,courant->pp.dateInfection.annee,courant->pp.Decede);
                cr1=courant->pp.maladies;
                while(cr1!=NULL){
                    printf("%s %d",cr1->m.nommaladie,cr1->m.nbrannee);
                    cr1=cr1->suivant;
                }
            }
        printf("\n");
        courant=courant->suivant;
    }while(courant!=NULL);
}


void afficherPersonnesDecedes (ListePersonnesInfectees l){
    ListePersonnesInfectees courant=l;
    float totalpersonne=0,nbrdecede=0;
    if(l==NULL)
        printf("La liste est vide");
    else
        do{
            if(courant->pp.Decede){
                printf("%s\t%s\n",courant->pp.Nom,courant->pp.Prenom);
                nbrdecede++;
            }
            courant=courant->suivant;
            totalpersonne++;

        }while(courant!=0);
    if(nbrdecede==0){
        printf("\n");
        printf("Heureusement Que le pourcentage de decede est 0\n");
    }else{
        printf("\n");
        printf("Le pourcentage de DECEDE est %.0f%% \n",(nbrdecede/totalpersonne)*100);
        printf("\n");
    }
}

const int nbreJrsParMois[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
int nbreAnneeBisextile (date d){
    int years = d.annee;
    if (d.mois<= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int diffrenceDates (date dt1, date dt2){
    long int n1 = dt1.annee*365 + dt1.jour;
    int i;
    for ( i=0; i<dt1.mois - 1; i++)
        n1 += nbreJrsParMois[i];
    n1 += nbreAnneeBisextile(dt1);

    long int n2 = dt2.annee*365 + dt2.jour;
    for ( i=0; i<dt2.mois - 1; i++)
        n2 += nbreJrsParMois[i];
    n2 += nbreAnneeBisextile(dt2);
return (n2 - n1);
}

void afficherPersonnesEnQuarantaine (ListePersonnesInfectees l, date DateEncours){
    Cellule* courant = l;
    int diffDate = 0;
    if (l == NULL){
        printf("La liste est vide");
    }else{
        while (courant != NULL){
            diffDate = diffrenceDates (courant->pp.dateInfection, DateEncours);
            if (diffDate < 14){
                printf("%s\t%s\n", courant->pp.Nom, courant->pp.Prenom);
            }
            courant = courant->suivant;
        }
    if (diffDate >= 14){
        printf("Personne n'est en Quarantaine\n");
    }
  }
}


void AfficherPersonnesARisque (ListePersonnesInfectees l){
  Cellule* courant = l;
  cellulemaladie* courantM;

  int risque = 0;

  if (l == NULL)
    printf("La liste est vide");
  else{
    printf ("==== >> Les Personnes a Risque sont << ==== \n");
    while (courant != NULL){
        if(courant->pp.age > 70){
            risque += 20;
        }
        else if ( (courant->pp.age <= 70) && (courant->pp.age > 50) ){
        risque += 10;
      }

     courantM = courant->pp.maladies;
     while (courantM != NULL){
         if ( strcmp("DIABETE", courantM->m.nommaladie) == 0){
            risque += 15;
        }
        else if ( strcmp ("HYPERTENSION",courantM->m.nommaladie) == 0)
        {
          risque += 20;
        }
        else if ( strcmp ("ASTHME",courantM->m.nommaladie) == 0)
        {
          risque += 20;
        }

        courantM = courantM->suivant;
      }

      if (risque != 0){
        printf ("%s\t%s\t Risque = %d%%\n", courant->pp.Nom, courant->pp.Prenom, risque);
      }

      courant = courant->suivant;
      risque = 0;

    }
  }

}

void enregistrement(ListePersonnesInfectees l,char * nomFichier,char * nomFichier1){
    FILE *fp;
    FILE *fp1;
    ListePersonnesInfectees courant=l;
    ListeMaladie cr1;
    fp=fopen(nomFichier,"w");
    fp1=fopen(nomFichier1,"w");

 while(courant!=NULL){
      fprintf(fp,"%s %s %s %s %s %d %d %d %d %d\n",courant->pp.Cin,courant->pp.Nom,courant->pp.Prenom,courant->pp.numTel,courant->pp.nationalite,courant->pp.age,courant->pp.dateInfection.jour,courant->pp.dateInfection.mois,courant->pp.dateInfection.annee,courant->pp.Decede);
        cr1=courant->pp.maladies;
        while(cr1!=NULL){
            fprintf(fp1,"%s %s %d\n",courant->pp.Cin,cr1->m.nommaladie,cr1->m.nbrannee);
            cr1=cr1->suivant;
        }
        printf("\n\n");
        courant=courant->suivant;

    }
fclose(fp);
fclose(fp1);
}



#endif // FUNCTIONS_H_INCLUDED
