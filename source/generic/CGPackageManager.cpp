/*
Generic implementation of the CGPackageManager extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "CGPackageManager_internal.h"
s3eResult CGPackageManagerInit()
{
    //Add any generic initialisation code here
    return CGPackageManagerInit_platform();
}

void CGPackageManagerTerminate()
{
    //Add any generic termination code here
    CGPackageManagerTerminate_platform();
}

const char* getInstallerPackageName()
{
	return getInstallerPackageName_platform();
}
