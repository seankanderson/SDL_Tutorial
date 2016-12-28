#include "..\include\CApp.h"

bool CApp::OnInit(){

    /* Print current working directory */
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "Current working dir: %s\n", cwd);
    else
       perror("getcwd() error");


    bool success = true;

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }

    Window = SDL_CreateWindow("My Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if (Window == NULL){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }

    /*

        Surface Code

    */


    // Get a reference to the Window surface so that we can copy other surfaces onto it with SDL_BlitSurface
    WindowSurface = SDL_GetWindowSurface(Window);
    if (WindowSurface == NULL) {
        success = false;
    }

    //Only way I know to copy a surface
    OriginalSurface = SDL_ConvertSurface(WindowSurface, WindowSurface->format, NULL);

    /* Load graphic assets */

    KeyPressSurface.push_back(LoadImage(".\\assets\\image.bmp"));
    KeyPressSurface.push_back(LoadImage(".\\assets\\berniehair.jpg"));
    KeyPressSurface.push_back(LoadImage(".\\assets\\freecollege.jpg"));
    KeyPressSurface.push_back(LoadImage(".\\assets\\freeedu.jpg"));
    KeyPressSurface.push_back(LoadImage(".\\assets\\freetree.jpg"));

    /*

        Renderer Code

    */

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    if (Renderer == NULL){
        success = false;
    }else {
        SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);


    }


    return success;
}
