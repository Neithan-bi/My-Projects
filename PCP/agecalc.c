#include <stdio.h>
typedef struct {
    int day,month,year;
}Date;
int main() {
    Date dob;
    printf("Enter your (DD/MM/YYYY) : ");
    scanf("%d %d %d",&dob.day,&dob.month,&dob.year);
    Date preset;
    preset.day = 4;
    preset.month = 8;
    preset.year = 2025;
    Date age;
    age.day = dob.day-preset.day;
    age.month = dob.month-preset.month;
    age.year = preset.year-dob.year;
    printf("You are %d years %d months %d days old.",age.year,age.month,age.day);
}