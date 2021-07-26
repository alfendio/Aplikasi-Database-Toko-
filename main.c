#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct data{
    int kode_transaksi;
    char *kasir;
	char *barang;
    int jumlah_barang;
    int harga_barang;
    int bayar_barang;
    int kembali_barang;
    int tanggal_barang;
    struct data *next;
    struct data *prev;
}*head, *tail, *current, temp;
int no_riwayat = 1;
char riwayat[100][100];

void insert(int kode_tran, char ksr[50],char brg[50],  int jml, int hrg, int byr, int kembali){
    current = (struct data*)malloc(sizeof(struct data));

    current->barang=(char*)calloc(strlen(brg),sizeof(char));
    strncpy(current->barang,brg,strlen(brg));

    current->kasir=(char*)calloc(strlen(ksr),sizeof(char));
    strncpy(current->kasir,ksr,strlen(ksr));

    current->kode_transaksi = kode_tran;
    current->jumlah_barang = jml;
    current->harga_barang = hrg;
    current->bayar_barang = byr;
    current->kembali_barang = kembali;

    if(head==NULL){
        head=tail=current;
        head->next=NULL;
    }else{
        tail->next=current;
        tail=current;
    }
    tail->next=NULL;
    tail=current;
}

void tampil(){
	struct tm *Sys_T;
	time_t Tval;
	Tval = time(NULL);
	Sys_T = localtime(&Tval);
	Sys_T = gmtime(&Tval);
    current=head;

    while(current!=NULL){

       printf("       |  %i\t\t%s\t\t%s\t\t%i\t%i\t\%i\t%i\t %d/%d/%d       | \n", current->kode_transaksi, current->kasir, current->barang, current->jumlah_barang, current->harga_barang,current->bayar_barang, current->kembali_barang, Sys_T->tm_mday, Sys_T->tm_mon+1, 1900+Sys_T->tm_year);
        current=current->next;
    }

}

void hapusAtas(int hapus)
{
   current=head;

   if(current==NULL)
   {
       printf("\n\nMaaf, data tidak ditemukan \n\n");
       return;
   }

   if(current->kode_transaksi==hapus)
   {
       printf("\nData dengan kode transaksi %d telah berhasil dihapus\n\n",hapus);
       head=head->next=NULL;

       free(head);
   }


   while(current->next!=NULL)
   {
       if(current->next->kode_transaksi==hapus)
       {
           printf("\nData dengan kode transaksi %d telah berhasil dihapus\n",hapus);
           current->next=current->next->next;
           return;
       }
       current=current->next;
   }
}

void update(int code_transaksi){
    char name_kasir_baru[50];
    char name_barang_baru[50];
    int jml_barang_baru;
    int harga_barang_baru;
    int bayar_baru;
    char ksr_baru[50];
    char brg_baru[50];
    current = (struct data*)malloc(sizeof(struct data));

    if(head==NULL)
    {
        printf("\nMaaf, data dengan kode transaksi tersebut tidak ada \n");
        system("pause >nul | echo Tekan tombol apapun untuk kembali...");
        system("cls");
      return;

    }

     current=head;

    if(current->kode_transaksi==code_transaksi)
    {
            printf("Nama kasir baru    : ");
            scanf(" %s", name_kasir_baru);

            current->barang=(char*)calloc(strlen(name_kasir_baru),sizeof(char)); //bisa hapus
            strncpy(current->kasir,name_kasir_baru,strlen(name_kasir_baru)); //bisa hapus

            //barang
            printf("Nama barang baru   : ");
            scanf(" %s", name_barang_baru);
            current->barang=(char*)calloc(strlen(name_barang_baru),sizeof(char)); //bisa hapus
            strncpy(current->barang,name_barang_baru,strlen(name_barang_baru)); //bisa hapus

            //barang
            printf("Jumlah barang baru : ");
            scanf("%i", &jml_barang_baru);
            current->jumlah_barang=jml_barang_baru;

            printf("Harga barang baru  : ");
            scanf("%i", &harga_barang_baru);
            current->harga_barang=harga_barang_baru;

            printf("Jumlah bayar baru  : ");
            scanf("%i", &bayar_baru);
            current->bayar_barang=bayar_baru;

            current->kembali_barang=bayar_baru-(jml_barang_baru*harga_barang_baru);
            system("cls");
            return;
    }

    while(current!=NULL)
    {
        if(current->kode_transaksi==code_transaksi)
        {
            printf("Nama kasir baru    : ");
            scanf("%s", &name_kasir_baru);
            current->barang=(char*)calloc(strlen(name_kasir_baru),sizeof(char)); //bisa hapus
            strncpy(current->kasir,name_kasir_baru,strlen(name_kasir_baru)); //bisa hapus


            printf("Nama barang baru   : ");
            scanf("%s", &name_barang_baru);
            current->barang=(char*)calloc(strlen(name_barang_baru),sizeof(char)); //bisa hapus
            strncpy(current->barang,name_barang_baru,strlen(name_barang_baru)); //bisa hapus


            printf("Jumlah barang baru : ");
            scanf("%i", &jml_barang_baru);
            current->jumlah_barang=jml_barang_baru;

            printf("Harga barang baru  : ");
            scanf("%i", &harga_barang_baru);
            current->harga_barang=harga_barang_baru;

            printf("Jumlah bayar baru  : ");
            scanf("%i", &bayar_baru);
            current->bayar_barang=bayar_baru;

            current->kembali_barang=bayar_baru-(jml_barang_baru*harga_barang_baru);
            system("cls");
            return;
        }
        current = current->next;

    }
    printf("Maaf, tidak ada data\n\n");
    system("pause >nul | echo Tekan tombol apapun untuk kembali...");
    system("cls");
}

void tambahData(int kode_tran, char ksr[50],char brg[50],  int jml, int hrg, int byr, int kembali){
    current = (struct data*)malloc(sizeof(struct data));

    current->barang=(char*)calloc(strlen(brg),sizeof(char));
    strncpy(current->barang,brg,strlen(brg));

    current->kasir=(char*)calloc(strlen(ksr),sizeof(char));
    strncpy(current->kasir,ksr,strlen(ksr));

    current->kode_transaksi = kode_tran;
    current->jumlah_barang = jml;
    current->harga_barang = hrg;
    current->bayar_barang = byr;
    current->kembali_barang = kembali;

    if(head==NULL){
        head=tail=current;
        head->next=NULL;
    }else{
        tail->next=current;
        tail=current;
    }
    tail->next=NULL;
    tail=current;
}

void cariData(){
}

void history(){
}

void sorting(){
    system("color ED");
    system("cls");
    int temp_kode_transaksi;
    char temp_nama_barang [100];
    int temp_harga_barang;
    int temp_jumlah_barang;

    struct data *temp;

    int pilihan;
    printf("\t\t\t              +--------------------------------+\n");
    printf("\t\t\t               No.\t Urutkan berdasarkan\n");
    printf("\t\t\t              +--------------------------------+\n");
//    printf("\t\t\t\t               Urutkan berdasarkan :\n\n");
    printf("\t\t\t                1.\t Kode transaksi\n");
    printf("\t\t\t                2.\t Nama barang \n");
    printf("\t\t\t                3.\t Harga barang\n");
    printf("\t\t\t                4.\t Jumlah barang\n");
    printf("\t\t\t              +--------------------------------+\n");
    printf("\t\t\t              +--------------------------------+\n\n");
    printf("\t\t\t               Masukkan pilihan Anda : "); scanf("%d", &pilihan);

    switch(pilihan){
    case 1: //kode transaksi
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->kode_transaksi > temp->kode_transaksi)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    break;

    case 2: //nama barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(strcmp(current->barang, temp->barang) > 0)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");

    break;

    case 3: //harga barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->harga_barang > temp->harga_barang)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    break;

    case 4: //jumlah barang
        for(current = head; current!= NULL; current = current->next)
        {
            for(temp=current->next; temp!=NULL; temp=temp->next)
            {
                if(current->jumlah_barang > temp->jumlah_barang)
                {

                    temp_kode_transaksi = current->kode_transaksi;
                    current->kode_transaksi = temp->kode_transaksi;
                    temp->kode_transaksi = temp_kode_transaksi;

                    strcpy(temp_nama_barang,current->barang);
                    strcpy(current->barang, temp->barang);
                    strcpy(temp->barang, temp_nama_barang);


                    temp_harga_barang = current->harga_barang;
                    current->harga_barang = temp->harga_barang;
                    temp->harga_barang = temp_harga_barang;


                    temp_jumlah_barang = current->jumlah_barang;
                    current->jumlah_barang = temp->jumlah_barang;
                    temp->jumlah_barang = temp_jumlah_barang;


                }
            }
        }

        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
    break;


    default:
        printf("\n\n\t\t\t\t               pilihan tidak ada \n\n");
        system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
        break;
    } // milik case


}

int main(){
           {
            system("color CF");
            char username[15];
            char password[12];
            int i;
            printf("\n\t\t\t SELAMAT DATANG DI DATABASE TOKO\n");
            printf("\n\t\t     Silahkan masukkan username dan password\n");
            printf("\t\t   ============================================\n\n");
            printf("\t\t\t\tUsername : ");
            scanf("%s",&username);

            printf("\n\t\t\t\tPassword : ");
            for(i=0;i<5;i++)
            { password[i]=getch();
            printf("*"); }
            password[i]='\0';
            if(strcmp(username,"alfend")==0){
            if(strcmp(password,"12345")==0){
            printf("\n\n\n\t\t\t\t Login Berhasil!\n\n");
            printf("\t\t   ============================================\n ");
            }else{
            printf("\n\n\n\t\t     Maaf, password yang Anda masukkan salah\n\n");
            printf("\t\t   ============================================\n ");
            return 0;
            }
            }else{
            printf("\n\n\n\t\t      Maaf, username yang Anda masukkan salah\n\n");
            printf("\t\t   ============================================\n ");
            return 0;
            }
            system("pause >nul | echo \t\t      Tekan tombol apapun untuk melanjutkan...");
            system("cls");
        }

int menu;
int kode;
char kasir[50];
char barang[50];
int jumlah;
int harga;
int bayar;
int kembalian;
int kotran;
int code_tran;

    do{
    system("color B0");
    printf("_____________________________________________________________________________________________________\n");
    printf("||-------------------------------------------------------------------------------------------------||\n");
    printf("||                                                                                                 ||\n");
    printf("||                  ----------------SELAMAT DATANG DI DATABASE TOKO----------------                ||\n");
    printf("|| --------------- TOKO MAJU ADIL MAKMUR SEJAHTERA BERSAMA KITA BISA BANGUN NEGERI --------------- ||\n");
    printf("||-------------------------------------------------------------------------------------------------||\n");
    printf("||                                                                                                 ||\n");
    printf("||                  PILIHAN MENU :                                                                 ||\n");
    printf("||                                                                                                 ||\n");
    printf("||                             Tekan  1. Membuat database toko                                     ||\n");
    printf("||                             Tekan  2. Menampilkan isi database toko                             ||\n");
    printf("||                             Tekan  3. Menghapus data di database toko                           ||\n");
    printf("||                             Tekan  4. Mengedit data di database toko                            ||\n");
    printf("||                             Tekan  5. Menambahkan data baru ke database toko                    ||\n");
    printf("||                             Tekan  6. Mencari data di database toko                             ||\n");
    printf("||                             Tekan  7. Riwayat aktivitas                                         ||\n");
    printf("||                             Tekan  8. Mengurutkan data di database toko                         ||\n");
    printf("||                             Tekan  9. Keluar                                                    ||\n");
    printf("||                                                                                                 ||\n");
    printf("||-------------------------------------------------------------------------------------------------||\n");
    printf("||_________________________________________________________________________________________________||\n\n");
    printf("Masukkan pilihan Anda : ");
    scanf("%i", &menu);
    switch(menu){

        case 1:
            system("color F0");
            system("cls");
            printf("\nMembuat database toko\n\n",kode+1);
            printf("Kode transaksi : ");
            scanf("%i", &kode);

            printf("Nama kasir     : ");
            scanf(" %s",kasir);

            printf("Nama barang    : ");
            scanf(" %s",barang);

            printf("Jumlah barang  : ");
            scanf("%i", &jumlah);

            printf("Harga per pcs  : ");
            scanf("%i", &harga);

            printf("Bayar          : ");
            scanf("%i", &bayar);

            printf("Kembalian      : %i  \n\n", bayar-(jumlah*harga));

            insert(kode, kasir, barang, jumlah, harga, bayar, bayar-(jumlah*harga));
            system("pause >nul | echo Tekan tombol apapun untuk kembali...");
            system("cls");
            strcpy(riwayat[no_riwayat],"Admin membuat data" );
            no_riwayat++;
        break;


        case 2:
        system("color E0");
        system("cls");
        printf("\n       |= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =|\n");
        printf("       | ::::::--------------------::::--::::--:::: TRANSAKSI ::::--::::--::::--------------------:::::: |\n");
        printf("       | ::::----::::--------------------------- PEMBELIAN BARANG --------------------------::::----:::: |\n");
        printf("       | --------------- TOKO MAJU ADIL MAKMUR SEJAHTERA BERSAMA KITA BISA BANGUN NEGERI --------------- |");
        printf("\n       | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
        printf("       | KodeTransaksi\tNamaKasir\tNamaBarang\tJumlah\tHarga\tBayar\tKembali\t TanggalTransaksi| \n");
        tampil();
        printf("\n       |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n");
        system("pause >nul | echo \tTekan tombol apapun untuk kembali...");
        system("cls");
        strcpy(riwayat[no_riwayat],"Admin menampilkan data");
        no_riwayat++;
        break;

        case 3:
        system("color 9F");
            system("cls");
            printf("\nMenghapus data di database toko \n\n");
            printf("Masukkan kode transaksi : ");
            scanf("%i", &kotran);
            hapusAtas(kotran);
            system("pause >nul | echo Tekan tombol apapun untuk kembali...");
            system("cls");
            strcpy(riwayat[no_riwayat],"Admin menghapus data");
            no_riwayat++;
            break;

        case 4:
         system("color 3F");
            system("cls");
            printf("\nMengedit data di database toko \n\n");
            printf("Masukkan kode transaksi : ");
            scanf("%i", &code_tran);
            update(code_tran);
            strcpy(riwayat[no_riwayat],"Admin mengedit data");
            no_riwayat++;
            break;

        case 5:
        system("color F6");
            system("cls");
            printf("\nMenambahkan data baru ke database toko\n\n");
            printf("Kode transaksi : ");
            scanf("%i", &kode);

            printf("Nama kasir     : ");
            scanf(" %s",kasir);

            printf("Nama barang    : ");
            scanf(" %s",barang);

            printf("Jumlah barang  : ");
            scanf("%i", &jumlah);

            printf("Harga per pcs  : ");
            scanf("%i", &harga);

            printf("Bayar          : ");
            scanf("%i", &bayar);

            printf("Kembalian      : %i  \n\n", bayar-(jumlah*harga));

            insert(kode, kasir, barang, jumlah, harga, bayar, bayar-(jumlah*harga));
            system("pause >nul | echo Tekan tombol apapun untuk kembali...");
            system("cls");
            strcpy(riwayat[no_riwayat],"Admin menambahkan data");
            no_riwayat++;
        break;

        case 6:cariData();
            system("color F4");
            system("cls");

            printf("\n\tMencari data di database toko \n\n");
        char buff[20];
        if(head==NULL)
        {
        puts("\t\t\t\t\tMaaf, data toko kosong..");
	    system("cls");
        }
        printf("\t\t\t\t\tMasukkan nama barang yang ingin dicari : ");
        fflush(stdin);
        gets(buff);

        current = head;
        while(current != NULL)
        {
        if(strcmp(current->barang, buff) == 0)
	    {
            printf("\n\t\t\t\t\t    ======Hasil Cari Data Barang======");
            printf("\n\t\t\t\t\t    Nama barang          : %s          ", current->barang);
            printf("\n\t\t\t\t\t    Kode transaksi       : %i          ", current->kode_transaksi);
            printf("\n\t\t\t\t\t    Nama kasir           : %s          ", current->kasir);
//            printf("\n\t\t\t\t\t    Nama barang          : %s          ", current->barang);
            printf("\n\t\t\t\t\t    Jumlah barang        : %i          ", current->jumlah_barang);
            printf("\n\t\t\t\t\t    Harga barang per pcs : %i          ", current->harga_barang);
            printf("\n\t\t\t\t\t    Bayar                : %i          ", current->bayar_barang);
            printf("\n\t\t\t\t\t    Kembalian            : %i          ", current->kembali_barang);
            printf("\n\t\t\t\t\t    =================================\n\n");
            current = current->next;
            printf("\n");
	    }
	    else
		{
			current = current->next;
			printf("\n\t\t\t\t\t\t     !............!\n",buff);
		}
        }
            system("pause >nul | echo \tTekan tombol apapun untuk kembali...");
            system("cls");
            strcpy(riwayat[no_riwayat],"Admin mencari data");
            no_riwayat++;
            break;

        case 7:history();
        system("color 5F");
        system("cls");
        printf("\t\t\t               +------------------------------------------+\n");
        printf("\t\t\t               No.\tRiwayat\n");
        printf("\t\t\t               +------------------------------------------+\n");
        for(int no_awal = 1; no_awal < no_riwayat;no_awal++){
		printf("\t\t\t               %d.\t%s\n\n",no_awal,riwayat[no_awal]);
        }
        printf("\t\t\t               +------------------------------------------+\n");
        system("pause >nul | echo Tekan tombol apapun untuk kembali...");
        system("cls");
        strcpy(riwayat[no_riwayat],"Admin membuka riwayat aktivitas");
        no_riwayat++;
        break;

        case 8:sorting();

        system("color ED");
        printf("\n       |= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =|\n");
        printf("       | ::::::--------------------::::--::::--:::: TRANSAKSI ::::--::::--::::--------------------:::::: |\n");
        printf("       | ::::----::::--------------------------- PEMBELIAN BARANG --------------------------::::----:::: |\n");
        printf("       | --------------- TOKO MAJU ADIL MAKMUR SEJAHTERA BERSAMA KITA BISA BANGUN NEGERI --------------- |");
        printf("\n       | = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
        printf("       | KodeTransaksi\tNamaKasir\tNamaBarang\tJumlah\tHarga\tBayar\tKembali\t TanggalTransaksi| \n");
        tampil();
        printf("\n       |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n\n");
//
//
//        //system("pause >nul | echo \t\t\t\t               enter untuk kembali . . .");
//
//            printf("Kode transaksi : ");
//            scanf("%i", &temp_kode_transaksi);
//
////            printf("Nama kasir     : ");
////            scanf(" %s",kasir);
//
//            printf("Nama barang    : ");
//            scanf(" %s",temp_nama_barang);
//
//            printf("Jumlah barang  : ");
//            scanf("%i", &temp_jumlah_barang);
//
//            printf("Harga per pcs  : ");
//            scanf("%i", &temp_harga_barang);
//
////            printf("Bayar          : ");
////            scanf("%i", &bayar);
////
////            printf("Kembalian      : %i  \n\n", bayar-(jumlah*harga));
//
//            sorting(temp_kode_transaksi, temp_nama_barang, temp_jumlah_barang, temp_harga_barang);
            system("pause >nul | echo Tekan tombol apapun untuk kembali...");
            system("cls");

        strcpy(riwayat[no_riwayat],"Admin mengurutkan data");
        no_riwayat++;
        break;

        case 9:
        system("color 6F");
            system("cls");
            int x; double y;

            char salam[]= "\n\n\n\n\t\t\t| Database ditutup. Terima kasih. |\n\n\n\n\t\t\t ALFENDIO ALIF FAUDISYAH \n\n\t\t\t 672019222 \n\n\t\t\t ALGORITMA DAN STRUKTUR DATA";

            for(x=0; salam[x]!=NULL; x++)
   {
     printf("%c",salam[x]);
      for(y=0; y<=9999999; y++)
      {
      }
   }
   getch();
            exit(0);
            break;

            }
    }

    while(menu!=9);
    return 0;

    }




