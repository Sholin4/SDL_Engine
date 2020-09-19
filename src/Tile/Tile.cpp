#include "Tile.h"

Tile::Tile(SDL_Renderer* renderer, SDL_Texture* texture) : Sprite(renderer, texture, 0, 0, TILE_RECT_WIDTH, TILE_RECT_HEIGHT)
{
    //ctor
}

Tile::~Tile()
{
    //dtor
}

bool Tile::estTouche(int curseurX,int curseurY)
{
    //collision Sprite
    if(Sprite::estTouche(curseurX, curseurY))
    {
        return true;
//        if(curseurX+20 > curseurY)
//        {
//            return true;
//        }
    }
    return false;
}

//void Tile::SetTile(Tile* tile, int orientation)
//{
//    m_tile[orientation] = tile;
//}
//
//Tile* Tile::SetTile(int orientation)
//{
//    return  m_tile[orientation];
//}
