/*
 *  RSGIS2DInterpolation.h
 *  RSGIS_LIB
 *
 *  Created by Pete Bunting on 14/09/2013.
 *
 *  Copyright 2013 RSGISLib.
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

#ifndef RSGIS2DInterpolation_H
#define RSGIS2DInterpolation_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "RSGISMathsUtils.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Interpolation_traits_2.h>
#include <CGAL/natural_neighbor_coordinates_2.h>
#include <CGAL/interpolation_functions.h>
#include <CGAL/algorithm.h>
#include <CGAL/Origin.h>
#include <CGAL/squared_distance_2.h>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::FT                                         CGALCoordType;
typedef K::Vector_2                                   CGALVector;
typedef K::Point_2                                    CGALPoint;

typedef CGAL::Delaunay_triangulation_2<K>             DelaunayTriangulation;
typedef CGAL::Interpolation_traits_2<K>               InterpTraits;
typedef CGAL::Delaunay_triangulation_2<K>::Vertex_handle    Vertex_handle;

typedef std::vector< std::pair<CGALPoint, CGALCoordType> >   CoordinateVector;
typedef std::map<CGALPoint, CGALCoordType, K::Less_xy_2>     PointValueMap;

namespace rsgis {namespace math{
    
    class RSGISInterpolationException : public RSGISMathException
    {
    public:
        RSGISInterpolationException():RSGISMathException("A RSGISInterpolationException has been created.."){};
        RSGISInterpolationException(const char* message):RSGISMathException(message){};
        RSGISInterpolationException(std::string message):RSGISMathException(message){};
    };
    
    struct RSGISInterpolatorDataPoint
    {
        RSGISInterpolatorDataPoint(double _x, double _y, double _value)
        {
            this->x = _x;
            this->y = _y;
            this->value = _value;
        };
        double x;
        double y;
        double value;
    };
    
    class RSGIS2DInterpolator
	{
	public:
		RSGIS2DInterpolator(){};
		virtual void initInterpolator(std::vector<RSGISInterpolatorDataPoint> *pts) throw(RSGISInterpolationException) = 0;
		virtual double getValue(double eastings, double northings) throw(RSGISInterpolationException) = 0;
		virtual ~RSGIS2DInterpolator(){};
	protected:
		bool initialised;
	};
    
    class RSGISSearchKNN2DInterpolator: public RSGIS2DInterpolator
	{
	public:
		RSGISSearchKNN2DInterpolator(unsigned int k);
		virtual void initInterpolator(std::vector<RSGISInterpolatorDataPoint> *pts) throw(RSGISInterpolationException);
        virtual double getValue(double eastings, double northings) throw(RSGISInterpolationException) = 0;
		virtual ~RSGISSearchKNN2DInterpolator(){};
	protected:
        virtual std::list<std::pair<double,RSGISInterpolatorDataPoint> >* findKNN(double eastings, double northings) throw(RSGISInterpolationException);
		unsigned int k;
        std::vector<RSGISInterpolatorDataPoint> *dataPTS;
	};
    
    class RSGIS2DTriagulatorInterpolator: public RSGIS2DInterpolator
	{
	public:
		RSGIS2DTriagulatorInterpolator():RSGIS2DInterpolator(){};
		virtual void initInterpolator(std::vector<RSGISInterpolatorDataPoint> *pts) throw(RSGISInterpolationException);
		virtual double getValue(double eastings, double northings) throw(RSGISInterpolationException) = 0;
		virtual ~RSGIS2DTriagulatorInterpolator(){};
	protected:
		DelaunayTriangulation *dt;
        PointValueMap *values;
	};
    
	class RSGISNearestNeighbour2DInterpolator : public RSGIS2DTriagulatorInterpolator
	{
	public:
		RSGISNearestNeighbour2DInterpolator():RSGIS2DTriagulatorInterpolator(){};
		double getValue(double eastings, double northings) throw(RSGISInterpolationException);
		~RSGISNearestNeighbour2DInterpolator(){};
	};
    
    class RSGISNaturalNeighbor2DInterpolator :public RSGIS2DTriagulatorInterpolator
	{
	public:
		RSGISNaturalNeighbor2DInterpolator():RSGIS2DTriagulatorInterpolator(){};
		double getValue(double eastings, double northings) throw(RSGISInterpolationException);
		~RSGISNaturalNeighbor2DInterpolator(){};
	};
    
    class RSGISNaturalNearestNeighbor2DInterpolator :public RSGIS2DTriagulatorInterpolator
	{
	public:
		RSGISNaturalNearestNeighbor2DInterpolator():RSGIS2DTriagulatorInterpolator(){};
		double getValue(double eastings, double northings) throw(RSGISInterpolationException);
		~RSGISNaturalNearestNeighbor2DInterpolator(){};
	};
    
    
    class RSGISKNearestNeighbour2DInterpolator : public RSGISSearchKNN2DInterpolator
	{
	public:
		RSGISKNearestNeighbour2DInterpolator(unsigned int k):RSGISSearchKNN2DInterpolator(k){};
		double getValue(double eastings, double northings) throw(RSGISInterpolationException);
		~RSGISKNearestNeighbour2DInterpolator(){};
	};
    

}}

#endif
