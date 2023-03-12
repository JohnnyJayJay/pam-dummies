#include <security/_pam_types.h>
#include <stdio.h>
#include <stdbool.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

PAM_EXTERN int pam_sm_authenticate(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_setcred(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_open_session(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_close_session(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_chauthtok(
    __attribute__ ((unused)) pam_handle_t *pamh,
    __attribute__ ((unused)) int flags,
    __attribute__ ((unused)) int argc,
    __attribute__ ((unused)) const char **argv
) {
    return PAM_SUCCESS;
}
