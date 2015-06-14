# CGPackageManager
Built with Marmalade 7.8 and NDK 10d.

Returns package installer.

1. Add extension to project mkb.

2. Reload the project.

3. Add reference: CGPackageManager.h

4. Call only method: getInstallerPackageName()

Notes:
1. Apparently it only works with apps installed with a recent version of Amazon App store or Google Play store.
2. All other stores and older amazon app store versions will return null.
3. Sample app provided called: CGPackageManagerTestApp

