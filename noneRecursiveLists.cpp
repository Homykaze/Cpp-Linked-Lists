#include <iostream>

using namespace std;

struct linked_list{
    int id;
    string data;
    linked_list* next;
};

//Add nodes in sorted order function
linked_list* addNode(linked_list* list);
//Displays list non-recursively
void display(linked_list* list);
//Non-recursive implementation of 'delete node' function
linked_list* removeNode(linked_list* list);

int main()
{
    linked_list* list = NULL;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++)
        list = addNode(list);

    display(list);
    cin >> number;
    for (int i = 0; i < number; i++)
        list = removeNode(list);
    display(list);
}

//Non-recursive function to remove a node
linked_list* removeNode(linked_list* list)
{
    int id;
    cout << "Item's ID to be deleted: ";
    cin >> id;

    //Simple case 1: list is empty
    if (list == NULL)
        return NULL;
    //Iterator for the list
    linked_list* current = list;
    //Keep the previous node to relink nodes on deletion
    linked_list* prev = current;
    //Variable to store the next node to relink nodes on deletion
    linked_list* next = current->next;
    //Simple case 2: first node is the target node
    if (list->id == id)
    {
        delete list;
        return next;
    }
    //Looping throught the whole list to find the node to be deleted
    while (current != NULL && current->id != id)
    {
        prev = current;
        current = current->next;
    }
    //This means we didn't find it
    if (current == NULL)
        return list;
    //This is where deletion is happening
    else
    {
        next = current->next;
        delete current;
        prev->next = next;
        return list;
    }
}

//Adds nodes to a linked list in sorted order
linked_list* addNode(linked_list* list)
{
    linked_list* node = new linked_list;
    cout << "ID: ";
    cin >> node->id;
    cout << "Data: ";
    cin >> node->data;

    if (list == NULL)
    {
        node->next = list;
        return node;
    }
    else if (node->id > list->id)
    {
        linked_list* current = list;
        linked_list* prev = current;
        while (current != NULL && node->id > current->id)
        {
            prev = current;
            current = current->next;
        }        
        if (current == NULL)
        {
            prev->next = node;
            current = node;
            node->next = NULL;
        }
        else
        {
            prev->next = node;
            node->next = current;
        }
        return list;
    }

    node->next = list;
    return node;
}

//None-recursive node finder
void getNode(linked_list* list, int id)
{
    linked_list* temp = list;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Data: " << temp->data << "; id = " << temp->id << endl;
            return;
        }
        temp = temp->next;
    }
}

//Displays the contents of a linked list
void display(linked_list* list)
{
    linked_list* current = list;
    cout << "\n";
    while (current != NULL)
    {
        cout << current->id << " " << current->data << endl;
        current = current->next;
    }
}