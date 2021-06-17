#include "NPC.h"

NPC::NPC(std::string type,Vector2f position)
{
 std::ifstream fp;
    fp.open("Data/NPC_Data.txt");
    std::string Name,animation_location,text_s,font_s,cloud_s;
    int width,height,textsize;
    while(true)
    {
        if(fp.good());
        else
            break;
        fp>>Name;
        fp>>width;
        fp>>height;
        fp>>text_s;
        fp>>font_s;
        fp>>textsize;
        fp>>animation_location;
        fp>>cloud_s;
        if(Name==type)
            break;
    }
    fp.close();

    Replace_withSpace(text_s);

    animations.LoadAnimationsFromFile(animation_location);
    hitbox.setSize(Vector2f(width,height));
    hitbox.setPosition(position);
    cloudTex.loadFromFile(cloud_s);
    Cloud.setTexture(cloudTex);
    Cloud.setPosition(Vector2f(hitbox.getPosition().x-Cloud.getGlobalBounds().width +10,hitbox.getPosition().y-(4*Cloud.getGlobalBounds().height/5)));
    font.loadFromFile(font_s);
    text.setFont(font);
    text.setCharacterSize(textsize);
    text.setFillColor(Color::Black);
    text.setPosition(Vector2f(Cloud.getPosition().x+5,Cloud.getPosition().y+15));
    text.setString(text_s);
    next=nullptr;
}

NPC::~NPC()
{
    //dtor
}

void NPC::Maintance(RenderWindow &window, int counter, RectangleShape players_hitbox)
{
    if(hitbox.getGlobalBounds().intersects(players_hitbox.getGlobalBounds()))
    {
        animations.find_animation(2)->Display_animation(window,hitbox.getPosition(),counter);
        window.draw(Cloud);
        window.draw(text);
    }
    else
        animations.find_animation(1)->Display_animation(window,hitbox.getPosition(),counter);
}
