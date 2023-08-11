#include "LinkedList.h"

struct Node *head = NULL;

int main()
{
    uint8 userChoice = 0;
    uint32 listLength = 0;

    printf("-> Hello to Single Linked List \n");
    while(1){
        printf("\n");
        printf("===============================\n");
        printf("-> 1) Insert_Node_At_Beginning \n");
        printf("-> 2) Insert_Node_At_End \n");
        printf("-> 3) Insert_Node_After \n");
        printf("-> 4) Delete_Node_At_Beginning \n");
        printf("-> 5) Delete_Node \n");
        printf("-> 6) Display_All_Nodes \n");
        printf("-> 7) Get_Length \n");
        printf("-> 8) Quit from application \n");
        printf("===============================\n");

        printf("\n");
        printf("UserChoice : ");
        scanf("%i", &userChoice);

        switch(userChoice){
            case 1:
                insertNodeAtBeginning(&head);
            break;
            case 2:
                insertNodeAtEnd(&head);
            break;
            case 3:
                insertNodeAfter(head);
            break;
            case 4:
                deleteNodeAtBeginning(&head);
            break;
            case 5:
                deleteNode(&head);
            break;
            case 6:
                displayAllNodes(head);
            break;
            case 7:
                listLength = getLength(head);
                printf("List Length : << %i >> Nodes\n", listLength);
            break;
            case 8:
                printf("Quit from application \n");
                exit(1);
            break;
            default:
                printf("User Choice out of range !!\n");
            break;
        }
    }


    return 0;
}