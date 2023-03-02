objs = 9_usehotel.o 10_hotel.o

9_usehotel : $(objs)
#$^所有依赖文件的集合，使用空格分开，如果在依赖文件中有多个重复的文件，
	gcc $^ -o 9_usehotel 

%.o : %.c
# -Wall表示显示编译的时候所有警告
# -nostdlib表示不链接系统标准启动文件和库文件，否则编译可能会出错
# -O2表示优化等级，和MDK上的设置含义一样
# $@规则中的目标集合，在模式规则中，如果有多个目标的话，“$@”表示匹配模式中定义的目标集合
# $<依赖文件集合中的第一个文件，如果依赖文件是以模式(即“%”)定义的，那么 “$<”就是符合模式的一系列的文件集合。
	gcc -Wall -nostdlib -c -O2 -o $@ $<

clean-o:
	rm -rf *.o

clean-all:
	rm -rf *.o 9_usehotel