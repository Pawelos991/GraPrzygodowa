#include "Menu.h"

void Menu::prepareMenu()
{
    counter = 0;
    resolution = Vector2u(1600, 900);
    isFullscreen = false; //To change later
    background_texture.loadFromFile("Textures/Backgrounds/Grass.png");
    menu_background.setTexture(background_texture);
    menu_background.setPosition(Vector2f(0, 0));
    menu_animations.LoadAnimationsFromFile("Data/Menu/Menu_Animations.txt");

    loadMainMenuTextures();
    loadInGameMenuTextures();
    loadArenaMenuTextures();
    loadOptionsMenuTextures();
    loadResolutionMenuTextures();
    loadGameModeMenuTextures();
    loadConfirmMenuTextures();
    loadAdventureMenuTextures();

    musicBuffer.loadFromFile("Sounds/Firelink.wav");
    music.setBuffer(musicBuffer);
    music.setVolume(10);
    isMusicPlaying = true;
    music.play();
}

void Menu::loadMainMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Main.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        main_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadInGameMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/InGame.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        inGame_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadGameModeMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/GameMode.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        gameMode_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadArenaMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Arena.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        arena_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadOptionsMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Options.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        options_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadResolutionMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Resolution.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        resolution_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadConfirmMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Confirm.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        confirm_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

void Menu::loadAdventureMenuTextures()
{
    std::ifstream fp;
    fp.open("Data/Menu/Adventure.txt");
    std::string location;
    int i = 0;
    while (true)
    {
        if (fp.good());
        else
            break;
        fp >> location;
        adventure_menu_textures[i].loadFromFile(location);
        i++;
    }
    fp.close();
}

int Menu::mainMenu(RenderWindow& window,bool finishedTutorial, bool adventureStarted)
{
    int actual_choice = 1; //1 - Play, 2 - Options, 3- Exit
    bool ready=false;
    while (window.isOpen())
    {
        while (!ready)
        {
            counter++;
            if (counter == 61)
            {
                counter = 0;
            }
            window.clear(Color::White);
            window.draw(menu_background);
            menu_sprite.setPosition(Vector2f(557, 177));
            for (int i = 1; i < 4; i++)
            {
                if (actual_choice == i)
                    menu_sprite.setTexture(main_menu_textures[i + 2]);
                else
                    menu_sprite.setTexture(main_menu_textures[i - 1]);

                window.draw(menu_sprite);
                menu_sprite.move(0, 191);
            }
            menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
            menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                    actual_choice--;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 3)
                    actual_choice++;
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                {
                    if (actual_choice == 1)
                    {
                        actual_choice = gameModeMenu(window, finishedTutorial,adventureStarted);
                        if (actual_choice != 0)
                            return actual_choice;
                        else
                            actual_choice = 1;
                    }

                    else if (actual_choice == 2)
                    {
                        optionsMenu(window);
                        actual_choice = 1;
                    }

                    else if (actual_choice == 3)
                    {
                        window.close();
                        return 0;
                    }
                }
            }
            window.display();
        }     
    }
}

int Menu::gameModeMenu(RenderWindow& window, bool finishedTutorial, bool adventureStarted)
{
    int actual_choice = 1; //1 - Tutorial, 2 - New adventure, 3 - Arena, 4 - Go Back
    bool ready = false;
    while (window.isOpen())
    {
        while (!ready)
        {
            counter++;
            if (counter == 61)
            {
                counter = 0;
            }
            window.clear(Color::White);
            window.draw(menu_background);
            menu_sprite.setPosition(Vector2f(557, 93));
            for (int i = 1; i < 5; i++)
            {
                if (actual_choice == i)
                    menu_sprite.setTexture(gameMode_menu_textures[i + 3]);
                else
                {
                    if (i == 2 && finishedTutorial == false)
                        menu_sprite.setTexture(gameMode_menu_textures[8]);
                    else
                        menu_sprite.setTexture(gameMode_menu_textures[i - 1]);
                }

                window.draw(menu_sprite);
                menu_sprite.move(0, 191);
            }
            menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
            menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice == 3 && finishedTutorial == false)
                    actual_choice -= 2;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                    actual_choice--;
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice == 1 && finishedTutorial == false)
                    actual_choice += 2;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 4)
                    actual_choice++;
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                {
                    if (actual_choice == 1)
                        return 1;
                    else if (actual_choice == 2)
                    {
                        actual_choice = adventureMenu(window, adventureStarted);
                        if (actual_choice == 1)
                            return 2;
                        else if (actual_choice == 2)
                            return 3;
                        else
                            actual_choice = 1;
                    }
                    else if (actual_choice == 3)
                    {
                        actual_choice = arenaMenu(window);
                        if (actual_choice != 3)
                        {
                            ready = true;
                            actual_choice += 3;
                        }
                        else
                            actual_choice = 1;
                    }
                    else if (actual_choice == 4)
                    {
                        return 0;
                    }
                }
            }
            window.display();
        }
        return actual_choice;
        
    }

}

void Menu::optionsMenu(RenderWindow& window)
{
    int actual_choice; //1 - Resolution, 2 - Fullscreen, 3 - Music, 4 - Go Back
    if (isFullscreen)
        actual_choice = 2;
    else
        actual_choice = 1;
    bool ready = false;
    while (window.isOpen())
    {
        while (!ready)
        {
            counter++;
            if (counter == 61)
            {
                counter = 0;
            }
            window.clear(Color::White);
            window.draw(menu_background);
            menu_sprite.setPosition(Vector2f(557, 93));
            for (int i = 1; i < 5; i++)
            {
                if (actual_choice == i)
                    menu_sprite.setTexture(options_menu_textures[i + 3]);
                else if(i==1 && isFullscreen==true)
                    menu_sprite.setTexture(options_menu_textures[8]);
                else
                    menu_sprite.setTexture(options_menu_textures[i - 1]);
                

                window.draw(menu_sprite);
                menu_sprite.move(0, 191);
            }
            menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
            menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice == 2 && isFullscreen==false)
                    actual_choice--;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 2)
                    actual_choice--;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 4)
                    actual_choice++;
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                {
                    if (actual_choice == 1)
                    {
                        resolutionMenu(window);
                        actual_choice = 1;
                    }
                    else if (actual_choice == 2)
                    {
                        actual_choice = confirmMenu(window);
                        if (actual_choice == 1 && isFullscreen==false)
                        {
                            isFullscreen = true;
                            window.close();
                            window.create(VideoMode(1600, 900), "Gra przygodowa - Pawel Mika", Style::Fullscreen);
                            window.setFramerateLimit(60);
                            Image img;
                            img.loadFromFile("Textures/Menu/Icon.png");
                            window.setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
                        }
                        else if (actual_choice == 2 && isFullscreen == true)
                        {
                            isFullscreen = false;
                            window.close();
                            window.create(VideoMode(1600, 900), "Gra przygodowa - Pawel Mika");
                            window.setFramerateLimit(60);
                            window.setSize(resolution);
                            window.setPosition(Vector2i(0, 0));
                            Image img;
                            img.loadFromFile("Textures/Menu/Icon.png");
                            window.setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr());
                        }
                        actual_choice = 2;
                    }
                    else if (actual_choice == 3)
                    {
                        actual_choice = confirmMenu(window);
                        if (actual_choice == 1 && isMusicPlaying == false)
                        {
                            isMusicPlaying = true;
                            music.play();
                        }
                        else if (actual_choice == 2 && isMusicPlaying == true)
                        {
                            isMusicPlaying = false;
                            music.stop();
                        }
                        actual_choice = 3;
                    }
                    else if (actual_choice == 4)
                    {
                        return;
                    }
                }
            }
            window.display();
        }
    }
}

int Menu::arenaMenu(RenderWindow& window)
{
    int actual_choice = 1; //1 - Arena(normal), 2 - Arena(Godmode), 3- Go Back
    while (window.isOpen())
    {
        counter++;
        if (counter == 61)
        {
            counter = 0;
        }
        window.clear(Color::White);
        window.draw(menu_background);
        menu_sprite.setPosition(Vector2f(557, 177));
        for (int i = 1; i < 4; i++)
        {
            if (actual_choice == i)
                menu_sprite.setTexture(arena_menu_textures[i + 2]);
            else
                menu_sprite.setTexture(arena_menu_textures[i - 1]);

            window.draw(menu_sprite);
            menu_sprite.move(0, 191);
        }
        menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
        menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                actual_choice--;
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 3)
                actual_choice++;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                return actual_choice;
            }
        }
        window.display();
    }
}

int Menu::inGameMenu(RenderWindow& window)
{
    int actual_choice = 1; //1 - resume, 2 - exit to menu
    while (window.isOpen())
    {
        counter++;
        if (counter == 61)
        {
            counter = 0;
        }
        window.clear(Color::White);
        window.draw(menu_background);
        menu_sprite.setPosition(Vector2f(557, 284));
        for (int i = 1; i < 3; i++)
        {
            if (actual_choice == i)
                menu_sprite.setTexture(inGame_menu_textures[i+1]);
            else
                menu_sprite.setTexture(inGame_menu_textures[i-1]);
            window.draw(menu_sprite);
            menu_sprite.move(0, 191);
        }
        menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
        menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                actual_choice--;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 2)
                actual_choice++;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
                return 1;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                return actual_choice;
            }
        }
        window.display();
    }
}

int Menu::confirmMenu(RenderWindow& window)
{
    int actual_choice = 1; //1 - Yes, 2 - No, 3 - Go Back
    bool ready = false;
    while (window.isOpen())
    {
        counter++;
        if (counter == 61)
        {
            counter = 0;
        }
        window.clear(Color::White);
        window.draw(menu_background);
        menu_sprite.setPosition(Vector2f(557, 177));
        for (int i = 1; i < 4; i++)
        {
            if (actual_choice == i)
                menu_sprite.setTexture(confirm_menu_textures[i + 2]);
            else
                menu_sprite.setTexture(confirm_menu_textures[i - 1]);

            window.draw(menu_sprite);
            menu_sprite.move(0, 191);
        }
        menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
        menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                actual_choice--;
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 3)
                actual_choice++;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                return actual_choice;
            }
        }
        window.display();
    }
}

void Menu::resolutionMenu(RenderWindow& window)
{
    int actual_choice = 1; //1 - 1920x1080, 2 - 1600x900, 3 - 1280x720, 4 - Go Back
    bool ready = false;
    while (window.isOpen())
    {
        while (!ready)
        {
            counter++;
            if (counter == 61)
            {
                counter = 0;
            }
            window.clear(Color::White);
            window.draw(menu_background);
            menu_sprite.setPosition(Vector2f(557, 93));
            for (int i = 1; i < 5; i++)
            {
                if (actual_choice == i)
                    menu_sprite.setTexture(resolution_menu_textures[i + 3]);
                else
                    menu_sprite.setTexture(resolution_menu_textures[i - 1]);

                window.draw(menu_sprite);
                menu_sprite.move(0, 191);
            }
            menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
            menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 1)
                    actual_choice--;
                else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 4)
                    actual_choice++;
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
                {
                    if (actual_choice == 1 && resolution != Vector2u(1920, 1080))
                    {
                        resolution = Vector2u(1920, 1080);
                        window.setSize(resolution);
                    }
                    else if (actual_choice == 2 && resolution != Vector2u(1600, 900))
                    {
                        resolution = Vector2u(1600, 900);
                        window.setSize(resolution);
                    }
                    else if (actual_choice == 3 && resolution != Vector2u(1280, 720))
                    {
                        resolution = Vector2u(1280, 720);
                        window.setSize(resolution);
                    }
                    else if (actual_choice == 4)
                        return;
                }
            }
            window.display();
        }
    }
}

int Menu::adventureMenu(RenderWindow& window, bool adventureStarted)
{
    int actual_choice = 2; //1 - Continue, 2 - New Adventure, 3- Go Back
    if (adventureStarted)
        actual_choice = 1;
    while (window.isOpen())
    {
        counter++;
        if (counter == 61)
        {
            counter = 0;
        }
        window.clear(Color::White);
        window.draw(menu_background);
        menu_sprite.setPosition(Vector2f(557, 177));
        for (int i = 1; i < 4; i++)
        {
            if (actual_choice == i)
                menu_sprite.setTexture(adventure_menu_textures[i + 2]);
            else if(i==1 && adventureStarted==false)
                menu_sprite.setTexture(adventure_menu_textures[6]);
            else
                menu_sprite.setTexture(adventure_menu_textures[i - 1]);

            window.draw(menu_sprite);
            menu_sprite.move(0, 191);
        }
        menu_animations.find_animation(1)->Display_animation(window, Vector2f(50, 125), counter);
        menu_animations.find_animation(2)->Display_animation(window, Vector2f(1000, 50), counter);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice == 2 && adventureStarted==true)
                actual_choice--;
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Up && actual_choice > 2)
                actual_choice--;
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Down && actual_choice < 3)
                actual_choice++;
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
            {
                return actual_choice;
            }
        }
        window.display();
    }
}