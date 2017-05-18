**编译指令:**
g++ -std=c++11 chrono_time.h data_structure.h generator.h generator.cpp main.cpp printer.h printer.cpp rein.h rein.cpp util.h util.cpp -o rein

（c++11需要g++ 4.8以上的版本支持）

**输入参数:**
从文件paras.txt中读入。

**运行:**
ulimit -s 819200

./rein

**输出:**
每行四个数值，依次表示1.订阅总数 2.单个订阅插入用时 3.单个事件匹配用时 4.匹配的订阅总数

20000	0.002196	5.335285	19.340000

