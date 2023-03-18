// Yunus Emre Ay / E-posta:TR.yunus.emre.ay@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Liste1
{
    int data;
    struct Liste1 *adres;
    struct Liste1 *next;
    struct Liste1 *prev;

};

struct Liste2
{
    int data;
    struct Liste2 *adres;
    struct Liste2 *next;
    struct Liste2 *prev;
};


struct Liste1 *start1 = NULL;
struct Liste1 *q1;

struct Liste2 *start2 = NULL;
struct Liste2 *q2;


void ekleme(int birinci,int ikinci)
{
    int eleman1=0,eleman2=0;
    int x=101;

    while(0==0)
    {
        if(eleman1<birinci)
        {
            struct Liste1 *yeni_eleman1;
            yeni_eleman1 = (struct Liste1*)malloc(sizeof(struct Liste1));
            yeni_eleman1->data=x;
            x++;

            if (start1 == NULL)
            {
                start1 = yeni_eleman1;
                yeni_eleman1->next = NULL;
                yeni_eleman1->prev= NULL;
                yeni_eleman1->adres =yeni_eleman1;
            }
            else
            {
                q1 = start1;
                while(q1->next!=NULL)
                {
                    q1 = q1->next;
                }
                q1->next = yeni_eleman1;
                yeni_eleman1->next=NULL;
                yeni_eleman1->prev=q1;
                yeni_eleman1->adres =yeni_eleman1;

            }
            eleman1++;
        }
        if(eleman2<ikinci)
        {
            struct Liste2 *yeni_eleman2;
            yeni_eleman2 = (struct Liste2*)malloc(sizeof(struct Liste2));
            yeni_eleman2->data=x;
            x++;

            if (start2 == NULL)
            {
                start2 = yeni_eleman2;
                yeni_eleman2->next = NULL;
                yeni_eleman2->prev= NULL;
                yeni_eleman2->adres =yeni_eleman2;
            }
            else
            {
                q2 = start2;
                while(q2->next!=NULL)
                {
                    q2 = q2->next;
                }
                q2->next = yeni_eleman2;
                yeni_eleman2->next=NULL;
                yeni_eleman2->prev=q2;
                yeni_eleman2->adres =yeni_eleman2;

            }
            eleman2++;
        }

        if((eleman1==birinci) && (eleman2==ikinci))
        {
            break;
        }
    }
}

void Listeleme(int x)
{
    int i=1;

    printf("\n\n1.Liste Eleman Bilgileri Ekrana Yaziliyor....");
    q1 = start1;
    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    while(q1->next!=NULL)
    {
        printf("%d. Data: %d / Adres: %p\n\n",i,q1->data,q1->adres);
        q1 = q1->next;
        printf("------------------------------------------------------------\n");
        i++;
    }
    printf("%d. Data: %d / Adres: %p\n\n",i,q1->data,q1->adres);
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");


    if (x==1)
    {
        printf("2.Liste Eleman Bilgileri Ekrana Yaziliyor....");
        q2 = start2;
        i=1;
        printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        while(q2->next!=NULL)
        {
            printf("%d.Data: %d / Adres: %p\n\n",i,q2->data,q2->adres);
            q2 = q2->next;
            printf("------------------------------------------------------------\n");
            i++;
        }
        printf("%d.Data: %d / Adres: %p\n\n",i,q2->data,q2->adres);
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }
}


void YenidenDuzenleme(int birinci,int ikinci)
{
    struct Liste2 *temp;

    int sayac=0;

    q2 = start2;
    q1 = start1;

    while(0==0)
    {
        if (birinci > ikinci)
        {
            if (sayac == ikinci)
            {
                break;
            }

            if (strcmp(q1->adres,q2->adres)>0)
            {
                temp = q2;
                q2 = q2->next;
                temp->next = q1;
                temp->prev = q1->prev;
                q1->prev->next = temp;
                q1->prev = temp;
                sayac++;
            }
            q1 = q1->next;
        }
        else
        {
            if (sayac == ikinci)
            {
                break;
            }


            if (birinci-1>sayac)
            {

                if (strcmp(q1->adres,q2->adres)>0)
                {
                    temp = q2;
                    q2 = q2->next;
                    temp->next = q1;
                    temp->prev = q1->prev;
                    q1->prev->next = temp;
                    q1->prev = temp;
                    sayac++;
                }
                if (birinci-1>sayac)
                {
                    q1 = q1->next;
                }

            }
            else
            {
                temp = q2;
                q2 = q2->next;

                temp->next = NULL;
                temp->prev = q1;
                q1->next=temp;
                q1 = q1->next;
                sayac++;
            }

        }

    }
}

TersCevirme()
{
    struct Liste1 *temp;
    q1 = start1;
    while(q1->next!=NULL)
    {
        temp = q1->prev;
        q1->prev = q1->next;
        q1->next = temp;
        q1 = q1->prev;
    }
    temp = q1->prev;
    q1->prev = q1->next;
    q1->next = temp;
    start1 = q1;
}







int main()
{
    int birinci,ikinci;

    printf("Lutfen 1.Cift Yonlu Bagli Listeye kac eleman eklmek istiyorsaniz giriniz: ");
    scanf("%d",&birinci);
    printf("Lutfen 2.Cift Yonlu Bagli Listeye kac eleman eklmek istiyorsaniz giriniz: ");
    scanf("%d",&ikinci);
    ekleme(birinci,ikinci);
    printf("\n\n\nCift Yonlu Bagli Listelere Eleman Eklemesi Yapildi.\n");
    printf("*************************************************************************************************");
    Listeleme(1);
    printf("*************************************************************************************************");
    YenidenDuzenleme(birinci,ikinci);
    printf("\n\n\nTum Elemanlar Referans Numarasina Gore 1.Bagli Listede Birlestirildi.\n");
    printf("*************************************************************************************************");
    Listeleme(1);
    printf("*************************************************************************************************");
    TersCevirme();
    printf("\n\n\n1.Bagli Listedeki Elemanlarin Yonu Tersine Cevrildi.\n");
    printf("*************************************************************************************************");
    Listeleme(1);
    printf("*************************************************************************************************");



    return 0;
}
