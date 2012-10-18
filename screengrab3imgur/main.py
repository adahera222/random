import os, sys
import hooks, grab, upload
from globals import globals


def main():
    homedir = os.path.expanduser('~')
    globals.ppath = os.path.join(homedir, 'AppData', 'Local', 'screengrab3imgur')

    try:
        os.mkdir(globals.ppath)
    except OSError:
        pass

    hooks.Hooks()


if __name__ == "__main__":
    main()
