//Data_Structs_Program_1 'till 05.11.2020 
#include <stdio.h>

int FindCorrectPosition(int Index ,int Number,int Grade ,int grades[][3],int IndexList[]);                   
int IndexToBeDeleted(int Index,int IndexList[]);
int GradeToBeChanged(int Index,int Number,int NewGrade,int grades[][3],int IndexList[]);
int PrintGrade(int Grade,int grades[][3],int IndexList[]);

int main(void)
{
    int i;
    int Indexes[15]={0};
    int StudentList[15][3]=     
    {
        {0,18060311,40},
        {1,20060045,50},
        {2,19061091,75},
        {3,20060134,90},
        {4,20060678,40},
        {5,18061086,75},
        {6,20060032,50},
        {7,20060067,60},
        {8,19060456,60},
        {9,18060245,75},
        {10,20060110,40},
        {11,20060234,90},
        {12,20060141,60},
        {13,20060011,50},
        {14,20060012,60},
    };  
    for(i=0;i<15;i++)       //Tüm listenin 1-Ekle fonksiyonundan geçirilmesi
    {
        FindCorrectPosition(StudentList[i][0],StudentList[i][1],StudentList[i][2],StudentList,Indexes);
    }

    for(i=0;i<15;i++)       //İlk oluşturulan index listesinin yazdırılması
    {
        printf("%d\n",Indexes[i]);
    }
    
    printf("\n");

    GradeToBeChanged(13,20060011,100,StudentList,Indexes);       //3-Değiştir fonksiyonu ile herhangi bir öğrencinin notunun değiştirilmesi
    
    for(i=0;i<15;i++)       //İşlem sonrası oluşan index listesinin yazdırılması
    {
        printf("%d\n",Indexes[i]);
    }
    printf("\n");
    
    IndexToBeDeleted(10,Indexes);       //2-Sil fonksiyonu ile herhangi bir indeksli öğrencinin notunun silinmesi
    IndexToBeDeleted(9,Indexes);
    
    for(i=0;i<15;i++)       //İşlem sonrası oluşan index listesinin yazdırılması
    {
        printf("%d\n",Indexes[i]);
    }
    printf("\n");

    PrintGrade(60,StudentList,Indexes);         //4-Yazdır fonksiyonu ile istenilen notdan yüksek olan notların index sırasına göre yazdırılması
}
int FindCorrectPosition(int Index ,int Number,int Grade ,int grades[][3],int IndexList[])       //1-Ekle Fonksiyonu
{
    int counter=0;
    int k;
    for(k=0;k<15;k++)
    {
        if(Grade < grades[k][2])
        {
            counter+=1;
        }
        else if(Grade == grades[k][2] && Number > grades[k][1])
        {
            counter+=1;
        }
    }
    IndexList[counter]=grades[Index][0];
    counter=0;
}
int IndexToBeDeleted(int Index,int IndexList[])     //2-Sil Fonksiyonu
{
    int i,j;
    for(i=0;i<15;i++)
    {
        if(IndexList[i] == Index)
        {
            break;
        }
    }
    for(j=i;j<15;j++)
    {
        IndexList[j]=IndexList[j+1];
    }
    IndexList[j-1]=0;       //Listeden eleman çıkarıldığı için son eleman(lar)a "0" değeri atanması
}
int GradeToBeChanged(int Index,int Number,int NewGrade,int grades[][3],int IndexList[])     //3-Değiştir Fonksiyonu
{
    int i;
    grades[Index][2] = NewGrade;
    for(i=0;i<15;i++)
    {
        FindCorrectPosition(grades[i][0],grades[i][1],grades[i][2],grades,IndexList);
    }
}
int PrintGrade(int Grade,int grades[][3],int IndexList[])       //4-Yazdır Fonksiyonu
{
    int i;
    int j;
    for(i=0;i<15;i++)
    {
        j = IndexList[i];
        if(grades[j][2] > Grade)
        {
            printf("%d %d\n",j,grades[j][2]);
        }
    }
}
