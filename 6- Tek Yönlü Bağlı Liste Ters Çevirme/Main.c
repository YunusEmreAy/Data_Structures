// Yunus Emre Ay / E-posta:TR.yunus.emre.ay@gmail.com


#include <stdio.h>
#include <stdlib.h>

struct liste
{
    int data;
    struct liste* next;
};

struct liste* start=NULL;
struct liste* p;

void ekleme()
{
    struct liste* yeni_eleman;
    yeni_eleman = (struct liste*)malloc(sizeof(struct liste));
    printf("\nData giriniz -->");
    scanf("%d",&yeni_eleman->data);
    yeni_eleman->next = NULL;

    if(start==NULL)
    {
        start = yeni_eleman;
    }
    else
    {
        p = start;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = yeni_eleman;
    }
}

void listeleme()
{
    p = start;

    printf("\n");

    while(p!=NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("\n");
    printf("\n");
}

void ters_cevir()
{
    struct liste* onceki;
    struct liste* sonraki;

    if(start==NULL || start->next==NULL)
    {
        printf("\nYetersiz eleman\n");
    }
    else
    {
        p=start;
        onceki=NULL;
        while(p->next!=NULL)
        {
            sonraki=p->next;
            p->next=onceki;
            onceki=p;
            p=sonraki;
        }
        p->next=onceki;
        start=p;
    }
}

int main()
{
    int secim;

    while(0==0)
    {
        printf("1)ekleme  2)listeleme  3)ters cevirme: ");
        scanf("%d",&secim);

        switch (secim)
        {
            case 1:
                ekleme();
                break;
            case 2:
                listeleme();
                break;
            case 3:
                ters_cevir();
        }
    }





    return 0;
}
