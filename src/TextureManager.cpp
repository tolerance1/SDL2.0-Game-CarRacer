#include "TextureManager.h"

#include "SDL_image.h"

#include <iostream>
using std::cout;
using std::endl;

//STATIC VAR INIT
TextureManager* TextureManager::pTextureManager = nullptr;

TextureManager* TextureManager::getpTextureManager()
{
    if(pTextureManager == nullptr)
    {
        pTextureManager = new TextureManager();
        return pTextureManager;
    }

    return pTextureManager;
}

TextureManager::TextureManager()
{
    cout << "_TextureManager constructor" << endl;
}

TextureManager::~TextureManager()
{
    cout << "_TextureManager destructor" << endl;
}

//load image, create texture, store the texture
bool TextureManager::createTexture(std::string fileName, std::string textureID,
                                 SDL_Renderer* pRenderer)
{
    //create surface first
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if(pTempSurface == NULL)//check for success
    {
        cout << "IMG_Load: " << IMG_GetError() << endl;
        return false;
    }

    //create a texture next and store it!!!
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    //free temp surface
    SDL_FreeSurface(pTempSurface);

    //add texture into container
    if(pTexture != 0)
    {
        textureUMap[textureID] = pTexture;//map string to texture
        return true;
    }

    //on error
    return false;
}

//retrieve a static texture from u_map and copy it to the renderer
//int destX, int destY - the coordinates for the destination rectangle
void TextureManager::drawStatic(std::string textureID, int destX, int destY,
                                int width, int height,
                                SDL_Renderer* pRenderer,
                                SDL_RendererFlip flip)
{
    SDL_Rect srcRectangle;
    SDL_Rect destRectangle;

    //set dimensions
    srcRectangle.w = destRectangle.w = width;
    srcRectangle.h = destRectangle.h = height;

    //set coordinates
    srcRectangle.x = 0;
    srcRectangle.y = 0;
    destRectangle.x = destX;
    destRectangle.y = destY;

    //copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, textureUMap[textureID],//provide key, get value
                     &srcRectangle, &destRectangle,
                     0, 0, flip);

}

//retrieve an animated texture from u_map and copy it to the renderer
void TextureManager::drawAnimated(std::string textureID, int destX, int destY,
                                  int width, int height,
                                  int currentRow, int currentFrame,
                                  SDL_Renderer* pRenderer,
                                  SDL_RendererFlip flip)
{
    SDL_Rect srcRectangle;
    SDL_Rect destRectangle;

    //set dimensions
    srcRectangle.w = destRectangle.w = width;
    srcRectangle.h = destRectangle.h = height;

    //set coordinates
    srcRectangle.x = width * currentFrame;//select the frame (45 * 0)
    srcRectangle.y = height * currentRow;//select the row (80 * 0)
    destRectangle.x = destX;
    destRectangle.y = destY;

    //copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, textureUMap[textureID],//provide key, get value
                     &srcRectangle, &destRectangle,
                     0, 0, flip);

}

void TextureManager::DestroyTextures()
{
    std::unordered_map<std::string, SDL_Texture*>::iterator umapIterator;

    for(umapIterator = textureUMap.begin();
        umapIterator != textureUMap.end();
        ++umapIterator)
    {
        cout << "SDL_DestroyTexture(" << umapIterator->first << ")" << endl;
        SDL_DestroyTexture(umapIterator->second);//deletes the texture pointed to
    }

}
