#ifndef ISERVICE_REGISTRATION_IMPL_H
#define ISERVICE_REGISTRATION_IMPL_H


#include "../util/logging/LoggerFactory.h"
#include "../util/logging/Logger.h"

#include "IServiceRegistration.h"
#include "IRegistry.h"
#include "ServiceInfo.h"

namespace sof { namespace framework {

using namespace sof::framework;
using namespace sof::util::logging;

/**
 * Represents an implementation of the 
 * sof::framework::IServiceRegistration interface.
 *
 * @author magr74
 */
class IServiceRegistrationImpl : public IServiceRegistration
{
	private:

		/**
		 * The registry object which stores all bundle relevant data.
		 */
		IRegistry& registry;

		/**
		 * The <code>ServiceInfo</code> describing the service which can
		 * be unregistered by this service registration object.
		 */
		ServiceInfoPtr serviceInfo;

		/**
         * The name of the bundle which registered the service object.
		 */
		string bundleName;

		/**
		 * The logger instance.
		 */
		static Logger& logger;

	public:

		/**
		 * Creates instances of class <code>IServiceRegistrationImpl</code>.
		 *
		 * @param bundleName
		 *				The name of the bundle.
		 *
		 * @param reg
		 *				The framework registry which holds all bundle relevant data.
		 *
		 * @param serviceInfo
		 *				The service info object.
		 */
		IServiceRegistrationImpl( const string& bundleName, IRegistry& reg, ServiceInfoPtr serviceInfo );

		/**
		 * Deletes the object.
		 */
		~IServiceRegistrationImpl();

		/**
		 * Unregisters the service object with the framework.
		 */
		virtual void unregister();
};

}}
#endif