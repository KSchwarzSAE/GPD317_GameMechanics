#pragma once


enum EntityFlags
{

	// Keine Flags.
	NONE			= 0,
	// Fuer die Entity werden Kollisionspruefungen gemacht.
	CAN_COLLIDE		= 1, // 0001
	// Gibt ab, dass die Update Methode aufgerufen werden soll.
	SHOULD_UPDATE	= 2  // 0010

};