# add custom variables to this file

# OF_ROOT allows to move projects outside apps/* just set this variable to the
# absoulte path to the OF root folder

OF_ROOT = ../../../of/0080

# USER_CFLAGS allows to pass custom flags to the compiler
# for example search paths like:
# USER_CFLAGS = -I src/objects

USER_CFLAGS = -I src/visuals -I src/visuals/model -I src/visuals/control
USER_CFLAGS += -I src/traces -I src/traces/model -I src/traces/control
USER_CFLAGS += -g -I src/view -I src/util

USER_CFLAGS += -I src/_layer/empty -I src/_layer/test  -I src/_layer/primitives
USER_CFLAGS += -I src/_layer/lines -I src/_layer/hypnose -I src/_layer/film
USER_CFLAGS += -I src/_layer/crowd -I src/_layer/dripping -I src/layer/eggs
USER_CFLAGS += -I src/_layer/paperfly -I src/_layer/fft -I src/_layer/image
USER_CFLAGS += -I src/_layer/mapping -I src/_layer/frame -I src/_layer/gallery
USER_CFLAGS += -I src/_layer/vinylrotate -I src/_layer/vinylshutter
USER_CFLAGS += -I src/_layer/treeshilouette -I src/_layer/flowers

USER_CFLAGS += -I src/_paths/empty -I src/_paths/tracing -I src/_paths/reklame
USER_CFLAGS += -I src/_paths/frame -I src/_paths/scribble -I src/_paths/voronoi
USER_CFLAGS += -I src/_paths/ct_painting -I src/_paths/ct_control -I src/_paths/fill


# USER_LDFLAGS allows to pass custom flags to the linker
# for example libraries like:
# USER_LDFLAGS = libs/libawesomelib.a

USER_LDFLAGS =
USER_LIBS = -laubio

EXCLUDE_FROM_SOURCE="bin,.xcodeproj,obj"

# change this to add different compiler optimizations to your project

USER_COMPILER_OPTIMIZATION = -march=native -mtune=native -Os


# android specific, in case you want to use different optimizations
USER_LIBS_ARM = 
USER_LIBS_ARM7 = 
USER_LIBS_NEON = 

# android optimizations

ANDROID_COMPILER_OPTIMIZATION = -Os

NDK_PLATFORM = android-8

# uncomment this for custom application name (if the folder name is different than the application name)
#APPNAME = folderName

# uncomment this for custom package name, must be the same as the java package that contains OFActivity
#PKGNAME = cc.openframeworks.$(APPNAME)

# linux arm flags

LINUX_ARM7_COMPILER_OPTIMIZATIONS = -march=armv7-a -mtune=cortex-a8 -finline-functions -funroll-all-loops  -O3 -funsafe-math-optimizations -mfpu=neon -ftree-vectorize -mfloat-abi=hard -mfpu=vfp



