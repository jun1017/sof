#ifndef STOP_ALL_BUNDLES_CMD_H
#define STOP_ALL_BUNDLES_CMD_H

#include <string>
#include <vector>

#include "ConsoleCommand.h"

namespace sof { namespace services { namespace admin {

using namespace std;

using namespace sof::services::admin;

/**
 * The <code>StopAllBundlesCmd<code> represents a console command
 * which stops all bundles.<br>
 * Example:<br>
 * <code>spab</code>
 *
 * @author magr74
 */
class StopAllBundlesCmd : public ConsoleCommand
{
	public:

		/**
		 * Creates instances of class </code>StopAllBundlesCmd</code>.
		 */
		StopAllBundlesCmd();

		/**
		 * @see sof::services::admin::ConsoleCommand::getName
		 */
		string getName();

		/**
		 * @see sof::services::admin::ConsoleCommand::getDescription
		 */
		string getDescription();

		/**
		 * @see sof::services::admin::ConsoleCommand::getParameterNum
		 */
		int getParameterNum();

		/**
		 * @see sof::services::admin::ConsoleCommand::execute
		 */
		string execute( IAdministrationService* const adminService, vector<string> params );
};

}}}

#endif