#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

int main(int argc,char* argv[]){
    int img_flag = IMG_INIT_JPG|IMG_INIT_PNG;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *img_texture = NULL;
    SDL_Texture *text1_texture = NULL;
    SDL_Texture *text2_texture = NULL;
    SDL_Surface *surface = NULL;
    TTF_Font *font = NULL;
    SDL_Rect img_rect = {0,0,300,300};
    SDL_Rect text1_rect = {0,300,0,0};
    SDL_Rect text2_rect = {0,0,0,0};
    
    //初期化
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) return -1;
    if(IMG_Init(img_flag)&(img_flag) != img_flag) return -1;
    if(TTF_Init() != 0) return -1;
    window = SDL_CreateWindow("画像と文字の表示テスト\0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    //各種ファイル読み込み
    surface = IMG_Load("image.png");
    if(surface == NULL) return -1;
    img_texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    font = TTF_OpenFont("migu-1p-regular.ttf",32);
    if(font == NULL) return -1;
    surface = TTF_RenderUTF8_Blended(font,"Font Draw Test",{255,255,255});
    text1_texture = SDL_CreateTextureFromSurface(renderer,surface);
    text1_rect.w = surface->w; text1_rect.h = surface->h;
    SDL_FreeSurface(surface);
    surface = TTF_RenderUTF8_Blended(font,"日本語も表示可能\0",{255,255,255});
    text2_texture = SDL_CreateTextureFromSurface(renderer,surface);
    text2_rect.y = text1_rect.y + text1_rect.h;
    text2_rect.w = surface->w; text2_rect.h = surface->h;
    SDL_FreeSurface(surface);

    //メインループ
    while(1){
        SDL_Event e;
        if(SDL_PollEvent(&e) && e.type == SDL_QUIT) break;
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img_texture, NULL, &img_rect);
        SDL_RenderCopy(renderer, text1_texture, NULL, &text1_rect);
        SDL_RenderCopy(renderer, text2_texture, NULL, &text2_rect);
        SDL_RenderPresent(renderer);
    }

    //終了処理
    SDL_DestroyTexture(img_texture);
    SDL_DestroyTexture(text1_texture);
    SDL_DestroyTexture(text2_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}