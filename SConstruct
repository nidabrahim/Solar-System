import os

# TODO maybe this could be solved more elegantly
# with build targets

main_path = os.getcwd()
Export('main_path')

env = Environment()

def compileSDL2Image():
	cur_dir = os.getcwd()

	if not os.path.exists('lib/SDL2_image'):
		print "Unpack"
		os.chdir("lib")
		Execute('tar xzfv SDL2_image-2.0.0.tar.gz')
		Execute('mv SDL2_image-2.0.0 SDL2_image')
		os.chdir('..')

	os.chdir("lib/SDL2_image")

	if os.path.exists('config.status'):
		print "...Configure is up to date"
	else:
		Execute("./configure")
	
	Execute("make")

	os.chdir(cur_dir)

compileSDL2Image()

SConscript('src/SConstruct', variant_dir='build', src='src', main_path='main_path', duplicate=0)

Execute('chmod +x solarsystem')
