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
    cout << " 2 C TextureManager" << endl;
}

TextureManager::~TextureManager()
{
    cout << " 2 D TextureManager" << endl;

    //release the textures
    while(! textureUMap.empty())
    {
        cout << "SDL_DestroyTexture(" << textureUMap.begin()->first << ")" << endl;
        SDL_DestroyTexture(textureUMap.begin()->second);//deletes the texture pointed to
        textureUMap.erase(textureUMap.begin());
    }
}

//load image, create texture, store the texture
bool TextureManager::createTexture(std::string fileName, std::string textureID,
                                   SDL_Renderer* pRenderer)
{
    //create surface first
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if(pTempSurface == NULL)//check for success
    {
        cout << "IMG_Load(): " << IMG_GetError() << endl;
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

//retrieve a texture from u_map and copy it to the renderer
//int destX, int destY - the coordinates for the destination rectangle
void TextureManager::drawTexture(std::string textureID, int destX, int destY,
                                 int width, int height,
                                 int currentRow, int currentFrame,
                                 SDL_Renderer* pRenderer,
                                 double rotationAngle,
                                 SDL_RendererFlip flip)
{
    SDL_Rect srcRectangle;
    SDL_Rect destRectangle;

    //set dimensions
    srcRectangle.w = destRectangle.w = width;
    srcRectangle.h = destRectangle.h = height;

    //set coordinates
    srcRectangle.x = width * currentFrame;//select the frame (80 * 0)
    srcRectangle.y = height * currentRow;//select the row (45 * 0)
    destRectangle.x = destX;
    destRectangle.y = destY;

    //copy the texture to the renderer
    SDL_RenderCopyEx(pRenderer, textureUMap[textureID],//provide key, get value
                     &srcRectangle, &destRectangle,
                     rotationAngle, 0, flip);

}

void TextureManager::destroyTexture(std::string textureID)
{
    SDL_DestroyTexture(textureUMap[textureID]);
    textureUMap.erase(textureID);
}
