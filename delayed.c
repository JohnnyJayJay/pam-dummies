#include <security/_pam_types.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

PAM_EXTERN int pam_sm_authenticate(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    int argc,
    const char **argv
) {
    int seconds = 5;
    if (argc > 0) {
        seconds = atoi(argv[0]);
        if (seconds <= 0) {
            return PAM_SYSTEM_ERR;
        }
    }
    printf("Authenticating you after %i seconds...\n", seconds);
    sleep(seconds);
    return PAM_SUCCESS;
}
