#ifndef TAKEN_QUESTS_H
#define TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbiór przyjêtych zadañ
*/
class Taken_Quests
{
    public:
        /**
        * Konsturktor klasy wczytuj¹cy potrzebne dane z plików i ustawiaj¹cy odpowiednie atrybuty
        */
        Taken_Quests();
        /**
        * Destruktor klasy
        */
        virtual ~Taken_Quests();

    protected:
        /**Wektor wskaŸników na przyjête zadania*/
        std::vector<Quest*> taken_quests;
        /**
        * Funkcja dodaj¹ca przyjête zadanie do wektora wskaŸników na przyjête zadania poprzez skopiowanie go z wektora wskaŸników na zadania nieprzyjête
        * @param id ID zadania które ma zostaæ dodane do wektora
        * @param not_taken_quests Wektor wskaŸników na zadania nieprzyjête
        */
        void add_t_quest(int id, std::vector<Quest*> &not_taken_quests);
        /**
        * Funkcja usuwaj¹ca zadanie o podanym ID z wektora wskaŸników na zadania przyjête
        * @param id ID zadania które ma zostaæ usuniête
        */
        void remove_t_quest(int id);
        /**
        * Funkcja usuwaj¹ca wszystkie zadania z wektora wskaŸników na zadania przyjête
        */
        void remove_all_t_quests();
        /**
        * Funkcja wyœwietlaj¹ca przyjête zadania w oknie
        * @param window Okno w którym maj¹ zostaæ wyœwietlone przyjête zadania
        * @param position Pozycja okienka zadañ potrzebna do odpowiedniego umieszczenia tekstów zadañ w oknie
        */
        void display_active_quests(RenderWindow &window, Vector2f position);
        /**
        * Funkcja wyœwietlaj¹ca nowe zadanie w oknie (dok³adniej jego tytu³)
        * @param window Okno w którym ma zostaæ wyœwietlone nowe zadanie
        * @param id ID nowego zadania którego tytu³ ma zostaæ wyœwietlony
        */
        void display_new_quest(RenderWindow& window, int id);
        /**
        * Funkcja dodaj¹ca nowe zadanie do wektora wskaŸników na przyjête zadania wraz z wyœwietleniem go w oknie
        * @param window Okno w którym wyœwietlony ma zostaæ tytu³ nowego zadania
        * @param ID ID zadania które ma zostaæ dodane do wektora wskaŸników zadañ przyjêtych
        * @param not_taken_quests Wektor wskaŸników na nieprzyjête zadania
        * @param counter Licznik klatek potrzebny do poprawnego wyœwietlenia powiadomienia o nowym zadniu w oknie
        */
        void add_t_quest_display(RenderWindow& window, int id, std::vector<Quest*>& not_taken_quests, int counter);
        /**Czcionka tekstu wypisuj¹cego przyjête zadania*/
        Font font;
        /**Tekst s³u¿¹cy do wypisania przyjêtych zadañ*/
        Text text;
        /**
        * Funkcja ³aduj¹ca czcionkê z pliku i ustawiaj¹ca j¹ w tekœcie powiadomienia o nowym zadaniu
        */
        void getFont();

    private:
        /**Tekstura okienka powiadomienia o nowym zadaniu*/
        Texture new_tex;
        /**Sprite okienka powiadomienia o nowym zadaniu*/
        Sprite new_sp;
        /**DŸwiêk powiadomienia o przyjêciu nowego zadania*/
        Sound sound;
        /**Bufor przechowuj¹cy dŸwiêk powiadomienia o przyjêciu nowego zadania*/
        SoundBuffer sb;
        /**Tekst powiadomienia o nowym zadaniu (ustawiany na tytu³ nowego zadania)*/
        Text te;
};

#endif // TAKEN_QUESTS_H
