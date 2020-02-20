#ifndef __CUECAT_H
#define __CUECAT_H

namespace cuecat {
	const char *sequence = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-";
	const char *base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	static char *getData(const char *input);
	static char *decode(char *in);
}

#endif
