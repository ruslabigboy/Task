#include <iostream>


struct Node
{
    int value = 0;
    Node* next = nullptr;
};
struct LinkedList
{
    Node* first = nullptr;
    Node* last = nullptr;
};

void add_wo_last(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;

    if (list->first == nullptr)
        list->first = node;
    else
    {
        Node* temp = list->first;

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = node;
    }
}

void add_w_last(LinkedList* list, int value)
{
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;

    if (list->first == nullptr)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        Node* temp = list->last;
        temp->next = node;
        list->last = node;
    }
}

void del(LinkedList* list)
{
    if (list->first == nullptr)
        std::cout << "There are no members in this linked list\n";

    else
    {
        Node* temp = list->first;
        Node* prev = list->first;

        while (temp->next != nullptr);
        {
            prev->next = temp;
            temp = temp->next;
        }

        list->last = prev;
        prev->next = nullptr;
    }
}

int find(LinkedList* list, int value)
{
    if (list->first == nullptr)
        std::cout << "There are no members in this linked list\n";
    else
    {
        Node* temp = list->first;

        int place = 0;

        do
        {
            if (temp->value == value)
                return place;
            else
                place += 1;

            temp = temp->next;
        }

        while (temp->next != nullptr);
    }

    return -1;
}


void print(LinkedList* list)
{
    if (list->first == nullptr)
        std::cout << "There are no members in this linked list\n";
    else
    {
        Node* temp = list->first;

        while (temp->next != nullptr)
        {
            std::cout << temp->value << "\n";
            temp = temp->next;
        }
        std::cout << temp->value << "\n";
    }
}


int main()
{
    LinkedList* list = new LinkedList;
    list->first = nullptr;
    list->last = nullptr;

    int value = 0;
    int result = 0;

    while (true)
    {
        std::cout << "Select the desired action: \n1. Add\n2. Del\n3. Find\n4. Print\n\n0. Exit\n";
        int userAction;
        std::cin >> userAction;

        if (userAction == 0)
            break;

        switch (userAction)
        {
        case 1:
            std::cout << "Your select ADD\n";
            std::cout << "Enter value of " << " element\n";
            std::cin >> value;

            add_w_last(list, value);

            break;

        case 2:
            std::cout << "Your select DEL\n";
            del(list);
            break;

        case 3:
            std::cout << "Your select FIND\n";
            std::cout << "Enter the value of the item you want to find\n";
            std::cin >> value;
            result = find(list, value);
            if (result == -1)
                std::cout << "There is no such element in the array\n";
            else
                std::cout << "The desired array element has an index of " << result << "\n";
            break;

        case 4:
            std::cout << "Your select PRINT\n";
            print(list);
            break;

        default:
            std::cout << "Unknown choice\nMake the right choice\n";
            break;
        };
    }

    return 0;
}