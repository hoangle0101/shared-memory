# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(DACK)

set(CMAKE_C_STANDARD 11)
include_directories(include)

add_executable(writer src/writer.c)
add_executable(reader src/reader.c)
add_executable(editor src/editor.c)
#add_executable(cleaner src/cleaner.c)
#add_executable(status src/status.c)
add_executable(overview src/overview.c)
add_executable(reset src/reset.c)
add_executable(queue src/queue.c)
add_executable(queue_reader src/queue_reader.c)
add_executable(initializer src/initializer.c)
#add_executable(info src/info.c)
add_executable(viewer src/viewer.c)
#add_executable(couter src/couter.c)
#add_executable(duplicator src/duplicator.c)
add_executable(monitor src/monitor.c)
add_executable(locker src/locker.c)
add_executable(deleterByKey src/deleterByKey.c)
add_executable(backup src/backup.c)
add_executable(restorer src/restorer.c)
add_executable(searcher src/searcher.c)
# add_executable(initializerQueue src/initializerQueue.c)
# add_executable(logger src/logger.c)
