from SCons.Environment import Base as Environment 

projectInclude = ['include/', 'libs/']
systemInclude = ['/usr/include/']
libsInclude = []

env=Environment(CPPPATH=projectInclude + systemInclude + libsInclude,
    INCDIR="include/",
    BINDIR="bin/",
    CPPDEFINES=[],
    LIBS=[],
    SCONS_C_STANDARD="c11",
    )

env.Program('cidl', env.RGlob("src", '*.c'))  


test = env.Command( target = "testoutput",
                source = "./bin/cidl",
                action = "./bin/cidl" )
env.AlwaysBuild( test )