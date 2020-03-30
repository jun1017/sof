template<class ThreadingModel>
Logger& CORBARegistryImpl<ThreadingModel>::logger = LoggerFactory::getLogger( "Remote-Framework" );

template<class ThreadingModel>
void CORBARegistryImpl<ThreadingModel>::addRegistryObserver( CORBARegistryObserver_ptr observer )
{
	// !!! synchronized access !!!
	typename ThreadingModel::Lock lock;

	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#addRegistryObserver] Called." );
	this->objectList.push_back( CORBARegistryObserver::_duplicate( observer ) );
	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#addRegistryObserver] Left." );
}

template<class ThreadingModel>
void CORBARegistryImpl<ThreadingModel>::registerService( const char* bundleName, const char* serviceName, CORBAService_ptr service, const CORBAServiceProps& props )
{
	// !!! synchronized access !!!
	typename ThreadingModel::Lock lock;

	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerService] Entered." );
	list<CORBARegistryObserver_var>::iterator iter;
	for ( iter = this->objectList.begin(); iter != this->objectList.end();)
	{
		logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerService] Forward registering service, bundle name: %1, service name: %2",
			string( bundleName ), string( serviceName) );
		try 
		{			
			(*iter)->registerService( bundleName, serviceName, CORBAService::_duplicate( service ), props );
			++iter;
		} 
		catch( std::exception &exc )
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerService] std::exception occurred: %1", string( exc.what() ) );
			iter = this->objectList.erase( iter );
		}
		catch(CORBA::Exception &cexc)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerService] CORBA::Exception occurred: %1", string( cexc._repoid() ) );
			iter = this->objectList.erase( iter );
		}
		catch(...)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerService] Exception occurred." );
			iter = this->objectList.erase( iter );
		}
	}
	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerService] Left." );
}

template<class ThreadingModel>
void CORBARegistryImpl<ThreadingModel>::registerServiceListener( const char* bundleName, const char* serviceName, CORBAServiceListener_ptr listener )
{
	// !!! synchronized access !!!
	typename ThreadingModel::Lock lock;

	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerServiceListener] Entered." );
	list<CORBARegistryObserver_var>::iterator iter;
	for ( iter = this->objectList.begin(); iter != this->objectList.end();)
	{
		logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerServiceListener] Forward registering service listener, bundle name: %1, service name: %2",
			string( bundleName ), string( serviceName) );
		try
		{
			(*iter)->registerServiceListener( bundleName, serviceName, CORBAServiceListener::_duplicate( listener ) );
			++iter;
		}
		catch( std::exception &exc )
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerServiceListener] std::exception occurred: %1", string( exc.what() ) );
			iter = this->objectList.erase( iter );
		}
		catch(CORBA::Exception &cexc)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerServiceListener] CORBA::Exception occurred: %1", string( cexc._repoid() ) );
			iter = this->objectList.erase( iter );
		}
		catch(...)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#registerServiceListener] Exception occurred." );
			iter = this->objectList.erase( iter );
		}

	}
	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#registerServiceListener] Left." );
}

template<class ThreadingModel>
void CORBARegistryImpl<ThreadingModel>::unregisterService( const char* bundleName, const char* serviceName, CORBAService_ptr service, const CORBAServiceProps& props )
{
	// !!! synchronized access !!!
	typename ThreadingModel::Lock lock;

	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterService] Entered." );
	list<CORBARegistryObserver_var>::iterator iter;
	for ( iter = this->objectList.begin(); iter != this->objectList.end();)
	{
		logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterService] Forward unregistering service, bundle name: %1, service name: %2",
			string( bundleName ), string( serviceName) );
		try
		{
			(*iter)->unregisterService( bundleName, serviceName, service, props );
			++iter;
		}
		catch( std::exception &exc )
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterService] std::exception occurred: %1", string( exc.what() ) );
			iter = this->objectList.erase( iter );
		}
		catch(CORBA::Exception &cexc)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterService] CORBA::Exception occurred: %1", string( cexc._repoid() ) );
			iter = this->objectList.erase( iter );
		}
		catch(...)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterService] Exception occurred." );
			iter = this->objectList.erase( iter );
		}
	}
	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterService] Left." );
}

template<class ThreadingModel>
void CORBARegistryImpl<ThreadingModel>::unregisterServiceListener( const char* bundleName, const char* serviceName, CORBAServiceListener_ptr listener )
{
	// !!! synchronized access !!!
	typename ThreadingModel::Lock lock;

	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterServiceListener] Entered." );
	list<CORBARegistryObserver_var>::iterator iter;
	for ( iter = this->objectList.begin(); iter != this->objectList.end();)
	{
		logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterServiceListener] Forward unregistering service listener, bundle name: %1, service name: %2",
			string( bundleName ), string( serviceName) );
		try
		{
			(*iter)->unregisterServiceListener( bundleName, serviceName, CORBAServiceListener::_duplicate( listener ) );
			++iter;
		}
		catch( std::exception &exc )
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterServiceListener] std::exception occurred: %1", string( exc.what() ) );
			iter = this->objectList.erase( iter );
		}
		catch(CORBA::Exception &cexc)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterServiceListener] CORBA::Exception occurred: %1", string( cexc._repoid() ) );
			iter = this->objectList.erase( iter );
		}
		catch(...)
		{
			logger.log( Logger::LOG_ERROR, "[CORBARegistryImpl#unregisterServiceListener] Exception occurred." );
			iter = this->objectList.erase( iter );
		}
	}
	logger.log( Logger::LOG_DEBUG, "[CORBARegistryImpl#unregisterServiceListener] Left." );
}
