#include "QPackageManager.h"
#include "CGPackageManager.h"

namespace packagemanager {

//-------------------------------------------------
	bool isAvailable()
	{
		return CGPackageManagerAvailable();
	}

//-------------------------------------------------
	const char* getInstallerName()
	{
        const char* installerName = getInstallerPackageName();
        return installerName;
        
	}
    
    

} // namespace packagemanager
