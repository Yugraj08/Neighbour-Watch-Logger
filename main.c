#include<stdio.h>
#include<conio.h>
void logIncident(){
// while (getchar() != '\n');
    FILE *fp;
    char name[50], houseNo[10], dateTime[50], description[200];

    // Clear buffer if needed
    while (getchar() != '\n');

    // Input
    printf("Enter name: \n");
    fgets(name, sizeof(name), stdin);
    //name[strcspn(name, "\n")] = '\0';  // remove newline

    printf("Enter house number: ");
    fgets(houseNo, sizeof(houseNo), stdin);
    houseNo[strcspn(houseNo, "\n")] = '\0';

    printf("Enter date and time: ");
    fgets(dateTime, sizeof(dateTime), stdin);
    dateTime[strcspn(dateTime, "\n")] = '\0';

    printf("Enter incident description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0';

    // Open file
    fp = fopen("logs.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write to file
    fprintf(fp, "Reporter: %s\n", name);
    fprintf(fp, "House No: %s\n", houseNo);
    fprintf(fp, "Date/Time: %s\n", dateTime);
    fprintf(fp, "Incident: %s\n", description);
    fprintf(fp, "-----------------------------");
    fprintf(fp,"\n");

    // Close file
    fclose(fp);
    printf("Incident logged successfully!\n");
};

void viewLogs(){
    while (getchar() != '\n');
    FILE*fp ;
    fp = fopen ("logs.txt","r");
    char line[100];
    if(fp==NULL){
        printf("NO data of logs ! \n");
        return;
    }
     printf("\n");
     printf("The LOGS are below -------------> \n");
     
    while (fgets(line , sizeof(line) , fp) !=NULL){
        
        //line[strcspn(line, "\n")] = '\0'; // remove newline
       printf("%s \n",line);
       
    }
    
    fclose(fp);
    printf("---------END OF LOGS----------\n");
}
void searchByHouse() {
    FILE *fp;
    char line[300];
    char searchHouse[20];
    int found = 0;

    // Flush input buffer if needed
    while (getchar() != '\n');

    printf("Enter the house number to search: ");
    fgets(searchHouse, sizeof(searchHouse), stdin);
    //searchHouse[strcspn(searchHouse, "\n")] = '\0'; // remove newline

    fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("\n--- Search Results ---\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, searchHouse) != NULL) {
            found = 1;

            // Print full log block
            printf("%s", line); // print House No
            for (int i = 0; i < 3; i++) {
                fgets(line, sizeof(line), fp); // print next 3 lines (time, incident, line)
                printf("%s", line);
            }
            printf("\n");
        }
    }

    if (!found) {
        printf("No records found for house number: %s\n", searchHouse);
    }

    fclose(fp);
}

int main(){
    
    int selectoption ;
    while (1)
    {
    printf("    MENU SECTION\n");
    printf("1. Log a new incident\n");
    printf("2. View all logs\n");
    printf("3. Search by House Number\n");
    printf("4. Exit\n");
    printf("Select the task you want to perform from above list : ");
    
    
        scanf("%d",&selectoption);
        switch (selectoption)
        {
        case 1:{
            logIncident();
            
            }break;
        case 2:{
            viewLogs();
            } break;
        case 3:{
            searchByHouse();
           break; }

        case 4:{
        return 0;
         break; }
    
        default:{
            printf("Invalid task number . Try something different !\n\n\n");
            break;
        }
        }
    }}
    
    
    
