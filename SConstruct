env = Environment()

debug = ARGUMENTS.get('debug', 0)
if int(debug):
    env.Append(CCFLAGS = '-g')

env.Program(target='libinspectfs', source=Glob('*.cpp')
    , LIBS=['udev'], LIBPATH=['/lib/x86_64-linux-gnu/'])

