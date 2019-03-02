#include <stdio.h>
#include <stdlib.h>

struct elemente
{
    int nr;
    struct elemente* urm;
};

typedef struct elemente NR;

void elimina_cifra6(NR *cap, NR *p, NR *q, int n)
{
    int i;

    p=cap;
    while(p->urm!=NULL)
    {
        if(p->urm->nr==6)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                {break;}
        }else {p=p->urm;}
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);
}

void ad_dupa(NR *p, NR *d, NR *cap)
{
    int i;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(i==2)
            {d->urm=p->urm;
            p->urm=d;
            }
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);
}

void inserare_primulelem(NR aux, NR *a, NR *cap)
{
    aux=*a;
    *a=*cap;
    *cap=aux;
    cap->urm=a;

}

int ad_dupaalt(NR *p, NR *b, NR *cap)
{
    int i, ok=0;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(i==4/* && ok!=4*/)
            {b->urm=p->urm;
            p->urm=b;
            }
        else ok++;
    }

    return ok;
}

int main()
{
    NR *cap, *prim, *ultim, *p, *q, *d, *a, aux, *b, *c;

    int i, n;

    printf("Introduceti numarul de elemente din lista\n");
    scanf("%d", &n);

    prim=(NR*)malloc(sizeof(NR));

    if(prim==NULL)
    {
        printf("Alocarea dinamica a esuat\n");
        exit(1);
    }

    printf("Introduceti primul numar din lista\n");
    scanf("%d", &prim->nr);

    prim->urm=NULL;

    cap=prim;

    for(i=2; i<=n; i++)
    {
        ultim=(NR*)malloc(sizeof(NR));

        if(ultim==NULL)
        {
            printf("Alocarea dinamica a esuat!\n");
            exit(1);
        }

        printf("Introduceti elementul %d din lista\n", i);
        scanf("%d", &ultim->nr);

        ultim->urm=NULL;

        prim->urm=ultim;

        prim=ultim;
    }

   /* while(cap->nr==6)
    {
        cap=cap->urm;
        n--;
    }*/// primul element NU TREBUIE SA FIE ELIMINAT

    /*for(p=cap; p->urm!=NULL; p=p->urm)
    {
        while(p->urm->nr==6 && p->urm!=NULL)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            n--;
        }

        if(p->urm==NULL && p->urm->nr==6)
        {
            p->urm=NULL;
            n--;
        }
    }
    /*for(i=1, p=cap; p->urm!=NULL; p=p->urm, i++)
    {
        while((p->urm->nr==6) && (i<n-1))
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            n--;
        }
    }*/

    elimina_cifra6(cap, p, q, n);

    d=(NR*)malloc(sizeof(NR));

    if(d==NULL)
    {
        printf("alc  din de mem nu a reusit\n");
        exit(1);
    }

    printf("Introduceti numarul ce trebuie inserat dupa al doilea elem\n");
    scanf("%d", &d->nr);

    ad_dupa(p, d, cap);

    a=(NR*)malloc(sizeof(NR));

    if(a==NULL)
    {
        printf("Aloc din a esuat\n");
        exit(1);
    }

    printf("Introduceti PRIMUL termen\n");
    scanf("%d", &a->nr);

    inserare_primulelem(aux, a, cap);

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);

    b=(NR*)malloc(sizeof(NR));

    if(b==NULL)
    {
        printf("alc  din de mem nu a reusit\n");
        exit(1);
    }

    printf("Introduceti numarul ce trebuie inserat dupa al patrulea elem\n");
    scanf("%d", &b->nr);


    if(ad_dupaalt(p, b, cap)==4)
        printf("al patrulea element este ultimul\n");
    else{for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);}

    NR *y, t;
    int poz;

    y=(NR*)malloc(sizeof(NR));

    if(y==NULL)
    {
        printf("Alocare din esuata\n");
        exit(1);
    }

    printf("Introduceti  INAINTEEE\n");
    scanf("%d", &y->nr);

    int u=0;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        //poz=i;

        if(p->nr==14)
        {
            t=*y;
            *y=*p;
            *p=t;
            p->urm=y;
            p=y;
            u++;
        }
    }

    if(u==0)
        printf("14 nu se afla in lista");

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);

    NR *z, tz;


    z=(NR*)malloc(sizeof(NR));

    if(z==NULL)
    {
        printf("Alocare din esuata\n");
        exit(1);
    }

    printf("Introduceti DUPAAAAA\n");
    scanf("%d", &z->nr);

    u=0;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        //poz=i;

        if(p->nr==14)
        {
            /*t=*y;
            *y=*p->urm;
            *p->urm=t;
            p->urm->urm=y;*/
            z->urm=p->urm;
            p->urm=z;
            u++;
        }
    }

    if(u==0)
        printf("14 nu se afla in lista");

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elementul %d este %d\n", i, p->nr);

    return 0;
}
