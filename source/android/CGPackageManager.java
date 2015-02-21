/*
java implementation of the CGPackageManager extension.

Add android-specific functionality here.

These functions are called via JNI from native code.
*/
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;
import android.content.pm.PackageManager;
import android.util.Log;
// Comment in the following line if you want to use ResourceUtility
// import com.ideaworks3d.marmalade.ResourceUtility;

class CGPackageManager
{
    public String getInstallerPackageName()
    {
        PackageManager pkgMan = LoaderActivity.m_Activity.getPackageManager();
        
        String packageName = LoaderActivity.m_Activity.getPackageName();
        Log.i("CGPackageManager", "Package name: "+ packageName);
        
        String installer = pkgMan.getInstallerPackageName(packageName);
        Log.i("CGPackageManager", "Package installer name: "+ installer);
        
        
        
        return installer;
    }
}
