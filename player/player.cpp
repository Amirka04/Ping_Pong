#include "player.h"

player::player(){
}

player::player(Vector Coordinate, Vector Size, Vector Speed): GameObject(Coordinate, Size, Speed){

}

player::player(Vector Coordinate, Vector Size): GameObject(Coordinate, Size){

}

player::player(GameObject u_gm): GameObject(u_gm){

}

