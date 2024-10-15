#include <bits/stdc++.h>
using namespace std;
class contact
{
public:
    string Name;
    long long int Number;
    contact *next;

    contact(string name, long long int number)
    {
        this->Name = name;
        this->Number = number;
        next = NULL;
    }

    // Function to insert in the contact list

    void insert(contact *&head, string contact_person, long long int contact_number)
    {
        contact *new_data = new contact(contact_person, contact_number);

        contact *curr = NULL;
        contact *forward = head;

        if (contact_person < head->Name)
        {
            new_data->next = head;
            head = new_data;
        }
        else
        {
            while (forward != NULL && forward->Name < contact_person)
            {
                curr = forward;
                forward = forward->next;
            }

            if (forward != NULL)
            {
                if (forward->Name == contact_person)
                {
                    if (forward->Number > contact_number)
                    {
                        curr->next = new_data;
                        new_data->next = forward;
                    }
                    else if (forward->Number < contact_number)
                    {
                        new_data->next = forward->next;
                        forward->next = new_data;
                    }
                    else
                    {
                        cout << "The give contact is already present\n";
                    }
                }
                else
                {
                    curr->next = new_data;
                    new_data->next = forward;
                }
            }
            else
            {
                curr->next = new_data;
            }
        }
    }
    // Function to delete the contact list
    void delete_the_list(contact *&head, string name)
    {
        contact *curr = NULL;
        contact *forw = head;

        if (name == head->Name)
        {
            contact *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }

        while (forw != NULL && forw->Name != name)
        {
            curr = forw;
            forw = forw->next;
        }

        if (forw == NULL)
        {
            cout << name << ": Does not exist in your contact list\n";
        }
        else
        {
            curr->next = forw->next;
            forw->next = NULL;
            delete forw;
        }
    }
    contact *search_for(contact *head, string name)
    {
        while (head != NULL && head->Name != name)
        {
            head = head->next;
        }
        return head;
    }
};
int main()
{
    contact *head = new contact("apple", 7960180);

    head->insert(head, "banana", 3552991);
    head->insert(head, "cat", 474868);
    head->insert(head, "dog", 9014775);
    head->insert(head, "mountain", 401475);
    head->insert(head, "hill", 46015);

    cout << "1: TO  ADD A CONTACT INFO\n";
    cout << "2: TO DELETE THE CONTACT\n";
    cout << "3: TO RENAME ANY LIST\n";
    cout << "4: TO GET PHONE NUMBER OF LIST\n";
    cout << "0: TO EXIT\n";

    int data;

    while (data != 0)
    {
        cout << "Enter the value to execute your process -> ";
        cin >> data;

        if (data == 1)
        {
            string name;
            long long int number;
            cout << "ENTER THE NAME OF MEMBER -> ";
            cin >> name;

            cout << "\nEnter the PHONE NUMBER THE MEMBER -> ";
            cin >> number;

            head->insert(head, name, number);
        }
        else if (data == 2)
        {
            string name;
            cout << "ENTER THE NAME OF PERSON TO DELETE -> ";
            cin >> name;

            head->delete_the_list(head, name);
        }
        else if (data == 3)
        {
            string new_name;
            string original_name;

            cout << "ENTER THE NAME OF CONTACT -> ";
            cin >> original_name;

            cout << "ENTER NEW NAME -> ";
            cin >> new_name;

            contact *temp = head->search_for(head, original_name);

            if (temp != NULL)
            {
                head->delete_the_list(head, original_name);
                head->insert(head, new_name, temp->Number);
            }
            else
            {
                cout << temp->Name << ": DOES NOT EXIT IN YOUR LIST\n";
            }
        }
        else if (data == 4)
        {
            string name;
            cout << "Enter the name of the person -> ";
            cin >> name;
            contact *temp = head->search_for(head, name);

            if (temp == NULL)
            {
                cout << name << ": DOES NOT EXIT IN YOUR LIST\n";
            }
            else
            {
                cout << "THE PHONE NUMBER OF " << name << " is " << temp->Number << endl;
            }
        }
    }
    return 0;
}
// contact *list1 = new contact("Mummy", 574523614);
// contact *list2 = new contact("Papa", 97458514);
// contact *list3 = new contact("Bro", 374574114);

// cout << "Before deleting \n\n";
// contact *temp = head;

// while (temp)
// {
//     cout << "Name -> " << temp->Name << ", Number -> " << temp->Number << endl;
//     temp = temp->next;
// }

// cout << "After deleting \n\n";

// head->delete_the_list(head,"rpp");
//  temp = head;

// while (temp)
// {
//     cout << "Name -> " << temp->Name << ", Number -> " << temp->Number << endl;
//     temp = temp->next;
// }