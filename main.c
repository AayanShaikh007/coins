// this push has the color change and partially finished data view function/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

// Start by making functon that stores data --> amount$, category, date.

typedef struct {
    double amount;
    int category;
    char date[11];
} Transaction;

void sort_file() {
    // read all lines into array of structs?
    int max_transactions = 100; 
    FILE *file = fopen("C:\\Coding\\siege\\coins\\data.txt", "r");
    Transaction transactions[max_transactions];
    
    int count = 0;
    char line[128];

    // this should parse through each line and store data in struct array
    while (fgets(line, sizeof(line), file) && count < max_transactions) {
        if (sscanf(line, "%lf,%d,%10s",
            &transactions[count].amount, 
            &transactions[count].category, 
            transactions[count].date) == 3) {
            count++;
        }
    }
    
    fclose(file);


    // used ai for bubble sort implementation
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count -i-1; j++) {
            if (strcmp(transactions[j].date, transactions[j+1].date) > 0) {  // if date is out of order, j comes after j+1
                // swap the transactions[j] and transactions[j+1] 
                Transaction temporary = transactions[j];
                transactions[j] = transactions[j+1];
                transactions[j+1] = temporary;
            }
        }
    }

    // writing sorted back to data.txt
    FILE *out = fopen("C:\\Coding\\siege\\coins\\data.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(out, "%.2lf,%d,%s\n", transactions[i].amount, transactions[i].category, transactions[i].date);
    }
    fclose(out);



    // sort array by date
    // write back to file
    // use bubble sort for simplicity
}


void data_record() {
    
    double amount;
    int category;   
    char category_name[20]; // string of max length 20, for safety
    const char *categories[] = {"groceries", "food", "transportation", "books", "entertainment", "utilities", "others"};

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
    
}



void data_view() {
    
    FILE *file = fopen("C:\\Coding\\siege\\coins\\data.txt", "r");
    if (file == NULL) {
        printf("error opening file");
        return;
    }
    
    printf("\nWhat would you like to do?\n");
    printf("1. View all data\n2. something 3. Go back to main menu\n");

    int choice; 
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            char line[128];
            printf("\n\nTransactions:\n\n");
            
            int m = 1; 
            while (fgets(line, sizeof(line), file)) {
                double amount; 
                int category; 
                char date[11];    

                if (sscanf(line, "%lf,%d,%10s", &amount, &category, date) == 3) {  
                    printf("Transaction %d: Amount: %.2lf | Category: %d | Date: %s\n", m++, amount, category, date);
                }
            }

            break;
        case 2:
            sort_file();

            break;
        
        case 3:
            printf("Going back to main menu\n");
            break;

        default:
            printf("Invalid choice.\n");
            return;
    } 




    
    
    // close file at end
    fclose(file);

}



int main() {
    // ascii art from generator: https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type+Something+&x=none&v=4&h=4&w=80&we=false
    printf("\033[1;32m"); // making terminal color green
    
    printf(" /$$$$$$$                  /$$                       /$$     /$$      /$$ /$$                      \n");
    printf("| $$__  $$                | $$                      | $$    | $$  /$ | $$|__/                      \n");
    printf("| $$  \\ $$ /$$   /$$  /$$$$$$$  /$$$$$$   /$$$$$$  /$$$$$$  | $$ /$$$| $$ /$$  /$$$$$$$  /$$$$$$   \n");
    printf("| $$$$$$$ | $$  | $$ /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/  | $$/$$ $$ $$| $$ /$$_____/ /$$__  $$  \n");
    printf("| $$__  $$| $$  | $$| $$  | $$| $$  \\ $$| $$$$$$$$  | $$    | $$$$_  $$$$| $$|  $$$$$$ | $$$$$$$$  \n");
    printf("| $$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$_____/  | $$ /$$| $$$/ \\  $$$| $$ \\____  $$| $$_____/  \n");
    printf("| $$$$$$$/|  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$$  |  $$$$/| $$/   \\  $$| $$ /$$$$$$$/|  $$$$$$$  \n");
    printf("|_______/  \\______/  \\_______/ \\____  $$ \\_______/   \\___/  |__/     \\__/|__/|_______/  \\_______/  \n");
    printf("                               /$$  \\ $$                                                           \n");
    printf("                              |  $$$$$$/                                                           \n");
    printf("                               \\______/                                                            \n");
    printf("Welcome to BudgetWise!\n");

    printf("\033[0m");   


    while (1) {
        printf("Select mode:\n1. Data Record\n2. Data View\n0. Exit\n");
        int mode;
        scanf ("%d", &mode);

        if (mode == 1) {
            data_record();
            while (1) {
                printf("\n Do you want to continue inputting data? (y/n)\n");
                char cont;
                scanf(" %c", &cont);
                if (cont == 'y' || cont == 'Y') {
                    data_record();
                } else {
                    printf("Returning to main menu.\n\n");
                    break;
                }
            }

        } else if (mode == 2) {
            data_view();  
        } else if (mode == 0) {
            printf("Exiting program. Goodbye!\n");
            exit(0);
        
        } else {
            printf("Invalid mode selected.\n");
        }
    }

    return 0;
}