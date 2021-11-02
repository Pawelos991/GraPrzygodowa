#ifndef TAKEN_QUESTS_H
#define TAKEN_QUESTS_H

#include "Quest.h"

/**
* Klasa reprezentuje zbiór przyjętych zadań
*/
class Taken_Quests
{
    public:
        /**
        * Konsturktor klasy wczytujący potrzebne dane z plików i ustawiający odpowiednie atrybuty
        */
        Taken_Quests();
        /**
        * Destruktor klasy
        */
        virtual ~Taken_Quests();

    protected:
        /**Wektor wskaźników na przyjęte zadania*/
        std::vector<Quest*> taken_quests;
        /**
        * Funkcja dodająca przyjęte zadanie do wektora wskaźników na przyjęte zadania poprzez skopiowanie go z wektora wskaźników na zadania nieprzyjęte
        * @param id ID zadania które ma zostać dodane do wektora
        * @param not_taken_quests Wektor wskaźników na zadania nieprzyjęte
        */
        void add_t_quest(int id, std::vector<Quest*> &not_taken_quests);
        /**
        * Funkcja usuwająca zadanie o podanym ID z wektora wskaźników na zadania przyjęte
        * @param id ID zadania które ma zostać usunięte
        */
        void remove_t_quest(int id);
        /**
        * Funkcja usuwająca wszystkie zadania z wektora wskaźników na zadania przyjęte
        */
        void remove_all_t_quests();
        /**
        * Funkcja wyświetlająca przyjęte zadania w oknie
        * @param window Okno w którym mają zostać wyświetlone przyjęte zadania
        * @param position Pozycja okienka zadań potrzebna do odpowiedniego umieszczenia tekstów zadań w oknie
        */
        void display_active_quests(RenderWindow &window, Vector2f position);
        /**
        * Funkcja wyświetlająca nowe zadanie w oknie (dokładniej jego tytuł)
        * @param window Okno w którym ma zostać wyświetlone nowe zadanie
        * @param id ID nowego zadania którego tytuł ma zostać wyświetlony
        */
        void display_new_quest(RenderWindow& window, int id);
        /**
        * Funkcja dodająca nowe zadanie do wektora wskaźników na przyjęte zadania wraz z wyświetleniem go w oknie
        * @param window Okno w którym wyświetlony ma zostać tytuł nowego zadania
        * @param id ID zadania które ma zostać dodane do wektora wskaźników zadań przyjętych
        * @param not_taken_quests Wektor wskaźników na nieprzyjęte zadania
        * @param counter Licznik klatek potrzebny do poprawnego wyświetlenia powiadomienia o nowym zadniu w oknie
        */
        void add_t_quest_display(RenderWindow& window, int id, std::vector<Quest*>& not_taken_quests, int counter);
        /**Czcionka tekstu wypisującego przyjęte zadania*/
        Font font;
        /**Tekst służący do wypisania przyjętych zadań*/
        Text text;
        /**
        * Funkcja ładująca czcionkę z pliku i ustawiająca ją w tekście powiadomienia o nowym zadaniu
        */
        void getFont();

    private:
        /**Tekstura okienka powiadomienia o nowym zadaniu*/
        Texture new_tex;
        /**Sprite okienka powiadomienia o nowym zadaniu*/
        Sprite new_sp;
        /**Dźwięk powiadomienia o przyjęciu nowego zadania*/
        Sound sound;
        /**Bufor przechowujący dźwięk powiadomienia o przyjęciu nowego zadania*/
        SoundBuffer sb;
        /**Tekst powiadomienia o nowym zadaniu (ustawiany na tytuł nowego zadania)*/
        Text te;
};

#endif // TAKEN_QUESTS_H
