# PAM Dummies

This repository is a collection of purely software-based PAM modules that can be used to test the behaviour of PAM-aware applications by allowing you to simulate different kinds of authentication.

Currently the following PAM modules are available:

- **keystroke**: Pressing a key authenticates you (does not work in native Wayland windows - use XWayland)
- **yesman**: Returns immediately with a positive response for any PAM service

## Build

- Run `make <name-of-the-module>` to get a corresponding shared library. E.g. `make yesman` gives you `pam_yesman.so`.
- Run `make` to make all modules.
- Run `make install` to install all modules to `/usr/lib/security`
- Run `make uninstall` to remove all pam-dummy modules from `/usr/lib/security`

## Use
Configure the modules for your desired services in regular PAM fashion. For instance, you can create a PAM service configuration in `/etc/pam.d/foo` like this:

```
#%PAM-1.0
auth	 required pam_yesman.so
```

And then, using [pamtester](https://pamtester.sourceforge.net/):

```
$ pamtester foo root authenticate
pamtester: successfully authenticated
```
