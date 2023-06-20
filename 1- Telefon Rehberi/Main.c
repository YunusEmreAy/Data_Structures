// Yunus Emre Ay / E-posta:TR.yunus.emre.ay@gmail.com
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KisiBilgileri
{
    char isim[20];
    char soyisim[20];
    long int telefon;
    struct KisiBilgileri *next;

};

struct KisiBilgileri *start=NULL;
struct KisiBilgileri *q;

void ekleme()
{
    long int tel;
    int kontrol = 0;

    struct KisiBilgileri *yeni_eleman;
    yeni_eleman = (struct KisiBilgileri*)malloc(sizeof(struct KisiBilgileri));
    printf("Lutfen isim giriniz --> ");
    scanf("%s",&yeni_eleman->isim);
    printf("Lutfen soy isim giriniz --> ");
    scanf("%s",&yeni_eleman->soyisim);
    printf("Lutfen basina 0 koymadan telefon numarasi giriniz --> ");
    scanf("%ld",&tel);



    if (start == NULL)
    {
        yeni_eleman->telefon=tel;
        start = yeni_eleman;
        yeni_eleman->next = start;
    }
    else
    {
        while(0==0)
        {
            q = start;
            while(q->next!=start)
            {
                if (q->telefon==tel)
                {
                    kontrol=1;
                    break;
                }
                q = q->next;
            }
            if (q->telefon==tel)
            {
                kontrol=1;
            }
            if (kontrol == 0)
            {
                yeni_eleman->telefon=tel;
                break;
            }
            printf("\n\nGirdiginiz telefon numarasi sistemde kayitli, lutfen yeni bir numara giriniz -->");
            scanf("%ld",&tel);
            kontrol = 0;
        }

        q = start;
        while(q->next!=start)
        {
            q = q->next;
        }
        q->next = yeni_eleman;
        yeni_eleman->next=start;
        start = yeni_eleman;
    }

}

void listeleme()
{
    q = start;
    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    while(q->next!=start)
    {
        printf("isim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
        q = q->next;
        printf("------------------------------------------------------------\n");
    }
    printf("isim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

void arama()
{
    int a,kontrol=0;
    char aranacak_isim[20];
    long int aranacak_tel;
    printf("------------------------------\n\n");
    printf("1.isme gore arama\n2.Telefona gore arama\n\n");
    printf("------------------------------\n\n\n");
    printf("Gerceklestirmek istediginiz islemi seciniz -->");
    scanf("%d",&a);

    if(a==1)
    {
        printf("Aramak istediginiz ismi giriniz -->");
        scanf("%s",aranacak_isim);
        while(0==0)
        {
            q = start;
            while(q->next!=start)
            {
                if (strcmp(q->isim,aranacak_isim)==0)
                {
                    printf("\n\nisim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                    kontrol = 1;
                    break;
                }
                q = q->next;
            }
            if ((strcmp(q->isim,aranacak_isim)==0)&&(kontrol==0))
            {
                printf("\n\nisim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                kontrol=1;
                break;
            }
            if (kontrol == 0)
            {
                printf("\n\nGirdiginiz isim sistemde yer almamakta, lutfen yeni bir isim giriniz -->");
                scanf("%s",&aranacak_isim);
            }
            else
            {
                break;
            }
        }
    }
    else
    {
       printf("Aramak istediginiz telefon numarasini giriniz -->");
       scanf("%ld",&aranacak_tel);
        while(0==0)
        {
            q = start;
            while(q->next!=start)
            {
                if (q->telefon==aranacak_tel)
                {
                    printf("\n\nisim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                    kontrol = 1;
                    break;
                }
                q = q->next;
            }
            if ((q->telefon==aranacak_tel)&&(kontrol==0))
            {
                printf("\n\nisim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                kontrol=1;
                break;
            }
            if (kontrol == 0)
            {
                printf("\n\nGirdiginiz telefon numarasi sistemde yer almamakta, lutfen yeni bir telefon numarasi giriniz -->");
                scanf("%ld",&aranacak_tel);
            }
            else
            {
                break;
            }

        }
    }
}

void silme()
{
    long int aranacak_tel;
    struct KisiBilgileri *sil;
    struct KisiBilgileri *sonraki;
    struct KisiBilgileri *onceki;


    printf("Silmek istediginiz kaydin telefon numarasini giriniz -->");
    scanf("%ld",&aranacak_tel);

    q=start;
    if(start->telefon==aranacak_tel)
    {
        sil=start;
        sonraki=start->next;
        while(q->next!=start)
        {
            q = q->next;
        }
        onceki = q;
        free(sil);
        onceki->next=sonraki;

    }
    else
    {
        while(q->next->telefon!=aranacak_tel)
        {
            q = q->next;
        }
        sil = q->next;
        onceki = q;
        sonraki = q->next->next;
        free(sil);
        onceki->next=sonraki;
    }


}

void siralama()
{
    int i=0,a,j,k,kontrol = 0;
    char *elemanlar[10];
    char *temp;
    char aranacak_soyisim[20];

    q = start;
    while(q->next!=start)
    {
        elemanlar[i]=&(q->soyisim);
        q=q->next;
        i++;
    }
    elemanlar[i]=&(q->soyisim);

    for (k=0;k<i+1;k++)
    {
       for (j=0;j<i;j++)
       {
           if (strcmp(elemanlar[j],elemanlar[j+1])>0)
           {
               temp=elemanlar[j];
               elemanlar[j]=elemanlar[j+1];
               elemanlar[j+1]=temp;
           }
       }
     }


    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("------------------------------------------------------------\n");
    for (a=0;a<i+1;a++)
    {
        while(0==0)
        {
            q = start;
            while(q->next!=start)
            {
                if (strcmp(q->soyisim,elemanlar[a])==0)
                {
                    printf("isim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                    printf("------------------------------------------------------------\n");
                    kontrol = 1;
                    break;
                }
                q = q->next;
            }
            if ((strcmp(q->soyisim,elemanlar[a])==0)&&(kontrol==0))
            {
                printf("isim: %s / Soyisim: %s / Telefon numarasi: %ld \n\n",q->isim,q->soyisim,q->telefon);
                printf("------------------------------------------------------------\n");
                kontrol=1;
                break;
            }

            break;
        }
        kontrol = 0;

    }
    printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

}



int main()
{
    int secim;
    printf("Su an sistemde hic eleman olmadigi icin dogrudan eleman ekleme fonksiyonuna yonlendiriliyorsunuz.\n\n");
    ekleme();

    while(0==0)
    {
        printf("----------------------------------------------------------------------------------------------------\n\n");
        printf("1.Ekleme\n2.Listeleme\n3.Arama\n4.Siralama(soyada gore)\n5.Silme(Telefon numarasina gore)\n6.Cikis\n\n");
        printf("----------------------------------------------------------------------------------------------------\n\n\n");
        printf("Gerceklestirmek istediginiz islemi seciniz -->");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            ekleme();
            break;
        case 2:
            listeleme();
            break;
        case 3:
            arama();
            break;
        case 4:
            siralama();
            break;
        case 5:
            silme();
            break;
        case 6:
            return 0;
        }
    }



    return 0;
}
