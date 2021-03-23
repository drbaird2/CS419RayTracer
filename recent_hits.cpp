

#include "constants.h"
#include "recent_hits.h"

recent_hits::recent_hits(Scene& wr)
	: 	colided(false),
		material_ptr(NULL),
		colidePoint(),
		colideNormal(),
		ra(),
		t(0.0),
		col(black),
		sceneRef(wr)

{}


recent_hits::recent_hits(const recent_hits& record)
	: 	colided(record.colided),
		material_ptr(record.material_ptr),
		colidePoint(record.colidePoint),
		colideNormal(record.colideNormal),
		ra(record.ra),
		t(record.t),
		col(record.col),
		sceneRef(record.sceneRef)
{}


		
		
						
		
