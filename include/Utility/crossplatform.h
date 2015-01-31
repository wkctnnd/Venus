#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H


#ifdef _WIN32
	#define VENUS_WIN32
	#elif defined _WIN64
		#define VENUS_WIN64
	#elif defined  _APPLE_
		#define VENUS_MAC
#endif
#endif
