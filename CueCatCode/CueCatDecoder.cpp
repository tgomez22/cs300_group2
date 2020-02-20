
//Edited by Kristin Bell for use with ChocAn System
/*
 * CueCat Decoder
 *
 * Thanks to:
 *   - http://oilcan.org/cuecat/base64.html
 *   - LibraryThing for shipping my CueCat
 *
 * Copyright (c) 2009 Ricardo Martins <ricardo@scarybox.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "CueCatDecoder.h"

#define CC_BUF_SIZE 1024
#define CC_XOR 'C'

/*
 * Returns just the barcode data, ignoring the CueCat's serial number and the
 * type of the barcode
 */
static char *cuecat::getData(const char *input)
{
	int nSeen;
	char *data;
	const char *pos = NULL;

	for (nSeen = 0; *input != '\0'; input++) {
		if (*input == '.') {
			nSeen++;
			if (nSeen == 3)
				pos = input + 1;
		}
	}

	assert(pos != NULL);

	size_t size = input - pos - 1;

	data = (char *)calloc(size+1, sizeof(char));
	
	strncpy(data, pos, size);

	return data;
}

/* Decodes the data encrypted by the CueCat */
static char *cuecat::decode(char *in)
{
	int i, j;
	size_t length = strlen(in) % 4;
        char * decoded;

        decoded = (char *)calloc(100, sizeof(char));	

	if (length != 0)
		length = 4 - length;

	for (i = 0; i < strlen(in); i++) {
		for (j = 0; in[i] != cuecat::sequence[j]; j++);
		in[i] = j;
	}

	for (i = 0, j = 0; i < strlen(in); i += 4) {
		int tmp = ((in[i] << 6 | in[i+1]) << 6 | in[i+2]) << 6 | in[i+3];
		decoded[j++] = (tmp >> 16) ^ CC_XOR;
		decoded[j++] = (tmp >> 8 & 255) ^ CC_XOR;
		decoded[j++] = (tmp & 255) ^ CC_XOR; // in[i+3]^XOR
	}

	memset(decoded+strlen(decoded) - length, 0, length);

	return decoded;
}
/*
int main(void)
{
	char *input, *data, *decoded;
        input = (char *)calloc(255, sizeof(char));


	scanf("%254s", input);

	data = getData(input);
	decoded = decode(data);
	printf("%s\n", decoded);

	free(input);
	free(data);
	free(decoded);

	return 0;
}
*/
// vim: et ts=4 sw=4 sts=4
