#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int n;
    struct lista *urm;
}ELEM;

void inserare_inaintede_valoarea14(ELEM *cap, ELEM *p)
{
    ELEM *a, aux;
    int i;

    a=(ELEM*)malloc(sizeof(ELEM));

    if(a==NULL)
    {
        printf("Alocarea dinamica de memorie nu a reusit\n");
        exit(1);
    }

    printf("Introduceti elementul ce trebuie inserat\n");
    scanf("%d", &a->n);

    for(p=cap; p!=NULL; p=p->urm)
    {
        if(p->n==14)
        {
            aux=*a;
            *a=*p;
            *p=aux;
            p->urm=a;
            p=a;
        }
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);

}

void inserare_dupa_valoarea14(ELEM *cap, ELEM *p, ELEM *a)
{
    int i;

    for(p=cap; p!=NULL; p=p->urm)
    {
        if(p->n==14)
        {
            a->urm=p->urm;
            p->urm=a;
        }
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void insereaza_ordonat(ELEM *cap, ELEM *p, ELEM *a)
{
    int i;
    if(a->n > cap->n)
    {
        a->urm=cap;
        cap=a;
    }else {
            p=cap;
            while(p->urm!=NULL && a->n <  p->urm->n)
                p=p->urm;
            a->urm=p->urm;
            p->urm=a;
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void sterge_altreilea(ELEM *cap, ELEM *p, ELEM *q)
{
    int i;

    p=cap;
    i=1;
    while(p->urm!=NULL)
    {
        if(i==2)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                break;
        }
        p=p->urm;
        i++;
    }
    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void insereaza_inainte_aldoilea(ELEM *cap, ELEM *p, ELEM *a)
{
    int i;
    ELEM aux;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(i==2)
        {
            aux=*a;
            *a=*p;
            *p=aux;
            p->urm=a;
        }
    }
    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void inserare_inaintea_primului(ELEM *cap, ELEM *a, ELEM *p)
{
    int i;
    ELEM aux;

    aux=*a;
    *a=*cap;
    *cap=aux;
    cap->urm=a;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void inserare_inaintea_ultimului(ELEM *cap, ELEM *p, ELEM *a)
{
    ELEM aux;
    int i;

    for(p=cap; p->urm!=NULL; p=p->urm)
        ;
    aux=*a;
    *a=*p;
    *p=aux;
    p->urm=a;
    p=a;
    a->urm=NULL;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void inserare_dupa_primul(ELEM *a, ELEM *p, ELEM *cap)
{
    int i;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(i==1)
        {
            a->urm=p->urm;
            p->urm=a;
        }
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void inserare_dupa_ultimul(ELEM *cap, ELEM *p, ELEM *a)
{
    int i;

    for(p=cap; p->urm!=NULL; p=p->urm)
        ;
    a->urm=NULL;
    p->urm=a;
    p=a;//poate lipsi

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void numara_cateelem(ELEM *cap, ELEM *p)
{
    int i, ok=0;

    for(p=cap; p!=NULL; p=p->urm)
        if(p->n==14)
            ok++;
    printf("14 apare de %d", ok);
}

void trei_elemente(ELEM *cap)
{
    cap=cap->urm;

    if(cap->n==cap->urm->n)
        printf("DA");
    else printf("NU");
}

void sterge_nr(ELEM *cap, ELEM *p, ELEM *q)
{
    int i;

    while(cap->n==2)
        cap=cap->urm;

    p=cap;
    while(p->urm!=NULL)
    {
        if(p->urm->n==2)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                break;
        }else p=p->urm;
    }
    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void adauga_dupapoz(ELEM *cap, ELEM *p, ELEM *a)
{
    int i;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(i==2)
        {
            a->urm=p->urm;
            p->urm=a;
        }
    }
    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void verifica(ELEM *cap, ELEM *p)
{
    int i, ok=0;

    for(p=cap; p!=NULL; p=p->urm)
    {
        if(p->n==15)
        {
            ok++;
            if(p->urm==NULL)
                printf("E ultimul\n");
            else if(p->urm->n > 15)
                printf("DA");
            else if(p->urm->n < 15)
                printf("NU");
        }
    }
    if(ok==0)
        printf("Nu e deloc in lista\n");
}

void poz_pare(ELEM *cap, ELEM *p)
{
    int i;

    for(p=cap->urm, i=2; p!=NULL; p=p->urm->urm, i=i+2)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void poz_impare(ELEM *cap, ELEM *p)
{
    int i;

    for(p=cap, i=1; p!=NULL; p=p->urm->urm, i=i+2)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void sterge_prim_ultim(ELEM *p, ELEM *cap, ELEM *q, int nr)
{
    int i=1;

    cap=cap->urm;

    p=cap;
    while(p->urm!=NULL)
    {
        if(i==nr-2)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                break;
        }p=p->urm;
        i++;
    }


for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);
}

void sterge_dupavalTOT(ELEM *cap, ELEM *p, ELEM *q)
{
    int i;

    p=cap;
    while(p->urm!=NULL)
    {
        if(p->urm->n==14)
        {
            q=p->urm->urm->urm;
            free(p->urm->urm);
            p->urm->urm=q;
            if(q==NULL)
                break;
        }else p=p->urm;
    }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);

}

void sterge_dupaval(ELEM *cap, ELEM *p, ELEM *q)
{
    int i;

    for(p=cap; p!=NULL; p=p->urm)
        if(p->n==14)
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                break;
        }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);

}

/*void sterge_inainteval(ELEM *cap, ELEM *p, ELEM *q)
{
    int i;

    for(p=cap; p!=NULL; p=p->urm)
        if()
        {
            q=p->urm->urm;
            free(p->urm);
            p->urm=q;
            if(q==NULL)
                break;
        }

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);

}*/


void max(ELEM *cap, ELEM *p)
{
    int i,max=0;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(p->n>max)
            max=p->n;
    }

    printf("maxim %d", max);
}

void min(ELEM *cap, ELEM *p)
{
    int i,min=99;

    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
    {
        if(p->n<min)
            min=p->n;
    }

    printf("minim %d", min);
}

int main()
{
    ELEM *cap, *p, *q, *a;
    int i, n;

    printf("Introduceti numarul de persoane din lista\n");
    scanf("%d", &n);

    p=(ELEM*)malloc(sizeof(ELEM));

    if(p==NULL)
    {
        printf("Alocarea dinamica de memorie nu a reusit\n");
        exit(1);
    }

    printf("Introduceti primul element din lista\n");
    scanf("%d", &p->n);

    p->urm=NULL;
    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(ELEM*)malloc(sizeof(ELEM));

        if(q==NULL)
        {
            printf("Alocarea dinamica de memeorie nu a reusit\n");
            exit(1);
        }

        printf("Introduceti elementul %d din lista\n", i);
        scanf("%d", &q->n);

        q->urm=NULL;
        p->urm=q;
        p=q;
    }
    for(p=cap, i=1; p!=NULL; p=p->urm, i++)
        printf("Elemntul %d din lista are valoarea %d si adresa %p\n", i, p->n, p->urm);

    //inserare_inaintede_valoarea14(cap,p);

    a=(ELEM*)malloc(sizeof(ELEM));

    if(a==NULL)
    {
        printf("Alocarea dinamica de memorie nu a reusit\n");
        exit(1);
    }

    printf("Introduceti elementul ce trebuie inserat\n");
    scanf("%d", &a->n);

    //inserare_dupa_valoarea14(cap,p,a);

    insereaza_ordonat(cap,p,a);

    //sterge_altreilea(cap,p,q);

    //insereaza_inainte_aldoilea(cap,p,a);

    //inserare_inaintea_primului(cap,a,p);

    //inserare_inaintea_ultimului(cap,p,a);

    //inserare_dupa_primul(a,p,cap);

    //inserare_dupa_ultimul(cap,p,a);

    //numara_cateelem(cap,p);

    //trei_elemente(cap);

    //sterge_nr(cap,p,q);

    //adauga_dupapoz(cap,p,a);

    //verifica(cap,p);

    //poz_pare(cap,p);

    //poz_impare(cap,p);

    //sterge_prim_ultim(p,cap,q,n);

    //max(cap,p);

    //min(cap,p);

    //sterge_dupavalTOT(cap,p,q);

    //sterge_dupaval(cap,p,q);

    //sterge_inainteval(cap,p,q);

    return 0;
}
