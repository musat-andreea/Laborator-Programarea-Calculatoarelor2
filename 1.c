#include <stdio.h>
#include <stdlib.h>

struct element
{
    int val;
    struct element* urmator;
};

typedef struct element ELEM;

int main()
{
    ELEM* cap, *prim, *ultim, *p, *q;

    int i, n;

    printf("Introduceti numarul de elemente din lista\n");
    scanf("%d", &n);

    prim=(ELEM*)malloc(sizeof(ELEM));

    if(prim==NULL)
    {
        printf("Alocarea a esuat!\n");
        exit(1);
    }

    printf("Tastati primul elemnt al listei\n");
    scanf("%d", &prim->val);

    prim->urmator=NULL;

    cap=prim; //memoreaza adresa primului element din lista

    for(i=2; i<=n; i++)
    {
        ultim=(ELEM*)malloc(sizeof(ELEM));

        if(ultim==NULL)
        {
            printf("Alocarea a esuat!");
            exit(1);
        }

        printf("Tastati elementul %d\n", i);
        scanf("%d", &ultim->val);

        ultim->urmator=NULL;

        prim->urmator=ultim;

        prim=ultim;
    }

    for(p=cap, i=1; p!=NULL; p=p->urmator, i++)
        printf("Valoarea elementului %d este %d\n", i, p->val);

    /*printf("Elementele impare din lista sunt\n");

    for(p=cap; p!=NULL; p=p->urmator)
        if(p->val%2!=0)
            printf("%d ", p->val);*/

    while(cap->val%2==0)
    {
        cap=cap->urmator;
        n--;
    }

    /*for(p = cap; p->urmator != NULL; p = q) {
	if(p->urmator->val % 2 == 0) {
		q = p->urmator->urmator;
		free(p->urmator);
		if(q = NULL) {
			break;
		}
	} else {
		q = p->urmator;
	}
}*/

    for(p=cap, i=1; p->urmator!=NULL; p=p->urmator, i++)
    {
        while((p->urmator->val%2==0) && (i<n-1))
        {
            q=p->urmator->urmator;
            free(p->urmator);
            p->urmator=q;
             n--;
        }
    }

    for(p = cap; p->urmator != NULL; p = q) {
	if(p->urmator->val % 2 == 0) {
		q = p->urmator->urmator;
		free(p->urmator);
		if(q == NULL) {
			break;
		}
	} else {
		q = p->urmator;
	}
}

    /*for(p=cap; p!=NULL; p=p->urmator)
        if((i==n) && (p->urmator->val%2==0))
    {
        p->urmator=NULL;
        n--;
    }*/


    printf("\n");

    for(i=1, p=cap; p!=NULL; p=p->urmator, i++)
        printf("%d\n",p->val);


    for(p=cap; p!=NULL; p=q)
    {
        ultim=p->urmator;
        free(p);
    }

    return 0;
}
