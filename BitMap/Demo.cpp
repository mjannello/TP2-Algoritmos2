#include "EasyBMP.h"
#include <iostream>

using namespace std;


int main()
{
    BMP AnImage;
    // Set size to 640 × 480
    AnImage.SetSize(640, 480);
    // Set its color depth to 8-bits
    AnImage.SetBitDepth(8);


    RGBApixel NewColor;

    NewColor.Red = 255;
    NewColor.Green = 250;
    NewColor.Blue = 100;
    NewColor.Alpha = 100;
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            AnImage.SetPixel(14 + i, 18 + j, NewColor);
        }
    }
    AnImage.SetPixel(14, 18, NewColor);
    //Write to file
    AnImage.WriteToFile("Imagen.bmp");
    // Declare another BMP image
    //BMP AnotherImage;
    // Read from a file
    //AnotherImage.ReadFromFile("sample.bmp");
}