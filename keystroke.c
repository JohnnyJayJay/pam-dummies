#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <uiohook.h>
#include <security/pam_modules.h>

bool success;
int remaining_tries;
uint16_t accept_key = VC_ENTER;
uint16_t deny_key = VC_BACKSPACE;

void on_event(uiohook_event * const event) {
    if (event->type == EVENT_KEY_PRESSED) {
        int key = event->data.keyboard.keycode;
        if (key == accept_key) {
            success = true;
        } else if (key == deny_key) {
            success = false;
            fprintf(stderr, "Permission denied\n");
        } else {
            if (remaining_tries == 0) {
                fprintf(stderr, "Authentication unsuccessful\n");
                success = false;
            } else {
                fprintf(stderr, "Unknown key, try again. Remaining tries: %i\n", remaining_tries--);
                return;
            }
        }
        int status = hook_stop();
        if (status != UIOHOOK_SUCCESS) {
            fprintf(stderr, "libuiohook error\n");
        }
    }
}

PAM_EXTERN int pam_sm_authenticate(__attribute__ ((unused)) pam_handle_t *pamh, __attribute__ ((unused)) int flags, __attribute__ ((unused)) int argc, __attribute__ ((unused)) const char **argv) {
    remaining_tries = 5;
    hook_set_dispatch_proc(&on_event);
    printf("Press a key to continue authenticating.\n");
    int status = hook_run();
    if (status != UIOHOOK_SUCCESS) {
        return PAM_SERVICE_ERR;
    } else if (success) {
        return PAM_SUCCESS;
    } else if (remaining_tries == 0) {
        return PAM_AUTH_ERR;
    } else {
        return PAM_PERM_DENIED;
    }
}
