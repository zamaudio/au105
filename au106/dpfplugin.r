#include <AudioUnit/AudioUnit.r>

#include "dpfpluginVersion.h"

// Note that resource IDs must be spaced 2 apart for the 'STR ' name and description
#define kAudioUnitResID_dpfplugin				1000

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ dpfplugin~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#define RES_ID			kAudioUnitResID_dpfplugin
#define COMP_TYPE		kAudioUnitType_Effect
#define COMP_SUBTYPE	dpfplugin_COMP_SUBTYPE
#define COMP_MANUF		dpfplugin_COMP_MANF	

#define VERSION			kdpfplugVersion
#define NAME			"__MyCompanyName__: dpfplugin"
#define DESCRIPTION		"dpfplugin AU"
#define ENTRY_POINT		"dpfplugEntry"

#include "AUResources.r"
