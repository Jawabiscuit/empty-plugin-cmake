#include <maya/MFnPlugin.h>
#include <maya/MGlobal.h>


MStatus initializePlugin(MObject pluginObj)
{
	const char* vendor = "Awesome Inc";
	const char* version = "0.1.0";
	const char* requiredApiVersion = "Any";

	MStatus status;
	MFnPlugin pluginFn(pluginObj, vendor, version, requiredApiVersion, &status);
	if (!status)
	{
		MGlobal::displayError("Failed to initialize plugin: " + status.errorString());
		return(status);
	}

	return(MS::kSuccess);
}


MStatus uninitializePlugin(MObject pluginObj)
{
	MStatus status;
	return(status);
}