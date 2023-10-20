#include <stdio.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

// char firstName;
// char lastName;
// char username;
// char password;
// int age;
union Data
{
    struct active
    {
        bool isActive;
    } active;
} data;

struct save
{
    char firstName;
    char lastName;
    char username;
    char password;
    int age;
};

void signup()
{
    union Data data;
    struct save u;
    FILE *store;
    store = fopen("save.txt", "a");

    if (store == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // printf("Enter your first name: ");
    // scanf("%s", &firstName);
    // printf("Enter your last name: ");
    // scanf("%s", &lastName);
    // printf("Enter your username: ");
    // scanf("%s", &username);
    // printf("Enter your password: ");
    // scanf("%s", &password);
    // printf("Enter your age: ");
    // scanf("%d", &age);

    printf("Enter your first name: ");
    scanf("%s", &u.firstName);
    printf("Enter your last name: ");
    scanf("%s", &u.lastName);
    printf("Enter your username: ");
    scanf("%s", &u.username);
    printf("Enter your password: ");
    scanf("%s", &u.password);
    printf("Enter your age: ");
    scanf("%d", &u.age);
    printf("type 1 or T if ur active & 0 OR F if ur not :");
    scanf("%s", &data.active.isActive);

    // fprintf(save,&firstName );
    // fprintf(&us, sizeof(us), 1, save);

    // fwrite(&u, 1, sizeof(u), store);
    // fclose(store);

    fprintf(store, "%s %s %s %s %d %s\n", &u.firstName, &u.lastName, &u.username, &u.password, &u.age, &data.active.isActive);
    printf("you signed up succesfully, now sign in");
    getch();
    system("CLS");
    login();
}

int login()
{
    union Data data;
    struct save u;
    FILE *store;
    store = fopen("save.txt", "r");

    char username[30];
    char password[30];

    printf("enter your username : ");
    scanf("%s", &username);
    // if (username < 5)
    // {
    //     printf("error, username should be atleast 6 characters ");
    //     login();
    // }
    // else if (username > 15)
    // {
    //     printf("error, username shouldnt exceed 15 characters ");
    //     login();
    // }

    printf("enter your password : ");
    scanf("%s", &password);

    while (fread(&u, 1, sizeof(u), store))
    {
        // if (strcmp(username, &username) == 0 && strcmp(password, &password) == 0)

        if (strcmp(username, u.username) == 0 && strcmp(password, u.password) == 0)
        {
            // printf("you signed in succesfully");
            if (data.active.isActive == 1 || data.active.isActive == 'T')
            {
                printf("you signed in succesfully");
            }
            else
            {
                printf("you can not sign in!");
            }
        }
        else
        {
            printf("some credintials arent correct");
        }
    }

    // printf("you signed in succesfully");

    fclose(store);

    // if (username == username && password == password)
    // {
    //     printf("you signed in succesfully");
    // }
    // else
    // {
    //     (" some credintials arent correct");
    // }
}

int main()
{
    union Data data;
    struct save u;
    int inorup;
    printf("type 0 to login OR type 1 to sign up\n");
    scanf("%d", &inorup);
    if (inorup == 0)
    {
        system("CLS");
        login();
    }
    else if (inorup == 1)
    {
        system("CLS");
        signup();
    }
}
