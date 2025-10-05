#include <stdio.h>
#include <time.h>

// Start by making functon that stores data --> amount$, category, date.

int main () {
    printf("BudgetWiseBudgetWiseBudgetWiseBudgetWiseBudgetWise\n");
    // printf("\n");  add ascii art  

    printf("Welcome to BudgetWise!\n");
    
    double amount;

    int category; 
    char category_name[20]; // string of max length 20, for safety
    const char *categories[] = {"food", "transport", "entertainment", "utilities", "others"};

    char date[11]; // Format: YYYY-MM-DD



    // add method to add new categories. 


    printf("Enter exact amount spent: ");
    scanf("%lf", &amount);
    while (getchar() != '\n'); // Clears the input buffer
    
    int category_length = sizeof(categories) / sizeof(categories[0]); // this is how you find len(list) in C
    // It is essentially finding the size of the entire array in bytes and dividing it by the size of one element.

    // category code  ------------------------------------------

    printf("\nHere are the saved categories:\n");   
    for (int i = 0; i < category_length; i++) {
        printf("%d. %s \n", i + 1, categories[i]);
    }

    printf("Enter category number (e.g., food, transport): ");
    scanf("%d", &category);
    while (getchar() != '\n'); // Clears the input buffer

    // date code  ------------------------------------------
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    
    printf("Assuming the date for this transaction is (%s), if so, enter anything, if not, please enter 'N'. ", date);
    char decision;
    
    scanf(" %c", &decision); 
    if (decision == 'N' || decision == 'n') {
        printf("Enter the date (YYYY-MM-DD): ");
        scanf("%s", date);
    }

    // Save information to txt file code  ----------------

    printf("%.2lf,%d,%s\n", amount, category, date);

    FILE *file = fopen("C:\\Coding\\siege\\coins\\data.txt", "a");
    if (file != NULL) {
        fprintf(file, "%.2lf,%d,%s\n", amount, category, date);
        fclose(file);
        printf("expect data in data.txt\n");
    } else {
        printf("Error opening file.\n");
    }
    
    // ------------------------------------------
    
    return 0; 
}