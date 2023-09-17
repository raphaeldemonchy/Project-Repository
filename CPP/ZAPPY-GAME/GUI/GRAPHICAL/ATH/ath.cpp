/*
** EPITECH PROJECT, 2023
** ath
** File description:
** ath
*/

#include "ath.hpp"

ATH::ATH() {}
ATH::~ATH() {}

void ATH::refreshInventory(std::string type, std::string uuid, std::string teamName, int level, int posx, int posy, int q0, int q1, int q2, int q3, int q4, int q5, int q6)
{
    _actualINV->refreshObject(type, uuid, teamName, level, posx, posy, q0, q1, q2, q3, q4, q5, q6);

}


void ATH::destroyInventory()
{

}

void ATH::updateScale(float xScale, float yScale)
{
    _actualINV->setScaleSPRITE(xScale, yScale);
    
    _actualINV->setScaleTEXT(xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale,
                            xScale, yScale);


}

void ATH::updatePos(float xPos, float yPos, float centercoeff)
{

    _actualINV->setPosSPRITE(xPos + (505 * centercoeff), yPos + (-140 * centercoeff));

    _actualINV->setPosTEXT(xPos + (520 * centercoeff), yPos + (-335 * centercoeff),  //UUID
                           xPos + (520 * centercoeff), yPos + (-277 * centercoeff),  //TEAM
                           xPos + (561 * centercoeff), yPos + (-234 * centercoeff),  //LEVEL
                           xPos + (440 * centercoeff), yPos + (-190 * centercoeff),  // x
                           xPos + (440 * centercoeff), yPos + (-155 * centercoeff),  // y
                           xPos + (550 * centercoeff), yPos + (-155 * centercoeff),  // q0
                           xPos + (464 * centercoeff), yPos + (-101 * centercoeff),  // q1
                           xPos + (525 * centercoeff), yPos + (-101 * centercoeff),  // q2
                           xPos + (589 * centercoeff), yPos + (-101 * centercoeff),  // q3
                           xPos + (464 * centercoeff), yPos + (-5 * centercoeff),  // q4
                           xPos + (525 * centercoeff), yPos + (-5 * centercoeff),  // q5
                           xPos + (589 * centercoeff), yPos + (-5 * centercoeff));  // q6
        

}

void ATH::displayInventory(sf::RenderWindow *window)
{
    _actualINV->displayINVENTORY(window);
}

