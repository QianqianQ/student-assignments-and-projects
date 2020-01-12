#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define data structure of a animal
typedef struct Animal animal;

typedef struct Animal{
    char *name; // animal's name, allocated dynamically
    float weight; // animal's weight
    char *diet; // animal's diet
    animal *next; // next animal in linked list
}animal;

animal *head=NULL; // the first animal in linked list
animal *end=NULL; // the last animal in linked list

// Add an animal into linked list
int add_animal(const char* s)
{
    char animal_name[161];
    float animal_weight;
    int ret=sscanf(s,"A %s %f",animal_name,&animal_weight);
    if(ret!=2){
        printf("The input is wrong!\n");
        return 0;
    }
    animal *new_animal=malloc(sizeof(animal)); // allocate memory for new animal
    if(new_animal==NULL){
        printf("Could not allocate memory for the new animal.\n");
        return 0;
    }
    // Assign the parameters of animal
    new_animal->name=malloc(strlen(animal_name)+1); // allocate memory for the new animal's name
    strcpy(new_animal->name,animal_name);
    new_animal->name[strlen(animal_name)]='\0';
    new_animal->weight=animal_weight;
    new_animal->diet=NULL; // the new's animal's diet has not been defined yet
    new_animal->next=NULL; // the new animal's next pointer is NULL

    // Add the new animal into the list
    if(head==NULL){  // If list is empty
        head=new_animal;
        end=new_animal; // both <head> and <end> point to the new animal
        printf("The animal is added to the zoo successfully!\n");
        return 1;
    }
    else{  // If list is not empty
        end->next=new_animal; // <next> of the last animal(<end>) points to the new animal
        end=new_animal; // the new animal is the last animal(<end>) now
        printf("The animal is added to the zoo successfully!\n");
        return 1;
    }
}

// Delete animal in linked list
int delete_animal(const char* s)
{
    char animal_name[161];
    int ret=sscanf(s,"D %s",animal_name);
    if(ret!=1){
        printf("The input is wrong!\n");
        return 0;
    }
    animal *current=head; // current animal being searched, begin from the first animal in linked list
    animal *previous=NULL; // previous one animal before <current> animal
    if(head==NULL){
        printf("The zoo is empty!\n");
        return 0;
    }
    while(strcmp(current->name,animal_name)!=0) // searching animal from <head> until the name is matched
    {
        if(current->next==NULL){ // current animal is the last animal in the list, but it still does not match the name
            printf("There is no %s in the zoo!\n",animal_name);
            return 0;
        }
        previous=current;
        current=current->next;
    }
    if(current==head){ // If the first animal in linked list matches
        head=head->next; // <head> points to the second animal
    }
    else if(current==end){ // If the animal will be deleted is the last animal
        previous->next=NULL; // its previous animal's <next> pointer points to NULL
        end=previous; // <end> points to its previous animal
    }
    else{ // Other  cases
        previous->next=current->next; // its previous animal's <next> pointer points to its next animal
    }
    // Release memory of the deleted animal
    free(current->name);
    free(current->diet);
    free(current);
    printf("The animal is removed from the zoo successfully!\n");
    return 1;
}

//Define diet of an animal
int define_diet(const char* s)
{
    char animal_name[161];
    char food[50];
    int ret=sscanf(s,"B %s %[^\n]",animal_name,food);
    if(ret!=2){
        printf("The input is wrong!\n");
        return 0;
    }
    animal *current=head;
    if(head==NULL){
        printf("The zoo is empty!\n");
        return 0;
    }
    while(strcmp(current->name,animal_name)!=0) // searching for matching animal name
    {
        if(current->next==NULL){
            printf("There is no %s in the zoo!\n",animal_name);
            return 0;
        }
        current=current->next;
    }
    /* Convert the string (possible mixed-case)
    to initial capital letter followed by lowercase letters */
    food[0]=toupper(food[0]);
    int i=1;
    while(food[i]!='\0')
    {
        food[i]=tolower(food[i]);
        i++;
    }
    /* If the food matches one of the possible food types
    (Fish, Banana, Grass),then animal's diet can be defined*/
    if(strcmp(food,"Fishes")==0)
        ;
    else if(strcmp(food,"Leaves")==0)
        ;
    else if(strcmp(food,"Grass")==0)
        ;
    else{ // Otherwise animal's diet can not be defined
        printf("The food type could not be defined!\n");
        return 0;
    }
    // Define animal's diet
    if(current->diet!=NULL) // If the diet has been defined, and then it will be changed
        free(current->diet); // release memory of current diet
    current->diet=malloc(strlen(food)+1); // allocate memory for new diet
    strcpy(current->diet,food);
    current->diet[strlen(food)]='\0';
    printf("The diet is defined successfully!\n");
    return 1;
}

// List the possible diets that can be used
void list_possible_diets()
{
    printf("Fishes\nLeaves\nGrass\n");
    printf("All the possible food types have been listed!\n");
}

// Eat food and weight change
int increase_weight(animal *a)
{
    if(strcmp(a->diet,"Fishes")==0)
        a->weight+=6.5;
    if(strcmp(a->diet,"Leaves")==0)
        a->weight+=2.5;
    if(strcmp(a->diet,"Grass")==0)
        a->weight+=4.5;
    printf("The animal likes the food!\n");
    return 1;
}

int possible_decrease_weight(animal *a, char *food)
{
    if(strcmp(food,"Fishes")==0){
	if (a->weight-6.5>=0)
        	a->weight-=6.5;
	else
		printf("The weight could not be decreased to under 0.");
        return 1;
    }
    else if(strcmp(food,"Leaves")==0){
	if (a->weight-2.5>=0)
        	a->weight-=2.5;
	else
		printf("The weight could not be decreased to under 0.");
        return 1;
    }
    else if(strcmp(food,"Grass")==0){
	if (a->weight-4.5>=0)
        	a->weight-=4.5;
	else
		printf("The weight could not be decreased to under 0.");
        return 1;
    }
    else
        return 0;
}

int eat_food(const char* s)
{
    char animal_name[161];
    char food[50];
    int ret=sscanf(s,"E %s %[^\n]",animal_name,food);
    if(ret!=2){
        printf("The input is wrong!\n");
        return 0;
    }
    animal *current=head;
    if(head==NULL){
        printf("The zoo is empty!\n");
        return 0;
    }
    while(strcmp(current->name,animal_name)!=0) // searching for matching animal name
    {
        if(current->next==NULL){
            printf("There is no %s in the zoo!\n",animal_name);
            return 0;
        }
        current=current->next;
    }
    if(current->diet==NULL){ // animal's diet has not been defined yet
        printf("The diet is not defined yet!\n");
        return 0;
    }
    /* Convert the string (possible mixed-case)
    to initial capital letter followed by lowercase letters */
    food[0]=toupper(food[0]);
    int i=1;
    while(food[i]!='\0')
    {
        food[i]=tolower(food[i]);
        i++;
    }
    if(strcmp(current->diet,food)==0) // If the given food matches diet
        increase_weight(current); // weight will increase
    else {// If the given food does not match
        if(possible_decrease_weight(current,food)) // decrease weight
            printf("The animal does not like the food.\n");
        else // does nothing
            printf("The food is not possible food type.\n");
    }
    return 1;
}

//Print the animals
int print_animals(const char* s)
{
    char label;
    int ret=sscanf(s,"%c",&label);
    if(ret!=1){
        printf("The input is wrong!\n");
        return 0;
    }
    animal *current=head;
    if(head==NULL){
        printf("The zoo is empty!\n");
        return 0;
    }
    while(current!=NULL){
        if(current->diet==NULL) // animal's diet has not been defined yet
            printf("%s %.1f\n",current->name,current->weight);
        else
            printf("%s %.1f %s\n",current->name,current->weight,current->diet);
        current=current->next;
    }
    printf("All the animals in the zoo are printed successfully!\n");
    return 1;
}

// Store animals on a disc
int save_animals(const char* s)
{
    char filename[50];
    int ret=sscanf(s,"W %s",filename);
    if(ret!=1){
        printf("The input is wrong!\n");
        return 0;
    }
    int i=0;
    while(filename[i]!='\0'){
        i++;
    }
    if(filename[i-1]!='t' || filename[i-2]!='x' || filename[i-3]!='t' || filename[i-4]!='.') // If filename does not contain extension
        strcat(filename,".txt"); // add file extension
    FILE *f;
    f=fopen(filename,"w");
    if(f==NULL){
        printf("Could not open the file!\n");
        return 0;
    }
    animal *current=head;
    while(current!=NULL){
        fprintf(f,"%s %.1f %s\n",current->name,current->weight,current->diet);
        current=current->next;
    }
    fclose(f);
    printf("The animals in the zoo are stored on a disc successfully!\n");
    return 1;
}

// Loading animals from a disc, and replace previous stored animals
int load_animals(const char *s)
{
    char filename[50];
    int ret=sscanf(s,"O %s",filename);
    if(ret!=1){
        printf("The input is wrong!\n");
        return 0;
    }
    int i=0;
    while(filename[i]!='\0'){
        i++;
    }
    if(filename[i-1]!='t' || filename[i-2]!='x' || filename[i-3]!='t' || filename[i-4]!='.')
        strcat(filename,".txt");
    FILE *f;
    f=fopen(filename,"r");
    if(!f)
	{
	  printf("An error occured!\n");
	  return 1;
	}
    // Release memory of the animal list previously stored
    animal *current;
    while((current=head)!=NULL){
        head=head->next;
        free(current->name);
        free(current->diet);
        free(current);
    }

    char animal_name[161];
    char animal_diet[30];
    float animal_weight;
    char *str=malloc(250*sizeof(char));
    /* reads characters (one line) from the file
    and stores them as a string until its end */
    while(fgets(str,250,f)!=NULL)
    {
        if(ferror(f)){
            fprintf(stderr,"An file error occurred.\n");
            return 0;
        }
        int ret=sscanf(str,"%s %f %[^\n]",animal_name,&animal_weight,animal_diet); // gets name,weight and diet of animal
        // Assign the parameters of animal
        if(ret==3) // animal's diet has been defined
        {
            current=malloc(sizeof(animal)); // allocate memory for a animal
            current->name=malloc(strlen(animal_name)+1);
            strcpy(current->name,animal_name);
            current->name[strlen(animal_name)]='\0';
            current->weight=animal_weight;
            current->diet=malloc(strlen(animal_diet)+1);
            strcpy(current->diet,animal_diet);
            current->diet[strlen(animal_diet)]='\0';
            current->next=NULL;
        }
        if(ret==2) // animal's diet has not been defined yet
        {
            current=malloc(sizeof(animal));
            current->name=malloc(strlen(animal_name)+1);
            strcpy(current->name,animal_name);
            current->name[strlen(animal_name)]='\0';
            current->weight=animal_weight;
            current->diet=NULL;
            current->next=NULL;
        }
        // Add animal into linked list
        if(head==NULL){
            head=current;
            end=current;
        }
        else{
            end->next=current;
            end=current;
        }
    }
    free(str);
    fclose(f);
    printf("All the animals from the disk are loaded successfully!\n");
    return 1;
}

// Exit the program
void exit_program()
{
    animal *current=NULL;
    // Release memory
    while((current=head)!=NULL)
    {
        head=head->next;
        free(current->name);
        free(current->diet);
        free(current);
    }
    exit(0); // exit the program
}

int main(void)
{
    printf("A simple program simulating a zoo\n");
    printf("The commands(keyboard input):\n");
    printf("Add an animal: A animal_name animal_weight\n");
    printf("Delete an animal: D animal_name\n");
    printf("List all possible diets: B\n");
    printf("Define the diet of the animal(only can be chosen from the possible diets): B animal_name food\n");
    printf("Eat food(if the food is the animal's diet, the weight will increse, otherwise decrease): E animal_name food\n");
    printf("List all animals in the zoo: L\n");
    printf("Store the animals on a disc: W filename\n");
    printf("Load the animals from a disc: O filename\n");
    printf("Exit the program: Q\n");
    char s[220];
    fgets(s,220,stdin); // user input, stores it as a string into s
    char label;
    sscanf(s,"%c %*s",&label); // gets the first single capital letter
    while(1){ // loop for repeatedly ask for use input and work
        // different function is executed according to the character stored into label each time
        switch(label)
        {
        case 'A':
            add_animal(s);
            break;
        case 'D':
            delete_animal(s);
            break;
        case 'B':{
            char animal_name[161];
            int ret=sscanf(s,"B %s",animal_name);
            if(ret==1)
                define_diet(s);
            else
                list_possible_diets();
            }
            break;
        case 'E':
            eat_food(s);
            break;
        case 'L':
            print_animals(s);
            break;
        case 'W':
            save_animals(s);
            break;
        case 'O':
            load_animals(s);
            break;
        case 'Q':
            exit_program();
        default:
            printf("The input is wrong!\n");
            break;
        }
        // after the function has been executed, ask for user input
        fgets(s,220,stdin);
        sscanf(s,"%c %*s",&label);
    }
    return 0;
}

