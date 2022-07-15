#include <iostream>
#include <fstream>
#include <string>
#include "src/Image.cpp"

using namespace std;

int image_width;
int image_height;

bool init(char* inputName) {
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
    cerr << "\nImage prête!\n";
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Pas assez d'argument!");
        return -1;
    }
    if(!init(argv[1])) {
        return -1;
    }
    if(!draw(argv[2])) {
       return -1;
    }
    /*char* arg2(argv[2]);
    string runImage = "open ";
    runImage += arg2;
    printf("%s ", runImage);*/
    //system(arg2);
    return 0;
}
