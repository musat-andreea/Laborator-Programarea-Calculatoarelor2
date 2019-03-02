#include <stdio.h>
#include <stdlib.h>

struct cuvinte
{
    char cuv[15];
    struct cuvinte *urm;
};

typedef struct cuvinte CUV;

int main()
{
    CUV *cap, *p, *q;

    int i, n;

    printf("Introduceti numarul de cuvinte din lista\n");
    scanf("%d", &n);

    p=(CUV*)malloc(sizeof(CUV));

    if(p==NULL)
    {
        printf("Alocarea dinamica a reusit!\n");
        exit(1);
    }

    printf("Intorduceti primul cuvant din lista\n");
    scanf("%s", &p->cuv);
    fflush(stdin);

    p->urm=NULL;

    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(CUV*)malloc(sizeof(CUV));

        if(q==NULL)
        {
            printf("Alocarea dinamica nu a reusit\n");
            exit(1);
        }

        printf("Introduceti elementul %d din lista\n", i);
        scanf("%s", &q->cuv);
        fflush(stdin);

        q->urm=NULL;

        p->urm=q;

        p=q;
    }

    for(i=1, p=cap; p!=NULL; p=p->urm, i++)
        printf("Cuvantul %d din lista: %s cu adresa %p\n", i, p->cuv, p->urm);

    printf("FRAZA\n");

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("%s ", p->cuv);




    return 0;
}
