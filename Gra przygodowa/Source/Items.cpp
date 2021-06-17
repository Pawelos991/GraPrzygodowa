#include "Items.h"

void Items::delete_all_items()
{
    Item *temp=head;
    while(temp!=nullptr)
    {
        temp=head->getNext();
        delete head;
        head=temp;
    }
}

void Items::add_item(Item *added)
{
    added->setNext(nullptr);
    if(head==nullptr)
    {
        head=added;
        head->setNext(nullptr);
        return;
    }
    else if(head!=nullptr && head->getNext()==nullptr)
    {
        head->setNext(added);
        return;
    }
    else if(head!=nullptr && head->getNext()!=nullptr)
    {
        Item *temp;
        temp=head;
        while(temp->getNext()!=nullptr)
            temp=temp->getNext();
        temp->setNext(added);
        return;
    }
}

void Items::add_item(int IDc, std::string namec, std::string location)
{
    Item *added=new Item(IDc,namec,location);
    add_item(added);
}

Item* Items::find_item(int ID)
{
    Item *temp=head;
    while(temp!=nullptr && temp->getID()!=ID)

        {
           temp=temp->getNext();
        }
    return temp;
}

void Items::delete_item(int ID)
{
    Item *temp=head;
    if(head->getID()==ID)
    {
        temp=temp->getNext();
        delete head;
        head=temp;
        return;
    }
    else
    {
        Item *temp2;
        while(temp->getNext()!=nullptr && temp->getNext()->getID()!=ID)
            temp=temp->getNext();
        temp2=temp->getNext();
        if(temp2!=nullptr)
            temp->setNext(temp->getNext()->getNext());
        delete temp2;
    }
}

void Items::LoadItemsFromFile()
{
    std::fstream fp;
    std::string name;
    int ID;
    std::string location;
    try
    {
        fp.open("Data/Items.txt");
        if(fp.good()==false)
            throw 1;
    }
    catch(int x)
    {
        if(x==1)
            std::cout<<"Brak pliku lub niepoprawny plik Data/Items.txt"<<std::endl;
    }

    while(true)
    {
    if(fp.good());
    else
        break;
    fp>>ID;
    fp>>name;
    fp>>location;
    add_item(ID,name,location);
    }

    fp.close();
}

std::vector<int> Items::Item_ids()
{
    Item* temp=head;
    std::vector<int> ret;
    while(temp!=nullptr)
    {
        ret.push_back(temp->getID());
        temp=temp->getNext();
    }
    return ret;
}

void Replace_withSpace(std::string &to_replace)
{
    for(int i=0;i<to_replace.length();i++)
    {
        if(to_replace[i]=='_')
            to_replace[i]=' ';
    }
}
