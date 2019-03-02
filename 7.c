#include <stdio.h>
#include <stdlib.h>

typedef struct intregi
{
    int nr;
    struct intregi *urm;
}NR;

void insereaza(NR *cap, NR *p, NR *a, NR *b)
{
    int i;
    NR aux, t;

    aux=*a;
    *a=*cap;
    *cap=aux;
    cap->urm=a;

    for(p=cap; p->urm!=NULL; p=p->urm)
        ;
    t=*b;
    *b=*p;
    *p=t;
    p->urm=b;
    p=b;
    b->urm=NULL;
}

int main()
{
    NR *cap, *p, *q, *a, *b;

    int i, n;

    printf("Introduceti numarul de elemente din lista!\n");
    scanf("%d", &n);

    p=(NR*)malloc(sizeof(NR));

    if(p==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!");
        exit(1);
    }

    printf("Introduceti prima valoare din lista\n");
    scanf("%d", &p->nr);

    p->urm=NULL;

    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(NR*)malloc(sizeof(NR));

        if(q==NULL)
        {
            printf("Alocarea dinamica de memorie a esuat!");
            exit(1);
        }

        printf("Introduceti valoarea %d din lista\n",i);
        scanf("%d", &q->nr);

        q->urm=NULL;
        p->urm=q;
        p=q;
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);

    a=(NR*)malloc(sizeof(NR));

    if(a==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!");
        exit(1);
    }

    printf("Introduceti numarul ce trebuie adaugat la inceputul listei\n");
    scanf("%d", &a->nr);

    b=(NR*)malloc(sizeof(NR));

    if(b==NULL)
    {
        printf("Alocarea dinamica de memorie a esuat!");
        exit(1);
    }

    printf("Introduceti numarul ce trebuie adaugat inaintea ultimului element\n");
    scanf("%d", &b->nr);

    insereaza(cap,p,a,b);

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);

    return 0;
}
