Import('*')

CORE_SRC = Glob('src/*.c')
MATH_SRC = Glob('kazmath/*.c')

env = Environment(
    LIBS=['m'],
    CPPPATH=['include', '.'],
    LINKFLAGS='-fopenmp',
    CFLAGS='-fopenmp -g -O3 -Wall -std=c99')

if GetOption('double'):
    env['CPPDEFINES'] = {'HEMAN_FLOAT': 'double'}

if env['PLATFORM'] == 'darwin':
    env['LINKFLAGS'] = ''

heman = env.SharedLibrary('heman.so', source=CORE_SRC + MATH_SRC)
Alias('lib', heman)

env = env.Clone(LIBS=['m', heman])
for test in TESTS:
    name = 'test_' + test
    path = 'test/' + name + '.c'
    env.Program(name, source=[path])
Default('test_heman')

# env = env.Clone(
#     LIBS=['boost_python', 'python2.7', 'm'],
#     CPPPATH=['/usr/include/python2.7', 'include', '.'],
#     SHLIBPREFIX='')
# pylib = env.SharedLibrary('_heman.so', source=CORE_SRC + MATH_SRC)
# Alias('pylib', pylib)
