#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys

class Slicer(object):

    """docstring for Slicer"""

    def __init__(self, arg):
        super(Slicer, self).__init__()
        self.arg = arg

    def sliceSimpleString(someString, somethingElse):
        return somethingElse

def main():
    toto = Slicer(42)
    print toto.sliceSimpleString("KarimEstUneJolieSecretaire")


if __name__ == "__main__":
    sys.exit(main())