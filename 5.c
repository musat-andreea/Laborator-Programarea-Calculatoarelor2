#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct catalog
{
    char nume[21];
    int nr_matricol;
    int cod_materie[3];
    float medie_materie[4];
    struct catalog *urm;
}STUDENTI;

int main()
{
    STUDENTI *cap, *p, *q, *nou;

    int n, i, k, m, pozi, pozk;
    float med_gen, s=0, med_max=0;

    printf("Introduceti numarul de studenti din lista\n");
    scanf("%d", &n);

    p=(STUDENTI*)malloc(sizeof(STUDENTI));

    if(p==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!\n");
        exit(1);
    }

    printf("Introduceti numele primului student din lista\n");
    fflush(stdin);
    gets(p->nume);
    //fflush(stdin);

    printf("Introduceti numarul matricol al primului student din lista\n");
    scanf("%d", &p->nr_matricol);

    printf("Introduceti codurile materiilor primului student din lista\n");
    for(k=1; k<=3; k++)
        scanf("%d", &p->cod_materie[k]);

    printf("Introduceti mediile primului student din lista\n");
    for(k=1; k<=3; k++)
        scanf("%f", &p->medie_materie[k]);

    p->urm=NULL;

    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(STUDENTI*)malloc(sizeof(STUDENTI));

        if(q==NULL)
        {
            printf("Alocarea dinamica de memorie a esuat!\n");
            exit(1);
        }

        printf("Introduceti numele studentului %d din lista\n", i);
        fflush(stdin);
        gets(q->nume);
        //fflush(stdin);

        printf("Introduceti numarul matricol al studentului %d din lista\n", i);
        scanf("%d", &q->nr_matricol);

        printf("Introduceti codurile materiilor studentului %d din lista\n", i);
        for(k=1; k<=3; k++)
            scanf("%d", &q->cod_materie[k]);

        printf("Introduceti mediile studentului %d din lista\n", i);
        for(k=1; k<=3; k++)
            scanf("%f", &q->medie_materie[k]);

        q->urm=NULL;
        p->urm=q;
        p=q;

    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        for(k=1; k<=3; k++)
            printf("%d:Studentul %s cu nr matricol %d are la materia %d media %.3f\n", i, p->nume, p->nr_matricol, p->cod_materie[k], p->medie_materie[k]);

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        for(k=1; k<=3; k++)
    {
        s=s+p->medie_materie[k];
    }

    m=n*3;

    med_gen=s/m;

    printf("Media generala a grupei de studenti este %f\n", med_gen);

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(((p->medie_materie[1]+p->medie_materie[2]+p->medie_materie[3])/3)>med_max)
        {
            med_max=(p->medie_materie[1]+p->medie_materie[2]+p->medie_materie[3])/3;
            pozi=i;
        }
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        {
            if(i==pozi)
                printf("Premiantul %s cu codul %d\n", p->nume, p->nr_matricol);
        }

    nou=(STUDENTI*)malloc(sizeof(STUDENTI));

    if(nou==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!\n");
        exit(1);
    }

    printf("Introduceti numele noului student\n");
    fflush(stdin);
    gets(nou->nume);

    printf("Introduceti nr matricol al noului student\n");
    scanf("%d", &nou->nr_matricol);

    printf("Introduceti codurile materiilor noului student\n");
    for(k=1; k<=3; k++)
        scanf("%d", &nou->cod_materie[k]);

    printf("Introduceti mediile noului student\n");
    for(k=1; k<=3; k++)
        scanf("%f", &nou->medie_materie[k]);

    for(p=cap; p->urm!=NULL; p=p->urm)
        ;
    p->urm=nou;
    nou->urm=NULL;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        for(k=1; k<=3; k++)
            printf("%d:Studentul %s cu nr matricol %d are la materia %d media %.3f\n", i, p->nume, p->nr_matricol, p->cod_materie[k], p->medie_materie[k]);

if(strcmp(cap->nume,nou->nume)>0)
    {

        nou->urm=cap;
        cap=nou;
         for(p=cap; p->urm!=NULL; p=p->urm)
            ;
    /* p=p->urm;
    p->urm->urm=NULL;*/
    q->urm=NULL;
        p->urm=q;
        p=q;

    } else {
            p=cap;
            while(p->urm!=NULL && strcmp(p->urm->nume, nou->nume)<0)
                p=p->urm;
            nou->urm=p->urm;
            p->urm=nou;
            //p->urm->urm=NULL;
    }


    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        for(k=1; k<=3; k++)
            printf("%d:Studentul %s cu nr matricol %d are la materia %d media %.3f\n", i, p->nume, p->nr_matricol, p->cod_materie[k], p->medie_materie[k]);


 /*p = cap;
 i=1;
    while(p->urm != NULL)
    {
        //if(p->urmator->val % 2 == 0)
        if(i==2)
        {
            q = p->urm->urm;
            free(p->urm);
            p->urm = q;
            if(q == NULL)
            {
                break;
            }
        } //else

            p = p->urm;
            i++;

    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        for(k=1; k<=3; k++)
            printf("%d:Studentul %s cu nr matricol %d are la materia %d media %.3f\n", i, p->nume, p->nr_matricol, p->cod_materie[k], p->medie_materie[k]);
*/
    return 0;
}
