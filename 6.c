#include <stdio.h>
#include <stdlib.h>

typedef struct produse
{
    int id_produs;
    int cant_produs;
    float pret_produs;
    struct produse *urm;
}PROD;

typedef struct cos
{

    struct cos *urm;
}

int main()
{
    PROD *cap, *p, *q;

    int i, n;

    printf("Introduceti numarul de produse\n");
    scanf("%d", &n);

    p=(PROD*)malloc(sizeof(PROD));

    if(p==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!");
        exit(1);
    }

    printf("Introduceti id ul primului produs din lista\n");
    scanf("%d", &p->id_produs);

    printf("Introduceti cantitatea primului produs din lista\n");
    scanf("%d", &p->cant_produs);

    printf("Introduceti pretul primului produs din lista\n");
    scanf("%f", &p->pret_produs);

    p->urm=NULL;
    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(PROD*)malloc(sizeof(PROD));

        if(q==NULL)
        {
            printf("Alocarea dinamica de memorie nu a reusit\n");
            exit(1);
        }

        printf("Introduceti id ul pt al %d lea produs din lista\n", i);
        scanf("%d", &q->id_produs);

        printf("Introduceti cantitatea pt al %d lea produs din lista\n", i);
        scanf("%d", &q->cant_produs);

        printf("Introduceti pretul pt al %d lea produs din lista\n", i);
        scanf("%f", &q->pret_produs);

        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Produsul %d are id->%d, cantitatea=%d la pretul %f\n", i, p->id_produs, p->cant_produs, p->pret_produs);



    return 0;
}
