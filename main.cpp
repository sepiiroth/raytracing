#include <iostream>
#include <fstream>
#include <string>
#include "src/Image.cpp"
#include "src/Application.cpp"
#include "src/Scene.cpp"
#include <SDL2/SDL.h>

using namespace std;

int image_width;
int image_height;

bool init(const char* inputName) {
    //Image
    ifstream sceneFile(inputName);
    if (!sceneFile) {
        printf("Scene non existante !");
        return  false;
    }
   sceneFile >> image_width >> image_height;
   return true;
 }

bool draw(const char* outputName) {
    //Render
    //ofstream img(outputName);
    Image im = Image(image_height, image_width);
    //img << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        cerr << "\rLignes de balayage restantes: " << j << ' ' << flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            im(i,j,0) = ir;
            im(i,j,1) = ig;
            im(i,j,2) = ib;
            im(i,j,3) = 255;
            //img << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    im.save(outputName);
    cerr << "\nImage pr�te!\n";
    return true;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Pas assez d'argument!");
        return -1;
    }
    if(!init(argv[1])) {
        return -1;
    }
    cerr << "Test";
    if(!draw(argv[2])) {
       return -1;
    }

    //init("scene.txt");
    cout << "Test";
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        fprintf(stderr, "Impossible d'initialiser SDL: %sn", SDL_GetError());
        exit(1);
    }

    Application app = Application(image_width, image_height);


    app.initSDL();

    Scene s = Scene();
    cout << s.nbLights() << " " << s.objects.size() << endl;

	//atexit(cleanup);

	while (1)
	{
		app.prepareScene();

		app.doInput();

		app.presentScene();

		SDL_Delay(16);
	}


    atexit(SDL_Quit);

    return 0;
}
