#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int option, choose;
    char password[100];
    printf("WELCOME! TO THE LIBRARY\n");
    printf("___________________________\n");

    while (1)
    {
        printf("choose your path:\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("~Welcome Admin~\n");
            printf("__________________\n");
            printf("Enter the password: ");
            scanf("%s", password);
            if (strcmp(password, "adminlogin") == 0)
            {
                printf("~Welcome Again~\n");
                printf("What are you gonna work on today?\n");
                printf("1. Add new books\n");
                printf("2. Remove books\n");
                printf("3. Exit\n");
                scanf("%d", &choose);
                switch (choose)
                {
                case 1:
                {
                    int id;
                    char book_name[100], author[100], description[500];
                    printf("Add books\n");
                    FILE *Add = fopen("data.txt", "a");
                    if (Add == NULL)
                    {
                        printf("Error opening file!\n");
                        break;
                    }
                    printf("Fill the following items:\n");
                    printf("ID: ");
                    scanf("%d", &id);
                    getchar();
                    printf("Book name: ");
                    fgets(book_name, sizeof(book_name), stdin);
                    printf("Author: ");
                    fgets(author, sizeof(author), stdin);
                    printf("Description: ");
                    fgets(description, sizeof(description), stdin);
                    fprintf(Add, "%d|%s|%s|%s", id, book_name, author, description);
                    fclose(Add);
                    break;
                }

                case 2:
                {
                    int remove_id, found = 0;
                    printf("Enter the ID of the book to remove: ");
                    scanf("%d", &remove_id);

                    FILE *original = fopen("data.txt", "r");
                    FILE *temp = fopen("temp.txt", "w");

                    if (original == NULL || temp == NULL)
                    {
                        printf("Error opening file!\n");
                        break;
                    }

                    char line[700];
                    while (fgets(line, sizeof(line), original) != NULL)
                    {
                        int id;
                        sscanf(line, "%d|", &id);
                        if (id != remove_id)
                        {
                            fputs(line, temp);
                        }
                        else
                        {
                            found = 1;
                        }
                    }

                    fclose(original);
                    fclose(temp);

                    remove("data.txt");
                    rename("temp.txt", "data.txt");

                    if (found)
                    {
                        printf("Book with ID %d removed successfully.\n", remove_id);
                    }
                    else
                    {
                        printf("Book with ID %d not found.\n", remove_id);
                    }
                    break;
                }

                case 3:
                    printf("Exiting Admin Mode...\n");
                    break;

                default:
                    printf("Invalid admin option.\n");
                    break;
                }
            }
            else
            {
                printf("Incorrect password, try again\n");
            }
            break;

        case 2:
        {
            int useroption;
            printf("Welcome User\n");
            printf("What's your plan for today?\n");
            printf("1. Borrow book\n");
            printf("2. Return book\n");
            printf("3. Exit\n");
            scanf("%d", &useroption);

            switch (useroption)
            {
            case 1:
            {
                int genre;
                char book_name[100];
                char book_option[100], your_name[100], genre_name[100];
                char continue_option[10] = "yes";
                while (strcmp(continue_option, "yes") == 0)
                {
                    printf("Choose the books by genre:\n");
                    printf("1. Psychological Thriller\n");
                    printf("2. Mystery\n");
                    printf("3. Non-fiction\n");
                    printf("4. Murder/Crime\n");
                    printf("5. Exit\n");
                    scanf("%d", &genre);
                    getchar(); // clean newline

                    switch (genre)
                    {
                    case 1:
                        printf("Listing the books\n");
                        printf("Genre - Psychological Thriller\n");
                        printf("1. Silent Patient\n");
                        printf("ID: 200\n");
                        printf("Author: Alex Michaelides\n");
                        printf("Description: A psychological thriller about a woman who stops speaking after a shocking act of violence.\n");
                        printf("Like this genre? Borrow a book? (yes/no): ");
                        scanf("%s", book_option);
                        if (strcmp(book_option, "yes") == 0)
                        {
                            printf("Enter your name: ");
                            scanf("%s", your_name);
                            printf("Enter the genre: ");
                            scanf("%s", genre_name);
                            printf("Enter the book name: ");
                            scanf("%s", book_name);
                            printf("~HAPPY READING~\n");
                        }
                        break;

                    case 2:
                        printf("Listing the books\n");
                        printf("Genre - Mystery\n");
                        printf("1. Gone Girl\n");
                        printf("ID: 210\n");
                        printf("Author: Gillian Flynn\n");
                        printf("Description: A suspenseful mystery about a missing wife and her suspicious husband.\n");
                        printf("Like this genre? Borrow a book? (yes/no): ");
                        scanf("%s", book_option);
                        if (strcmp(book_option, "yes") == 0)
                        {
                            printf("Enter your name: ");
                            scanf("%s", your_name);
                            printf("Enter the genre: ");
                            scanf("%s", genre_name);
                            printf("Enter the book name: ");
                            scanf("%s", book_name);
                            printf("~HAPPY READING~\n");
                        }
                        break;

                    case 3:
                        printf("Listing the books\n");
                        printf("Genre - Non-fiction\n");
                        printf("1. Atomic Habits\n");
                        printf("ID: 220\n");
                        printf("Author: James Clear\n");
                        printf("Description: A guide to building good habits and breaking bad ones through small daily changes.\n");
                        printf("Like this genre? Borrow a book? (yes/no): ");
                        scanf("%s", book_option);
                        if (strcmp(book_option, "yes") == 0)
                        {
                            printf("Enter your name: ");
                            scanf("%s", your_name);
                            printf("Enter the genre: ");
                            scanf("%s", genre_name);
                            printf("Enter the book name: ");
                            scanf("%s", book_name);
                            printf("~HAPPY READING~\n");
                        }
                        break;

                    case 4:
                        printf("Listing the books\n");
                        printf("Genre - Murder/Crime\n");
                        printf("1. The Girl in Room 105\n");
                        printf("ID: 230\n");
                        printf("Author: Chetan Bhagat\n");
                        printf("Description: A gripping murder mystery about love, obsession, and justice.\n");
                        printf("Like this genre? Borrow a book? (yes/no): ");
                        scanf("%s", book_option);
                        if (strcmp(book_option, "yes") == 0)
                        {
                            printf("Enter your name: ");
                            scanf("%s", your_name);
                            printf("Enter the genre: ");
                            scanf("%s", genre_name);
                            printf("Enter the book name: ");
                            scanf("%s", book_name);
                            printf("~HAPPY READING~\n");
                        }
                        break;

                    case 5:
                        strcpy(continue_option, "no");
                        break;

                    default:
                        printf("Option under development.\n");
                        break;
                    }
                }
                break;
            }

            case 2:
                printf("Feature coming soon...\n");
                break;

            case 3:
                printf("Exiting User Mode...\n");
                break;

            default:
                printf("Invalid user option.\n");
                break;
            }
            break;
        }

        case 3:
            printf("Exiting Program. Bye!\n");
            exit(0);

        default:
            printf("Invalid option.\n");
            break;
        }
    }

    return 0;
}
