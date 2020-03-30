#ifndef ISERVICE_REGISTRATION_H
#define ISERVICE_REGISTRATION_H

namespace sof { namespace framework {

/**
 * The <code>IServiceRegistration</code> class defines an
 * interface which enables the deregistration of a service
 * object.<br>
 * If a service object is registered with the framework
 * the register method returns an object of type 
 * <code>IServiceRegistration</code> which can be stored
 * within the bundle implementation. For deregistration
 * of the service object this registration object can be used
 * by calling the <code>unregister</code> method.
 *
 * @author magr74
 */
class IServiceRegistration
{
	public:

		/**
		 * Defines a constant pointer to a <code>IServiceRegistration</code> object.
		 */
		typedef IServiceRegistration* const ConstPtr;

		/**
		 * Deletes the object.
		 */
		virtual ~IServiceRegistration() {};

		/**
		 * Unregisters a service object with the framework.
		 */
		virtual void unregister() = 0;
};

}}

#endif