//
//  main.cpp
//  CS486 - HW1
//
//  Created by Taylor Mansfield on 2/16/13.
//  Copyright (c) 2013 Taylor Mansfield. All rights reserved.
//

#include <iostream>
//#include "ReadImage.cpp"
//#include "WriteImage.cpp"
#include "Gauss2D.h"
#include "Image.h"

using namespace std;

int main()
{
    char filename[30];
    int Width = 0;
    int Height = 0;
    int Depth = 0;
    float Sigma = 0;
    int Mask = 0;
    int **image;//pointer to array
    
    cout<<"Please enter the filename of the image: ";
    
    cin>>filename;
    
    ReadImage(filename, &image, Width, Height, Depth);
    
    do{
    cout<<"Set an odd mask size: ";
    
    cin>>Mask;
    
    if (Mask%2==0 || Mask>Width || Mask>Height) {
        cout<<"Sorry, that is an even size or bigger than one of the image dimensions."<<endl
            <<"Please try again."<<endl;
    }
    }while ((Mask%2==0 || Mask>Width || Mask>Height));
    
    cout<<"Set sigma for smoothing: ";
    
    cin>>Sigma;
    
    Gauss2D *Gaussian = new Gauss2D(Height, Width, Sigma, Mask, Depth, &image);
    
    Gaussian->smooth();
    
    WriteImage("result.pgm", image, Width, Height, Depth);
    
    cout<<"/nSmoothing completed.";
    
    
    return 0;
}

