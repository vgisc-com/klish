/** @file ktp.h
 *
 * @brief Klish Transfer Protocol
 */

#ifndef _klish_ktp_h
#define _klish_ktp_h

#include <faux/msg.h>

typedef enum {
	KTP_NULL = '\0',
	KTP_STDIN = 'i',
	KTP_STDOUT = 'o',
	KTP_STDERR = 'e',
	KTP_CMD = 'c',
	KTP_CMD_ACK = 'C',
	KTP_COMPLETION = 'v',
	KTP_COMPLETION_ACK = 'V',
	KTP_HELP = 'h',
	KTP_HELP_ACK = 'H',
	KTP_ALERT = 'a',
	KTP_EXIT = 'x',
} ktp_cmd_e;


C_DECL_BEGIN

int ktp_connect(const char *sun_path);
void ktp_disconnect(int fd);
int ktp_accept(int listen_sock);

C_DECL_END

#endif // _klish_ktp_h
