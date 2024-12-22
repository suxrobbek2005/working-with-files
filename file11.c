#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fayl;
    char belgi;
    int new_word = 1; // Harf so'zning birinchi harfi ekanligini tekshirish uchun bayroq

    // Faylni o'qish va yozish uchun ochish
    fayl = fopen("matn.txt", "r+");
    if (fayl == NULL) {
        return 1;
    }

    // Fayldagi matnni qayta ishlash
    while ((belgi = fgetc(fayl)) != EOF) {
    // Agar yangi so'z boshlangan bo'lsa
        if (new_word && isalpha(belgi)) { 
             // Belgini qayta yozish uchun fayl ko'rsatkichini orqaga qaytarish
            fseek(fayl, -1, SEEK_CUR);  
            // Katta harfga aylantirish
            fputc(toupper(belgi), fayl); 
             // Endi bu yangi so'z emas
            new_word ;             
        // Bo'sh joy belgisi yangi so'z boshlanganini bildiradi
        } else if (isspace(belgi)) {     
            new_word;
        }
    }

    // Faylni yopish
    fclose(fayl);

    printf("Har bir so'z katta xarfga almashtirlidi.\n");

    return 0;
}
