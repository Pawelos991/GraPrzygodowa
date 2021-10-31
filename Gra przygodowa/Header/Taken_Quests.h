#ifndef TAKEN_QUESTS_H
#define TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbi�r przyj�tych zada�
*/
class Taken_Quests
{
    public:
        /**
        * Konsturktor klasy wczytuj�cy potrzebne dane z plik�w i ustawiaj�cy odpowiednie atrybuty
        */
        Taken_Quests();
        /**
        * Destruktor klasy
        */
        virtual ~Taken_Quests();

    protected:
        /**Wektor wska�nik�w na przyj�te zadania*/
        std::vector<Quest*> taken_quests;
        /**
        * Funkcja dodaj�ca przyj�te zadanie do wektora wska�nik�w na przyj�te zadania poprzez skopiowanie go z wektora wska�nik�w na zadania nieprzyj�te
        * @param id ID zadania kt�re ma zosta� dodane do wektora
        * @param not_taken_quests Wektor wska�nik�w na zadania nieprzyj�te
        */
        void add_t_quest(int id, std::vector<Quest*> &not_taken_quests);
        /**
        * Funkcja usuwaj�ca zadanie o podanym ID z wektora wska�nik�w na zadania przyj�te
        * @param id ID zadania kt�re ma zosta� usuni�te
        */
        void remove_t_quest(int id);
        /**
        * Funkcja usuwaj�ca wszystkie zadania z wektora wska�nik�w na zadania przyj�te
        */
        void remove_all_t_quests();
        /**
        * Funkcja wy�wietlaj�ca przyj�te zadania w oknie
        * @param window Okno w kt�rym maj� zosta� wy�wietlone przyj�te zadania
        * @param position Pozycja okienka zada� potrzebna do odpowiedniego umieszczenia tekst�w zada� w oknie
        */
        void display_active_quests(RenderWindow &window, Vector2f position);
        /**
        * Funkcja wy�wietlaj�ca nowe zadanie w oknie (dok�adniej jego tytu�)
        * @param window Okno w kt�rym ma zosta� wy�wietlone nowe zadanie
        * @param id ID nowego zadania kt�rego tytu� ma zosta� wy�wietlony
        */
        void display_new_quest(RenderWindow& window, int id);
        /**
        * Funkcja dodaj�ca nowe zadanie do wektora wska�nik�w na przyj�te zadania wraz z wy�wietleniem go w oknie
        * @param window Okno w kt�rym wy�wietlony ma zosta� tytu� nowego zadania
        * @param ID ID zadania kt�re ma zosta� dodane do wektora wska�nik�w zada� przyj�tych
        * @param not_taken_quests Wektor wska�nik�w na nieprzyj�te zadania
        * @param counter Licznik klatek potrzebny do poprawnego wy�wietlenia powiadomienia o nowym zadniu w oknie
        */
        void add_t_quest_display(RenderWindow& window, int id, std::vector<Quest*>& not_taken_quests, int counter);
        /**Czcionka tekstu wypisuj�cego przyj�te zadania*/
        Font font;
        /**Tekst s�u��cy do wypisania przyj�tych zada�*/
        Text text;
        /**
        * Funkcja �aduj�ca czcionk� z pliku i ustawiaj�ca j� w tek�cie powiadomienia o nowym zadaniu
        */
        void getFont();

    private:
        /**Tekstura okienka powiadomienia o nowym zadaniu*/
        Texture new_tex;
        /**Sprite okienka powiadomienia o nowym zadaniu*/
        Sprite new_sp;
        /**D�wi�k powiadomienia o przyj�ciu nowego zadania*/
        Sound sound;
        /**Bufor przechowuj�cy d�wi�k powiadomienia o przyj�ciu nowego zadania*/
        SoundBuffer sb;
        /**Tekst powiadomienia o nowym zadaniu (ustawiany na tytu� nowego zadania)*/
        Text te;
};

#endif // TAKEN_QUESTS_H
