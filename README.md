# DsCode
分享一些常见考研数据结构代码题写法
# 运行方式
打开命令行输入
g++ -o 输出目标文件名 源文件名\
输出目标文件名 参数1 参数2 ... 参数 \
(为了测试方便 部分题目使用命令行传参)\
或直接复制代码到编译器运行(部分命令行传参需要修改为从键盘键入 cin或者scanf)
# 顺序表
1、顺序表递增有序，插入元素 x，仍递增有序\
2、用顺序表最后一个元素覆盖整个顺序表中最小元素，并返回该最小元素 \
3、将顺序表中的元素逆置 \
4、将（a1,a2,a3……am,b1,b2,……bn）转换成( b1,b2,……bn,a1,a2,a3,……am ) \
5、删除顺序表中所有值为 x 的元素(两种方法) \
6、从顺序表中删除给定值在 s 到 t 之间（包含 s 和 t）的所有元素 \
7、从有序表中删除所有值重复的元素 \
8、两个递增有序表合并成一个递增有序表 \
9、求两个递增序列合并后的中位数(两种方法) \
10、设计一个时间上尽可能高效的算法，找出数组中未出现的最小正整数 \
11、若一个整数序列中有过半相同元素，则称其为主元素，设计算法找出数组 A( a0,a1……an-1 )的主元素。（其中 0<ai<n）若存在主元素则输出，否则返回-1
# 链表
1、删除带头节点单链表中所有值为 x 的结点\
2、删除带头节点单链表中第一个值为 x 的结点 \
3、从尾到头反向输出单链表每个结点的值 \
4、试编写算法将单链表就地逆置 \
5、从链表中删除给定值在 s 到 t 之间（不包含 s 和 t）的所有元素\
6、试编写在带头结点的单链表 L 中删除最小值点的高效算法（已知最小值唯一） \
7、试编写在不带头结点的单链表 L 中删除最小值点的高效算法（已知最小值唯 一）\
8、给定一个单链表，按递增排序输出的单链表中各结点的数据元素，并释放节点所占空间 
9、将一个带头节点的单链表 A 分解成两个带头节点的单链表 A 和 B，使 A 中含奇数位置元素，B中含偶数位置元素，且相对位置不变 
10、将一个单链表{a1,b1,a2,b2……an,bn}拆分成{ a1,a2……an }和{ bn,bn-1,……b1 } 
11、删除递增链表中重复的元素 
12、两个递增有序的单链表，设计算法成一个非递减有序的链表
# 栈和队列
1、Q 是一个队列，S 是一个空栈，编写算法使得队列中元素逆置\
2、判断单链表的全部 n 个字符是否中心对称 \
3、两个栈 s1,s2 都采用顺序存储，并共享一个存储区[0,...,maxsize-1]。采用栈顶 相向，迎面增长的存储方式，设计 s1,s2 入栈和出栈的操作。\
4、判断一个表达式中括号是否配对(假设只包含圆括号)\
5、假设一个序列为 HSSHHHS，运用栈的知识，编写算法将 S 全部提到 H 之前， 即为 SSSHHHH
