/*
=================
cAsteroid.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cAsteroid.h"

/*
=================================================================
Defualt Constructor
=================================================================
*/
cAsteroid::cAsteroid() : cSprite()
{
	this->asteroidVelocity = { 0.0, 0.0 };
}
/*
=================================================================
Update the sprite position
=================================================================
*/

void cAsteroid::update(double deltaTime)
{

	this->setSpriteRotAngle(this->getSpriteRotAngle() +(50.0f * deltaTime)); 
	if (this->getSpriteRotAngle() > 360)
	{
		this->setSpriteRotAngle(this->getSpriteRotAngle() -360);
	}

	SDL_Rect currentSpritePos = this->getSpritePos();
	currentSpritePos.x += this->getSpriteTranslation().x * deltaTime * 10;
	currentSpritePos.y += this->getSpriteTranslation().y * deltaTime * 10;

	this->setSpritePos({ currentSpritePos.x, currentSpritePos.y });
	cout << "Asteroid position - x: " << this->getSpritePos().x << " y: " << this->getSpritePos().y << " deltaTime: " << deltaTime << endl;
	this->setBoundingRect(this->getSpritePos());

	if (currentSpritePos.x <= 0 || currentSpritePos.x >= (1024 - this->getSpriteDimensions().w))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x * (-1.1), this->getSpriteTranslation().y });
	}

	if (currentSpritePos.y <= 0 || currentSpritePos.y >= (700 - this->getSpriteDimensions().h))
	{
		this->setSpriteTranslation({ this->getSpriteTranslation().x, this->getSpriteTranslation().y * (-1.1) });
	}
}
/*
=================================================================
  Sets the velocity for the Asteroid
=================================================================
*/
void cAsteroid::setAsteroidVelocity(SDL_Point AsteroidVel)
{
	asteroidVelocity = AsteroidVel;
}
/*
=================================================================
  Gets the Asteroid velocity
=================================================================
*/
SDL_Point cAsteroid::getAsteroidVelocity()
{
	return asteroidVelocity;
}
