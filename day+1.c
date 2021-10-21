#include <stdio.h>
 //变量新类型date 
struct date {
	int day;
	int month;
	int year;
};
int isleap(struct date d);
int dayoff(struct date d) {
	int days = 0;
	const int everyday[12] = {31, 28, 31, 30, 31, 30, 30, 31, 30, 31, 30, 31};
	if (d.month == 2 && isleap(d) == 1) {
		days = 29;
	} else {
		days = everyday[d.month - 1];
	}
	// printf("days is %d  \n",days);
	return days;
}
int isleap(struct date d) {
	int leap = 0;
	if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
		leap = 1;

	}
	//printf("%d\n",leap);
	return leap;
}
int main(/*int argc, char const *argv[]*/) {
	struct date today, tomorrow;
	printf("请输入day—month—year:");
	scanf("%i %i %i", &today.day, &today.month, &today.year);
//printf("leap=%d\n",isleap(today));
	if (today.day != dayoff(today)) {
		tomorrow.day = ++today.day;
		tomorrow.month = today.month;
		tomorrow.year = today.year;
		printf("yes\n");

	} else if (today.month == 12) {
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	} else {
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	printf("tomorrow date is %i-%i-%i\n", tomorrow.day, tomorrow.month, tomorrow.year);
	return 0;
}
