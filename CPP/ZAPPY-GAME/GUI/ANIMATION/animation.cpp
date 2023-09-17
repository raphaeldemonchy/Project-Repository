/*
** EPITECH PROJECT, 2023
** animation
** File description:
** animation
*/

#include "animation.hpp"

//constructor && destructor
Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;

    totalTime = 0.0f;
    currentImage.x = 0.0f;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

}

Animation::~Animation()
{

}

void Animation::update(int row, float deltaTime)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if(currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

// int main()
// {
//     // Créer la fenêtre
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Animation");

//     // Charger la texture du sprite
//     sf::Texture texture;
//     if (!texture.loadFromFile("assets/tile_map.png"))
//     {
//         // Gestion de l'erreur si le chargement échoue
//         return -1;
//     }

//     // Créer l'objet d'animation
//     Animation animation(&texture, sf::Vector2u(3, 1), 0.5f);

//     // Créer le sprite
//     sf::Sprite sprite;
//     sprite.setTexture(texture);
//     sprite.setScale(1.0f, 1.0f);

//     sf::Clock clock;

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         float deltaTime = clock.restart().asSeconds();
//         animation.update(0, deltaTime); // Changer la valeur du paramètre "row" pour animer différentes lignes du sprite
//         sprite.setTextureRect(animation.uvRect);

//         window.clear();
//         window.draw(sprite);
//         window.display();
//     }

//     return 0;
// }