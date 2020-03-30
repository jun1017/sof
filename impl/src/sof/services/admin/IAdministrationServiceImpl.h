#ifndef IADMINISTRATION_SERVICE_IMPL_H
#define IADMINISTRATION_SERVICE_IMPL_H

#include <string>
#include <vector>
#include <map>

#include "IAdministrationService.h"
#include "IAdministrationProvider.h"
#include "ConsoleCommand.h"

#include "../../util/logging/Logger.h"
#include "../../util/logging/LoggerFactory.h"
#include "../../services/admin/IAdministrationProvider.h"

using namespace std;

using namespace sof::util::logging;

namespace sof { namespace services { namespace admin {

/**
 * The <code>IAdministrationServiceImpl</code> class implements
 * the <code>IAdministrationService</code> interface which provides
 * functionality for interacting with the framework.
 */
	class IAdministrationServiceImpl : public IAdministrationService
{
	private:

		/**
		 * The <code>Launcher</code> the calls are forwarded to.
		 */
		IAdministrationProvider* adminProvider;

		/**
		 * The logger instance.
		 */
		static Logger& logger;

		/**
		 * The map which contains all possible console commands.
		 */
		map<string,ConsoleCommand*> cmdMap;		

	public:

		/**
		 * Creates instances of class <code>IAdministrationServiceImpl</code>.
		 *
		 * @param launcher
		 *				The <code>Launcher</code> object.
		 */
		IAdministrationServiceImpl( IAdministrationProvider* provider );

		/**
		 * Starts the administration console.
		 */
		void startConsole();

		/**
		 * Stops the administration console.
		 */
		void stopConsole();

		/**
		 * @see sof::services::admin::IAdministrationService::getBundleNames
		 */
		vector<string> getBundleNames();			
		
		/**
		 * @see sof::services::admin::IAdministrationService::dumpBundleInfo
		 */
		string dumpBundleInfo( const string& bundleName );

		/**
		 * @see sof::services::admin::IAdministrationService::dumpAllBundleNames
		 */
		string dumpAllBundleNames();
		
		/**
		 * @see sof::services::admin::IAdministrationService::stopBundle
		 */
		void stopBundle( const string& bundleName );
		
		/**
		 * @see sof::services::admin::IAdministrationService::stopAllBundles
		 */
		void stopAllBundles();
		
		/**
		 * @see sof::services::admin::IAdministrationService::startBundleFromDLL
		 */
		void startBundleFromDLL( const string& bundleName, const string& className, const string& libPath, const string& libName );
		
		/**
		 * @see sof::services::admin::IAdministrationService::startBundle
		 */
		void startBundle( const string& bundleName, const string& className );
		
		/**
		 * @see sof::services::admin::IAdministrationService::startBundlesFromConfigFile
		 */
		void startBundlesFromConfigFile( const string& configFile );
};

}}}
#endif