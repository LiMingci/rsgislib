/*
 *  RSGISMorphologyFindExtrema.h
 *  RSGIS_LIB
 *
 *  Created by Peter Bunting on 01/03/2012
 *  Copyright 2012 RSGISLib.
 * 
 *  RSGISLib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  RSGISLib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RSGISLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef RSGISMorphologyFindExtrema_H
#define RSGISMorphologyFindExtrema_H

#include <iostream>
#include <string>
#include "gdal_priv.h"

#include "img/RSGISImageBandException.h"
#include "img/RSGISCalcImage.h"
#include "img/RSGISCalcImageValue.h"

#include "math/RSGISMatrices.h"

namespace rsgis{namespace filter{
    
    class RSGISImageMorphologyFindExtrema
    {
    public:
        enum RSGISMinimaOutputs
        {
            binary,
            sequential
        };
        RSGISImageMorphologyFindExtrema();
        void findMinima(GDALDataset **datasets, std::string outputImage, rsgis::math::Matrix *matrixOperator, RSGISMinimaOutputs outputType, bool allowEquals, std::string format, GDALDataType outDataType) throw(rsgis::img::RSGISImageCalcException, rsgis::img::RSGISImageBandException);
        void findMinimaAll(GDALDataset **datasets, std::string outputImage, rsgis::math::Matrix *matrixOperator, RSGISMinimaOutputs outputType, bool allowEquals, std::string format, GDALDataType outDataType) throw(rsgis::img::RSGISImageCalcException, rsgis::img::RSGISImageBandException);
        ~RSGISImageMorphologyFindExtrema(){};
    };
    
    class RSGISMorphologyFindLocalMinima : public rsgis::img::RSGISCalcImageValue
    {
    public: 
        RSGISMorphologyFindLocalMinima(int numberOutBands, rsgis::math::Matrix *matrixOperator, RSGISImageMorphologyFindExtrema::RSGISMinimaOutputs outputType, bool allowEquals); 			
        virtual rsgis::img::RSGISCalcImage* getCalcImage()throw(RSGISImageException){return new rsgis::img::RSGISCalcImage(this, "", true);};
        void calcImageValue(float *bandValues, int numBands, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float *bandValues, int numBands) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals, geos::geom::Envelope extent)throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(float *bandValues, int numBands, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float *bandValues, int numBands, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException);
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        ~RSGISMorphologyFindLocalMinima();
    private:
        rsgis::math::Matrix *matrixOperator;
        RSGISImageMorphologyFindExtrema::RSGISMinimaOutputs outputType;
        bool allowEquals;
        unsigned long *outVal;
    };
    
    class RSGISMorphologyFindLocalMinimaAll : public rsgis::img::RSGISCalcImageValue
    {
    public: 
        RSGISMorphologyFindLocalMinimaAll(int numberOutBands, rsgis::math::Matrix *matrixOperator, RSGISImageMorphologyFindExtrema::RSGISMinimaOutputs outputType, bool allowEquals); 			
        virtual rsgis::img::RSGISCalcImage* getCalcImage()throw(RSGISImageException){return new rsgis::img::RSGISCalcImage(this, "", true);};
        void calcImageValue(float *bandValues, int numBands, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float *bandValues, int numBands) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(long *intBandValues, unsigned int numIntVals, float *floatBandValues, unsigned int numfloatVals, geos::geom::Envelope extent)throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        void calcImageValue(float *bandValues, int numBands, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float *bandValues, int numBands, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException);
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, geos::geom::Envelope extent) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not implemented");};
        bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(rsgis::img::RSGISImageCalcException){throw rsgis::img::RSGISImageCalcException("Not Implemented.");};
        ~RSGISMorphologyFindLocalMinimaAll();
    private:
        rsgis::math::Matrix *matrixOperator;
        RSGISImageMorphologyFindExtrema::RSGISMinimaOutputs outputType;
        bool allowEquals;
        unsigned long outVal;
    };
    
}}

#endif
