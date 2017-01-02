import sys
import gflags

Flags = gflags.FLAGS

gflags.DEFINE_string("name", "test", "help string")
gflags.DEFINE_float("fV", 1.2, "help float")


def main(argv):
    Flags(argv)
    print "double : ", Flags.name
    print 'double value : ', Flags.fV

if __name__ == "__main__":
    main(sys.argv)
