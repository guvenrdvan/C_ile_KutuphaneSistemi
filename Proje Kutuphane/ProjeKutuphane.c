#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_KISI_SAYISI 50
#define MAX_KITAP_SAYISI 50

typedef enum{
	ogrenci=0,calisan=1	
}YetkiSeviyeleri;

typedef struct{
	char *uyeAdi;
	char *uyeSoyadi;
	int kutuphaneID;
	int sifre;
	YetkiSeviyeleri kisiYetkisi;
}kisiBilgileri;

typedef struct{
	char *kitapAdi;
	char *yazarAdi;
	char *yazarSoyadi;
	char *yayinEvi;
	int sayfaSayisi;
	int kitapDurumu;
}kitapBilgileri;

int kisiSorgula(kisiBilgileri *uyeListesi,int ID){
	int i;
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==ID){
				return ID; //Daha önce kullanýldýðýný gösteriyor.
		}
	return -1;//Kullanýlabilir olduðunu gösteriyor.	
}
}

int kayitOl(kisiBilgileri *uyeListesi){
	
	int i,kayitYapilacakIndex,ID;
	char kisiAdi[30],kisiSoyadi[30],ch;
	
	srand(time(NULL));
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==0){
				kayitYapilacakIndex=i;
				break;
		}
	}
	ID=rand()%100000+1;
	
	if(kisiSorgula(uyeListesi,ID)!=-1){
		printf("Bu ID degeri kullanilmaktadir.... Kayit yapilamiyor.\n ");
		exit(1);
	}
	
	printf("ID numaraniz  %d olarak belirlenmistir \n",ID);
	uyeListesi[kayitYapilacakIndex].kutuphaneID=ID;
	
	printf("\nLutfen sirasiyla Ad-Soyad giriniz: ");
	scanf("%s%s",&kisiAdi,&kisiSoyadi);
	
	uyeListesi[kayitYapilacakIndex].uyeAdi=(char*)malloc(sizeof(char)*(strlen(kisiAdi)+1));//Buradaki +1 sondaki null karakterden kaynaklanýyor.
	uyeListesi[kayitYapilacakIndex].uyeSoyadi=(char*)malloc(sizeof(char)*(strlen(kisiSoyadi)+1));
	strcpy(uyeListesi[kayitYapilacakIndex].uyeAdi,kisiAdi);
	strcpy(uyeListesi[kayitYapilacakIndex].uyeSoyadi,kisiSoyadi);
	puts("\nLutfen ogrenciyseniz 'O' calisansaniz 'C' tuslamasini yapiniz: ");
	fflush(stdin);
	ch=getchar();
	if(ch=='O'){
		uyeListesi[kayitYapilacakIndex].kisiYetkisi=ogrenci;
	}
	else{
		uyeListesi[kayitYapilacakIndex].kisiYetkisi=calisan;
	}
     
     puts("\nLutfen sifrenizi giriniz: ");
     scanf("%d",&uyeListesi[kayitYapilacakIndex].sifre);
     return uyeListesi[kayitYapilacakIndex].kisiYetkisi;
}

void kitapGoruntule(kitapBilgileri *kitapListesi){
	int i;
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitapListesi[i].sayfaSayisi!=0){
			printf("----------------------------------------------------------------------------------\n");	
			printf("Kitap Adi: %s \n",kitapListesi[i].kitapAdi);
			printf("Kitap Yazari: %s %s \n",kitapListesi[i].yazarAdi,kitapListesi[i].yazarSoyadi);
			printf("Yayýnevi: %s \n",kitapListesi[i].yayinEvi);
			printf("Sayfa Sayisi: %d \n",kitapListesi[i].sayfaSayisi);
			if(kitapListesi[i].kitapDurumu==0){
				printf("Bu kitap su an raftadir. \n");
			}
			else{
				printf("Bu kitap su an baskasi tarafýndan alinmistir. \n");
			}
			printf("----------------------------------------------------------------------------------\n");	
		}
		else{
			return;
		}
	}	
}

void kitapAra(kitapBilgileri *kitapListesi){
	int i=0;
	char aranacakKitap[50];
	puts("Lutfen aramak istediginiz kitabin adini giriniz: ");
	fflush(stdin);//Buffer ý temizlemek için.
	scanf("%s",&aranacakKitap);
	
	while(i<MAX_KITAP_SAYISI && kitapListesi[i].sayfaSayisi!=0){
		if(strcmp(kitapListesi[i].kitapAdi,aranacakKitap)==0){
			puts("------------------------------------------------------------------------------------------------\n");
			printf("Kitap Adi: %s \n",kitapListesi[i].kitapAdi);
			printf("Kitap Yazari: %s %s \n",kitapListesi[i].yazarAdi,kitapListesi[i].yazarSoyadi);
			printf("Yayýnevi: %s \n",kitapListesi[i].yayinEvi);
			printf("Sayfa Sayisi: %d \n",kitapListesi[i].sayfaSayisi);
			puts("------------------------------------------------------------------------------------------------\n");
			return;
		}
		i++;
	}	
	puts("Malesef Aradiginiz Kitap Kutuphanemizde Bulunmamaktadir. \n");
}
void kitapEkle(kitapBilgileri *kitapListesi){
	int sayfaSayisi,i;
	char kitapAdi[50],yazarAdi[50],yazarSoyadi[50],yayinEvi[50];
	puts("\nLutfen Kitap Adini giriniz: ");
	scanf("%s",&kitapAdi);
	puts("Lutfen Yazar Ad-Soyad giriniz: ");
	scanf("%s%s",&yazarAdi,&yazarSoyadi);
	puts("Lutfen Kitabýn Yayýnevini giriniz: ");
	scanf("%s",&yayinEvi);
	puts("Lutfen Kitabýn Sayfa Sayisini giriniz: ");
	scanf("%d",&sayfaSayisi);
	
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitapListesi[i].sayfaSayisi==0){
			kitapListesi[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
			kitapListesi[i].yazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
			kitapListesi[i].yazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
			kitapListesi[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
			strcpy(kitapListesi[i].kitapAdi,kitapAdi);
			strcpy(kitapListesi[i].yazarAdi,yazarAdi);
			strcpy(kitapListesi[i].yazarSoyadi,yazarSoyadi);
			strcpy(kitapListesi[i].yayinEvi,yayinEvi);
		    kitapListesi[i].sayfaSayisi=sayfaSayisi;
		    break;
		}
	}	
}

void uyeGoruntule(kisiBilgileri *uyeListesi){
	int i=0;
	while(i<MAX_KISI_SAYISI && uyeListesi[i].kutuphaneID!=0){
		puts("---------------------------------------------------------------------\n");
		printf("Uye Adi-Soyadi: %s %s \n",uyeListesi[i].uyeAdi,uyeListesi[i].uyeSoyadi);
		printf("Uye ID: %d\n",uyeListesi[i].kutuphaneID);
		if(uyeListesi[i].kisiYetkisi==1){
			printf("Uye Durumu: CALISAN \n");
		}
	    else{
	    	printf("Uye Durumu: OGRENCI \n");
		} 
	printf("Uye Adi-Soyadi: %s %s \n",uyeListesi[i].uyeAdi,uyeListesi[i].uyeSoyadi);
	puts("---------------------------------------------------------------------\n");
	i++;
	}
}

int girisYap(kisiBilgileri *uyeListesi){
	int ID,i,sifre;
	puts(" Lutfen kutuphane ID'nizi giriniz: ");
	scanf("%d",&ID);
	puts("Lutfen kutuphane sifrenizi giriniz: ");
	scanf("%d",&sifre);
	
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==ID){
			if(uyeListesi[i].sifre==sifre){
				puts("\nID-SIFRE dogru...Giris Basarili.\n");
				return uyeListesi[i].kisiYetkisi;
			}
			return -1;//Sifre yanlýþ olduðu için giriþ baþarýsýz bilgisi dönücek.
						
		}
		
	}
	return -2;//ID yanlýþ olduðu için giriþ baþarýsýz bilgisi dönücek.
}

void uyeleriAktar(kisiBilgileri *uyeListesi){
	int i;
	char kisiAdi[30],kisiSoyadi[30];
	FILE *uyeKayitlari;
	uyeKayitlari=fopen("uyeListesi.txt","r");
	if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesine ulasilirken bir hata meydana geldi. \n ");
		exit(1);
	}	
	while(!feof(uyeKayitlari)){
		for(i=0;i<MAX_KISI_SAYISI;i++){
			if(uyeListesi[i].kutuphaneID==0){
				fscanf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",kisiAdi,kisiSoyadi,&uyeListesi[i].kisiYetkisi,&uyeListesi[i].kutuphaneID,&uyeListesi[i].sifre);
				uyeListesi[i].uyeAdi=(char*)malloc(sizeof(char)*(strlen(kisiAdi)+1));
				uyeListesi[i].uyeSoyadi=(char*)malloc(sizeof(char)*(strlen(kisiSoyadi)+1));
				strcpy(uyeListesi[i].uyeAdi,kisiAdi);
				strcpy(uyeListesi[i].uyeSoyadi,kisiSoyadi);
				break;
			}
		}				
	}
	fclose(uyeKayitlari);
}

void kitaplariAktar(kitapBilgileri *kitapListesi){
	FILE *kitapKayitlari;
	int i;
	char kitapAdi[50],yazarAdi[50],yazarSoyadi[50],yayinEvi[50];
	kitapKayitlari=fopen("kitapListesi.txt","r");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine ulasilirken bir hata meydana geldi. \n ");
		exit(1);
	}
	
	while(!feof(kitapKayitlari)){
		for(i=0;i<MAX_KITAP_SAYISI;i++){
			if(kitapListesi[i].sayfaSayisi==0){
				fscanf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitapAdi,yazarAdi,yazarSoyadi,yayinEvi,&kitapListesi[i].sayfaSayisi,&kitapListesi[i].kitapDurumu);
				kitapListesi[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
				kitapListesi[i].yazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
				kitapListesi[i].yazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
				kitapListesi[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
				
				strcpy(kitapListesi[i].kitapAdi,kitapAdi);
				strcpy(kitapListesi[i].yazarAdi,yazarAdi);
				strcpy(kitapListesi[i].yazarSoyadi,yazarSoyadi);
				strcpy(kitapListesi[i].yayinEvi,yayinEvi);
				break;	
			}			
		}
	}	
	fclose(kitapKayitlari);	
}
void kitaplariYedekle(kitapBilgileri *kitapListesi){
	FILE *kitapKayitlari;
	int i=0;
	kitapKayitlari=fopen("kitapListesi.txt","w");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine ulasilirken bir hata meydana geldi. \n ");
		exit(1);
	}
	while(i<MAX_KITAP_SAYISI && kitapListesi[i].sayfaSayisi!=0){
		fprintf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitapListesi[i].kitapAdi,kitapListesi[i].yazarAdi,kitapListesi[i].yazarSoyadi,kitapListesi[i].yayinEvi,kitapListesi[i].sayfaSayisi,kitapListesi[i].kitapDurumu);
		      i++;
	}
	fclose(kitapKayitlari);
}

void uyeleriYedekle(kisiBilgileri *uyeListesi){
		FILE *uyeKayitlari;
		int i=0;
		uyeKayitlari=fopen("uyeListesi.txt","w");
		
		if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesine ulasilirken bir hata meydana geldi. \n ");
		exit(1);
	}	
	while(i<MAX_KISI_SAYISI && uyeListesi[i].kutuphaneID!=0){
		fprintf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",uyeListesi[i].uyeAdi,uyeListesi[i].uyeSoyadi,uyeListesi[i].kisiYetkisi,uyeListesi[i].kutuphaneID,uyeListesi[i].sifre);
               i++;
	}
	fclose(uyeKayitlari);
}







int main(void){
	
	kitapBilgileri *kitaplik;
	kisiBilgileri  *uyeListesi;
	YetkiSeviyeleri uyeYetkisi;
	int girisDurumu;
	char ch;
	kitaplik=(kitapBilgileri*)calloc(MAX_KITAP_SAYISI,sizeof(kitapBilgileri));
	uyeListesi=(kisiBilgileri*)calloc(MAX_KISI_SAYISI,sizeof(kisiBilgileri));
	
	uyeleriAktar(uyeListesi);//Bu fonksiyonlarý program kapandýðýnda bilgilerin tekrar sisteme gelmesi için yazdým.
	kitaplariAktar(kitaplik);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("\t\t\t\tMerhabalar, Kutuphane Sistemine Hosgeldiniz. \n");
	printf("1.Sisteme Kayit Yapmak Icin 'K'\n2.Giris Yapmak Icin 'G'\n ");
	fflush(stdin);
	ch=getchar();
	if(ch=='K'||ch=='k'){
		girisDurumu=kayitOl(uyeListesi);//Öðrenci mi yoksa Çalýþan olup olmadýðýný kontrol ediyoruz.
	}
	else if(ch=='G'||ch=='g'){
		girisDurumu=girisYap(uyeListesi);//Öðrenci mi yoksa Çalýþan olup olmadýðýný kontrol ediyoruz.
		if(girisDurumu==-1){
			printf("Sifreniz yanlis.....Giris Yapilamiyor. \n");
			exit(1);
		}
		else if(girisDurumu==-2){
			printf("Sistemde boyle bir ID yok....Giris Yapilamiyor. \n");
			exit(1);
		}
	}
	else{
		puts("Yanlis bir tuslama yaptiniz.....Sistemden cikis yapiliyor. \n");
		exit(1);
	}
///////////////////////////////////////////////////////////////////////////////////	
	if(girisDurumu==1){
		uyeYetkisi=calisan;
	}
	else{
		uyeYetkisi=ogrenci;
	}
///////////////////////////////////////////////////////////////////////////////////	
	if(uyeYetkisi==ogrenci){
		do{
			printf("1.Tum kitaplari goruntulemek icin 'G'\n2.Kitap aramak icin 'A'\n3.Sistemden cikis yapmak icin 'Q' tuslamasini yapiniz: ");
			fflush(stdin);
			ch=getchar();
			switch(ch){
				case 'G':
				case 'g':
					kitapGoruntule(kitaplik);
					break;
					
				case 'A':
				case 'a':
				    kitapAra(kitaplik);
					break;
				
				case 'Q':
				case 'q':
				    kitaplariYedekle(kitaplik);
					uyeleriYedekle(uyeListesi);
					puts("Cikis Yapiliyor........");
					break;	
				
				default:
				puts("Hatali bir tuslama yaptiniz....Cikis Yapiliyor. ");
				break;		
			}
		}while(ch!='Q');	
	}
	else{
		
		do{
			printf("1.Kitap eklemek icin 'E'\n2.Tum uyeleri gormek icin 'U'\n3.Cikis yapmak icin 'Q' tuslamasini yapiniz: ");
			fflush(stdin);
			ch=getchar();
			
			switch(ch){
				 case 'E':
				 case 'e':
				 	kitapEkle(kitaplik);
				 	break;
				 		
				 case 'U':
				 case 'u':
				    uyeGoruntule(uyeListesi);
					break;
				
				case 'Q':
				case 'q':
				   	kitaplariYedekle(kitaplik);
					uyeleriYedekle(uyeListesi);
					puts("Cikis Yapiliyor........");
					break;
				
				default:
				   puts("Yanlis bir tuslama yaptiniz.....Sistemden Cikis Yapiliyor...");
				   break;		
			}
		}while(ch!='Q');	
	}
}

