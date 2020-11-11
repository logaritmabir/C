//Data_Struct_Program_2 'till 12.11.2020 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musteri
{
    int indeks;
    char isim[8];
    int fatura;
    struct musteri *sonraki;
};
int sayac;
struct musteri *baslangic = NULL;
struct musteri *aktarma = NULL;
struct musteri *aktarma2 = NULL;
void musteriekle(char isim[8],int fatura);
void yazdir();
void faturayagoreindexlistesi();
void indeksileyazdir();
void indexata();

int main(void)
{
    musteriekle("Ahmet",100);       //Müşterilerin sırasız bir şekilde bağlı listesinin oluşturulması           
    musteriekle("Bilal",1000);
    musteriekle("Cemal",600);
    musteriekle("Adem",650);
    musteriekle("Yasin",350);
    musteriekle("Esin",270);
    musteriekle("Emel",410);
    musteriekle("Mustafa",750);
    musteriekle("Ayten",600);
    musteriekle("Ceylan",1000);
    musteriekle("Nesrin",900);
    musteriekle("Bekir",850);
    musteriekle("Emin",790);
    musteriekle("Hakan",610);
    musteriekle("Hatice",550);
    yazdir();
    indexata();
    printf("\n\n");
    indeksileyazdir();
    printf("\n\n");
    faturayagoreindexlistesi();
    indeksileyazdir();

}
void musteriekle(char isim[8],int fatura)       //Müşterilerilerden bağlı liste oluşturan fonksiyon
{
    struct musteri *musteri;
    musteri = (struct musteri *)malloc(sizeof(struct musteri));
    musteri->fatura = fatura;
    musteri->sonraki = NULL;
    strcpy(musteri->isim,isim);


    if (baslangic == NULL)
    {
        baslangic = musteri;
    }
    else
    {
        aktarma = baslangic;
        while(aktarma->sonraki != NULL)
        {
            aktarma = aktarma->sonraki;
        }
        aktarma->sonraki = musteri;
    }
}
void yazdir()       //Sırasız  bağlı listeyi yazdıran fonksiyon
{
    aktarma2=baslangic;
    while (aktarma2->sonraki != NULL)
    {
        printf("%s %d\n",aktarma2->isim,aktarma2->fatura);
        aktarma2 = aktarma2->sonraki;
    }
    printf("%s %d ",aktarma2->isim,aktarma2->fatura);
}
void indeksileyazdir()      // İndeksli şekilde bağlı listeyi yazdıran fonksiyon
{
    aktarma2=baslangic;
    while (aktarma2->sonraki != NULL)
    {
        printf("%d %s %d\n",aktarma2->indeks,aktarma2->isim,aktarma2->fatura);
        aktarma2 = aktarma2->sonraki;
    }
    printf("%d %s %d",aktarma2->indeks,aktarma2->isim,aktarma2->fatura);   
}
void indexata()         //Sıralanmamış şekilde bağlanan bağlı listeye indisleri atayan fonksiyon
{
    sayac=0;
    aktarma2 = baslangic;
    while (aktarma2->sonraki != NULL)
    {
        aktarma2->indeks = sayac;
        sayac +=1;
        aktarma2 = aktarma2->sonraki;
    }
    aktarma2->indeks=sayac;
}

void faturayagoreindexlistesi()     //Faturayı büyükten küçüğe doğru yazdırma
{
    int i,f1,f2,i1,i2;
    char n1[8],n2[8];
    aktarma2 = baslangic;
    for (i=0;i<=sayac;i++)
    {
        aktarma2 = baslangic;
        while (aktarma2->sonraki != NULL)
        {
            if(aktarma2->fatura <= aktarma2->sonraki->fatura)
            {
                f1 = aktarma2->fatura;
                f2 = aktarma2->sonraki->fatura;
                i1 = aktarma2->indeks;
                i2 = aktarma2->sonraki->indeks;
                strcpy(n2,aktarma2->isim);
                strcpy(n1,aktarma2->sonraki->isim); 
                aktarma2->sonraki->indeks = i1;
                aktarma2->indeks = i2;
                aktarma2->sonraki->fatura = f1;
                aktarma2->fatura = f2;
                strcpy(aktarma2->sonraki->isim,n2);
                strcpy(aktarma2->isim,n1);
            }
            aktarma2 = aktarma2->sonraki;
        }
    }
}