#ifndef OBJECTS_ENGINE_H
#define OBJECTS_ENGINE_H

struct object {
	struct pos position; 	
	uint8_t id;	/*| Not necessary to be OBJECT_ID, only if the object is uniq |*/
};

uint8_t object_init(struct object *object);
void object_control(struct object *object, struct creature *player, struct location *location);

#endif
