/*
 *  RSGISCountValsAboveThresInCol.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 13/12/2010.
 *  Copyright 2010 RSGISLib. All rights reserved.
 *
 * This file is part of RSGISLib.
 * 
 * RSGISLib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RSGISLib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RSGISLib.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef RSGISCountValsAboveThresInCol_H
#define RSGISCountValsAboveThresInCol_H

#include <iostream>
#include <string>
#include <math.h>

#include "gdal_priv.h"

#include "img/RSGISImageCalcException.h"
#include "img/RSGISCalcImageValue.h"

namespace rsgis{namespace img{
	
	class RSGISCountValsAboveThresInCol : public RSGISCalcImageValue
	{
	public: 
		RSGISCountValsAboveThresInCol(int numberOutBands, float upper, float lower);
		void calcImageValue(float *bandValues, int numBands, float *output) throw(RSGISImageCalcException);
		void calcImageValue(float *bandValues, int numBands) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands, geos::geom::Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		void calcImageValue(float *bandValues, int numBands, float *output, geos::geom::Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
        void calcImageValue(float ***dataBlock, int numBands, int winSize, float *output, geos::geom::Envelope extent) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		bool calcImageValueCondition(float ***dataBlock, int numBands, int winSize, float *output) throw(RSGISImageCalcException){throw RSGISImageCalcException("No implemented");};
		~RSGISCountValsAboveThresInCol();
	private:
		float upper;
		float lower;
	};
	
}}

#endif

