#include <iostream>

using namespace std;

struct linked_list
{
    int data;
    linked_list* next;
};

//Recursive function that adds nodes to the list in the order of input
linked_list* addNode(linked_list* list);
//Recursive function that displays nodes of the list
void display(linked_list* list);
//Recursive function that sums up values of the list
int sum(linked_list* list);
//Recursive function that counts the number of elements in the list
int getNumberOfElements(linked_list* list, int counter);
//Recursive function to find the greatest number in the list
int getMax(linked_list* list, int max);
//Recursive function to remove a node from the list by value
linked_list* removeNode(linked_list* list, int target);

int main()
{
    linked_list* list = NULL;
    int input;
    cout << "Number of elements: ";
    cin >> input;
    for (int i = 0; i < input; i++)
        list = addNode(list);
    display(list);
    cout << "Sum: " << sum(list) << endl;
    cout << "Number of elements in the list: " << getNumberOfElements(list, 0) << endl;
    cout << "Greatest number in the list: " << getMax(list, -1234567890) << endl;
    cout << "Remove node: ";
    cin >> input;
    list = removeNode(list, input);
    display(list);
}

linked_list* addNode(linked_list* list)
{
    //Base case
    if (list == NULL)
    {
        int value;
        cin >> value;
        linked_list* node = new linked_list;
        node->data = value;
        node->next = NULL;
        return node;
    }
    //Recursive case
    list->next = addNode(list->next);
    return list;
}

void display(linked_list* list)
{
    //Base case
    if (list == NULL)
    {
        cout << endl;
        return;
    }
    cout << list->data << " ";
    //Recursive case
    display(list->next);
}

int sum(linked_list* list)
{
    //Base case
    if (list == NULL)
        return 0;
    //Recursive case
    else
        return list->data + sum(list->next);
}

int getNumberOfElements(linked_list* list, int counter)
{
    //Base case
    if (list == NULL)
        return counter;
    //Recursive case
    else
        return getNumberOfElements(list->next, counter + 1);
}

int getMax(linked_list* list, int max)
{
    //Base case
    if (list == NULL)
        return max;
    //Recursive case
    else
    {
        if (list->data > max)
            max = list->data;
        return getMax(list->next, max);
    }
}

linked_list* removeNode(linked_list* list, int target)
{
    //Base case
    if (list == NULL)
        return list;
    //Second base case
    if (list->data == target)
    {
        linked_list* temp = list->next;
        delete list;
        //We can keep on calling recursively here to remove all nodes with this value from the list
        return temp;
    }
    //Recursive case
    else
    {
        list->next = removeNode(list->next, target);
        return list;
    }
}
