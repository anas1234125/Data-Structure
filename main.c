#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//////////////////////////////////////////Exercice2////////////////////////////////////////////////////////////////////////////////////////////////
       //////Dans ce deuxième exercie , nous allons travailler avec un type particulier des listes chainées : une liste circulaire (ou le dernier élement 
       //de la liste pointe sur le premier élement)
                 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    /////////////////////////////////////////////////////////
           //Nous commençons par définir les deux structures maillon et liste
typedef struct maillon {
    int valeur;
    struct maillon * suivant;
}Maillon;

//Nous commençons par une fonction qui permet de réserver de l'espace pour un maillon et retourne son adresse
Maillon * CreerMaillon (int V) {
    Maillon *m ;
    m = (Maillon*) malloc(sizeof(Maillon));
    if( m != NULL ) {
        m->valeur = V ;
        m->suivant=NULL;
    }
    return m;
}

//Ensuite, nous créons une fonction pour retourner l'adresse du dernier maillon de la liste
Maillon* DernierElement (Maillon *L) {

    Maillon *R;

    if( L == NULL )
        return NULL;

    else {
        R = L;

        while ( R->suivant != NULL )
            R = R->suivant;
        return R;
    }
}

//Enfin , la fonction "InsererFin" pour insérer un élement à la fin
void InsererFin (Maillon * L, int V ) {

    Maillon *R, *p ;
    R = CreerMaillon (V) ;

    if ( R != NULL ) {
        if ( L == NULL ) {
            L = R;
            R->suivant = L;
        }

        else {
            p = DernierElement (L);
            p->suivant = R;
            R->suivant = L;
        }
    }
}


int main(int argc, char *argv[]) {
	return 0;
}
