#include "ObjectField.h"

SpaceObject::SpaceObject(int nx, int ny)
{
	this->pos.x = nx;
	this->pos.y = ny;
}

void SpaceObject::update(void)
{
	this->pos.y += 1;
}

vec2i SpaceObject::getPos(void) const
{
	return this->pos;
}

/* ==================================== */

void ObjectField::setBounds(rect a)
{
	this->field_bounds = a;
}

std::vector<SpaceObject> ObjectField::getData(void) const
{
	return this->object_set;
}

void ObjectField::erase(size_t i)
{
	this->object_set.erase(object_set.begin() + 1);
}

void ObjectField::update(void)
{
	//update existing objects
	for(size_t i = 0; i < object_set.size(); i++)
	{
		if(object_set.at(i).getPos().y > field_bounds.bot())
			object_set.erase(object_set.begin() + i);
		object_set.at(i).update();
	}

	// sqawn a new object
	SpaceObject s(rand() % field_bounds.width(), 0);
	object_set.push_back(s);
}
