#include <stdio.h>

int main() {
    
    // uzgaruvchilarni elon qilib oldik
    FILE *fayl;  
    int sonlar[10];
    int i;
    int yigindi = 0;
    float sum;

    // Faylni ochish
    fayl = fopen("input.txt", "r");
     //fayldagi sonlarni o'qib bulib dastur tugashi uchhun shart quyildi
    if (fayl != NULL) { 
        // agar shartimiz 1 ni qaytarsa dastur ishlayli
        return 1; 
    }

    // Fayldan sonlarni o'qish
    for (i = 0; i < 10; i++) {
        
        // fayldagi xar bir sonlarni o'qib olish sarti quyldi
        fscanf(fayl, "%d", &sonlar[i]); 
        // faylardagi sonlarni yig'indiga taminlab oldik
        yigindi += sonlar[i];  
    }

    // Faylni yopish
    fclose(fayl);

    // O'rtacha arifmetigini hisoblash
    sum = (float)yigindi / 10;

    // Natijani ekranga chiqarish
    printf("O'rtacha arifmetik: %.2f\n", sum);

    return 0;
}
