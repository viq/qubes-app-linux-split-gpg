#ifndef _GPG_H
#define _GPG_H

#include <stdint.h>
#include <getopt.h>

#define COMMAND_MAX_LEN 1024

struct command_hdr {
	uint32_t len;
	char command[COMMAND_MAX_LEN];
};

#define MAX_FDS 16
#define MAX_FD_VALUE 1024

enum {
	opt_always_trust = 257,
	opt_attribute_fd,
	opt_batch,
	opt_cert_digest_algo,
	opt_charset,
	opt_cipher_algo,
	opt_clearsign,
	opt_command_fd,
	opt_comment,
	opt_compress_algo,
	opt_digest_algo,
	opt_disable_cipher_algo,
	opt_disable_mdc,
	opt_disable_pubkey_algo,
	opt_display_charset,
	opt_emit_version,
	opt_encrypt,
	opt_encrypt_to,
	opt_fingerprint,
	opt_fixed_list_mode,
	opt_force_mdc,
	opt_force_v3_sigs,
	opt_force_v4_certs,
	opt_gnupg,
	opt_list_config,
	opt_list_only,
	opt_list_sigs,
	opt_logger_fd,
	opt_max_output,
	opt_no_comments,
	opt_no_emit_version,
	opt_no_force_v3_sigs,
	opt_no_force_v4_certs,
	opt_no_tty,
	opt_openpgp,
	opt_passphrase_fd,
	opt_personal_cipher_preferences,
	opt_personal_compress_preferences,
	opt_personal_digest_preferences,
	opt_pgp2,
	opt_pgp6,
	opt_pgp7,
	opt_pgp8,
	opt_rfc1991,
	opt_rfc2440,
	opt_rfc4880,
	opt_s2k_cipher_algo,
	opt_s2k_count,
	opt_s2k_digest_algo,
	opt_s2k_mode,
	opt_status_fd,
	opt_store,
	opt_trust_model,
	opt_use_agent,
	opt_verify,
	opt_version,
	opt_with_fingerprint,
	opt_with_keygrip
};

int parse_options(int argc, char *argv[], int *input_fds,
		  int *input_fds_count, int *output_fds,
		  int *output_fds_count, int is_client);
int prepare_pipes_and_run(const char *run_file, char **run_argv, int *input_fds,
			  int input_fds_count, int *output_fds,
			  int output_fds_count);

static const int gpg_allowed_options[] = {
	'b',
	'a',
	'c',
	'd',
	'e',
	'k',
	'K',
	'n',
	'q',
	'r',
	's',
	't',
	'u',
	opt_always_trust,
	opt_batch,
	opt_charset,
	opt_clearsign,
	opt_comment,
	opt_digest_algo,
	opt_disable_mdc,
	opt_display_charset,
	opt_emit_version,
	opt_encrypt,
	opt_encrypt_to,
	opt_encrypt_to,
	opt_fingerprint,
	opt_fixed_list_mode,
	opt_force_mdc,
	opt_force_v3_sigs,
	opt_force_v4_certs,
	opt_gnupg,
	opt_list_config,
	opt_list_only,
	opt_list_sigs,
	opt_max_output,
	opt_no_comments,
	opt_no_comments,
	opt_no_emit_version,
	opt_no_force_v3_sigs,
	opt_no_force_v4_certs,
	opt_no_tty,
	opt_no_verbose,
	opt_openpgp,
	opt_personal_cipher_preferences,
	opt_personal_compress_preferences,
	opt_personal_digest_preferences,
	opt_pgp2,
	opt_pgp6,
	opt_pgp7,
	opt_pgp8,
	opt_rfc1991,
	opt_rfc2440,
	opt_rfc4880,
	opt_s2k_cipher_algo,
	opt_s2k_count,
	opt_s2k_digest_algo,
	opt_s2k_mode,
	opt_status_fd,
	opt_store,
	opt_trust_model,
	opt_use_agent,
	opt_verify,
	opt_version,
	opt_with_fingerprint,
	opt_with_keygrip,
	0
};

static const char gpg_short_options[] = "bacdekKnr:stu:";

static const struct option gpg_long_options[] = {
	{"always-trust", 0, 0, opt_always_trust},
	{"armor", 0, 0, 'a'},
	{"batch", 0, 0, opt_batch},
	{"cert-digest-algo", 1, 0, opt_cert_digest_algo},
	{"charset", 1, 0, opt_charset},
	{"cipher-algo", 1, 0, opt_cipher_algo},
	{"clearsign", 0, 0, opt_clearsign},
	{"comment", 1, 0, opt_comment},
	{"compress-algo", 1, 0, opt_compress_algo},
	{"decrypt", 0, 0, 'd'},
	{"detach-sign", 0, 0, 'b'},
	{"digest-algo", 1, 0, opt_digest_algo},
	{"disable-cipher-algo", 1, 0, opt_disable_cipher_algo},
	{"disable-mdc", 0, 0, opt_disable_mdc},
	{"disable-pubkey-algo", 1, 0, opt_disable_pubkey_algo},
	{"display-charset", 1, 0, opt_display_charset},
	{"dry-run", 0, 0, 'n'},
	{"emit-version", 0, 0, opt_emit_version},
	{"encrypt", 0, 0, 'e'},
	{"encrypt", 0, 0, opt_encrypt},
	{"encrypt-to", 1, 0, opt_encrypt_to},
	{"fingerprint", 0, 0, opt_fingerprint},
	{"fixed-list-mode", 0, 0, opt_fixed_list_mode},
	{"fixed-list-mode", 0, 0, opt_fixed_list_mode},
	{"force-mdc", 0, 0, opt_force_mdc},
	{"force-v3-sigs", 0, 0, opt_force_v3_sigs},
	{"force-v4-certs", 0, 0, opt_force_v4_certs},
	{"gnupg", 0, 0, opt_gnupg},
	{"list-config", 0, 0, opt_list_config},
	{"list-keys", 2, 0, 'k'},
	{"list-only", 0, 0, opt_list_only},
	{"list-public-keys", 2, 0, 'k'},
	{"list-secret-keys", 2, 0, 'K'},
	{"list-sigs", 2, 0, opt_list_sigs},
	{"local-user", 1, 0, 'u'},
	{"max-output", 1, 0, opt_max_output},
	{"no-comments", 0, 0, opt_no_comments},
	{"no-comments", 0, 0, opt_no_comments},
	{"no-emit-version", 0, 0, opt_no_emit_version},
	{"no-force-v3-sigs", 0, 0, opt_no_force_v3_sigs},
	{"no-force-v4-certs", 0, 0, opt_no_force_v4_certs},
	{"no-tty", 0, 0, opt_no_tty},
	{"no-verbose", 0, 0, opt_no_verbose},
	{"openpgp", 0, 0, opt_openpgp},
	{"personal-cipher-preferences", 0, 0,
	 opt_personal_cipher_preferences},
	{"personal-compress-preferences", 0, 0,
	 opt_personal_compress_preferences},
	{"personal-digest-preferences", 0, 0,
	 opt_personal_digest_preferences},
	{"pgp2", 0, 0, opt_pgp2},
	{"pgp6", 0, 0, opt_pgp6},
	{"pgp7", 0, 0, opt_pgp7},
	{"pgp8", 0, 0, opt_pgp8},
	{"quiet", 0, 0, 'q'},
	{"recipient", 1, 0, 'r'},
	{"rfc1991", 0, 0, opt_rfc1991},
	{"rfc2440", 0, 0, opt_rfc2440},
	{"rfc4880", 0, 0, opt_rfc4880},
	{"s2k-cipher-algo", 0, 0, opt_s2k_cipher_algo},
	{"s2k-count", 0, 0, opt_s2k_count},
	{"s2k-digest-algo", 0, 0, opt_s2k_digest_algo},
	{"s2k-mode", 0, 0, opt_s2k_mode},
	{"sign", 0, 0, 's'},
	{"status-fd", 1, 0, opt_status_fd},
	{"store", 0, 0, opt_store},
	{"symmetric", 0, 0, 'c'},
	{"textmode", 0, 0, 't'},
	{"trust-model", 1, 0, opt_trust_model},
	{"use-agent", 0, 0, opt_use_agent},
	{"verify", 0, 0, opt_verify},
	{"version", 0, 0, opt_version},
	{"with-colons", 0, 0, 'k'},
	{"with-fingerprint", 0, 0, opt_with_fingerprint},
	{"with-keygrip", 0, 0, opt_with_keygrip},
	{0, 0, 0, 0}
};

#endif				/* _GPG_H */
