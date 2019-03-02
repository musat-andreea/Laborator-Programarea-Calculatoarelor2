#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

struct persoane
{
    char nume[50];
    int varsta;
    struct persoane *urmator;
};

typedef struct persoane PERS;

int main()
{
    PERS *cap, *p, *q;

    int i, n, ok=0;



    printf("Introduceti numarulde persoane din lista\n");
    scanf("%d", &n);

    p=(PERS*)malloc(sizeof(PERS));

    if(p==NULL)
    {
        printf("Aloarea dinamica de memorie nu a reusit!\n");
        exit(1);
    }

    printf("Tastati numele primei persoane din lista\n");
    scanf("%s", &p->nume);
    fflush(stdin);

    printf("Tastati varsta primei persoane din lista\n");
    scanf("%d", &p->varsta);
    fflush(stdin);

    p->urmator=NULL;

    cap=p;

    for(i=2; i<=n; i++)
    {
        q=(PERS*)malloc(sizeof(PERS));

        if(q==NULL)
        {
            printf("Alocarea dinamica de memorie nu a reusit!\n");
            exit(1);
        }

        printf("Tastati numele persoanei %d din lista\n", i);
        scanf("%s", &q->nume);
        fflush(stdin);

        printf("Tastati varsta persoanei %d din lista\n", i);
        scanf("%d", &q->varsta);
        fflush(stdin);

        q->urmator=NULL;

        p->urmator=q;

        p=q;
    }



    for(p=cap; p!=NULL; p=p->urmator)
    {
        if((strcmp(p->nume,"George")==0) && (p->varsta==19))
        {
            ok++;

            if(p->urmator!=NULL)
            {
                if(p->urmator->varsta < 19)
                    printf("Urmatoarea persoana din lista este mai tanara decat George\n");
                    else printf("Uramtoarea persoana din lista nu este mai tanara ca George\n");
            }else printf("George este ultima persoana din lista!\n");
        }
    }

    if(ok==0)
        printf("In lista nu exista o persoana cu numele George de 19 ani\n");

    for(p=cap; p!=NULL; p=q)
    {
            q=p->urmator;
            free(p);
    }

    return 0;
}
