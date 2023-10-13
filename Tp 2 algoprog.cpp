/*
DZAKI IMAM FAWWAZ - 2702367486
Date    : 13 - okt - 2023
version : 05.01.05

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// head fun
void code_program();
void nama_mahasiswa();
void clear_screen();
void thank_you();

int main()
{
  int pilihanMenu;

  // main menu
  while (1)
  {
    printf("\nPilihan Menu\n");
    printf("-------------------------\n");
    printf("1. Nama Mahasiswa\n");
    printf("2. Jalankan Program\n");
    printf("3. Clear Screen\n");
    printf("4. Exit\n");
    printf("-------------------------\n");
    printf("Masukkan Pilihan : ");
    scanf("%d", &pilihanMenu);

    // logika main menu
    switch (pilihanMenu)
    {
    case 1:
      nama_mahasiswa();
      break;

    case 2:
      code_program();
      break;

    case 3:
      clear_screen();
      break;

    case 4:
      thank_you();
      exit(0); // untuk keluar program
      
    default : 
    printf("\n\033[31;47mMasukkan pilihan 1-4\033[0m\n");
    }
  }

  return 0;
}

/*
  body function
*/

// function program
void code_program()
{
  int input_huruf, i, cocok[12], num_cocok = 0, pilihan, vokal = 0, nonvokal = 0;

  do
  {
    // Daftar nama bulan menggunakan contanta
    const char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
                           "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    // Input huruf dari pengguna
    char input_huruf;
    printf("\n\033[32mMasukkan huruf dari A hingga Z :\033[0m ");
    scanf(" %c", &input_huruf);

    // Mencocokkan huruf awalan dengan nama bulan
    for (i = 0; i < 12; i++)
    {
      if (bulan[i][0] == input_huruf || bulan[i][0] == input_huruf - 32)
      {
        cocok[num_cocok] = i;
        num_cocok++;
      }
    }

    // Menampilkan daftar bulan yang cocok
    if (num_cocok > 0)
    {
      printf("\nBulan yang cocok dengan huruf awalan  :\n");
      for (i = 0; i < num_cocok; i++)
      {
        printf("%d. %s\n", i + 1, bulan[cocok[i]]);
      }

      // Memilih bulan dengan looping do while
      do
      {
        printf("Pilih nomor bulan yang Anda inginkan (1-%d): ", num_cocok);
        scanf("%d", &pilihan);

        if (pilihan >= 1 && pilihan <= num_cocok)
        {
          pilihan--;
          const char *bulan_pilihan = bulan[cocok[pilihan]];

          // Menghitung jumlah karakter vokal dan nonvokal
          for (i = 0; i < strlen(bulan_pilihan); i++)
          {
            char huruf = bulan_pilihan[i];
            if (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o' ||
                huruf == 'A' || huruf == 'I' || huruf == 'U' || huruf == 'E' || huruf == 'O')
            {
              vokal++;
            }
            else if ((huruf >= 'a' && huruf <= 'z') || (huruf >= 'A' && huruf <= 'Z'))
            {
              nonvokal++;
            }
          }

          // ouput
          printf("\n--------------------------------------------\n");
          printf("Jumlah karakter vokal    dalam %s : %d\n", bulan_pilihan, vokal);
          printf("Jumlah karakter nonvokal dalam %s : %d\n", bulan_pilihan, nonvokal);
          printf("--------------------------------------------\n");
          break;
        }
        else
        {
          printf("\033[31;47mNomor bulan yang Anda pilih tidak valid.\033[0m\n\n"); // walidasi check
          break;
        }
      } while (pilihan = '0');
    }
    else
    {
      printf("\033[31;47mTidak ada bulan yang cocok dengan huruf awalan \'%c\'.\033[0m\n", input_huruf); // validasi vheck
      break;
    }
  } while (pilihan = 0);
}

// function menu 1
void nama_mahasiswa()
{
  printf("\n\033[30;47m");
  printf("Nama : Dzaki Imam Fawwaz\n");
  printf("Nim  : 2702367486       ");
  printf("\033[0m\n");
}

// function clear screen
void clear_screen()
{
  printf("\033[2J");
  printf("\033[H");
}

// function terima kasih
void thank_you()
{
  printf("\n\033[32m----------------------------------\n");
  printf("          Terimakasih \n");
  printf("   Semoga harimu menyenangkan :)\n");
  printf("----------------------------------\033[0m\n");
}
