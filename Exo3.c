#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
////////////////////////////////////////////////////Exercice3/////////////////////////////////////////////////////////////////////////////////////
//Premièrement , on définit les structures Tache,Maillon et Liste
typedef struct {
    char nom[30];
    int duree;
    int priorite;
} Tache ;

typedef struct maillon {
    Tache tach;
    struct maillon * suivant;
} Maillon;

typedef Maillon* liste;

//Maintenat , nous définissons une fonction pour créer un maillon à partir d'une tache
Maillon* CreerMaillon (Tache T) {
    Maillon *m;
    m = (Maillon*)malloc(sizeof(Maillon));

    if ( m != NULL ) {
        m->tach = T;
        m->suivant = NULL;
    }
    return m;
}

//La deuxième fonction permet d'insérer une tache au début de la liste
void InsererDebut (Maillon * L,Tache T) {
    Maillon *m ;
    m = CreerMaillon(T);

    if ( m != NULL ) {
        m->suivant = L;
        L = m;
    }
}

//Ensuite , nous allons essayer d'ajouter une tache à la liste.Cependant , la liste doit etre ordonnée après
void InsererOrdonnee (Maillon * L, Tache T ) {
    Maillon *m, *pred, *par ;

    if( L == NULL || L->tach.duree  >  T.duree )
        InsererDebut( L, T);

    else {
        m = CreerMaillon (T);
        if( m != NULL) {
            par = L->suivant;
            pred = L;
            while ( par != NULL  && par-> tach.duree <  T.duree) {
                pred = par ;
                par = par->suivant;
            }
            m->suivant = par ;
            pred->suivant = m;
        }
    }
}

//Enfin , nous allons essayer d'afficher les informations de la tache la plus prioritaire
void AfficherTachePrioritaire (Maillon *L) {
    Tache max;
    Maillon * p;

    if ( L == NULL)
        printf("Cette liste est vide") ;
    else {
        max = L->tach ;
        p = L;
        while ( p != NULL) {
            if( p->tach.priorite > max.priorite )
                max = p->tach;
            p = p->suivant ;
        }
        printf("La tache la plus prioritaire est : %s  de duree %d et de prioritee %d\n", max.nom, max.duree, max.priorite );
    }
}

int main(int argc, char *argv[]) {
	return 0;
}
