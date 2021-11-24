///================les includes================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>


///===============les declarations=============
 typedef struct
 {
int num;
    char nom[30],prenom[30];
    char sexe;
    int age;
 }Client;//déclaration d'une variable globale de type structure de nom Client avec les champs 2 chaines de carctères pour le nom et le prénom et 1 entier pour l'age et un caractère pour le sexe
 Client *cl, c;//déclaration de deux variables globales de type Client l'une sous forme de pointeur et l'autre sous forme normale
 typedef struct 
 {
    char nom_train[4];
    char classe[14];
    int num;
 }Ticket;//déclaration d'une variable globale de type structure de nom Ticket avec les champs 2 chaines de carctères pour le nom du train et la classe et 1 entier pour le numéro du train
 Ticket *ti, t;//déclaration de deux variables globales de type Ticket l'une sous forme de pointeur et l'autre sous forme normale                           
  int i=0;   //déclaration et initalisation par 0 d'une variable globale, on a declaré ce comteur (i) comme variable globale pour qu'on puisse suivre 
            //tout changement  de la taille des données saisies sans utiliser des méthodes plus complexes
 /*****************************************************
 *              FONCTION SAISIE INITIALE DES CLIENTS
 ******************************************************/
void saisie_clients(Client *c, Ticket *t, int taille)
{
	FILE *FICH_CLIE=fopen("FICH_CLIENT.txt", "a");
FILE *FICH_TICK=fopen("FICH_TICKET.txt", "a");//ouverture des 2 fichiers en mode écriture
c=(Client*)malloc(taille*sizeof(Client));//réservation d'un espace mémoire de taille (taille) pour le tableau dynamique c
t=(Ticket*)malloc(taille*sizeof(Ticket));//réservation d'un espace mémoire de taille (taille) pour le tableau dynamique t
while(i<taille){//répéter cette boucle tant que i qui est initialisé par 0 est inférieure à taille
printf("Saisir les informations du client et de son ticket :  \n");
fflush(stdin);// Nettoyage de l'entree
printf("Nom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
gets((c+i)->nom);//demande l'utilisateur de saisir le nom et le stocke dans le champs nom pour (c+i)
printf("Prenom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
fflush(stdin);// Nettoyage de l'entree
gets((c+i)->prenom);//demande l'utilisateur de saisir le prenom et le stocke dans le champs prenom pour (c+i)
printf("Sexe : ");
scanf("%2c", &(c+i)->sexe);//demande l'utilisateur de saisir le sexe et le stocke dans le champs sexe pour (c+i)
printf("Age : ");
scanf("%d", &((c+i)->age));//demande l'utilisateur de saisir le sexe et le stocke dans le champs sexe pour (c+i)
fflush(stdin);// Nettoyage de l'entree
printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
gets(((t+i)->nom_train));//demande l'utilisateur de saisir le nom du train et le stocke dans le champs nom_train pour (t+i)
while(strcmp((t+i)->nom_train,"tr1")!=0 && strcmp((t+i)->nom_train,"tr2")!=0 && strcmp((t+i)->nom_train,"tr3")!=0 && strcmp((t+i)->nom_train,"tr4")!=0 && strcmp((t+i)->nom_train,"tr5")!=0){
    printf("Erreur, le train saisi est introuvable.\n");
    printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
    gets((t+i)->nom_train);
}//tant que le choix du train de l'utilisateur est hors les 5 trains valables on lui redemande d'entrée un train valide avec cette boucle
fflush(stdin);// Nettoyage de l'entree
printf("Classe de voyage : 1ere 2eme ou economique ?  ");
gets((t+i)->classe);
while(strcmp((t+i)->classe,"1ere")!=0 && strcmp((t+i)->classe,"2eme")!=0 && strcmp((t+i)->classe,"economique")!=0){
    printf("Erreur, la classe saisie est introuvable.\n");
    printf("Classe de voyage : 1ere 2eme ou economique ?  ");
    gets((t+i)->classe);
}//tant que le choix de la classe de l'utilisateur est hors les 3 classes valables on lui redemande d'entrée une classe valide avec cette boucle
printf("Numero de ticket : ");
scanf("%d", &(t+i)->num);//demande le numéro de ticket de l'utilisateur et le stocke
fprintf(FICH_CLIE,"%s\t%s\t%2c\t%d\n",(c+i)->nom,(c+i)->prenom,(c+i)->sexe,(c+i)->age);
fprintf(FICH_TICK,"%s\t%s\t%d\n",(t+i)->nom_train,(t+i)->classe,(t+i)->num);//on ajoute toutes ces données entrées aux 2 fichiers client et ticket pour chaque client
i++;//incrémentation du i pour continiuer la boucle
}
fclose(FICH_CLIE);
fclose(FICH_TICK);//fermeture des 2 fichiers
}
 /*****************************************************
 *              FONCTION AJOUTER UN OU PLUSIEURS CLIENTS
 ******************************************************/
void ajouter_clients(Client *c, Ticket *t, int taille)
{int i=0;
	FILE *FICH_CLIE=fopen("FICH_CLIENT.txt", "a");
FILE *FICH_TICK=fopen("FICH_TICKET.txt", "a");//ouverture des 2 fichiers en mode écriture à la fin
c=(Client*)malloc(taille*sizeof(Client));//réservation d'un espace mémoire de taille (taille) pour le tableau dynamique c
t=(Ticket*)malloc(taille*sizeof(Ticket));//réservation d'un espace mémoire de taille (taille) pour le tableau dynamique t
while(i<taille){//répéter cette boucle tant que i qui est initialisé par 0 est inférieure à taille
printf("Saisir les informations du client et de son ticket :  \n");
fflush(stdin);// Nettoyage de l'entree
printf("Nom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
gets((c+i)->nom);//demande l'utilisateur de saisir le nom et le stocke dans le champs nom pour (c+i)
printf("Prenom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
fflush(stdin);// Nettoyage de l'entree
gets((c+i)->prenom);//demande l'utilisateur de saisir le prenom et le stocke dans le champs prenom pour (c+i)
printf("Sexe : ");
scanf("%2c", &(c+i)->sexe);//demande l'utilisateur de saisir le sexe et le stocke dans le champs sexe pour (c+i)
printf("Age : ");
scanf("%d", &((c+i)->age));//demande l'utilisateur de saisir le sexe et le stocke dans le champs sexe pour (c+i)
fflush(stdin);// Nettoyage de l'entree
printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
gets(((t+i)->nom_train));//demande l'utilisateur de saisir le nom du train et le stocke dans le champs nom_train pour (t+i)
while(strcmp((t+i)->nom_train,"tr1")!=0 && strcmp((t+i)->nom_train,"tr2")!=0 && strcmp((t+i)->nom_train,"tr3")!=0 && strcmp((t+i)->nom_train,"tr4")!=0 && strcmp((t+i)->nom_train,"tr5")!=0){
    printf("Erreur, le train saisi est introuvable.\n");
    printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
    gets((t+i)->nom_train);
}//tant que le choix du train de l'utilisateur est hors les 5 trains valables on lui redemande d'entrée un train valide avec cette boucle
fflush(stdin);// Nettoyage de l'entree
printf("Classe de voyage : 1ere 2eme ou economique ?  ");
gets((t+i)->classe);
while(strcmp((t+i)->classe,"1ere")!=0 && strcmp((t+i)->classe,"2eme")!=0 && strcmp((t+i)->classe,"economique")!=0){
    printf("Erreur, la classe saisie est introuvable.\n");
    printf("Classe de voyage : 1ere 2eme ou economique ?  ");
    gets((t+i)->classe);
}//tant que le choix de la classe de l'utilisateur est hors les 3 classes valables on lui redemande d'entrée une classe valide avec cette boucle
printf("Numero de ticket : ");
scanf("%d", &(t+i)->num);//demande le numéro de ticket de l'utilisateur et le stocke
fprintf(FICH_CLIE,"%s\t%s\t%2c\t%d\n",(c+i)->nom,(c+i)->prenom,(c+i)->sexe,(c+i)->age);
fprintf(FICH_TICK,"%s\t%s\t%d\n",(t+i)->nom_train,(t+i)->classe,(t+i)->num);//on ajoute toutes ces données entrées aux 2 fichiers client et ticket pour chaque client
i++;//incrémentation du i pour continiuer la boucle
}
fclose(FICH_CLIE);
fclose(FICH_TICK);//fermeture des 2 fichiers
}
 /*****************************************************
 *              FONCTION AFFICHAGE DE TOUS LES DONNEES
 ******************************************************/
void affichage_de_tous_les_donnees()// fonction pour l'affichage des donneés sauvegardées
{int k, l=0;//déclaration de deux variables l'une pour compter le nombre de clients et l'autre un compteur dans la boucle for
char s;//variable qui prend le contenu du fichier lettre par lettre pour le tester 
FILE *F=fopen("FICH_CLIENT.txt", "r");//ouverture du fichier clients dans le pointeur F
FILE *H=fopen("FICH_TICKET.txt", "r");//ouverture du fichier tickets dans le pointeur H
while((s=fgetc(F))!=EOF)
{
	if(s=='\n')
	l++;
}//le passage des informations d'un client à un autre se fait avec un retour à la ligne; donc on compte le nombre de clients en comptant le nombre d'espace
fclose(F);//fermeture du pointeur de lecture du fichier client
FILE *T=fopen("FICH_CLIENT.txt", "r");//reouverture du fichier clients dans le pointeur T
Client *c=(Client*)malloc(l*sizeof(Client));//réservation de l emplacements mémoire pour le pointeur de type Client
Ticket *t=(Ticket*)malloc(l*sizeof(Ticket));//réservation de l emplacements mémoire pour le pointeur de type Ticket
while(!feof(T) && !feof(H)){//répétition de cette boucle jusqu'à la fin des 2 fichiers
 for(k=0; k<l ; k++){//boucle for de 0 à l où l est le nombre de clients
fscanf(T,"%s\t%s\t%2c\t%d\n", &(c+k)->nom, &(c+k)->prenom, &(c+k)->sexe, &(c+k)->age);//lecture des données du fichier de client dans la kième case du pointeur c
                    printf("\n          Nom: %s", (c+k)->nom);
                    printf("\n          Prenom: %s", (c+k)->prenom);
                    printf("\n          Sexe: %2c", (c+k)->sexe);
                    printf("\n          Age: %d", (c+k)->age);//affichage des données du client selon le tableau dynamique de la structure client
fscanf(H,"%s\t%s\t%d\n", &(t+k)->nom_train, &(t+k)->classe, &(t+k)->num);//lecture des données du fichier de tickets dans la kième case du pointeur t
                    printf("\n          Nom du train: %s", (t+k)->nom_train);
                    printf("\n          Classe: %s", (t+k)->classe);
                    printf("\n          Numero de ticket: %d\n", (t+k)->num);//affichage des données du ticket selon le tableau dynamique de la structure ticket
}
}
fclose(T);//fermeture du du fichier client
fclose(H);//fermeture du fichier ticket
}
 /*****************************************************
 *              FONCTION RECHERCHE PAR NOM
 ******************************************************/
int recherche_par_nom()//fonction de recherche des clients en entrant le nom du cilent recherché
{
    char nom_recherche[30]; // Declare un string de 30 caractères
    FILE *FICH = fopen("FICH_CLIENT.txt", "r");//ouverture du fichier clients dans le pointeur FICH
    FILE *F=fopen("FICH_TICKET.txt", "r");//ouverture du fichier tickets dans le pointeur F
    fflush(stdin);
	printf("\n Entrer le nom a rechercher : ");
    gets(nom_recherche);//demande et stockage du nom à rechercher
do
{
	fscanf(FICH, "%s\t%s\t%2c\t%d\n", &c.nom, &c.prenom, &c.sexe, &c.age);//stockage des informations des clients qui sont dans le fichier client par client dans la variable c de type structure Client
	fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//stockage des informations des tickets qui sont dans le fichier ticket par ticket dans la variable t de type structure Ticket
if((strcmp(c.nom,nom_recherche)==0))//teste l'égalité des deux chaines de caractère élément par élément
{
fclose(FICH);
fclose(F);//si ils sont égaux on commence par fermer les 2 fichiers
printf("Les informations de la personne recherchee par nom sont : ");//on affiche à l'utilisateur les données du client recherché par nom
printf("\n  Nom: %s", c.nom);
printf("\n  Prenom: %s", c.prenom);
printf("\n  Sexe: %2c", c.sexe);
printf("\n  Age: %d", c.age);
printf("\n  Nom du train: %s", t.nom_train);
printf("\n  Classe: %s", t.classe);
printf("\n  Numero de ticket: %d", t.num);
return 1;//la fonction retourne de plus un entier qui est égal à 1 si on trouve ce nom et on sort de la fonction
         //on a ajouté ce principe pour qu'on puisse employer cette fonction à l'intérieur de d'autres fonctions
}
}while((!feof(FICH)) && (!feof(F)));//la boucle se répéte jusqu'à la fin des 2 fichiers
fclose(FICH);
fclose(F);//si on ne trouve pas le nom et la boucle a terminé on commence par fermer les 2 fichiers
printf("Le nom a rechercher n\'existe pas dans les donnees sauvegardees\n");//on retourne à l'utilisateur un message indiquant que le nom qu'il
                                                                            //veut chercher n'existe pas dans les données sauvegardées
return 0;//la fonction retourne 0 car elle n'a pas trouvé le nom
}

/*******************************************************
*           FONCTION RECHERCHE PAR PRENOM
********************************************************/

int recherche_par_prenom()
{
    char prenom_recherche[30]; // Declare un string de 30 caractères pour le prenom recherché
    FILE *FICH = fopen("FICH_CLIENT.txt", "r");
    FILE *F=fopen("FICH_TICKET.txt", "r");//ouverture des 2 fichiers clients et tickets en mode lecture
    fflush(stdin);// Nettoyage de l'entree
	printf("\n Entrer le prenom a rechercher : ");
    gets(prenom_recherche);//demande et stockage du prenom à rechercher
    fflush(stdin);// Nettoyage de l'entree
do
{
	fscanf(FICH, "%s\t%s\t%2c\t%d\n", &c.nom, &c.prenom, &c.sexe, &c.age);//stockage des informations des clients qui sont dans le fichier client par client dans la variable c de type structure Client
	fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//stockage des informations des tickets qui sont dans le fichier ticket par ticket dans la variable t de type structure Ticket
if((strcmp(c.prenom,prenom_recherche)==0))//teste l'égalité des deux chaines de caractère élément par élément
{
fclose(FICH);
fclose(F);//si ils sont égaux on commence par fermer les 2 fichiers
printf("Les informations de la personne recherchee par prenom sont : ");
printf("\n  Nom: %s", c.nom);
printf("\n  Prenom: %s", c.prenom);
printf("\n  Sexe: %2c", c.sexe);
printf("\n  Age: %d", c.age);
printf("\n  Nom du train: %s", t.nom_train);
printf("\n  Classe: %s", t.classe);
printf("\n  Numero de ticket: %d", t.num);//on affiche à l'utilisateur les données du client recherché par prenom
return 1;//la fonction retourne de plus un entier qui est égal à 1 si on trouve ce prenom et on sort de la fonction
         //on a ajouté ce principe pour qu'on puisse employer cette fonction à l'intérieur de d'autres fonctions
}
}while((!feof(FICH)) && (!feof(F)));//la boucle se répéte jusqu'à la fin des 2 fichiers
fclose(FICH);
fclose(F);//si on ne trouve pas le nom et la boucle a terminé on commence par fermer les 2 fichiers
printf("Le prenom a rechercher n\'existe pas dans les donnees sauvegardees\n");//on retourne à l'utilisateur un message indiquant que le prenom qu'il
                                                                              //veut chercher n'existe pas dans les données sauvegardées
return 0;//la fonction retourne 0 car elle n'a pas trouvé le prenom
}
/*******************************************************************
*                   FONCTION RECHERCHE PAR NUMERO
********************************************************************/
int recherche_par_numero()
{
    int numero_recherche;//déclare un entier pour le numéro recherché

    printf("\n  Entrer le numero a rechercher: ");
    scanf("%d", &numero_recherche);//demande et stockage du numéro à rechercher
    FILE *F=fopen("FICH_TICKET.txt", "r");
	FILE *FICH = fopen("FICH_CLIENT.txt", "r");//ouverture des 2 fichiers clients et tickets en mode lecture
do
{
	fscanf(FICH, "%s\t%s\t%2c\t%d\n", &c.nom, &c.prenom, &c.sexe, &c.age);//stockage des informations des clients qui sont dans le fichier client par client dans la variable c de type structure Client
	fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//stockage des informations des tickets qui sont dans le fichier ticket par ticket dans la variable t de type structure Ticket
if(t.num==numero_recherche)//teste l'égalité des deux entiers
{
fclose(FICH);
fclose(F);//si ils sont égaux on commence par fermer les 2 fichiers
printf("Les informations de la personne recherchee par numero sont : ");
printf("\n  Nom: %s", c.nom);
printf("\n  Prenom: %s", c.prenom);
printf("\n  Sexe: %2c", c.sexe);
printf("\n  Age: %d", c.age);
printf("\n  Nom du train: %s", t.nom_train);
printf("\n  Classe: %s", t.classe);
printf("\n  Numero de ticket: %d\n", t.num);//on affiche à l'utilisateur les données du client recherché par numéro
return 1;//la fonction retourne de plus un entier qui est égal à 1 si on trouve ce numéro et on sort de la fonction
         //on a ajouté ce principe pour qu'on puisse employer cette fonction à l'intérieur de d'autres fonctions
}
}while((!feof(FICH)) && (!feof(F)));//la boucle se répéte jusqu'à la fin des 2 fichiers
fclose(FICH);
fclose(F);//si on ne trouve pas le nom et la boucle a terminé on commence par fermer les 2 fichiers
printf("Le numero a rechercher n\'existe pas dans les donnees sauvegardees\n");//on retourne à l'utilisateur un message indiquant que le numéro qu'il
                                                                              //veut chercher n'existe pas dans les données sauvegardées
return 0;//la fonction retourne 0 car elle n'a pas trouvé le numéro
}
 /*****************************************************
 *              FONCTION MODIFIER CLIENT
 ******************************************************/
void modifier_client()
{int k;//déclaration d'un entier pour le numéro recherché
    FILE *FICH, *F, *K, *H;//déclaration de 4 pointeurs sur fichiers
    printf("Saisissez le  numero de ticket du client a modifier : ");
    scanf("%d", &k);//demande et stockage du numéro à rechercher
    if(recherche_par_numero()==1)//on teste si le numéro du client qu'on veut modifier existe avec la fonction rechereche par numero
    {
    	FICH = fopen("FICH_CLIENT.txt", "r");
    	F=fopen("FICH_TICKET.txt", "r");//ouverture des 2 fichiers clients et tickets en mode lecture
    	H=fopen("NOUV_FICH.txt", "w");
    	K=fopen("NOUV_FICH1.txt", "w");//ouverture de 2 nouveaux fichiers en mode écriture
do
{
fscanf(FICH, "%s\t%s\t%2c\t%d\n", &c.nom, &c.prenom, &c.sexe, &c.age);
fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//on stocke les données des 2 fichiers dans 2 variables de types structures correspondantes
if(t.num==k)//on teste si le numéro entré est égal à l'un des numéros dans les données
{
printf("Saisir les nouveaux informations du client et de son ticket :  \n");
fflush(stdin);
printf("Nom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
gets(c.nom);
printf("Prenom (si vous avez des espaces dans votre nom veuillez les remplacer par : _ ) : ");
gets(c.prenom);
printf("Sexe : ");
scanf("%2c", &c.sexe);
printf("Age : ");
scanf("%d", &c.age);
fflush(stdin);
printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
gets(t.nom_train);
while(strcmp(t.nom_train,"tr1")!=0 && strcmp(t.nom_train,"tr2")!=0 && strcmp(t.nom_train,"tr3")!=0 && strcmp(t.nom_train,"tr4")!=0 && strcmp(t.nom_train,"tr5")!=0){
printf("Erreur, le train saisi est introuvable.\n");
printf("Nom du train auquel vous voulez reserver : tr1, tr2, tr3, tr4 ou tr5 ? ");
fflush(stdin);
gets(t.nom_train);
}
fflush(stdin);
printf("Classe de voyage : 1ere 2eme ou economique ?  ");
gets(t.classe);
while(strcmp(t.classe,"1ere")!=0 && strcmp(t.classe,"2eme")!=0 && strcmp(t.classe,"economique")!=0){
printf("Erreur, la classe saisie est introuvable.\n");
printf("Classe de voyage : 1ere 2eme ou economique ?  ");
fflush(stdin);
gets(t.classe);
}
printf("Numero de ticket : ");
  scanf("%d", &t.num);//on demande à l'utilisateur d'entrer à nouveau les données de ce client et do son ticket de la même manière que la fonction saisie
	}
	fprintf(H, "%s\t%s\t%2c\t%d\n", c.nom, c.prenom, c.sexe, c.age);
	fprintf(K,"%s\t%s\t%d\n", t.nom_train, t.classe, t.num);//on entre les informations dans les 2 nouveaux fichiers ; si le numéro n'est pas égale les données entrées sont les mêmes que ceux
	                                                        //dans les anciens fichiers, si on trouve le numéro les données qu'on sauvegarde sont les nouvelles données entrées par l'utilisateur 
	}while((!feof(FICH) && !feof(F)));//on répéte la boucle jusqu'à la fin des 2 anciens fichiers
	fclose(FICH);
	fclose(F);
	fclose(H);
	fclose(K);//on ferme les 4 fichiers selon leurs pointeurs
	remove("FICH_CLIENT.txt");//on supprime le premier ancien fichier
	rename("NOUV_FICH.txt", "FICH_CLIENT.txt");//on renomme le premier nouveau fichier avec le nom du premier ancien fichier
	remove("FICH_TICKET.txt");//on supprime le deuxième ancien fichier
	rename("NOUV_FICH1.txt", "FICH_TICKET.txt");//on renomme le deuxième nouveau fichier avec le nom du deuxième ancien fichier
	printf("La modification a ete faite avec succes !");//on affiche un message indiquant que la modification est términé avec succès
    }
    else
    printf("Ce numero n\'existe pas dans les donnees sauvegardees\n");//si la fonction recherche par numéro renvoie une valeur différente de 1 (0) on affiche un message d'erreur que le numéro n'existe pas
	return ;
}
 /*****************************************************
 *              FONCTION SUPPRIMER CLIENT
 ******************************************************/
void supprimer_client()
{
	int num_ticket;//déclaration d'un entier pour le numéro recherché
	printf("Enter le numero du ticket a suprimmer : ");
	scanf("%d",&num_ticket);//demande et stockage du numéro à rechercher
	if(recherche_par_numero()==1)//on teste si le numéro du client qu'on veut supprimer existe avec la fonction rechereche par numero
{
	FILE *FICH = fopen("FICH_CLIENT.txt", "r");
	FILE *F=fopen("FICH_TICKET.txt", "r");//ouverture des 2 fichiers clients et tickets en mode lecture
	FILE *FICH1 = fopen("tempFICH_CLIENT.txt", "w");
	FILE *F1=fopen("tempFICH_TICKET.txt", "w");//ouverture de 2 nouveaux fichiers en mode écriture
	do
	{
    fscanf(FICH, "%s\t%s\t%2c\t%d\n", &c.nom, &c.prenom, &c.sexe, &c.age);
	fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//on stocke les données des 2 fichiers dans 2 variables de types structures correspondantes
	if(num_ticket!=t.num)//on teste si le numéro entré est différents des numéros dans les données numéro par numéro
	{
	fprintf(FICH1, "%s\t%s\t%2c\t%d\n", c.nom, c.prenom, c.sexe, c.age);
	fprintf(F1,"%s\t%s\t%d\n", t.nom_train, t.classe, t.num);//si la condition d'inégalité est satisfaite on entre les informations des clients des fichiers anciens de façon directe et sans changement dans les 2 nouveaux fichiers	
	}
	}
	while(!feof(FICH)&&!feof(F));//on répéte la boucle jusqu'à la fin des 2 anciens fichiers
	fclose(FICH);
	fclose(F);
	fclose(FICH1);
	fclose(F1);//on ferme les 4 fichiers selon leurs pointeurs
	remove("FICH_CLIENT.txt");//on supprime le premier ancien fichier
	rename("tempFICH_CLIENT.txt","FICH_CLIENT.txt");//on renomme le premier nouveau fichier de clients avec le nom du premier ancien fichier de clients
	remove("FICH_TICKET.txt");//on supprime le deuxième ancien fichier
	rename("tempFICH_TICKET.txt","FICH_TICKET.txt");//on renomme le deuxième nouveau fichier de tickets avec le nom du deuxième ancien fichier de tickets
	printf("La suppression a ete faite avec succes !");//on affiche à l'utilisateur un message indiquant que la suppression a été faite avec succès
}
else
printf("Ce numero n\'existe pas dans les donnees sauvegardees\n");//si la fonction recherche par numéro renvoie une valeur différente de 1 (0) on affiche un message d'erreur que le numéro n'existe pas
}
 /*****************************************************
 *             FONCTION NOMBRE DE CLIENTS DANS CHAQUE TRAIN
 ******************************************************/
void nombre_de_clients_dans_chaque_train()
{int t1=0, t2=0, t3=0, t4=0, t5=0;//déclaration de 5 entiers chacun stocke le nombre de clients dans un train
	FILE *F=fopen("FICH_TICKET.txt", "r");//ouverture du fichier ticket en mode lecture
do
{
fscanf(F,"%s\t%s\t%d\n", &t.nom_train, &t.classe, &t.num);//stockage des données de chaque ticket pour faire le teste sur le nom du train
if(strcmp("tr1", t.nom_train)==0)
{
	t1++;
}//si le nom du train est tr1 incrémenter t1
else if(strcmp("tr2", t.nom_train)==0)
{
	t2++;
}//si le nom du train est tr2 incrémenter t2
else if(strcmp("tr3", t.nom_train)==0)
{
	t3++;
}//si le nom du train est tr3 incrémenter t3
else if(strcmp("tr4", t.nom_train)==0)
{
	t4++;
}//si le nom du train est tr4 incrémenter t4
else if(strcmp("tr5", t.nom_train)==0)
{
	t5++;
}//si le nom du train est tr5 incrémenter t5
}while(!feof(F));//répéter la boucle jusqu'à la fin du fichier
printf("Le nombre de client qui ont reserve dans le train 1 est %d\n", t1);
printf("Le nombre de client qui ont reserve dans le train 2 est %d\n", t2);
printf("Le nombre de client qui ont reserve dans le train 3 est %d\n", t3);
printf("Le nombre de client qui ont reserve dans le train 4 est %d\n", t4);
printf("Le nombre de client qui ont reserve dans le train 5 est %d\n", t5);//affichage de l'effectif de chque train train par train
return;
}


main()
{
 	int taille, h, l, k, choix, retour;
 	 printf("Saisir le nombre de clients dont vous desirez entrer les informations comme base de donnees initiales : ");
     scanf("%d", &taille);//on commence par demander le nombre de clients qu'on veut saisir et le stocker
 	saisie_clients(cl, ti, taille);//on demande de saisir les clients tout d'abord pour créer une base de données initiales à laquelle on va effectuer les opérations du menu de gestion
 	system("cls"); //Nettois le terminal
 	do
 	{
        printf("\n\n                     ....................GESTION DE RESERVATION DE TICKETS DE TRAIN POUR LES CLIENTS....................                   \n\n\n");
        printf("                     1.AJOUTER UN OU PLUSIEURS CLIENTS \n");
        printf("                     2.AFFICHER TOUS LES CLIENTS\n");
        printf("                     3.RECHERCHER UN CLIENT PAR NOM \n");
        printf("                     4.RECHERCHER UN CLIENT PAR PRENOM\n");
        printf("                     5.RECHERCHER UN CLIENT PAR NUMERO DE TICKET\n");
        printf("                     6.MODIFIER LES INFORMATIONS D'UN CLIENT PAR SON NUMERO DE TICKET\n");
        printf("                     7.SUPPRIMER UN CLIENT PAR SON NUMERO DE TICKET\n");
        printf("                     8.AFFICHER LE NOMBRE DE CLIENT DANS CHAQUE TRAIN \n");
        //Demande du choix de l'utilisateur

        printf("\n            - Entrer votre choix: ");
        scanf("%d", &choix);
        system("cls"); //Nettois le terminal



      /**************************************************************
      *             TRAITEMENT DU CHOIX DE L'UTILISATEUR
      **************************************************************/

        switch(choix){

            case 1:  {
                       printf("Saisir le nombre de clients dont vous desirez ajouter : ");
                       scanf("%d", &taille);
                       ajouter_clients(cl, ti, taille); break;}               // Si le choix vaut 1 , alors ajouter un ou plusieurs client.
            case 2: affichage_de_tous_les_donnees(); break;             // Si le choix vaut 2 , alors afficher tous les clients.
            case 3: l=recherche_par_nom(); break;             // Si le choix vaut 3 , alors rechercher  un client par nom.
            case 4: k=recherche_par_prenom(); break;              // Si le choix vaut 4 , alors rechercher  un client par prenom.
            case 5: h=recherche_par_numero(); break;   // Si le choix vaut 5 , alors rechercher  un client par numero de ticket.
            case 6: modifier_client(cl, ti); break;               // Si le choix vaut 6 , alors modifier les infos d un client .
            case 7: supprimer_client(); break;            // Si le choix vaut 7 , alors supprimer les infos d un client.
            case 8 : nombre_de_clients_dans_chaque_train(); break; // Si le choix vaut 8 , alors afficher le nombre de clients dans chaque train.
			default:
                {
                   //Si le choix n'est pas pris en compte afficher un message d'erreur
                    printf("\n Valeur non pris en compte, reessayer \n\n");
                    break;
                }

        }

        // On demander à l'utilisateur  cette action
        // si seulement si le choix prealablement entrer
        // est compris entre 1 et 8
        if(choix >= 1 && choix <= 8){

            printf("\n Pour retourner au menu taper 1: ");
            scanf("%d",&retour);

            if(retour == 1)
                system("cls"); //Nettois le terminal
            else
                printf("\n FERMETURE DE LA SESSION MERCI D'ETRE PASSER.......\n\n\n\n");//si l'utilisateur entre une valeur différente de 1 on affiche ce message qui 
                                                                                        //montre la fin du programme

        }


  } while(retour == 1 || (choix < 1 || choix > 8));//répéter l'affichage du menu et effectuer ces opérations tant que le choix est hors l'intervalle des choix valides
                                                   //ou l'utilisateur a choisi 1 dans la valeur de retour donc a choisi de revenir au menu
}
