#include "contact.h"

void menu()
{
    printf("*********************************\n");
    printf("*****  1.display  2.add     *****\n");
    printf("*****  3.erase    4.search  *****\n");
    printf("*****  5.modify   6.save    *****\n");
    printf("*****  0.exit               *****\n");
    printf("*********************************\n");
}
void test1()
{
    contact cont;
    InitContact(&cont);
    int input = 0;
    do
    {
        menu();
        printf("Please enter your choice: ");
        scanf("%d", &input);
        switch (input)
        {
        case DISPLAY:
            DisplayContact(&cont);
            break;
        case ADD:
            AddContact(&cont);
            break;
        case ERASE:
            // EraseContact(&cont);
            break;
        case SEARCH:
            SearchContact(&cont);
            break;
        case MODIFY:
            // ModifyContact(&cont);
            break;
        case SAVE:
            SaveContact(&cont);
            break;
        case EXIT:
            SaveContact(&cont);
            DestroyContact(&cont);
            printf("Exit.\n");
            break;
        default:
            printf("Illegal input.\n");
            break;
        }
    } while (input);
}
int main()
{
    test1();
    return 0;
}