#include <stdio.h>
#include <stdlib.h>

void urun_kaydet();
void urun_goster();

struct et       //Et yapisinin olusturulmasi
{
    struct et *next;
    char isim[20];
    int tl;
    char etturu;
    int paketlenme[9];
    int sonkullanma[10];
};
struct tarim        //Tarim yapisinin olusturulmasi
{
    char isim[20];
    int tl;
    char tarimturu;
    int alinmatarihi[10];
    struct tarim *next;
};
struct sut      // Sut yapisinin olusturulmasi
{
    char isim[20];
    int tl;
    char sonkullanma[10];
    struct sut *next;
};
struct konserve     //Konserve yapisinin olusturulmasi
{
    char isim[20];
    int tl;
    int sonkullanma[7];
    int reyon;
    char reyontaraf;
    struct konserve *next;
};
struct gidadisi     //Gida disi yapisinin olusturulmasi
{
    char isim[20];
    int tl;
    char gidadisitur;
    int reyon;
    char reyontaraf;
    struct gidadisi *next;
};

struct et *topet = NULL;        //Yigitlarin ilk dügümü
struct tarim *toptarim = NULL;
struct sut *topsut = NULL;
struct konserve *topkonserve = NULL;
struct gidadisi *topgidadisi = NULL;


int main(void)
{
    urun_kaydet();      //Urun girisleri
    urun_kaydet();
    urun_kaydet();
    urun_kaydet();
    urun_kaydet();
    
    printf("--------------------------KAYITLI URUNLER--------------------------\n");
    
    urun_goster();      //Urunlerin yazdirilmasi
}

void urun_goster()      //Istenilen kategorideki urunleri yazdiran fonksiyon(Istege gore tum urunlerin yazdirilmasi)
{
    char A;
    printf("Yazdirmak istediginiz urun kategorisini giriniz (E : Et , T : Tarim , S : Sut , K : Konserve , G : Gida Disi ; I : Tum urunler) -> ");
    scanf("%s",&A);
    if(A == 'E')
    {
        struct et *aktarma = (struct et*)malloc(sizeof(struct et));
        aktarma = topet;
        while(aktarma != NULL)
        {
            printf("%s  %d  %c  %s  %s\n",aktarma->isim,aktarma->tl,aktarma->etturu,aktarma->paketlenme,aktarma->sonkullanma);
            aktarma = aktarma->next;
        }
    }
    else if(A == 'T')
    {
        struct tarim *aktarma = (struct tarim*)malloc(sizeof(struct tarim));
        aktarma = toptarim;
        while(aktarma != NULL)
        {
            printf("%s  %d  %c  %s\n",aktarma->isim,aktarma->tl,aktarma->tarimturu,aktarma->alinmatarihi);
            aktarma = aktarma->next;
        }
    }
    else if(A == 'S')
    {
        struct sut *aktarma = (struct sut*)malloc(sizeof(struct sut));
        aktarma = topsut;
        while(aktarma != NULL)
        {
            printf("%s  %d  %s\n",aktarma->isim,aktarma->tl,aktarma->sonkullanma);
            aktarma = aktarma->next;
        }
    }
    else if(A == 'G')
    {
        struct gidadisi *aktarma = (struct gidadisi*)malloc(sizeof(struct gidadisi));
        aktarma = topgidadisi;
        while(aktarma != NULL)
        {
            printf("%s  %d  %c  %d  %c\n",aktarma->isim,aktarma->tl,aktarma->gidadisitur,aktarma->reyon,aktarma->reyontaraf);
            aktarma = aktarma->next;
        }
    }
    else if(A == 'K')
    {
        struct konserve *aktarma = (struct konserve*)malloc(sizeof(struct konserve));
        aktarma = topkonserve;
        while(aktarma != NULL)
        {
            printf("%s  %d  %s  %d  %c\n",aktarma->isim,aktarma->tl,aktarma->sonkullanma,aktarma->reyon,aktarma->reyontaraf);
            aktarma = aktarma->next;
        }
    }
    else if(A == 'I')       //Tum urunlerin yazdirilmasi
    {
        struct et *aktarmaET = (struct et*)malloc(sizeof(struct et));
        aktarmaET = topet;
        while(aktarmaET != NULL)
        {
            printf("%s  %d  %c  %s  %s\n",aktarmaET->isim,aktarmaET->tl,aktarmaET->etturu,aktarmaET->paketlenme,aktarmaET->sonkullanma);
            aktarmaET = aktarmaET->next;
        }
        struct tarim *aktarmaTAR = (struct tarim*)malloc(sizeof(struct tarim));
        aktarmaTAR = toptarim;
        while(aktarmaTAR != NULL)
        {
            printf("%s  %d  %c  %s\n",aktarmaTAR->isim,aktarmaTAR->tl,aktarmaTAR->tarimturu,aktarmaTAR->alinmatarihi);
            aktarmaTAR = aktarmaTAR->next;
        }
        struct sut *aktarmaSUT = (struct sut*)malloc(sizeof(struct sut));
        aktarmaSUT = topsut;
        while(aktarmaSUT != NULL)
        {
            printf("%s  %d  %s\n",aktarmaSUT->isim,aktarmaSUT->tl,aktarmaSUT->sonkullanma);
            aktarmaSUT = aktarmaSUT->next;
        }
        struct konserve *aktarmaKON = (struct konserve*)malloc(sizeof(struct konserve));
        aktarmaKON = topkonserve;
        while(aktarmaKON != NULL)
        {
            printf("%s  %d  %s  %d  %c\n",aktarmaKON->isim,aktarmaKON->tl,aktarmaKON->sonkullanma,aktarmaKON->reyon,aktarmaKON->reyontaraf);
            aktarmaKON = aktarmaKON->next;
        }
        struct gidadisi *aktarmaGIDA= (struct gidadisi*)malloc(sizeof(struct gidadisi));
        aktarmaGIDA = topgidadisi;
        while(aktarmaGIDA != NULL)
        {
            printf("%s  %d  %c  %d  %c\n",aktarmaGIDA->isim,aktarmaGIDA->tl,aktarmaGIDA->gidadisitur,aktarmaGIDA->reyon,aktarmaGIDA->reyontaraf);
            aktarmaGIDA = aktarmaGIDA->next;
        }
    }
}
void urun_kaydet()      //Istenilen yapiya urun ekleyen fonksiyon
{
    char X;
    printf("Urun kategorisini seciniz (E,T,S,G,K) -> ");
    scanf("%s",&X);
    if(X == 'E')
    {
        struct et *yeniet = (struct et *)malloc(sizeof(struct et));

        printf("Urun adini giriniz -> ");
        scanf("%s",yeniet->isim);
        
        printf("Urunun TL cinsinden birim maliyetini giriniz -> ");
        scanf("%d",&yeniet->tl);
        
        printf("Et turunu giriniz ->(R: Kirmizi Et, B: Balik, P : Tavuk) -> ");
        scanf(" %c",&yeniet->etturu);

        printf("Urunun paketlenme tarihi (#-#-#) -> ");
        scanf("%s",yeniet->paketlenme);

        printf("Urunun son kullanma tarihi (#-#-#) ->");
        scanf("%s",yeniet->sonkullanma);

        yeniet->next = NULL;
        if(topet != NULL)
        {
            yeniet->next = topet;
        }
        topet = yeniet;

    }
    else if(X == 'T')
    {
        struct tarim *yenitarim = (struct tarim *)malloc(sizeof(struct tarim));

        printf("Urun adini giriniz -> ");
        scanf("%s",yenitarim->isim);
        
        printf("Urunun TL cinsinden birim maliyetini giriniz -> ");
        scanf("%d",&yenitarim->tl);
        
        printf("Urunun tarim turunu giriniz (M: Meyve, S: Sebze) -> ");
        scanf(" %c",&yenitarim->tarimturu);

        printf("Urunun alinma tarihi (#-#-#) -> ");
        scanf("%s",&yenitarim->alinmatarihi);

        yenitarim->next = NULL;
        if(toptarim != NULL)
        {
            yenitarim->next = toptarim;
        }
        toptarim = yenitarim;
    }
    else if(X == 'S')
    {
        struct sut *yenisut = (struct sut *)malloc(sizeof(struct sut));

        printf("Urun adini giriniz -> ");
        scanf("%s",yenisut->isim);
        
        printf("Urunun TL cinsinden birim maliyetini giriniz -> ");
        scanf("%d",&yenisut->tl);

        printf("Urunun son kullanma tarihi (#-#-#) ->");
        scanf("%s",yenisut->sonkullanma);
        
        yenisut->next = NULL;
        if(topsut != NULL)
        {
            yenisut->next = topsut;
        }
        topsut = yenisut;
    }
    else if(X == 'K')
    {
        struct konserve *yenikonserve = (struct konserve *)malloc(sizeof(struct konserve));

        printf("Urun adini giriniz -> ");
        scanf("%s",yenikonserve->isim);
        
        printf("Urunun TL cinsinden birim maliyetini giriniz -> ");
        scanf("%d",&yenikonserve->tl);

        printf("Urunun son kullanma tarihi (Sadece ay ve yil) (#-#) ->");
        scanf("%s",yenikonserve->sonkullanma);

        printf("Urunun reyon numarasi (bir tam sayi) -> ");
        scanf("%d",&yenikonserve->reyon);

        printf("Urunun reyon tarafi (A ya da B) -> ");
        scanf("%s",&yenikonserve->reyontaraf);

        yenikonserve->next = NULL;
        if(topkonserve != NULL)
        {
            yenikonserve->next = topkonserve;
        }
        topkonserve = yenikonserve;
    }
    else if(X == 'G')
    {
        struct gidadisi *yenigidadisi = (struct gidadisi *)malloc(sizeof(struct gidadisi));

        printf("Urun adini giriniz -> ");
        scanf("%s",yenigidadisi->isim);
        
        printf("Urunun TL cinsinden birim maliyetini giriniz -> ");
        scanf("%d",&yenigidadisi->tl);

        printf("Urunun turu (C: Temizlik urunleri, P: Eczane, D : Diger urunler) -> ");
        scanf("%s",&yenigidadisi->gidadisitur);

        printf("Urunun reyon numarasi (bir tam sayi) -> ");
        scanf("%d",&yenigidadisi->reyon);

        printf("Urunun reyon tarafi (A ya da B) -> ");
        scanf("%s",&yenigidadisi->reyontaraf);
                
        yenigidadisi->next = NULL;
        if(topgidadisi != NULL)
        {
            yenigidadisi->next = topgidadisi;
        }
        topgidadisi = yenigidadisi;
    }
    else 
    {
        printf("Hatali tuslama\n");
    }
}