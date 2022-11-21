#include <iostream>

struct Array
{
    int* content = nullptr;
    int capacity = 0;
    int lenght = 0;
};


void push(Array& arr, int value)
{
    if (arr.lenght == arr.capacity)
    {
        int* tempArray = new int[arr.capacity * 2]();

        for (int i = 0; i < arr.capacity; ++i)
            tempArray[i] = arr.content[i];

        delete[] arr.content;
        arr.content = new int[arr.capacity * 2]();

        for (int i = 0; i < arr.capacity; ++i)
            arr.content[i] = tempArray[i];

        delete[] tempArray;
        tempArray = nullptr;

        arr.capacity *= 2;
    }
    arr.content[arr.lenght] = value;
    arr.lenght += 1;
}

void pull(Array& arr)
{
    if (arr.lenght == 0)
    {
        std::cout << "There are no items to pull\n";
    }
    else
    {
        arr.content[arr.lenght - 1] = 0;
        std::cout << "Pull element with index " << arr.lenght - 1 << "\n";
        arr.lenght -= 1;
    }
}

int find(Array& arr, int value)
{
    for (int i = 0; i < arr.lenght; ++i)
    {
        if (arr.content[i] == value)
            return i;
    }
    return -1;
}

void print(Array& arr)
{
    for (int i = 0; i < arr.capacity; ++i)
        std::cout << arr.content[i] << "\n";
}


int main()
{
    Array arr;
    arr.content = new int[2]();
    arr.capacity = 2;
    arr.lenght = 0;

    int value;
    int result;

    while (true)
    {
        std::cout << "Select the desired action: \n1. Push\n2. Pull\n3. Find\n4. Print\n\n0. Exit\n";
        int userAction;
        std::cin >> userAction;

        if (userAction == 0)
            break;

        switch (userAction)
        {
        case 1:
            std::cout << "Your select PUSH\n";
            std::cout << "Enter value of " << arr.lenght + 1 << " of " << arr.capacity << " element\n";
            std::cin >> value;

            push(arr, value);

            break;

        case 2:
            std::cout << "Your select PULL\n";
            pull(arr);
            break;

        case 3:
            std::cout << "Your select FIND\n";
            std::cout << "Enter the value of the item you want to find\n";
            std::cin >> value;
            result = find(arr, value);
            if (result == -1)
                std::cout << "There is no such element in the array\n";
            else
                std::cout << "The desired array element has an index of " << result << "\n";
            break;

        case 4:
            std::cout << "Your select PRINT\n";
            print(arr);
            break;

        default:
            std::cout << "Unknown choice\nMake the right choice\n";
            break;
        };
    }
    return 0;
}

