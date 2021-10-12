#include "Animations.h"


Animations::~Animations()
{
    //dtor
}

Animation* Animations::add_animation(std::string Name, int ID,int Frames,float Delay)
{
    Animation *added = new Animation(Name, ID,Frames,Delay);
    added->setNext(nullptr);
    if(head==nullptr)
    {
        head=added;
        return added;
    }
    else
    {
        Animation *temp=head;
        while(temp->getNext()!=nullptr)
            temp=temp->getNext();
        temp->setNext(added);
        return added;
    }
}

void Animations::delete_all_animations()
{
    Animation *temp=head;
    while(temp!=nullptr)
    {
        temp=head->getNext();
        delete head;
        head = temp;
    }
}

Animation* Animations::find_animation(int ID)
{
    Animation *temp=head;
    while(temp!=nullptr && temp->getID()!=ID)
        temp=temp->getNext();
    return temp;
}

void Animations::add_animation(Animation* added)
{
    added->setNext(nullptr);
    if(head==nullptr)
    {
        head=added;
        return;
    }
    else
    {
        Animation *temp=head;
        while(temp->getNext()!=nullptr)
            temp=temp->getNext();
        temp->setNext(added);
        return;
    }
}


void Animations::LoadAnimationsFromFile(std::string adress)
{
    std::ifstream fp;

    int ID, a;
    int delay;
    std::string name;
    std::string location;
    Texture t;

    try
    {
    fp.open(adress);
    if (fp.good()==false)
        throw 1;
    }
    catch(int x)
    {
        if(x==1)
            std::cout<<"Brak pliku lub niepoprawny plik "<<adress<<std::endl;
    }

    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>ID;
        fp>>name;
        fp>>a;
        fp>>delay;
        Animation *added = add_animation(name,ID,a,delay);
        for(int i=0; i<a;i++)
        {
            fp>>location;
            t.loadFromFile(location);
            added->setTexture(i,t);
        }
    }
    fp.close();
}
