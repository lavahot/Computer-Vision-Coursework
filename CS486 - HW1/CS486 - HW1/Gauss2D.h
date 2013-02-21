//
//  Gauss2D.h
//  CS486 - HW1
//
//  Created by Taylor Mansfield on 2/17/13.
//  Copyright (c) 2013 Taylor Mansfield. All rights reserved.
//

#ifndef __CS486___HW1__Gauss2D__
#define __CS486___HW1__Gauss2D__

#include <iostream>
#include "Gauss_masks.c"

class Gauss2D {
    int imgH, imgW, sigma, mask, depth;
    int ***H;
    
public:
    inline Gauss2D(int height, int width, int sig, int mas, int dep, int ***IMG)
    {
        imgH=height;
        imgW=width;
        sigma=sig;
        H=IMG;
        mask=mas;
        depth=dep;
    }
    void smooth()
    {
        //create mask
        float GIMG [mask];
        Gauss(sigma, mask, GIMG);
        
        //initialize new matrix to hold smoothed rows
        float FIMG[imgH][imgW];
        for (int i=0;i<imgH; i++) {
            for (int j=0; j<imgW; j++) {
                FIMG[i][j]=0;
            }
        }

        //rows first
        for (int i=0; i<imgH; i++) {
            for (int j = 0; j<imgW; j++) {
                for (int k = 0; k<mask; k++) {
                    FIMG[i][j] += (*H)[i][j-k] * GIMG[k];
                }
            }
        }
        
        float HIMG[imgH][imgW];
        for (int i=0;i<imgH; i++) {
            for (int j=0; j<imgW; j++) {
                HIMG[i][j]=0;
            }
        }
        //columns last
        for (int i=0; i<imgW; i++) {
            for (int j = 0; j<imgH; j++) {
                for (int k = 0; k<mask; k++) {
                    HIMG[j][i] += FIMG[j-k][i] * GIMG[k];
                }
            }            
        }
        
        for (int i=0;i<imgH; i++) {
            for (int j=0; j<imgW; j++) {
                (*H)[i][j]=HIMG[i][j];
            }
        }
        
        

    }
};



#endif /* defined(__CS486___HW1__Gauss2D__) */
