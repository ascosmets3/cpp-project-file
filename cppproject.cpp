#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Vehicle
{
char brand[15];
char model[10];
char color[10];
char type[10];
int mfg_year;
short capacity;
float rent;
};

struct node
{
struct Vehicle* vehicle;
struct node *next;
};
struct linkedList
{
struct node *start;
struct node *end;
};
void createList(struct linkedList* list)
{
list->start = NULL;
list->end = NULL;
}
void insertInList(struct linkedList* list, struct Vehicle* vehicle)
{
if(list->start == NULL)
{
list->start = (struct node*) malloc(sizeof(struct node));
list->start->vehicle = (struct Vehicle*) malloc(sizeof(struct Vehicle));
strcpy(list->start->vehicle->brand, vehicle->brand);
strcpy(list->start->vehicle->model, vehicle->model);
strcpy(list->start->vehicle->color, vehicle->color);
strcpy(list->start->vehicle->type, vehicle->type);
list->start->vehicle->capacity = vehicle->capacity;
list->start->vehicle->mfg_year = vehicle->mfg_year;
list->start->vehicle->rent = vehicle->rent;
list->start->next = NULL;
list->end = list->start;
}
else
{
list->end->next = (struct node*) malloc(sizeof(struct node));
list->end = list->end->next;
list->end->vehicle = (struct Vehicle*) malloc(sizeof(struct Vehicle));
strcpy(list->end->vehicle->brand, vehicle->brand);
strcpy(list->end->vehicle->model, vehicle->model);
strcpy(list->end->vehicle->color, vehicle->color);
strcpy(list->end->vehicle->type, vehicle->type);
list->end->vehicle->capacity = vehicle->capacity;
list->end->vehicle->mfg_year = vehicle->mfg_year;
list->end->vehicle->rent = vehicle->rent;
list->end->next = NULL;
}
}
void deleteInList(struct linkedList* list, int number)
{
if (list->end == NULL)
{
return;
}
struct node* temp = list->start;
struct node* prev = NULL;
int i = 1;
while (1)
{
if (i == number)
{
if (temp == list->start)
{

list->start = temp->next;
free(temp);
return;
}
if (temp == list->end)
{
list->end = prev;
prev->next == NULL;
free(temp);
}
prev->next = temp->next;
free(temp);
return;
}
if (temp->next == NULL)
{
return;
}
prev = temp;
temp = temp->next;
i++;
}
}
void printVehicle(struct Vehicle* vehicle)
{
printf("-----------------------------------------------------------------------------------------------\n");
printf("\n%10s%10s %d %10s%15s %d %.2f ruppes/day\n" , vehicle->brand,vehicle->model, vehicle->mfg_year, vehicle->color, vehicle->type,vehicle->capacity, vehicle->rent);
}
void printVehicleWithNumber(struct Vehicle* vehicle, int number)
{
printf("-----------------------------------------------------------------------------------------------\n");
printf("\n[%d] %10s%10s %d %10s%15s %d %.2f ruppes/day\n" , number, vehicle->brand,vehicle->model, vehicle->mfg_year, vehicle->color, vehicle->type,vehicle->capacity, vehicle->rent);
}
void printList(struct linkedList* list)
{
if (list->end == NULL)
{
return;
}
struct node* temp = list->start;
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
printf("-----------------------------------------------------------------------------------------------\n");
int i = 1;
while (1)
{
printVehicleWithNumber(temp->vehicle, i++);
if (temp->next == NULL)
{
return;
}

temp = temp->next;
}
}
void printByBrands(struct linkedList* list, char brandName[15])
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles of Brand %s: \n" , brandName);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
int flag = 1;
while (1)
{
if (strcasecmp(temp->vehicle->brand, brandName) == 0)
{
flag = 0;
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
break;
}
temp = temp->next;
}
if (flag == 1)
{
printf("\nNot Found!!\n");
}
}
void printByColor(struct linkedList* list, char color[10])
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles of colour %s: \n" , color);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
int flag = 1;
while (1)
{
if (strcasecmp(temp->vehicle->color, color) == 0)
{
flag = 0;
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
break;
}
temp = temp->next;
}
if (flag == 1)

{
printf("\nNot Found!!\n");
}
}
void printByType(struct linkedList* list, char type[10])
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles of type %s: \n" , type);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
int flag = 1;
while (1)
{
if (strcasecmp(temp->vehicle->type, type) == 0)
{
flag = 0;
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
break;
}
temp = temp->next;
}
if (flag == 1)
{
printf("\nNot Found!!\n");
}
}
void printByModel(struct linkedList* list, char model[10])
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles of model %s: \n" , model);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
int flag = 1;
while (1)
{
if (strcasecmp(temp->vehicle->model, model) == 0)
{
flag = 0;
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
break;
}
temp = temp->next;
}
if (flag == 1)

{
printf("\nNot Found!!\n");
}
}
void printInYearRange(struct linkedList* list, int start, int end)
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles from the Year (%d - %d): \n" , start, end);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
while (1)
{
if (temp->vehicle->mfg_year >= start && temp->vehicle->mfg_year <= end)
{
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
return;
}
temp = temp->next;
}
}
void printInCapacityRange(struct linkedList* list, short start, short end)
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nVehicles with capacity range (%d - %d): \n" , start, end);
printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
while (1)
{
if (temp->vehicle->capacity >= start && temp->vehicle->capacity <= end)
{
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
return;
}
temp = temp->next;
}
}
void printInRentRange(struct linkedList* list, float start, float end)
{
if (list->start == NULL)
{
return;
}
struct node* temp = list->start;
printf("\nvehicles with rent in range (%0.2f - %0.2f) ruppes/day: \n" , start, end);

printf("_________________________________\n");
printf("| Brand | Model | Mfg Year | Colour | Type | Capacity | Rent |\n");
while (1)
{
if (temp->vehicle->rent >= start && temp->vehicle->rent <= end)
{
printVehicle(temp->vehicle);
}
if (temp->next == NULL)
{
return;
}
temp = temp->next;
}
}
int main()
{
printf("-----------------------------------------------------------------------------------------------\n\n");
printf("\t\t\t| INNOVATIVE ASSIGNMENT |\n\n");
printf("\t\t\t| DATA STRUCTURE AND ALGORITHMS  |\n\n");
printf("-----------------------------------------------------------------------------------------------\n");
printf("\n\n\n\n\t\t\t-----------------------------------------");
printf("\n\t\t\t| WELCOME TO |");
printf("\n\t\t\t| Vehicle Rental Service Application |");
printf("\n\t\t\t-----------------------------------------\n\n");
struct linkedList vehicles;
createList(&vehicles);
int input=1;
if (input == 1)
{
struct Vehicle temp;
strcpy(temp.brand,"Maruti");strcpy(temp.model,"Swift");strcpy(temp.color,"red");strcpy(temp.type,"hatchback");
temp.mfg_year=2014;temp.capacity=5;temp.rent=1640;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Hyundai");strcpy(temp.model,"i10");strcpy(temp.color,"white");strcpy(temp.type,"hatchback");
temp.mfg_year=2019;temp.capacity=5;temp.rent=1900;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Mahindra");strcpy(temp.model,"Scorpio");strcpy(temp.color,"black");strcpy(temp.type,"suv");
temp.mfg_year=2017;temp.capacity=7;temp.rent=2500.75;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Toyota");strcpy(temp.model,"Innova");strcpy(temp.color,"gray");strcpy(temp.type,"suv");
temp.mfg_year=2018;temp.capacity=7;temp.rent=2550.5;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Honda");strcpy(temp.model,"Amaze");strcpy(temp.color,"red");strcpy(temp.type,"sedan");
temp.mfg_year=2017;temp.capacity=5;temp.rent=1900;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Tata");strcpy(temp.model,"Indigo");strcpy(temp.color,"gray");strcpy(temp.type,"hatchback");
temp.mfg_year=2014;temp.capacity=5;temp.rent=1500;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Maruti");strcpy(temp.model,"Alto");strcpy(temp.color,"white");strcpy(temp.type,"hatchback");
temp.mfg_year=2015;temp.capacity=5;temp.rent=1450;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Honda");strcpy(temp.model,"City");strcpy(temp.color,"silver");strcpy(temp.type,"sedan");
temp.mfg_year=2020;temp.capacity=5;temp.rent=2350;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Tata");strcpy(temp.model,"Nano");strcpy(temp.color,"yellow");strcpy(temp.type,"hatchback");
temp.mfg_year=2015;temp.capacity=5;temp.rent=1400;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Toyota");strcpy(temp.model,"Innova");strcpy(temp.color,"blue");strcpy(temp.type,"suv");
temp.mfg_year=2020;temp.capacity=7;temp.rent=2800;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Skoda");strcpy(temp.model,"Rapid");strcpy(temp.color,"white");strcpy(temp.type,"sedan");
temp.mfg_year=2018;temp.capacity=5;temp.rent=2100;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Hyundai");strcpy(temp.model,"Verna");strcpy(temp.color,"white");strcpy(temp.type,"sedan");
temp.mfg_year=2018;temp.capacity=5;temp.rent=2200;
insertInList(&vehicles, &temp);
strcpy(temp.brand,"Honda");strcpy(temp.model,"Amaze");strcpy(temp.color,"blue");strcpy(temp.type,"sedan");
temp.mfg_year=2019;temp.capacity=5;temp.rent=2300.5;
insertInList(&vehicles, &temp);
}

int todo = 1;
while(todo)
{
printf("\n _______________________ \n");
printf("| 1. ADMINISTRATOR | \n");
printf("|_______________________| \n\n");
printf(" _______________________ \n");
printf("| 2. CUSTOMER | \n");
printf("|_______________________| \n\n");
printf(" _______________________ \n");
printf("| 3. EXIT | \n");
printf("|_______________________| \n\n");
printf("Enter your choice from 1 to 3:- ");
int choice;
scanf("%d", &choice);
switch(choice)
{
case 1:
{
while (1)
{
fflush(stdin);
printf("\nenter 1 to add another vehicle and 0 to stop adding: ");
scanf("%d" , &input);
if (input != 1)
{
break;
}
struct Vehicle* temp = (struct Vehicle*) malloc(sizeof(struct Vehicle));
printf("\nenter brand: ");
scanf("%s" , temp->brand);
printf("enter model: ");
scanf("%s" , temp->model);
printf("enter colour: ");

scanf("%s" , temp->color);
printf("enter type: ");
scanf("%s" , temp->type);
printf("enter year: ");
scanf("%d" , &temp->mfg_year);
printf("enter capacity: ");
scanf("%d" , &temp->capacity);
printf("enter rent: ");
scanf("%f" , &temp->rent);
insertInList(&vehicles, temp);
printf("inserted succesfully");
}
break;
}
case 2:
{
while (1)
{
printf(" _______________________________________________ \n");
printf("| 1.view all vehicles\n");
printf(" _______________________________________________ \n");
printf("| 2.search vehicles by Brand\n");
printf(" _______________________________________________ \n");
printf("| 3.search vehicles by Colour\n");
printf(" _______________________________________________ \n");
printf("| 4.search vehicles by type of vehicle\n");
printf(" _______________________________________________ \n");
printf("| 5.search vehicles by model\n");
printf(" _______________________________________________ \n");
printf("| 6.search for vehicles from year range\n");
printf(" _______________________________________________ \n");
printf("| 7.search for vehicles with capacity range\n");
printf(" _______________________________________________ \n");
printf("| 8.search for vehicles with rent in range\n");
printf(" _______________________________________________ \n");
printf("| 9.To book a vehicle\n");
printf(" _______________________________________________ \n");
printf("| 0.EXIT\n");
printf("|_______________________________________________ \n");
printf("\nEnter your choice from 0 to 9: ");
int input;
scanf("%d",&input);
if (input == 0)
{
break;
}

else if (input == 1)

{
printf("\nAll vehicles:\n\n");
printList(&vehicles);
printf("\n");
}

else if (input == 2)

{
char brandName[15];
printf("\nenter brand: ");
scanf("%s" , brandName);
printByBrands(&vehicles, brandName);
}

else if (input == 3)

{
char color[10];
printf("enter colour: ");

scanf("%s" , color);
printByColor(&vehicles, color);
}

else if (input == 4)

{
char type[10];
printf("enter type: ");
scanf("%s" , type);
printByType(&vehicles, type);
}
else if (input == 5)
{
char model[10];
printf("enter model: ");
scanf("%s" , model);
printByModel(&vehicles, model);
}

else if (input == 6)

{
int start, end;
printf("\nenter starting year: ");
scanf("%d" , &start);
printf("enter ending year: ");
scanf("%d" , &end);
printInYearRange(&vehicles, start, end);
}
else if (input == 7)
{
short start, end;
printf("\nenter starting capacity: ");
scanf("%d" , &start);
printf("enter ending capacity: ");
scanf("%d" , &end);
printInCapacityRange(&vehicles, start, end);
}

else if (input == 8)

{
float start, end;
printf("\nenter starting rent(rupees/day): ");
scanf("%f" , &start);
printf("enter ending rent: ");
scanf("%f" , &end);
printInRentRange(&vehicles, start, end);
}

else if (input == 9)

{
int number;

printf("\nenter serial number of Vehicle: ");

scanf("%d" , &number);
deleteInList(&vehicles, number);
printf("\nvehicle booked!!\n");
}
else
{

printf("\ninvalid input!!\n");
}
}
break;
}
case 3:
{
printf("\n\n-----------------------------------------\n");
printf("\t\tTHANK YOU\n");
printf("-----------------------------------------\n");
return 0;
}

default:
printf
(" Please Enter the Valid Choice. \n");
}
}
}
