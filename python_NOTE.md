## 基础知识
* 编译器 编译型语言 统一翻译 一起执行 速度更快 
* 解释器 解释型语言 读取一行 翻译一行 执行一行 跨平台更有优势
> + 其他解释器:CPython Ipython Jpython PyPy
* IDE 集成开发环境 图形用户界面 代码编辑器(Editor) 编译器/解释器 调试器 控制台(console)
* python程序执行原理:操作系统先让CPU把python解释器加载到内存 python解释器根据语法规则从上到下让CPU翻译python程序中的代码 CPU再来执行翻译后的代码
* QQ软件在运行之前是保存在硬盘中的 运行之后就会加载到内存中 并获得专属的内存空间 登录时将号码和密码保存之后 发给腾讯服务器 并分配一些内存空间来保存号码和密码 使用别名(变量名)来标记号码和密码
* 使用import导入模块python解释器将模块源码转换为字节码的pyc二进制文件 以提高速度 
## pycharm快捷键 及使用技巧
* ctrl+Q 查看函数内置文件 点在函数名上 再左侧黄色灯泡中插入内置文件
* debug的时候 F8 -- step over 把函数当作一行代码来执行   F7 -- step into 在函数里面一行一行执行
* 字符串的判断避免使用or拼接复杂的逻辑条件，改为使用in


## crawler
* 通用爬虫是搜索引擎用的爬虫:百度快照也是一种爬虫可以爬存和文本相关的内容 不能爬取图片电影二进制文件等
* 通过url访问 将域名通过DNS解析 返回给浏览器一个IP地址 再将IP地址发给服务器访问对应网站 也可以直接访问ip 就是没有经过DNS技术的转化 直接访问目标服务器
* 新的网站诞生第一天 各大搜索引擎如何获取新网址的url：
* 1.主动提交给百度 2.在其他网址设置网站的外链
* 3.搜索引擎会和DNS服务商合作 快速收录新网址的url
* Robots.txt 只是一个协议 一般只有大型的搜索引擎爬虫才会有很多限制
* 协议://ip或域名[:端口]/路径/.../[?参数][#锚 用于跳转到网页指定锚点]
* https协议是由SSL和HTTP共同构建的可进行加密传输、身份认证的网络协议 需要ca申请证书,一般需要收费 并由具有安全性的ssl加密传输
* 二者端口不一样 http-80 https-443
* http的连接很简单是无状态的 是基于tcp的一种规范、协议  规定客户端和服务器的互联
* 发起请求的时候 请求(request)分为header和body     
* header中至少含有GET /(要访问的文件名) HTTP/1.1    其中Host是本机IP 
* 若没有特别的写要访问的文件 就是访问的网站的主页
* 服务器返回给浏览器的内容(response)包括2个部分:headers和body 2者用空行分开
* headers中含有set-cookie 即服务器给浏览器的设置，可能包含用户的浏览痕迹 还有反馈连接协议和状态的 HTTP/1.1 200 OK 以及规定解码的charset=utf-8/....
* body中含有前端的所有html/css/js等 是浏览器要展示的东西
* http 1.0 短链接 每一次请求都重新3次握手创建新的套接字
* http 1.1 长链接 先得到整个页面的数据 后一次性请求所有需要的数据
* 本机 [IP查询](http://www.ip138.com/)
- ip地址:用来标记网络上的一台电脑 
+ windows:ipconfig linux/mac/unix:ifconfig 出现2个网卡 想与别人通信用以太网 自己联网用本地 sudo ifconfig ens40 down 把通信网关掉
+ 分类:ipv4/ipv6 v指版本  ipv6 正在发展
+ ipv4 更常用 4组数 总共有256 * 256 * 256 * 256 种
> * C类地址前3个标记网络号 同一个局域网前3个3位数一样 最后一个标记主机号 0和255用于广播 不能随便用
> * A类IP地址第1组当作网络号 后3组当作主机号 B类前2后2 C类前3后1
> * D类主要用于多点广播 E类地址保留仅用于实验
- 端口号(port)类似软件的IP 可以理解为门牌号 一个程序没有运行叫程序 运行起来叫进程
> * 知名端口(小于1024)是众所周知的 大家默认都使用的端口 不能随便用 比如80端口分配给HTTP 21端口分给FTP
> * 动态端口(1024到65535) 可以随意使用
## 网络通信基础：使用网络的目的是联机
### socket是一种进程的通信方式
### 网络-udp 写信模型 每一封信都需要署名收信人和寄信人 但是并不安全 数据可能丢 udp是面向无连接的通信

```python
import socket # socket.socket(AddressFamilly(协议族ipv4),Type(udp/tcp))
tcp_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM) # tcp套接字
udp_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # udp套接字
# 给套接字设置固定端口
local_addr = (' ',7788) # ip一般不写,表示本机任何一个ip
udp_socket.bind(local_addr) # 必须绑定自己电脑的IP 但不可以占用其他进程的端口 不绑定操作系统就会给一个随机端口
dest_ip = '192.168.0.147'
dest_sort = 7788
recv_data = udp_socket.recvfrom(1024) # 接收数据,默认接受元组,具有阻塞的特性,操作系统收到数据会先存起来,等待程序的调用来取数据
print(recv_data)
data = 'hello'
udp_socket.sendto(data.encode('utf-8'),(dest_ip,dest_sort)) #后接ip和port的元组
#若是发不通则试一下ping 192.168.0.147
#若是电脑有几个IP则把虚拟网卡VMware关掉
udp_socket.close()
```

+ 单工:收音机 只能收
+ 半双工:对讲机 可以收发，但同一时刻只能收或发
+ 全双工:电话 同一时刻可以同时收发 socket套接字是全双工

```python
import socket
print('XXX聊天器'.center(50,'='))
udp_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

udp_socket.bind(('192.168.0.147',7788))

def send_msg(udp_socket):
data = input('send some data:')
udp_socket.sendto(data.encode('utf-8'),('192.168.0.147',7799))    

def recv_msg(udp_socket):
recv_data = udp_socket.recvfrom(1024)
print(\%s:%s\ % (str(recv_data[1]),recv_data[0].decode('utf-8')))

while True:
print('1-send message')
print('2-recieve message')
choice = input('choose your function:')
if choice == '1':
    send_msg(udp_socket)
elif choice == '2':
    recv_msg(udp_socket)
else:
    break
udp_socket.close()
```

```python
# udp聊天器 优化版
import socket,threading
def send_msg(udp_socket):
while True:
    data = input('send some data:')
    udp_socket.sendto(data.encode('utf-8'),('192.168.0.147',7799))    

def recv_msg(udp_socket):
while True:
    recv_data = udp_socket.recvfrom(1024)
    print(\%s:%s\ % (str(recv_data[1]),recv_data[0].decode('utf-8')))

print('XXX聊天器'.center(50,'='))
udp_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
udp_socket.bind(('192.168.0.147',7788))

t1 = threading.Thread(target=send_msg,args=(udp_socket,))
t2 = threading.Thread(target=recv_msg,args=(udp_socket,))

t1.start()
t2.start()

#udp_socket.close() 将最后一行注释掉否则会报错
```

### 网络-tcp 传输控制协议 较为安全 更稳定 类似打电话 tcp是面向链接的通信
> * 发送应答机制:在传输前必须建立链接(拨号) 发出数据后可以知道对方收到没有
> * 超时重传
> * 错误校验 检验是否有误
> * 流量控制和阻塞管理 
> * 严格区分客户端和服务器 服务器离主机越远越卡
> * 客户端 eg:APP     
> * 3次握手 (双方都在准备资源)客户端先发syn 服务器准备好资源后返回ack和新的syn 客户端准备好后返回ack
> * 4次挥手 (双方都在释放资源)(全双工套接字有两个通道 收和发都要关)  客户端向服务器发close关闭发送通道\\ 服务器关闭接收通道并告诉客户端已收到 \\ 服务器再关闭发送通道并向客户端发close\\ 客户端关闭接收通道并告诉服务器已收到 
> * 因为第2次挥手是为了确认服务器收到并对new_socket.recv解堵塞  第3次是为了服务器关闭发送通道new_socket.close  在程序中二者之间可以time.sleep()延迟 所以这2次不能简化为1次
> * 谁先调close谁就会保留资源 一直等到超时重传时间过去了  即数据包在网络上能存活的时间的两倍  如果没有重发过来 就释放资源
> * 服务器不能先close 因为保留的资源 会影响下一次connect 即端口被占
> * 如果服务器想要重新利用套接字 则需要加一行代码:            
tcp_server_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
> * 客户端可以先close 原因是客户端一般不绑定端口 每一次重连都会用新的端口号

### tcp客户端 一般不绑定端口 先发
### 两台QQ客户端可以都不绑定 通过第三方服务器来交换信息
```python
# 模拟下载
from socket import *
tcp_client_socket = socket(AF_INET,SOCK_STREAM)
server_ip = input('请输入要链接的服务器IP')
server_port = input('请输入要链接的服务器port')
# 链接服务器
tcp_client_socket.connect((server_ip,server_port))
send_data = input('输入要下载的文件:')
tcp_client_socket.send(send_data.encode('gbk'))
recvdata = tcp_client_socket.recv(1024) #1024个字节为1K 1024*1024为1M
if recvdata:
with open('[新]'+send_data,'wb') as f:
    f.write(recv_data)
print('接收到的数据为',recvdata.decode('utf-8'))
tcp.client.socket.close()
```

### tcp服务器 先收
```python
from socket import *
tcp_server_socket = socket(AF_INET,SOCK_STREAM)
address = ('',7788)
tcp_server_socket.bind(address) # 服务器需要绑定ip和端口,方便客户端链接
# listen使套接字变为可以被动链接,从而可以接收别人的链接
tcp_server_socket.listen(128) # 128与同一时刻链接的客户端有关 与操作系统有关
while True: # 循环接受客户端,为客户端服务
print('等待新客户端连接.....')
# accept等待客户端的链接connect,默认如果没有客户端链接则会一直等待,产生新的套接字client_socket为这个客户端服务
# clientaddr 是这个客户端的信息IP和port
# tcp_server_socket就可以省下来专门等待其他新客户端的链接
client_socket,clientaddr = tcp_server_socket.accept()
while True: # 为同一个客户端服务多次
    print('{0}客户端连接成功'.format(clientaddr))
    # 接收和发送数据
    recvdata = client_socket.recv(1024)
    print('客户端送过来的的数据为',recvdata.decode('utf-8'))
    # 如果recv解堵塞可能是
    # 1.客户端发送来数据
    # 2.客户端close
    if not recvdata:
	client_socket.send('continue'.encode('utf-8'))
    else:
	client_socket.send('goodbye'.encode('utf-8'))
	break

    client_socket.close() #关闭套接字不再为这个客户端服务
    print('已经为这个客户端服务完毕')

tcp_server_socket.close() # 最后关服务器
```

```python
from socket import *
def send_file_2_client(new_client_socket,client_addr):
recvdata = new_client_socket.recv(1024).decode('utf-8')
print('客户端要下载的数据为',recvdata)
file_content = None
try:
    f = open(recvdata,'rb')
    file_content = f.read()
    f.close()
except Exception as e:
    print('没有要下载的文件{}'.format(revcdata))
if file_content:
    client_socket.send(file_content)

def main():
tcp_server_socket = socket(AF_INET,SOCK_STREAM)
tcp_server_socket.bind((\\,7890)) 
tcp_server_socket.listen(128)
print('等待新客户端连接.....')
while True:
    client_socket,clientaddr = tcp_server_socket.accept()        
    print('{0}客户端连接成功'.format(str(clientaddr)))
    send_file_2_client(client_socket,clientaddr)

    client_socket.close() #关闭套接字不再为这个客户端服务
    print('已经为这个客户端服务完毕')
tcp_server_socket.close() 
main()
```

```python
# tcp模型模拟实现http服务器 返回固定页面
from socket import *
tcp_server_socket = socket(AF_INET,SOCK_STREAM)
tcp_server_socket.setsockopt(SOL_SOCKET,SO_REUSEADDR,1) # 设定套接字选项 保证服务器可以先close
address = ('',7788)
tcp_server_socket.bind(address) 
tcp_server_socket.listen(128) 
while True: 
print('等待新客户端连接.....')
client_socket,clientaddr = tcp_server_socket.accept()
while True: 
    print('IP端口号为{0}的客户端连接成功'.format(clientaddr))
    ''' 接收请求头'''
    request = client_socket.recv(1024) # 客户端不只是发送请求的页面 还有超链接
    print('客户端送过来的的请求为\\n',request.decode('utf-8'))
    ''' 返回headers和body'''
    headers = \HTTP/1.1 200 OK\\r\\n\ # 每一行后面都有一个换行
    konghang = \\\r\\n\   # 2者中空一行
    f = open('baidu.html','r')
    body = f.read()
    f.close()
    # body = \<h1>this is a headline</h1>\
    response = headers + body
    client_socket.send(response.encode('utf-8'))
    client_socket.close() #关闭套接字不再为这个客户端服务
    print('已经为这个客户端服务完毕')
    break
tcp_server_socket.close() # 最后关服务器的监听套接字
```

```python
# 应用多进程多线程协程改进tcp模拟http服务器
from socket import *
import re,multiprocessing,threading
#import gevent
#from gevent import monkey
#monkey.patch_all()
def service_client(client_socket):
''' 接收请求头'''
request = client_socket.recv(1024).decode('utf-8')
print(request)
request_lines = request.splitlines()
ret = re.search(r\/[^/1|\\D]*[^\\s]*\,request_lines[0]) if len(request_lines) else None
file_name = ret.group(0) if ret else \baidu.html\
print(\请求访问\,file_name)
try:
    f = open(file_name[1:],'rb')
except:
    headers = \HTTP/1.1 404 NOT FOUND\\r\\n\
    headers = headers + \\\r\\n\
    client_socket.send(headers.encode('utf-8'))
else:
    body = f.read()
    f.close()
    ''' 打开成功就返回状态码200'''
    headers = \HTTP/1.1 200 OK\\r\\n\ 
    konghang = \\\r\\n\   
    headers = headers + konghang
    client_socket.send(headers.encode('utf-8'))
    client_socket.send(body)
client_socket.close()
def main():
tcp_server_socket = socket(AF_INET,SOCK_STREAM)
tcp_server_socket.setsockopt(SOL_SOCKET,SO_REUSEADDR,1) 
tcp_server_socket.bind((\192.168.0.147\,7788)) 
tcp_server_socket.listen(128) 
while True: 
    print('等待新客户端连接.....')
    client_socket,clientaddr = tcp_server_socket.accept()
    print('IP端口号为{0}的客户端连接成功'.format(clientaddr))
    #gevent.spawn(service_client,client_socket) # 协程
    #t = threading.Thread(target=service_client,args = (client_socket,)) # 多线程
    #t.start()  # 注意多线程不会复制资源 所以不用client_socket.close()
    p = multiprocessing.Process(target=service_client,args=(client_socket,)) # 多进程
    p.start()
    client_socket.close() # 多进程会复制之前定义的所有变量 这里需要先关一次主进程的 之后再关的子进程才会指向fd文件描述符 然后才会开始4次挥手
tcp_server_socket.close() # 最后关服务器的监听套接字
if __name__ == \__main__\:
main()
```

```python
# 单进程 单线程 利用列表遍历 实现同时服务多个客户端
from socket import *
import time
tcp_server_tcp = socket(AF_INET,SOCK_STREAM)
tcp_server_tcp.bind(\\,7890)
tcp_server_tcp.listen(128)
tcp_server_tcp.setblocking(False) # 设置套接字为非堵塞
client_socket_list = list()
while True:
    time.sleep(1)
    try:
        new_socket, new_addr = tcp_server_tcp.accept()
    except Exception as ret:
        print('----没有新的客户端到来----')
    else:
        print('----只要没有产生异常，就意味着有新客户端连接成功')
        new_socket.setblocking(False) # 设置套接字为非堵塞方式
        client_socket_list.append(new_socket)
for client_socket in client_socket_list:
    try:
	recv_data = client_socket.recv(1024) 
	# 每一次recv并不是直接从对方客户端拿数据 而是从操作系统的缓存区域拿数据
    except Exception as ret:
	print('----这个客户端没有发送数据')
    else:
	if recv_data:
	    print('----这个客户端发送来数据')
	    print(str(recv_data))
	else:
	    print('客户端调用close')
	    client_socket_list.remove(client_socket)
	    client_socket.close()
```

```python
# 利用单进程 单线程 遍历实现 长链接
from socket import *
import re
def service_client(client_socket, request):
    ''' 接收请求头'''
    #request = client_socket.recv(1024).decode('utf-8')
    #print(request)
    request_lines = request.splitlines()
    ret = re.search(r\/[^/1|\\D]*[^\\s]*\,request_lines[0]) if len(request_lines) else None
    file_name = ret.group(0) if ret else \baidu.html\
    print(\请求访问\,file_name)
    try:
        f = open(file_name[1:],'rb')
    except:
        headers = \HTTP/1.1 404 NOT FOUND\\r\\n\
        headers = headers + \\\r\\n\
        client_socket.send(headers.encode('utf-8'))
    else:
        content = f.read()
        f.close()
        ''' 打开成功就返回状态码200'''
        response_body = content
        response_header = \HTTP/1.1 200 OK\\r\\n\
        response_header += \Content-Length:%d\\r\\n\% len(response_body) 
    # 在长连接的链接中 规定内容长度来验证每一次的请求 是否接收完数据
        response_header += \\\r\\n\
        response = response_header.encode(\utf-8\) + response_body
        client_socket.send(response)
    #client_socket.close() # 不断开保持长连接
def main():
    tcp_server_socket = socket(AF_INET,SOCK_STREAM)
    tcp_server_socket.setsockopt(SOL_SOCKET,SO_REUSEADDR,1) 
    tcp_server_socket.bind((\127.0.0.1\,7788)) 
    tcp_server_socket.listen(128) 
    tcp_server_socket.setblocking(False)
    client_socket_list = list()
    while True: 
        print('等待新客户端连接.....')
        try:
        client_socket,clientaddr = tcp_server_socket.accept()
        print('IP端口号为{0}的客户端连接成功'.format(clientaddr))
        except Exception as ret:
        print('----没有新的客户端到来----')
        else:
        print('----只要没有产生异常，就意味着有新客户端连接成功')
        client_socket.setblocking(False) # 设置套接字为非堵塞方式
        client_socket_list.append(client_socket)
        for client_socket in client_socket_list:
        try:
            recv_data = client_socket.recv(1024).decode(\utf-8\) 
            # 每一次recv并不是直接从对方客户端拿数据 而是从操作系统的缓存区域拿数据
        except Exception as ret:
            print('----这个客户端没有发送数据')
        else:
            if recv_data:
            service_client(client_socket, recv_data)
            else:
            print('客户端调用close')
            client_socket_list.remove(client_socket)
            client_socket.close() 
    tcp_server_socket.close() # 最后关服务器的监听套接字
if __name__ == \__main__\:
    main()
```
    
* 操作系统的内存分为 内核的内存 和 普通进程使用的
* 每一次调用应用程序 就是把普通进程使用的内存中的内容 复制到内核内存区 查找调用相关内容
* 单进程单线程的效率瓶颈与 遍历一遍列表所需的时间有关 即轮询(Select)
* epoll ：有一个内存空间是http服务器和kernel共享的(内存映射) 减少复制的过程 并且所有套接字不通过轮询 而是通过事件通知来提高效率
* epoll仅支持linux 不支持Windows

```python
from socket import *
import re
import select
def service_client(client_socket, request):
    ''' 接收请求头'''
    #request = client_socket.recv(1024).decode('utf-8')
    #print(request)
    request_lines = request.splitlines()
    ret = re.search(r\/[^/1|\\D]*[^\\s]*\,request_lines[0]) if len(request_lines) else None
    file_name = ret.group(0) if ret else \baidu.html\
    print(\请求访问\,file_name)
    try:
        f = open(file_name[1:],'rb')
    except:
        headers = \HTTP/1.1 404 NOT FOUND\\r\\n\
        headers = headers + \\\r\\n\
        client_socket.send(headers.encode('utf-8'))
    else:
        content = f.read()
        f.close()
        ''' 打开成功就返回状态码200'''
        response_body = content
        response_header = \HTTP/1.1 200 OK\\r\\n\
        response_header += \Content-Length:%d\\r\\n\% len(response_body) 
# 在长连接的链接中 规定内容长度来验证每一次的请求 是否接收完数据
        response_header += \\\r\\n\
        response = response_header.encode(\utf-8\) + response_body
        client_socket.send(response)
    #client_socket.close() # 不断开保持长连接
def main():
    tcp_server_socket = socket(AF_INET,SOCK_STREAM)
    tcp_server_socket.setsockopt(SOL_SOCKET,SO_REUSEADDR,1) 
    tcp_server_socket.bind((\127.0.0.1\,7788)) 
    tcp_server_socket.listen(128) 
    tcp_server_socket.setblocking(False)
    # 创建一个epoll对象
    epl = select.epoll()
    epl.register(tcp_server_socket.fileno(),select.EPOLLIN)
    client_socket_list = list()
    fd_event_dict = dict()
    while True: 
        fd_event_list = epl.poll() #默认堵塞 直到os检测到数据到来 通过事件通知方式告诉程序 解堵塞 返回列表中的每一个值都是元组[(fd,event),(套接字对应的文件描述符，这个文件描述符到底是什么事件 例如可以调用recv接收等)]
        for fd,event in fd_event_list:
            if fd == tcp_server_socket.fileno():
                client_socket,clientaddr = tcp_server_socket.accept()
                print('IP端口号为{0}的客户端连接成功'.format(clientaddr))
                epl.register(client_socket.fileno(),select.EPOLLIN)
                fd_event_dict[client_socket.fileno()] = client_socket
            elif event == select.EPOLLIN:
                # 判断已经连接的客户端是否有数据发送过来
                recv_data = fd_event_dict[fd].recv(1024).decode(\utf-8\) 
                if recv_data:
                    service_client(fd_event_dict[fd], recv_data)
                else:
                    print('客户端调用close')
                    fd_event_dict[fd].close()
                    epl.unregister(fd)
                    del fd_event_dict[fd]
    tcp_server_socket.close() # 最后关服务器的监听套接字
if __name__ == \__main__\:
    main()
```
    
## tcp/ip协议族  --- 一类协议的简称
* 应用层 HTTP协议/QQ 原始套接字可以从应用层直接到IP(网络攻击) (加请求头 包装请求体)
* 传输层 TCP / UDP 二者端口号可以重复 (加原/目的端口)
* 网际层 IP / 域名 / ICMP (加原/目的IP)
* 网络接口层 (加原/目的mac地址)

## OSI协议族分7层 但还是源于tcp/ip
* 应用层 表示层 会话层 对应应用层
* 传输层 对应传输层
* 网络层 对应网际层
* 数据链路层 物理层 对应网络接口层

## 两台电脑之间可以通过网络连接直接通信,但需要设置好IP和网络掩码,IP地址需要控制在同一网段
* 子网掩码用于确定网络号和主机号 确定处于同一局域网的IP
* 192              168                  0                147
* 1100 0000       1010 1000          0000 0000         1001 0011
* 默认生成子网掩码
* 255  \t           \t255 \t\t     255\t\t         0
* 1111 1111       1111 1111       1111 1111          0000 0000
* 按位与 与子网掩码的每一个二进制比较  只有全是1 才输出1 否则输出0 
* 1100 0000       1010 1000         0000 0000            0000 0000
* 192\t         \t168\t          \t    0\t            \t0
* 最后转为十进制就可以看出前两组数为网络号，后组为主机号
* 想要连接多个电脑形成网络，不能拆网线，应该加设备，比如hub集线器缺点是一直在广播，容易卡
* 交换机更强，该广播的时候广播，该单播的时候单播、
* 发送数据时必须带上对方的mac地址，对方用于识别是否丢掉接收到的数据
* 首先看arp广播列表中有没有对方的mac地址，若没有则通过arp广播，发给交换机，然后通过共有的mac地址(ff:ff:ff:ff:ff)传给所有连接的电脑
* 传到IP层通过特殊方法识别出正确的目的地，对方返回给发送者，获得对方IP的mac地址，之后通过单播发送数据
* 路由器最核心的功能是链接2个以上的网(交换机)形成1张大网，即1个路由器里面有多个网卡，分别链接多个网络
把具有接发数据能力的机器称为网关，一般就是路由器
在发送给路由器的数据包中，会带上原IP和原mac以及路由器的mac和目标IP，传到路由器之后由路由器转换为目标IP的mac地址
在传送的过程中，每经过1次转换mac地址就变1次，IP地址不变，因为IP地址仅仅是在逻辑上标记
每个大区都有自己的DNS服务器
浏览器向服务器发送请求大致过程如下
1.解析域名：先通过arp获得默认网关的mac地址-向网关发送带有域名的请求-经过一层层互联网的mac地址的转换-传到DNS服务器查找对应IP地址-回送接收
2.向服务器发送tcp 3次握手
3.发送http的请求数据以及等待服务器的应答
4.发送tcp 4次挥手

  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "aa\n",
      "bb\n",
      "cc\n",
      "0 aa\n",
      "1 bb\n",
      "2 cc\n"
     ]
    }
   ],
   "source": [
    "names = ['aa','bb','cc']\n",
    "for temp in names:\n",
    "    print(temp)\n",
    "for index,name in enumerate(names): # 拆包\n",
    "    print(index,name)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* 单核CPU 时间片轮转 只要转的够快就可以模拟多线程\n",
    "* 并行：真的多任务\n",
    "* 并发：假的多任务 CPU核数小于任务数\n",
    "* 线程 是操作系统调度的单位 依赖于进程\n",
    "* 多线程 一个程序执行起来后会有一个执行的箭头 称之为线程\n",
    "* 多线程是指在一个进程(一坨资源)里面有多个箭头\n",
    "### 多线程适用于:大量密集的I/O处理,输入输出操作,比如文件读写,网络爬虫操作"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {
    "collapsed": true
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "sing0....线程号<Thread(Thread-6, started 16256)>dance0....线程号<Thread(Thread-7, started 8720)>\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-6, started 16256)>, <Thread(Thread-7, started 8720)>]\n",
      "\n",
      "dance1....线程号<Thread(Thread-7, started 8720)>sing1....线程号<Thread(Thread-6, started 16256)>\n",
      "\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-6, started 16256)>, <Thread(Thread-7, started 8720)>]\n",
      "dance2....线程号<Thread(Thread-7, started 8720)>sing2....线程号<Thread(Thread-6, started 16256)>\n",
      "\n",
      "sing3....线程号<Thread(Thread-6, started 16256)>dance3....线程号<Thread(Thread-7, started 8720)>\n",
      "\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-6, started 16256)>, <Thread(Thread-7, started 8720)>]\n",
      "dance4....线程号<Thread(Thread-7, started 8720)>sing4....线程号<Thread(Thread-6, started 16256)>\n",
      "\n",
      "dance5....线程号<Thread(Thread-7, started 8720)>\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-7, started 8720)>]\n",
      "dance6....线程号<Thread(Thread-7, started 8720)>\n",
      "dance7....线程号<Thread(Thread-7, started 8720)>\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-7, started 8720)>]\n",
      "dance8....线程号<Thread(Thread-7, started 8720)>\n",
      "dance9....线程号<Thread(Thread-7, started 8720)>\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>, <Thread(Thread-7, started 8720)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n",
      "[<_MainThread(MainThread, started 14632)>, <Thread(Thread-4, started daemon 14296)>, <Heartbeat(Thread-5, started daemon 15852)>, <HistorySavingThread(IPythonHistorySavingThread, started 18304)>, <ParentPollerWindows(Thread-3, started daemon 15052)>]\n"
     ]
    },
    {
     "ename": "KeyboardInterrupt",
     "evalue": "",
     "output_type": "error",
     "traceback": [
      "\u001b[1;31m---------------------------------------------------------------------------\u001b[0m",
      "\u001b[1;31mKeyboardInterrupt\u001b[0m                         Traceback (most recent call last)",
      "\u001b[1;32m<ipython-input-2-d1e761e45758>\u001b[0m in \u001b[0;36m<module>\u001b[1;34m\u001b[0m\n\u001b[0;32m     33\u001b[0m     \u001b[0mprint\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mthreading\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0menumerate\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m     34\u001b[0m \u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m---> 35\u001b[1;33m \u001b[0mmain\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m     36\u001b[0m \u001b[1;31m#main2()\u001b[0m\u001b[1;33m\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n",
      "\u001b[1;32m<ipython-input-2-d1e761e45758>\u001b[0m in \u001b[0;36mmain\u001b[1;34m()\u001b[0m\n\u001b[0;32m     24\u001b[0m         \u001b[1;32mif\u001b[0m \u001b[0mlen\u001b[0m\u001b[1;33m(\u001b[0m\u001b[0mthreading\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0menumerate\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m==\u001b[0m\u001b[1;36m2\u001b[0m\u001b[1;33m:\u001b[0m \u001b[1;31m#只有在指定函数执行完成之后 子线程才会结束\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m     25\u001b[0m             \u001b[1;32mbreak\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m---> 26\u001b[1;33m         \u001b[0mtime\u001b[0m\u001b[1;33m.\u001b[0m\u001b[0msleep\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;36m2\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m\u001b[0;32m     27\u001b[0m \u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m     28\u001b[0m \u001b[1;32mdef\u001b[0m \u001b[0mmain2\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m:\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n",
      "\u001b[1;31mKeyboardInterrupt\u001b[0m: "
     ]
    }
   ],
   "source": [
    "import time,threading\n",
    "def sing():\n",
    "    for i in range(5):\n",
    "        print('sing{0}....线程号{1}'.format(i,threading.current_thread()))\n",
    "        time.sleep(1)\n",
    "    # 如果创建Thread时执行的函数运行结束 那么意味着这个子线程结束\n",
    "\n",
    "def dance():\n",
    "    for i in range(10):\n",
    "        print('dance{0}....线程号{1}'.format(i,threading.current_thread()))\n",
    "        time.sleep(1)\n",
    "\n",
    "def main():\n",
    "    #tlist = list()\n",
    "    t1 = threading.Thread(target=sing) #只写函数名 相当于传入一个变量名 确定该函数的位置\n",
    "    t2 = threading.Thread(target=dance)\n",
    "    t1.start() # 主线程会生出一个子线程 单独运行    \n",
    "    t2.start() # 主线程生出第二个子线程 单独运行 但线程的先后运行是随机的\n",
    "    #tlist.append(t1)\n",
    "    #tlist.append(t2)\n",
    "    #[n.join() for n in tlist] # 也可以用join()来调用线程 适用于1个函数 多次调用\n",
    "    while True:\n",
    "        print(threading.enumerate()) #查看当前的所有线程数\n",
    "        if len(threading.enumerate())==2: #只有在指定函数执行完成之后 子线程才会结束\n",
    "            break\n",
    "        time.sleep(2)\n",
    "        \n",
    "def main2():\n",
    "    print(threading.enumerate())\n",
    "    t1 = threading.Thread(target=sing) #只是实例化一个对象 不会创建线程\n",
    "    print(threading.enumerate())\n",
    "    t1.start() # 当调用start方法时 才会创建线程以让这个线程开始运行\n",
    "    print(threading.enumerate())\n",
    "    \n",
    "main()\n",
    "#main2()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 5,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "I'mThread-12@0\n",
      "I'mThread-12@1\n",
      "I'mThread-12@2\n"
     ]
    }
   ],
   "source": [
    "# 在一个函数中对全局变量进行修改可能不需要加global \n",
    "# 如果让全局变量指向了一个新的值 必须使用global\n",
    "import threading,time\n",
    "class MyThread(threading.Thread):\n",
    "    def run(self):\n",
    "        for i in range(3):\n",
    "            time.sleep(1)\n",
    "            msg = \"I'm\"+self.name+'@'+str(i)\n",
    "            print(msg)\n",
    "    \n",
    "t = MyThread() #创建一个实例对象 只能对应一个子线程\n",
    "t.start()"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* 多线程之间全局变量共享 改变一个则都变 但是不能两个都改 即同一时刻对变量操作\n",
    "* 资源竞争 CPU会把语句命令复杂化 多个线程的命令会复杂化执行\n",
    "* 同步 协同步骤 按预定步骤的先后顺序进行运行\n",
    "* 互斥锁 保证多个线程几乎同时修改某个共享数据时 进行同步控制 解决资源竞争\n",
    "* 死锁 二者都在等待对方解锁\n",
    "* 避免死锁的方法：1.程序设计尽量避免(银行家算法) 2.添加超时时间"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "----in test1 g_num=1000000\n",
      "-----in test2 g_num=2000000\n",
      "-----in main g_num=2000000\n"
     ]
    }
   ],
   "source": [
    "import threading,time\n",
    "g_num = 0\n",
    "def test1(num):\n",
    "    global g_num\n",
    "    # 上锁，如果之前没有上锁，上锁成功\n",
    "    # 如果之前已经有锁，则阻塞在这里直到对方解锁\n",
    "    mutex.acquire()    \n",
    "    for i in range(num):\n",
    "        g_num += 1\n",
    "    mutex.release() # 解锁\n",
    "    print(f'----in test1 g_num={g_num}')\n",
    "def test2(num):\n",
    "    global g_num\n",
    "    for i in range(num):\n",
    "        mutex.acquire()\n",
    "        g_num += 1  # 上锁部分越少越好\n",
    "        mutex.release()\n",
    "    print('-----in test2 g_num=%s'%(g_num))\n",
    "mutex = threading.Lock()\n",
    "def main():\n",
    "    t1 = threading.Thread(target=test1,args=(1000000,))# args中传入参数元组\n",
    "    t2 = threading.Thread(target=test2,args=(1000000,))\n",
    "    t1.start()\n",
    "    t2.start()\n",
    "    time.sleep(10)\n",
    "    print('-----in main g_num=%s'%(g_num))\n",
    "    \n",
    "main()"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* 程序是静态的 在没有运行的时候 没有网络资源 而进程 是一坨资源的总称 \n",
    "### 进程是资源分配的单位  多进程最稳定\n",
    "* 一个进程里面最少有一个主线程 程序的执行由线程负责\n",
    "### 线程是操作系统调度的单位  多线程稳定性一般\n",
    "* 每创建一个子进程都会copy一份代码和资源 单独给子进程使用 \n",
    "### 因此进程占用资源比线程多\n",
    "* copy时代码和内存不会变 可以共享 但是数据可能改变 因此多进程全局变量不共享\n",
    "* 写时拷贝 写的时候再拷贝\n",
    "* 可以将进程理解为工厂的一条流水线 而其中的线程就是这个流水线上面的工人\n",
    "* 不同的流水线之间 不共享全局变量\n",
    "### 因此多进程适用于:大量的密集并行计算\n",
    "* 下示使用多进程实现多任务 每一个资源里面有一个箭头"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 35,
   "metadata": {},
   "outputs": [],
   "source": [
    "import multiprocessing\n",
    "import time,os\n",
    "def sing(n):\n",
    "    for i in range(n):\n",
    "        print('sing{0}....进程号:{1}'.format(i,os.getpid()))\n",
    "        time.sleep(1)\n",
    "\n",
    "def dance(n):\n",
    "    for i in range(n):\n",
    "        print('dance0}....进程号:{1}'.format(i,os.getpid()))\n",
    "        time.sleep(1)\n",
    "if __name__ == '__main__':\n",
    "    #tlist = list()\n",
    "    t1 = multiprocessing.Process(target=sing,args=(5,))\n",
    "    t2 = multiprocessing.Process(target=dance,args=(5,))\n",
    "    t1.start()\n",
    "    #tlist.append(t1)\n",
    "    t2.start()\n",
    "    #tlist.append(t2)\n",
    "    #[n.join() for n in tlist] # 也可以用join方法调用进程 该方法适合1个函数 多次调用\n",
    "\n",
    "# windows 系统只有在powershell中或cmd中运行才会有结果\n",
    "# 在power shell中输入 ps 查看所有进程 kill 中止进程"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "False\n",
      "True\n",
      "消息1\n",
      "消息2\n"
     ]
    }
   ],
   "source": [
    "# 多进程之间通信可以通过 socket 或 访问本地硬盘的文件 或 Queue队列(解耦 降低耦合性)\n",
    "from multiprocessing import Queue\n",
    "q = Queue(3) # 最多接收3条消息 放多了或取多了都会堵塞 如果不传入参数 系统自动放最大\n",
    "q.put('消息1')\n",
    "q.put('消息2')\n",
    "print(q.full()) #False\n",
    "q.put('消息3')\n",
    "print(q.full()) #True\n",
    "print(q.qsize()) #获取队列长度\n",
    "print(q.empty()) #False 非空\n",
    "print(q.get()) # block默认为True\n",
    "# 如果队列为空，block=True，不会结束，会进入阻塞状态 直到队列有新的值\n",
    "# 如果队列为空，block=False，会弹出一个Queue.empty()的异常\n",
    "print(q.get_nowait())"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [],
   "source": [
    "import multiprocessing\n",
    "from multiprocessing import Queue\n",
    "def download(q):\n",
    "    '''模拟从网上下载数据'''\n",
    "    data = [11,22,33,44]\n",
    "    '''像队列中写入数据'''\n",
    "    for i in data:\n",
    "        q.put(i)\n",
    "    print('下载完毕 并存入队列中')\n",
    "\n",
    "def analysis(q):\n",
    "    '''数据处理'''\n",
    "    waitting_analysis = list()\n",
    "    while True:\n",
    "        data = q.get()\n",
    "        waitting_analysis.append(data)\n",
    "        if q.empty():\n",
    "            break\n",
    "    print(waitting_analysis)\n",
    "    \n",
    "def main():\n",
    "    '''创建队列'''\n",
    "    q = multiprocessing.Queue()\n",
    "    '''创建多个进程，将队列的引用当作实参进行传递到里面'''\n",
    "    t1 = multiprocessing.Process(target=download,args=(q,))\n",
    "    t2 = multiprocessing.Process(target=analysis,args=(q,))\n",
    "    t1.start()\n",
    "    t2.start()\n",
    "main()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "metadata": {
    "scrolled": false
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "-------start--------0开始执行,进程号为131561开始执行,进程号为13156\n",
      "2开始执行,进程号为13156\n",
      "\n",
      "\n",
      "1 执行完毕,耗时0.29\n",
      "3开始执行,进程号为13156\n",
      "3 执行完毕,耗时0.21\n",
      "4开始执行,进程号为13156\n",
      "2 执行完毕,耗时0.75\n",
      "5开始执行,进程号为13156\n",
      "4 执行完毕,耗时0.60\n",
      "6开始执行,进程号为13156\n",
      "6 执行完毕,耗时0.26\n",
      "7开始执行,进程号为13156\n",
      "0 执行完毕,耗时1.60\n",
      "5 执行完毕,耗时1.64\n",
      "7 执行完毕,耗时1.63\n",
      "--------end---------\n"
     ]
    }
   ],
   "source": [
    "from multiprocessing.dummy import Pool # 在线程池中产生了异常 并不会抛出异常\n",
    "import os,time,random\n",
    "def worker(msg):\n",
    "    t_start = time.time()\n",
    "    print('%s开始执行,进程号为%d'%(msg,os.getpid()))\n",
    "    time.sleep(random.random()*2)\n",
    "    t_stop = time.time()\n",
    "    print(msg,\"执行完毕,耗时%0.2f\"%(t_stop-t_start))\n",
    "\n",
    "po = Pool(3) # 最大进程数为3\n",
    "for i in range(8):\n",
    "    '''要调用的目标，需要的参数元组\n",
    "    每次循环将会用空闲出来的子进程去调用目标'''\n",
    "    po.apply_async(worker,(i,))\n",
    "print(\"start\".center(20,'-'))\n",
    "po.close() # 关闭进程池 关闭后再开始执行 关闭后po不再接收新的请求\n",
    "po.join() # 等待进程池中的所有子进程执行完毕 必须放在close语句之后\n",
    "print(\"end\".center(20,'-'))"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "### copy文件实例\n",
    "```python\n",
    "from multiprocessing.dummy import Pool\n",
    "from multiprocessing import Manager,Queue\n",
    "import os, time\n",
    "\n",
    "def copy_file(queue,file_name, old_folder_name, new_folder_name):\n",
    "    \"\"\"完成文件的复制\"\"\"\n",
    "    # print(\"=====>模拟copy[%s]文件:从%s--->%s\" % (file_name, old_folder_name, new_folder_name))\n",
    "    old_f = open(os.getcwd() + \"\\\\\" + old_folder_name + '\\\\' + file_name,'rb')\n",
    "    content = old_f.read()\n",
    "    old_f.close()\n",
    "    new_f = open(new_folder_name+'\\\\'+file_name,'wb')\n",
    "    new_f.write(content)\n",
    "    new_f.close()\n",
    "    '''拷贝完文件之后就向队列写入一个消息'''\n",
    "    queue.put(file_name)\n",
    "\n",
    "def main():\n",
    "    global new_folder_name\n",
    "    old_folder_name = input('请输入要copy的文件夹')\n",
    "    queue = Manager().Queue()\n",
    "    try:\n",
    "        new_folder_name = old_folder_name + \"[附件]\"\n",
    "        os.mkdir(new_folder_name)\n",
    "    except:\n",
    "        print('wrong')\n",
    "\n",
    "    po = Pool(5)\n",
    "    for i in os.listdir(os.getcwd() + '\\\\' + old_folder_name):\n",
    "        po.apply_async(copy_file, args=(queue,i, old_folder_name, new_folder_name))\n",
    "\n",
    "    po.close()\n",
    "    copy_ok_num = 0\n",
    "    while True:\n",
    "        # print('已经完成copy:',queue.get())\n",
    "        copy_ok_num += 1\n",
    "        print('\\r拷贝进度为%.2f %%'%(copy_ok_num*100/len(os.listdir(os.getcwd() + '\\\\' + old_folder_name))),end='')\n",
    "        if len(os.listdir(os.getcwd() + '\\\\' + old_folder_name))==copy_ok_num:\n",
    "            break\n",
    "    # po.join()\n",
    "\n",
    "if __name__ == \"__main__\":\n",
    "    main()\n",
    "```"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "call:a,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_0, started daemon 8916)>\n",
      "call:b,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_1, started daemon 4204)>\n",
      "call:c,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_2, started daemon 11656)>\n",
      "call a finished,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_0, started daemon 8916)>\n",
      "call b finished,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_1, started daemon 4204)>call c finished,process num:1556,thread num:<Thread(ThreadPoolExecutor-0_2, started daemon 11656)>\n",
      "\n"
     ]
    }
   ],
   "source": [
    "# 实现进程池和线程池的另一种方法\n",
    "from concurrent.futures import ThreadPoolExecutor,ProcessPoolExecutor\n",
    "from threading import Thread\n",
    "import os,threading,time\n",
    "\n",
    "def work(n):\n",
    "    print('call:{0},process num:{1},thread num:{2}'.format(n,os.getpid(),threading.current_thread()))\n",
    "    time.sleep(2)\n",
    "    print('call {0} finished,process num:{1},thread num:{2}'.format(n,os.getpid(),threading.current_thread()))\n",
    "# for i in ['a','b','c']:\n",
    "#     work(i)\n",
    "\n",
    "#创建线程池/进程池\n",
    "pool = ThreadPoolExecutor(max_workers=3)\n",
    "#pool = ProcessPoolExecutor(max_workers=3)\n",
    "#循环指派任务\n",
    "[pool.submit(work,user) for user in ['a','b','c']]\n",
    "#关闭线程池\n",
    "pool.shutdown()    "
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# 迭代器\n",
    "#### 可迭代对象 iterable 列表 元组 字典 字符串\n",
    "* 迭代器只是存储生成数值的方法 因此占用内存更少 因此可以节省内存空间\n",
    "* 不仅可以代替for循环使用 还可以节省类型转换所需要的内存 而类型转换其实也是利用迭代重新生成一个新的对象\n",
    "\n",
    "```python\n",
    "nums = list()\n",
    "a,b = 0,1\n",
    "i = 0\n",
    "while i<10:\n",
    "    nums.append(a)\n",
    "    a,b = b,a+b    \n",
    "    i+=1\n",
    "for i in nums:\n",
    "    print(i)\n",
    "    \n",
    "class Fibnacci:\n",
    "    def __init__(self,num):\n",
    "        self.num = num\n",
    "        self.col_num = 0\n",
    "        self.a,self.b = 0,1\n",
    "    def __iter__(self):\n",
    "        return self\n",
    "    def __next__(self):\n",
    "        if self.col_num < self.num:\n",
    "            res = self.a\n",
    "            self.a,self.b = self.b,self.b+self.a\n",
    "            self.col_num += 1\n",
    "            return res\n",
    "        else:\n",
    "            raise StopIteration\n",
    "fib = Fibnacci(10)\n",
    "for i in fib:\n",
    "    print(i) # 结果一样\n",
    "```"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "a\n",
      "b\n",
      "c\n"
     ]
    }
   ],
   "source": [
    "from collections import Iterable,Iterator\n",
    "# class Classmate(object): # 可迭代的不一定是迭代器\n",
    "#     def __init__(self):\n",
    "#         self.names = list()\n",
    "#     def add(self,name):\n",
    "#         self.names.append(name)\n",
    "#     def __iter__(self):\n",
    "#         '''加入该方法 变为可迭代对象 并且必须返回一个含有iter和next方法的实例'''\n",
    "#         return ClassIterator(self) # 返回一个迭代器\n",
    "# class ClassIterator:\n",
    "#     def __init__(self,obj):\n",
    "#         self.obj = obj\n",
    "#         self.num = 0\n",
    "#     def __iter__(self):\n",
    "#         pass\n",
    "#     def __next__(self):\n",
    "#         if self.num < len(self.obj.names):\n",
    "#             res = self.obj.names[self.num]\n",
    "#             self.num += 1\n",
    "#             return res\n",
    "#         else:\n",
    "#             raise StopIteration\n",
    "\n",
    "class Classmate: # 迭代器一定可以迭代 迭代器里面存储的不是数值 而是生成数值的方法\n",
    "    def __init__(self):\n",
    "        self.names = list()\n",
    "        self.num = 0\n",
    "    def __iter__(self):\n",
    "        return self\n",
    "    def add(self,name):\n",
    "        self.names.append(name)\n",
    "    def __next__(self):\n",
    "        if self.num < len(self.names):\n",
    "            res = self.names[self.num]\n",
    "            self.num += 1\n",
    "            return res\n",
    "        else:\n",
    "            raise StopIteration\n",
    "\n",
    "classmate = Classmate()\n",
    "classmate.add('a')\n",
    "classmate.add('b')\n",
    "classmate.add('c')\n",
    "# print(isinstance(classmate,Iterable)) # 判断该对象是否是可迭代对象\n",
    "# print(isinstance(iter(classmate),Iterator)) # 判断__iter__方法的返回值是否是迭代器\n",
    "# print(next(iter(classmate)))\n",
    "\n",
    "for i in classmate:\n",
    "    print(i)\n",
    "# 1.判断是否有__iter__2.判断调用iter()函数得__iter__方法的返回值是否是迭代器\n",
    "# 3.每迭代一次调用一次next()函数 返回一次__next__方法的返回值"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# 生成器 是一种特别的迭代器 可以用于暂停函数并保留数据\n",
    "## 将列表推导式的方括号改为圆括号\n",
    "```python\n",
    "a = [i*2 if pow(i*2,1/2)%2 == 0 else None for i in range(1,11)]\n",
    "print(type(a)) # list \n",
    "b = (i*2 if pow(i*2,1/2)%2 == 0 else None for i in range(1,11))\n",
    "print(type(b)) # generator\n",
    "```\n",
    "## 函数中只要有yield关键字就不是函数而是生成器"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 43,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<generator object create_num at 0x00000210AE1C49A8>\n",
      "----1-----\n",
      "----2-----\n",
      "None\n",
      "----3-----\n",
      "----4-----\n",
      "----2-----\n",
      "1\n",
      "ret\n",
      "----3-----\n",
      "----4-----\n",
      "----2-----\n",
      "None\n",
      "----3-----\n",
      "----4-----\n",
      "----2-----\n",
      "2\n"
     ]
    }
   ],
   "source": [
    "def create_num(all_num):\n",
    "    print('1'.center(10,'-'))\n",
    "    a, b = 0, 1\n",
    "    num = 0\n",
    "    while num < all_num:\n",
    "        print('2'.center(10,'-'))\n",
    "        # print(a)\n",
    "        # yield a\n",
    "        ret = yield a\n",
    "        print(ret)\n",
    "        print('3'.center(10,'-'))\n",
    "        a, b = b, a+b\n",
    "        num += 1\n",
    "        print('4'.center(10,'-'))\n",
    "    return 'done'.center(10,'-')\n",
    "obj = create_num(4) # 创建一个生成器对象,可以创建多个对象，之间互不影响\n",
    "\n",
    "# 用循环调用生成器\n",
    "#for i in obj:\n",
    "#    print(i)\n",
    "print(iter(obj))\n",
    "\n",
    "# 用next调用生成器\n",
    "# while True:\n",
    "#     try:\n",
    "#         print(next(obj))\n",
    "#     except Exception as m:\n",
    "#         print(m.value) # 捕获异常返回值\n",
    "#         break\n",
    "\n",
    "# 用send调用生成器 可以传入参数作为生成器内部的参考 影响生成器的取值\n",
    "obj.send(None) # 无法将非None值传给一个刚创建的生成器\n",
    "print(next(obj))\n",
    "obj.send('ret') # 送到并赋值给yield左边的变量 ret只被传一次 因此第二次是None\n",
    "print(next(obj))"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# 协程稳定性最差 但最快\n",
    "* 协程耗费的资源小于线程  是依托于线程的\n",
    "* 协程 yield 实现多任务并发(假的并行)\n",
    "* 协程是利用线程开发中 等待堵塞的时间来执行其他任务\n",
    "* 因此在很多需要等待的任务中 比如爬虫下载网络数据 优先用协程\n",
    "```python\n",
    "import time\n",
    "def task_1():\n",
    "    while True:\n",
    "        print('--1--')\n",
    "        time.sleep(0.1)\n",
    "        yield\n",
    "def task_2():\n",
    "    while True:\n",
    "        print('--2--')\n",
    "        time.sleep(0.1)\n",
    "        yield\n",
    "def main():\n",
    "    t1 = task_1()\n",
    "    t2 = task_2()\n",
    "    while True:\n",
    "        next(t1)\n",
    "        next(t2)\n",
    "main()\n",
    "```\n",
    "```python\n",
    "from greenlet import greenlet # greenlet对yield实行了封装 用起来更为方便\n",
    "import time\n",
    "def task_1():\n",
    "    while True:\n",
    "        print('--1--')\n",
    "        gr2.switch()\n",
    "        time.sleep(0.1)\n",
    "def task_2():\n",
    "    while True:\n",
    "        print('--2--')\n",
    "        gr2.switch()\n",
    "        time.sleep(0.1)\n",
    "gr1 = greenlet(task_1)\n",
    "gr2 = greenlet(task_2)\n",
    "gr1.switch()\n",
    "```\n",
    "```python\n",
    "import gevent  # 凡是需要用到延时操作的，都需要把堵塞的方法换成gevent里面对应的方法\n",
    "from gevent import monkey \n",
    "monkey.patch_all()  # 或者打个补丁\n",
    "def f1(n):\n",
    "    for i in range(n):\n",
    "        print(gevent.getcurrent(),i)\n",
    "        gevent.sleep(0.5)\n",
    "def f2(n):\n",
    "    for i in range(n):\n",
    "        print(gevent.getcurrent(),i)\n",
    "        gevent.sleep(0.5)\n",
    "g1 = gevent.spawn(f1,5)\n",
    "g2 = gevent.spawn(f2,5)\n",
    "g1.join() # 遇到演示操作就会创建协程 执行其他语句\n",
    "g2.join()\n",
    "gevent.joinall([\n",
    "    gevent.spawn(f1,5),gevent.spawn(f2,5)  # 更简洁的方法是将对象放在一起调用\n",
    "])\n",
    "```"
   ]
  },
  {
   "cell_type": "markdown",
   "source": [
    "GIL是全局解释器锁，会保证同一时刻只有一个线程在跑\n",
    "只有cpython有GIL，如果不是cpython就可以用多线程实现并行来节省资源\n",
    "主线程死循环，占满cpu中的1个核\n",
    "```python\n",
    "while True:\n",
    "    pass\n",
    "```\n",
    "子线程死循环，主线程死循环\n",
    "多线程只是假的并发,并不会占用CPU多核，虽然节省了资源，但速度比不上多进程\n",
    "可以用htop检验发现2个核都只占了一半\n",
    "```python\n",
    "import threading\n",
    "\n",
    "def test():\n",
    "    while True:\n",
    "        pass\n",
    "\n",
    "t1 = threading.Thread(target=test)\n",
    "t1.start()\n",
    "\n",
    "while True:\n",
    "    pass\n",
    "```\n",
    "多进程才是真正的多核并行，可以htop检验发现2个核都占满了\n",
    "```python\n",
    "import multiprocessing\n",
    "\n",
    "def deadLoop():\n",
    "    while True:\n",
    "        pass\n",
    "\n",
    "#子进程死循环\n",
    "p1 = multiprocessing.Process(target=deadLoop)\n",
    "p1.start()\n",
    "\n",
    "#主进程死循环\n",
    "deadLoop()\n",
    "```\n",
    "\n",
    "想要解决GIL带来的问题，真正用多线程实现多核并行，可以换一个解释器或换一种语言\n",
    "比如c语言\n",
    "```\n",
    "#include<stdio.h>\n",
    "\n",
    "int main(int argc, char **argv)\n",
    "{\n",
    "        printf(\"编译型语言需要先进行gcc编译成二进制文件a.out,才能执行\");\n",
    "        return 0;\n",
    "}\n",
    "\n",
    "void DeadLoop()\n",
    "{\n",
    "    while(1)\n",
    "    {\n",
    "        ;\n",
    "    }\n",
    "}\n",
    "```\n",
    "或者用python调用C\n",
    "```python\n",
    "from ctypes import *\n",
    "from threading import Thread\n",
    "\n",
    "#把一个ｃ语言文件编译成一个动态库的命令（linux平台下）:\n",
    "# gcc xxx.c -shared -o libxxxx.so\n",
    "\n",
    "#加载动态库libdead_loop.so\n",
    "lib = cdll.LoadLibrary(\"./libdead_loop.so\")\n",
    "\n",
    "#创建一个子线程，让其执行ｃ语言编写的函数，此函数是一个死循环\n",
    "t = Thread(target=lib.DeadLoop)\n",
    "t.start()\n",
    "\n",
    "#主线程\n",
    "while True:\n",
    "    pass\n",
    "```"
   ],
   "metadata": {
    "collapsed": false,
    "pycharm": {
     "name": "#%% md\n"
    }
   }
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* 抓包工具:[千峰fiddler](https://www.bilibili.com/video/av45394845?p=7)  [传智播客fiddler](https://www.bilibili.com/video/av62303270?p=4)  [千峰charles](https://www.bilibili.com/video/av76899389?p=3)\n",
    "* [wireshark](https://www.bilibili.com/video/av81257032/?p=86):\n",
    "From top to bottom are the number of packets,the contents of the packets, \n",
    "and the specific hexadecimal display of the packets in memory.\n",
    "\n",
    "##### 动态页面的技术javascript/jquery/Ajax/DHTML\n",
    "* 1.直接从Javascript 代码里面采集内容(费时费力)\n",
    "* 2.用第三方库运行JavaScript，直接采集在浏览器看到的页面\n",
    "* Selenium 需要与第三方浏览器结合使用 支持所有主流的浏览器 可以进行截屏\n",
    "* 可以用无界面浏览器教程：[PhantomJS-千峰](https://www.bilibili.com/video/av45394845?p=58)\n",
    "* 因为PhantomJS无人维护 也可以用无头谷歌浏览器参考教程[headless chrome-千峰](https://www.bilibili.com/video/av45394845?p=65)\n",
    "* 因为selenium不再支持PhantomJS 故采用headless firefox [geckodriver](https://github.com/mozilla/geckodriver)\n",
    "\n",
    "##### 验证码的解决\n",
    "* 把图片下载下来 人眼识别input\n",
    "* ORC库 图像光学识别 只能识别简单的\n",
    ">* Tesseract在官网安装 是一个python的命令行工具 在web使用 一般用于验证码登录\n",
    ">* 先在系统中设置新的环境变量 然后放一份tessdata在Tesseract目录下\n",
    ">* pip install pytesseract 安装python版本的Tesseract 结合PIL使用\n",
    "\n",
    "* 云打码 注册普通用户、开发者 参考教程[千峰](https://www.bilibili.com/video/av45394845?p=78)\n",
    ">* 使用云打码时 在我的软件中新加一个软件"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# urllib\n",
    "```python\n",
    "import urllib.request, urllib.parse, urllib.error, urllib.robotparser\n",
    "import http.cookiejar\n",
    "try:\n",
    "    cj = http.cookiejar.CookieJar()\n",
    "    opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cj))\n",
    "    # some url must cookie (proxyHandler HTTPSHandler HTTPRedirectHandler)\n",
    "    # urllib.request.install_opener(opener)\n",
    "    url = \"https://www.baidu.com/s?wd=\"  # 定义请求地址\n",
    "    headers = {'User-Agent': 'Mozilla/5.0 3578.98 Safari/537.36', }  # 定义自定义请求头\n",
    "    postdata = urllib.parse.urlencode().encode('utf-8')\n",
    "    request = urllib.request.Request(url=url + urllib.parse.quote(wd), headers=headers)  # 定义请求对象\n",
    "    response = urllib.request.urlopen(request, timeout=15)  # take a time发送请求\n",
    "    # url = ur.Request('http://ac.scmor.com/')\n",
    "    # url.add_data('a','1')\n",
    "    # url.add_header('User-Agent','Mozilla/5.0')\n",
    "    # urllib.request.urlretrieve('https://www.baidu.com','baidu.html')直接将百度页面的html保存到文件中\n",
    "    # urllib.request.urlcleanup()清除缓存\n",
    "    html = response.read()  # 300 words\n",
    "    print(html.decode('utf-8')) \n",
    "    # print(response.getcode())print(response.info())print(response.geturl())\n",
    "    # print(cj)\n",
    "    response.close()\n",
    "except urllib.error.URLError as e:\n",
    "    if hasattr(e, 'code'):\n",
    "        print(e.code)\n",
    "    elif hasattr(e, 'reason'):\n",
    "        print(e.reason)\n",
    "```"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "## requests\n",
    "+ 拟爬取: [your name的图片](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1580960249421&di=fc1d6365ad60bdc379752936d2aec931&imgtype=0&src=http%3A%2F%2Fhbimg.b0.upaiyun.com%2F4b742d8ba786c6d7041278073633b396150d779a32e86-705oar_fw658) 并利用numpy修改图片灰度值\n",
    "\n",
    "* ![your name](https://ss0.bdstatic.com/94oJfD_bAAcT8t7mm9GUKT-xh_/timg?image&quality=100&size=b4000_4000&sec=1581990576&di=a0c074ab281601ca59a581f660e3823a&src=http://cdn.vox-cdn.com/thumbor/3gx7OvAytfYj70moLh8Kax-1eDw=/0x0:1920x1080/1200x0/filters:focal(0x0:1920x1080):no_upscale()/cdn.vox-cdn.com/uploads/chorus_asset/file/8303383/yournamecomet.jpg)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Analysis\n",
    "## numpy,scipy,pandas,matploblib,seaborn\n",
    "## plotly 是 github 上面的动态图像处理项目 在后端绘制  兼容matplotlib和pandas \n",
    "\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [],
   "source": [
    "import random\n",
    "user_agent=['Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50',\n",
    "'Mozilla/5.0(compatible;MSIE9.0;WindowsNT6.1;Trident/5.0',\n",
    "'Mozilla/4.0(compatible;MSIE8.0;WindowsNT6.0;Trident/4.0)',\n",
    "'Mozilla/5.0(Macintosh;IntelMacOSX10.6;rv:2.0.1)Gecko/20100101Firefox/4.0.1',\n",
    "'Mozilla/5.0(Macintosh;IntelMacOSX10_7_0)AppleWebKit/535.11(KHTML,likeGecko)Chrome/17.0.963.56Safari/535.11',\n",
    "'Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Maxthon2.0)',\n",
    "'Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;TencentTraveler4.0)',\n",
    "'Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Trident/4.0;SE2.XMetaSr1.0;SE2.XMetaSr1.0;.NETCLR2.0.50727;SE2.XMetaSr1.0)',\n",
    "'Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;360SE)',\n",
    "'Mozilla/5.0(Macintosh;U;IntelMacOSX10_6_8;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50']\n",
    "headers={'user-agent':random.choice(user_agent),'Host':'timgsa.baidu.com',\n",
    "         'Accept':'text/plain, */*; q=0.01', # 一般不写accept 以防接收到的文件受限\n",
    "'Accept-Language':'zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2',\n",
    "'Accept-Encoding':'gzip, deflate, br',\n",
    "'Referer':'https://www.baidu.com/index.php?tn=monline_3_dg',\n",
    "'X-Requested-With':'XMLHttpRequest','Connection':'keep-alive'}"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {},
   "outputs": [],
   "source": [
    "class get_proxies:\n",
    "    proxies = [{\"https\": \"https://222.95.144.120:3000\"},\n",
    "               {\"https\": \"https://175.42.122.109:9999\"}]\n",
    "\n",
    "    def __init__(self, num):\n",
    "        self.main(num)\n",
    "\n",
    "    def xici_ip(self, page):\n",
    "        for num_page in range(1, page + 1):\n",
    "            url_part = \"https://www.xicidaili.com/wn/\"\n",
    "            # 爬取西刺代理的IP，此处选的是国内https\n",
    "            # 构建爬取的页面URL\n",
    "            url = url_part + str(num_page)\n",
    "            r = requests.get(url, headers={'User-Agent': random.choice(user_agent)})\n",
    "            r.raise_for_status()\n",
    "            soup = BeautifulSoup(r.text, 'lxml')\n",
    "            trs = soup.find_all('tr')\n",
    "            for i in range(1, len(trs)):\n",
    "                tr = trs[i]\n",
    "                tds = tr.find_all('td')\n",
    "                ip_item = tds[1].text + ':' + tds[2].text\n",
    "                # print('抓取第'+ str(page) + '页第' + str(i) +'个：' + ip_item)\n",
    "                self.proxies.append({'HTTPS': 'HTTPS://' + ip_item})\n",
    "            #                 time.sleep(1)\n",
    "            print('存储成功')\n",
    "\n",
    "    def check_ip(self):\n",
    "        try:\n",
    "            headers = {'user-agent': random.choice(user_agent)}\n",
    "            for item in self.proxies:\n",
    "                r = requests.get('http://httpbin.org/ip', headers=headers,\n",
    "                                 proxies=item)\n",
    "                r.raise_for_status()\n",
    "                r.encoding = r.apparent_encoding\n",
    "                if not r.json()['origin'].split(',')[0] == '125.80.138.167':\n",
    "                    self.proxies.remove(item)\n",
    "                    print('获取IP无效')\n",
    "        except Exception as e:\n",
    "            print(e)\n",
    "\n",
    "    def main(self, n):\n",
    "        self.xici_ip(n)  # 抓取第n页，一页100个url\n",
    "        try:\n",
    "            self.check_ip()\n",
    "        except Exception as e:\n",
    "            print(e)\n",
    "            self.check_ip()\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 4,
   "metadata": {
    "collapsed": true
   },
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "存储成功\n",
      "[<Element div at 0x1b6f4645d48>]\n",
      "http://img62.ddimg.cn/digital/product/49/70/1960444970_ii_cover.jpg?version=937f9e9d-b66b-48de-860d-941449b0c655\n",
      "http://img62.ddimg.cn/digital/product/40/22/1960154022_ii_cover.jpg?version=17505b87-ef31-429f-b94a-a79c4bf8d6c9\n",
      "http://img62.ddimg.cn/digital/product/36/45/1960183645_ii_cover.jpg?version=e23ee3ba-69e0-48e2-bd4a-8c7c6965b070\n",
      "http://img60.ddimg.cn/digital/product/80/29/1960408029_ii_cover.jpg?version=2f96b74c-c9d0-4b6d-8d06-154be75c759d\n",
      "http://img62.ddimg.cn/digital/product/82/44/1960408244_ii_cover.jpg?version=ce52053a-02a2-494c-83e4-e35b02eb134e\n",
      "http://img62.ddimg.cn/digital/product/51/37/1960455137_ii_cover.jpg?version=3b68dd5e-4c53-48bb-8c9d-b435fab8ed05\n",
      "http://img62.ddimg.cn/digital/product/43/44/1960404344_ii_cover.jpg?version=689e94ff-d852-400b-a009-82e1afc4d862\n",
      "http://img62.ddimg.cn/digital/product/94/30/1960459430_ii_cover.jpg?version=e71aa627-44b3-43d0-aacf-dd47e1bafa76\n",
      "http://img62.ddimg.cn/digital/product/48/10/1960404810_ii_cover.jpg?version=55a8d6b1-4152-449d-94de-d4305247ecb4\n",
      "http://img60.ddimg.cn/digital/product/25/2/1960452502_ii_cover.jpg?version=481be49e-8706-4c06-bbde-ff64c6c9047e\n",
      "http://img61.ddimg.cn/digital/product/58/30/1960455830_ii_cover.jpg?version=34c214a8-9941-47eb-88b1-18ae4e5d2e36\n",
      "http://img62.ddimg.cn/digital/product/10/38/1960181038_ii_cover.jpg?version=f56a7b62-0063-4e3e-9789-06dc6fb5c654\n",
      "http://img61.ddimg.cn/digital/product/29/69/1960392969_ii_cover.jpg?version=e13f02a1-f221-408b-8377-1f53361c9111\n",
      "http://img62.ddimg.cn/digital/product/43/57/1960084357_ii_cover.jpg?version=bc2d4b04-1b02-40d2-9480-adb8145f0272\n",
      "http://img61.ddimg.cn/digital/product/80/10/1960408010_ii_cover.jpg?version=3d9a29c9-bc85-42cf-afa0-5989591f8736\n",
      "http://img62.ddimg.cn/digital/product/20/30/1960152030_ii_cover.jpg?version=0b9625df-0e78-4b04-a587-117fa530dfa2\n",
      "http://img61.ddimg.cn/digital/product/26/71/1960442671_ii_cover.jpg?version=290eb2bc-b887-48bc-acb4-b71cdfba5f15\n",
      "http://img62.ddimg.cn/digital/product/18/23/1960401823_ii_cover.jpg?version=8ddc36bc-c7af-4034-b54b-8c5a333e856b\n",
      "http://img61.ddimg.cn/digital/product/80/21/1960408021_ii_cover.jpg?version=7e0a2ed1-4c21-4329-bdfd-e2a025f2df24\n",
      "http://img61.ddimg.cn/digital/product/19/3/1960071903_ii_cover.jpg?version=c385b4ae-0fe4-4323-b9de-3f27a5844254\n",
      "http://img61.ddimg.cn/digital/product/24/75/1960072475_ii_cover.jpg?version=33d6c65c-13b5-4184-82af-3eb88a1d575d\n"
     ]
    }
   ],
   "source": [
    "from lxml import etree\n",
    "url = 'http://e.dangdang.com/new_original_index_page.html'\n",
    "headers = {'user-agent':random.choice(user_agent),'Host':'img61.ddimg.cn'}\n",
    "proxies_2 = get_proxies(1)\n",
    "response = requests.request(\"get\",url,headers=headers,\n",
    "                            proxies=random.choice(proxies_2.proxies))\n",
    "response.raise_for_status()\n",
    "response.encoding = response.apparent_encoding\n",
    "html = etree.HTML(response.text)\n",
    "basic_url = html.xpath('/html/body/div[5]/div[1]/div[1]/div[1]/ul/li[2]/a/@href')[0]\n",
    "url2 = \"http://e.dangdang.com\"+basic_url[1:]\n",
    "print(url2)\n",
    "headers = {'user-agent':random.choice(user_agent),'Host':'img61.ddimg.cn'}\n",
    "response = requests.request(\"get\",url2,headers=headers,\n",
    "                            proxies=random.choice(proxies_2.proxies))\n",
    "response.raise_for_status()\n",
    "html2 = etree.HTML(response.text)\n",
    "print(html2.xpath('//*[@id=\"book_list\"]')) # js动态生成的网址爬不到\n",
    "\n",
    "# 需要基础抓包分析\n",
    "# 观察F12中的XHR类型文件的响应(response)是否符合动态生成的内容\n",
    "url = 'http://e.dangdang.com/media/api.go?action=mediaCategoryLeaf&promotionType=1&deviceSerialNo=html5&macAddr=html5&channelType=html5&permanentId=20200204092203962235681531963345504&returnType=json&channelId=70000&clientVersionNo=5.8.4&platformSource=DDDS-P&fromPlatform=106&deviceType=pconline&token=&start=0&end=20&category=KHLY&dimension=sale'\n",
    "headers = {'user-agent':random.choice(user_agent),'Host':'e.dangdang.com'}\n",
    "response = requests.request(\"get\",url,headers=headers,\n",
    "                            proxies=random.choice(proxies_2.proxies))\n",
    "response.raise_for_status()\n",
    "for i in range(21):\n",
    "    print(response.json()['data'].get('saleList')[i]['mediaList'][0]['coverPic'])\n",
    "    # json.loads(response.text) # json==>python\n",
    "    # json.dump(response.text,open('json.txt','w',encoding = 'utf-8'))\n",
    "    # json.load(open('json.txt','r',encoding='utf-8')) # 从文件中读取json==>python"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "from selenium import webdriver\n",
    "# 调用键盘按键操作时需要引入的Keys包\n",
    "from selenium.webdriver.common.keys import Keys\n",
    "\n",
    "profile = webdriver.FirefoxProfile()\n",
    "profile.set_preference('network.proxy.type', 1)\n",
    "profile.set_preference('network.proxy.http', '120.83.107.146')\n",
    "profile.set_preference('network.proxy.http_port', 9999)  # int\n",
    "profile.update_preferences()\n",
    "# 如果没有配置环境变量 则需指定Firefox位置\n",
    "driver = webdriver.Firefox(executable_path=\"\",firefox_profile=profile)\n",
    "driver.get('http://httpbin.org/ip')\n",
    "\n",
    "driver.get(\"http://www.baidu.com/\")\n",
    "# 获取页面名为 wrapper的id标签的文本内容\n",
    "data = driver.find_element_by_id(\"wrapper\").text\n",
    "# 生成当前页面快照并保存\n",
    "driver.save_screenshot(\"baidu.png\")\n",
    "# id=\"kw\"是百度搜索输入框，输入字符串\"长城\"\n",
    "driver.find_element_by_id(\"kw\").send_keys(u\"长城\")\n",
    "# id=\"su\"是百度搜索按钮，click() 是模拟点击\n",
    "driver.find_element_by_id(\"su\").click()\n",
    "# 获取新的页面快照\n",
    "driver.save_screenshot(\"长城.png\")\n",
    "# 清除输入框内容\n",
    "driver.find_element_by_id(\"kw\").clear()\n",
    "# 输入框重新输入内容\n",
    "driver.find_element_by_id(\"kw\").send_keys(\"itcast\")\n",
    "# 模拟Enter回车键\n",
    "driver.find_element_by_id(\"su\").send_keys(Keys.RETURN)\n",
    "\n",
    "# 打印网页渲染后的源代码\n",
    "print(driver.page_source)\n",
    "# 获取当前页面Cookie\n",
    "print(driver.get_cookies())\n",
    "# 打印页面标题 \"百度一下，你就知道\"\n",
    "print(driver.title)\n",
    "# 获取当前url\n",
    "print(driver.current_url)\n",
    "\n",
    "# ctrl+a 全选输入框内容\n",
    "driver.find_element_by_id(\"kw\").send_keys(Keys.CONTROL,'a')\n",
    "\n",
    "# ctrl+x 剪切输入框内容\n",
    "driver.find_element_by_id(\"kw\").send_keys(Keys.CONTROL,'x')\n",
    "\n",
    "# find_element_by_id\n",
    "# find_elements_by_name\n",
    "# find_elements_by_link_text\n",
    "# find_elements_by_partial_link_text\n",
    "# find_elements_by_tag_name\n",
    "# find_elements_by_class_name\n",
    "# find_elements_by_css_selector\n",
    "# find_elements_by_xpath # 输入xpath匹配\n",
    "\n",
    "# 关闭当前页面，如果只有一个页面，会关闭浏览器\n",
    "# driver.close()\n",
    "\n",
    "# 关闭浏览器\n",
    "driver.quit()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "# 配置环境变量的时候需要 配置tessdata 的位置\n",
    "from pytesseract import *\n",
    "from PIL import Image\n",
    "image = Image.open(\"XXX.png\") # 打开图片文件\n",
    "text = image_to_string(image) # 调用函数图片转字符串\n",
    "print(text)\n",
    "img = image.convert('L')\n",
    "img.show()\n",
    "threshold = 140\n",
    "table = list()\n",
    "for a in range(256):\n",
    "    if a < threshold:\n",
    "        table.append(0)\n",
    "    else:\n",
    "        table.append(1)\n",
    "out = img.point(table,'1')\n",
    "out.show()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "import unittest\n",
    "from selenium import webdriver\n",
    "\n",
    "class douyu(unittest.TestCase):\n",
    "    def setUp(self):\n",
    "        # 初始化无头浏览器\n",
    "        self.driver = webdriver.Firefox(executable_path=\"\",firefox_profile=profile)\n",
    "    def testXX(self):\n",
    "        self.driver.get(\"XXX\")\n",
    "        while True:\n",
    "            if self.driver.page_source.find(\"XXX\") != -1:\n",
    "                break\n",
    "            self.driver.find_element_by_xpath(\"XXX\").click()\n",
    "    def tearDown(self):\n",
    "        self.driver.quit()\n",
    "if __name__ == \"__main__\":\n",
    "    unittest.main()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 10,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "[<Element div at 0x23a4d18b4c8>]\n"
     ]
    }
   ],
   "source": [
    "from lxml import etree\n",
    "start_url = \"https://www.bilibili.com\"\n",
    "'''\n",
    "User-agent: *\n",
    "Disallow: /include/\n",
    "Disallow: /mylist/\n",
    "Disallow: /member/\n",
    "Disallow: /images/\n",
    "Disallow: /ass/\n",
    "Disallow: /getapi\n",
    "Disallow: /search\n",
    "Disallow: /account\n",
    "Disallow: /badlist.html\n",
    "Disallow: /m/\n",
    "'''\n",
    "kw = {\"user-agent\":random.choice(user_agent),'Host':'message.bilibili.com'}\n",
    "try:\n",
    "    response1 = requests.request('get',start_url,headers = kw,\n",
    "                                 proxies = random.choice(proxies_2.proxies))\n",
    "    response1.raise_for_status()\n",
    "    response1.encoding = response1.apparent_encoding\n",
    "except Exception as e:\n",
    "    print(str(e))\n",
    "html1 = etree.HTML(response1.text)\n",
    "print(html1.xpath('/html/body/div[2]'))\n",
    "url2 = \"https://www.bilibili.com/video/av45394845?p=81\""
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "存储成功\n",
      "存储成功\n",
      "(370, 658) float64\n"
     ]
    }
   ],
   "source": [
    "url = 'https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1580960249421&di=fc1d6365ad60bdc379752936d2aec931&imgtype=0&src=http%3A%2F%2Fhbimg.b0.upaiyun.com%2F4b742d8ba786c6d7041278073633b396150d779a32e86-705oar_fw658'\n",
    "response = requests.request(\"get\",url,headers=headers,\n",
    "                            proxies=random.choice(get_proxies(2).proxies))\n",
    "response.raise_for_status()\n",
    "response.encoding = response.apparent_encoding\n",
    "#response.text  response.content.decode('utf-8')\n",
    "direct = 'c:/Users/向致承/Desktop/'\n",
    "open(direct+'your_name.jpg','wb').write(response.content)\n",
    "open(direct+'your_name2.jpg','wb').write(response.content)\n",
    "#RGB色彩模式(0-255),需要PIL库,pip install pillow\n",
    "from PIL import Image\n",
    "import numpy\n",
    "im = numpy.array(Image.open(direct+'your_name2.jpg').convert('L')).astype('float') \n",
    "#convert成灰度图片,在转换可得黑白图\n",
    "print(im.shape,im.dtype) #图像由三维数组表示,高度，宽度，像素RGB\n",
    "depth = 10\n",
    "grad = numpy.gradient(im)\n",
    "grad_x ,grad_y = grad\n",
    "grad_x = grad_x * depth/100\n",
    "grad_y = grad_y * depth/100\n",
    "A = numpy.sqrt(grad_x**2 + grad_y**2 +1)\n",
    "uni_x = grad_x/A\n",
    "uni_y = grad_y/A\n",
    "uni_z = 1/A\n",
    "vec_el = numpy.pi/2.2\n",
    "vec_az = numpy.pi/4\n",
    "dx  = numpy.cos(vec_el)*numpy.cos(vec_az)\n",
    "dy = numpy.cos(vec_el)*numpy.sin(vec_az)\n",
    "dz = numpy.sin(vec_el)\n",
    "b = 255*(dx*uni_x + dy*uni_y + dz*uni_z)\n",
    "a = b.clip(0,255)\n",
    "# a = 255 - im #换成黑白图\n",
    "# a = (100/255)*im + 150 # 区间变换\n",
    "# a = 255 * (a/255)**2 #像素平方\n",
    "im = Image.fromarray(a.astype('uint8'))\n",
    "im.save(direct+'your_name2.jpg')"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* json    信息有类型，适合程序处理，较xml简洁，无注释，一般用在程序对接口的部分\n",
    "* YAML  信息无类型，文本信息比例最高，可读性好，用于各类系统的配置文件，有注释易读\n",
    "* xml  最早的通用信息标记语言，可扩展性好但繁琐，用于Internet上的信息交互与传递\n",
    "## jsonpath(json path)\n",
    "* [参考blog](https://blog.csdn.net/luxideyao/article/details/77802389)\n",
    "* [参考视频-千峰1](https://www.bilibili.com/video/av45394845?p=55)\n",
    "* [参考视频-传智播客](https://www.bilibili.com/video/av62303270?p=22)\n",
    "* [参考视频-千峰2](https://www.bilibili.com/video/av76899389?p=20)"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "collapsed": true
   },
   "source": [
    "# re\n",
    "+ [在线验证正则:regex](https://regex101.com/)\n",
    "\n",
    "```python\n",
    "import re\n",
    "# 模式修正符flags=\n",
    "# A 使转义字符\\w,\\b,\\s,\\d只能匹配ASCII字符\n",
    "# I 匹配时忽略大小写\n",
    "# M 多行匹配 影响 ^$\n",
    "# L 本地化识别匹配,支持当前的地区语言\n",
    "# U 根据Unicode字符集解析字符。这个标志影响 \\w, \\W, \\b, \\B.\n",
    "# S 让.匹配包括换行符\n",
    "# X 该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。\n",
    "print(re.search('Pyt', 'python', re.I).group(0))  # pyt\n",
    "print(re.search('Pyt', 'python', re.I).start())  # 0\n",
    "print(re.search('Pyt', 'python', re.I).end())  # 3\n",
    "print(re.search('Pyt', 'python', re.I).span())  # (0,3)\n",
    "print(re.search('Pyt', 'python', re.I).string)  # python\n",
    "print(re.search('Pyt', 'python', re.I).re)  # re.compile(r'Pyt', re.UNICODE)\n",
    "print(re.search('Pyt', 'python', re.I).pos)  # 0\n",
    "print(re.search('Pyt', 'python', re.I).endpos)  # 6\n",
    "\n",
    "print(re.split(r'\\d', '123abc', maxsplit=1, flags=re.U))  # ['', '23abc']\n",
    "# 将字符按照正则表达式进行分割,此处匹配到的数字会被切掉,超出最大分割数的部分作为最后一个元素被输出\n",
    "re.findall(r'\\d', 'iloveyou531tosimida')  # 规则,字符串,['5','3','1']\n",
    "# 当使用转义字符时在前面加个'r'若使用string模块则需要用\\\\d表示\\d\n",
    "re.findall(r'\\d{3}', 'iloveyou531tosimida')  # ['531']\n",
    "print(next(re.finditer(r'\\d', 'iiii44ii')))  # 只能看到第一个\n",
    "print(list(re.finditer(r'\\d', 'iirr44rr4')))  # 可以看到一个对象列表\n",
    "print(next(re.finditer(r'44', 'iiii44ii')))\n",
    "for i in re.finditer(r'44', 'iiii44ii'):\n",
    "    print(i.group(), re.S)\n",
    "res = re.match(r'ilove', 'iloveyou', flags=0)  # 从头开始匹配只匹配开头一次,返回None或者match对象,flags=0表示单行匹配\n",
    "print(res, res.group(), res.span())  # group返回字符串,span返回下标\n",
    "rep = re.search(r'love', 'iloveyou', flags=0)\n",
    "# 不从头开始匹配 只匹配一次,返回None或者match对象,flags=0表示单行匹配\n",
    "print(bool(re.sub(r'\\d', 'i', '2loveyou', count=1) == re.sub(r'\\d{2}', 'i', '22loveyou', count=1)))  # count代表匹配的最大替换数\n",
    "def add(temp):\n",
    "    strNum = temp.group()\n",
    "    num = int(strNum)+1\n",
    "    return str(num)\n",
    "ret = re.sub(r\"\\d+\",add,\"python = 997\")\n",
    "print(ret) #将匹配到的对象作为参数传到add函数中 再将结果替换到字符串中\n",
    "str1 = 'iloveeyou44tosimi67da'\n",
    "reg = re.compile(r'\\d{2}')\n",
    "print(reg.findall(string=str1))\n",
    "print(reg.search(str1).group())\n",
    "\n",
    "var = '\\n$_2 iloveyou5211'\n",
    "res = r'love'\n",
    "print(re.search(res, var).group())  # 'love'\n",
    "\n",
    "# \\可以解除字符的特殊功能, \\.表示匹配点号本身\n",
    "# 引用字符的ASCII码的八进制 来匹配该字符\n",
    "re.search('\\{}'.format(oct(ord('b'))[-3:]), 'b').group()  # 'b'\n",
    "# 引入1-99表示匹配字符对应的序号\n",
    "re.search(r'(fishc)\\1', 'fishcfishcfishc').group()  # 'fishcfishc'\n",
    "# '\\w' 单个字母/数字/下划线\n",
    "# '\\W' 单个非字母/非数字/非下划线\n",
    "# '\\D' 单个非十进制数字\n",
    "# '\\s' 单个的空格符/制表符\n",
    "# '\\S' 单个非空格符/非制表符\n",
    "# '\\w\\w\\w\\w\\d' 组合使用连续4个加1个数字\n",
    "# \\A 匹配字符串开始\n",
    "# \\Z 匹配字符串结束,如果是存在换行,只匹配到换行前的结束字符串。\n",
    "# \\z 匹配字符串结束\n",
    "# \\G 匹配最后匹配完成的位置。\n",
    "# \\b 匹配一个单词边界，也就是指单词和空格间的位置。例如， 'er\\b' 可以匹配\"never\" 中的 'er'，但不能匹配 \"verb\" 中的 'er'。\n",
    "# \\B 匹配非单词边界。'er\\B' 能匹配 \"verb\" 中的 'er'，但不能匹配 \"never\" 中的 'er'。\n",
    "# \\n  匹配一个换行符\n",
    "# \\t  匹配一个制表符\n",
    "print(re.search(r'\\w', var).group())  # _\n",
    "print(re.search(r'\\w{2,5}', var).group())  # 必须匹配次数的区间,返回最大次数\n",
    "print(re.search('[a-z,A-Z,0-9,_]', var).group())  # 中括号代表范围,此处等同于\\w\n",
    "# [...] 规则如下\n",
    "# 注1：连字符 - 如果出现在字符串中间表示字符范围描述；如果如果出现在首位则仅作为普通字符\n",
    "# 注2：特殊字符仅有反斜线 \\ 保持特殊含义，用于转义字符。其它特殊字符如 *、+、? 等均作为普通字符匹配\n",
    "# 注3：脱字符 ^ 如果出现在首位则表示匹配不包含其中的任意字符；如果 ^ 出现在字符串中间就仅作为普通字符匹配\n",
    "# [abc] -- a或b或c    [^abc] -- 非a非b和非c\n",
    "# pyth[^a]n -- python或pythbn...\n",
    "# pyth{:3}n -- pytn或pythn或pythhn或pythhhn \n",
    "# pyth{2,}on -- h至少2次\n",
    "# pyth{2,4}on -- h至少2次至多4次\n",
    "# ^[A-Za-z]+$ -- 任意连续个数的字母\n",
    "# ^[A-Za-z0-9]+$ -- 任意连续数字的字母或数字\n",
    "# ^-?\\d+$ -- 整数形式的字符串\n",
    "# ^[0-9]*[1-9][0-9]*+$ -- 正整数形式的字符串\n",
    "# [1-9]\\d{5} -- 中国境内邮编 6位\n",
    "# [\\u4e00-\\u9fa5] -- 匹配中文字符\n",
    "# \\d{3}-\\d{8}|\\d{4}-\\d{7} -- 电话号码\n",
    "# IP地址范围为[0-255],分成四段\n",
    "# (([1-9]?\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}([1-9]?\\d|1\\d{2}|2[0-4]\\d|25[0-5])\n",
    "print(re.search('\\w+\\d{4}', var).group())\n",
    "print(re.search('\\w+(\\d{4})', var).group())  # 返回整体匹配内容\n",
    "# ()代表子组,括号中的表达式首先作为整个正则的一部分另外会把符合小括号的内容单独提取 可以用于避免|引发的错误 规定了|发挥的范围\n",
    "# \\1...\\9  匹配第n个分组的内容。如果它经匹配。否则指的是八进制字符码的表达式。\n",
    "print(re.search(r'<(\\w*)>.*</\\1>','<h1>hahha</h1>').group())\n",
    "#\\1意思是第一个括号里面的匹配的是啥 此处就必须一样\n",
    "# 为了避免匹配序列的错误 可以将匹配字符命名\n",
    "print(re.search(r'<(?P<A>h1)>.*</(?P=A)>','<h1>hashh</h1>').group()\n",
    "# (?P<A>这里写正则表达式) 把这个分组匹配到的字符命名为A (?P=A) 再匹配这个子组的字符时就可以用A代替 而不是\\1\n",
    "print(re.search('\\w+(\\d{4})', var).groups())  # 返回小括号的匹配内容('5211',)\n",
    "print(re.search('(\\w+(\\d{4}))', var).groups())  # ('iloveyou5211', '5211')\n",
    "print(re.search('^2\\d{3}', '2345').group())  \n",
    "# ^匹配开头 $匹配结尾     \n",
    "# ^abc -- abc且在一个字符开头 abc$ -- abc且在一个字符结尾\n",
    "# '.' 任意字符除了换行符\n",
    "# '*' 代表匹配次数,可为任意次(可为0)\n",
    "# 如果符合就一直匹配直到不符合,一开始就不符合那么就返回空,任务完成\n",
    "# abc* -- ab或abc或abcc... abc+ -- abc或abcc或abccc...\n",
    "print(re.search('\\w*', ' hello').group())\n",
    "# '+' 代表匹配次数,至少匹配一次任务才算完成,如果一开始就不符合那么往后找\n",
    "# 如果一直符合就一直往后\n",
    "print(re.search('\\w+', ' hello').group())\n",
    "# '?' 拒绝贪婪,前面的要求只要达成就返回,表示前一个字符0或1次的扩展\n",
    "# ab? -- ab或abb\n",
    "print(re.search('\\w+?', 'hello world').group())  # 'h'\n",
    "print(re.search('\\w*?', 'hello world').group())  # ''\n",
    "print(re.search(r'Py??', 'pythonpython', re.I).group())  # 'p'\n",
    "print(re.findall('h|w', 'hello world'))  # ['h','w']\n",
    "print(re.compile('p.*?y').findall('python'))\n",
    "```"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "collapsed": true
   },
   "source": [
    "# bs4\n",
    "```python\n",
    "from bs4 import BeautifulSoup\n",
    "soup = BeautifulSoup(response.text,'lxml') # html.parser,xml,html5lib\n",
    "print(soup.prettify(encoding='utf-8',formatter='minimal'))#结果更美观,树形结构更为直观\n",
    "\n",
    "#soup.find_all() 可以简写成 soup()\n",
    "#soup.find() 只能找到第一个\n",
    "#soup.title soup.name\n",
    "for i in soup.find_all('a'):  #也可用在标签上\n",
    "    print(i.prettify())\n",
    "for i in soup.find_all(True,recursive = False,string = '网易云课堂'):  \n",
    "    print(i.name) #取所有的标签的名,再取所有子节点,其中满足字符要求的部分\n",
    "    print(i.text) #print(i.get_text())\n",
    "#for i in soup.find_all('a',target=\"_blank\")\n",
    "#for i in soup.find_all('a','_blank')\n",
    "#for i in soup.find_all('a',target=re.compile('link')) \n",
    "#正则表达式可以检索包含link的字符串\n",
    "\n",
    "#find_parents() find_parent() find_next_siblings()\n",
    "#find_next_sibling() find_previous_siblings() find_previous_sibling()\n",
    "tag = soup.a #只能获得第一个a标签 等同于 tag = soup.find('a')\n",
    "print(tag,tag.name,tag.parent.name,tag.parent.parent.name) #父类标签\n",
    "print(tag.attrs) #所有属性,返回字典类对象\n",
    "print(tag.attrs['href'])\n",
    "tag2 = soup.p\n",
    "print(tag2.string) #返回字符内容,若为注释则返回一个注释类型\n",
    "print(tag2.comment) #注释内容\n",
    "#下行遍历\n",
    "len(soup.body.contents)\n",
    "'''\n",
    "for i in soup.body.children:\n",
    "    print(i)\n",
    "    \n",
    "for i in soup.body.descendants:\n",
    "    print(i)\n",
    "'''\n",
    "#上行遍历\n",
    "for i in soup.title.parents:  #遍历所有的父标签\n",
    "    if i is None:   #遍历到soup本身时会返回None\n",
    "        print(i)\n",
    "    else:\n",
    "        print(i.name)\n",
    "#平行遍历必须发生在同一个父节点下\n",
    "print(soup.a.next_sibling.next_sibling)\n",
    "print(soup.a.previous_sibling)\n",
    "for i in soup.head.next_siblings:  #遍历所有后续节点\n",
    "    print(i)\n",
    "for i in soup.a.previous_siblings:  #遍历所有前续节点\n",
    "    print(i)\n",
    "\n",
    "r = soup.select('title')#获取所有含有'title'属性的标签，返回一个列表\n",
    "print(r[0].text)\n",
    "for i in r:\n",
    "    print(i['con']) # 打印所有title值为con的标签\n",
    "    infos = list(i.stripped_strings) # 返回纯文本列表\n",
    "    print(infos)\n",
    "print(soup.select('.container'))#获取所有类中class属性为container的类，返回一个列表\n",
    "print(soup.select(\"tr[class='container']\") # 所有class属性为container的tr标签\n",
    "print(soup.select('#btnCloseUpdateBrowser'))#id=btnCloseUpdateBrowser的类，返列表\n",
    "print(soup.select('html body a'))#html里面的body里面的a标签\n",
    "print(soup.select('p,title'))#所有含p或title的标签\n",
    "```"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {
    "collapsed": true
   },
   "source": [
    "# xpath (xml path)\n",
    "```python\n",
    "from lxml import etree\n",
    "# html = etree.parse(source='text.html', etree.HTMLParser(encoding='utf-8')) \n",
    "# 从文件中读取 解析器默认为xml 此处设为html解析器\n",
    "html = etree.HTML(response.text)\n",
    "print(html.xpath('/html/body/script[1]/text()')) #此处索引从1开始\n",
    "print(html.xpath('/html/head/meta[@name=\"keywords\"]/@content'))\n",
    "print(html.xpath('/html/body/script[1]/text()'))\n",
    "# print(html.xpath('/html/body/script/text()'));print(html.xpath('//script/text()'))\n",
    "print(html.xpath('//div[@class=\"browser-edition-tip\"]/span/text()'))\n",
    "print(html.xpath('//*[@class=\"browser-edition-tip\"]/span/text()'))  # *代表所有标签\n",
    "a = html.xpath('//div[starts-with(@class,\"browser-edition-tip\")]')  \n",
    "# class属性以dictionary开头的div属性中的text\n",
    "for i in a:\n",
    "    if len(i.xpath('//a/text()')) != 0:\n",
    "        print(i.xpath('//a/@class'))\n",
    "print(html.xpath('//span/text()'))  # 只能获得span属性下的text\n",
    "print(html.xpath('string(//span)').replace(' ', '').replace('\\n', ''))  \n",
    "# 可以获得包括span子属性的text\n",
    "# result = etree.tostring(html)\n",
    "# print(result.decode('utf-8'))\n",
    "```"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# scrapy\n",
    "* pip install scrapy 可能需要开个VPN;另外还需安装(PFW里面) Twisted\n",
    "* scrapy fetch --nolog （http://www.evenyan.com/post/6） 最简单的爬取网站\n",
    "* scrapy startproject 创建项目后加项目名\n",
    "* scrapy genspider 生成爬虫文件后加文件名和要爬取的域名\n",
    "* scrapy genspider -l 查看爬虫模板 后加爬虫文件名和域名\n",
    "* scrapy runspider 运行爬虫\n",
    "* scrapy settings --get botname 显示配置\n",
    "* scrapy crawl 运行爬虫后加爬虫名\n",
    "* scrapy crawl book -o book.json/book.jsonl/book.csv/book.xml 输出不同格式的文件\n",
    "* scrapy shell  --nolog 调试工具后加域名\n",
    "* scrapy view 在浏览器打开某个网页\n",
    "* scrapy check 检查爬虫是否合格"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# Python标准异常总结,由于异常的传递性,只在主程序捕获异常\n",
    "\n",
    "* AssertionError\t断言语句（assert）失败\n",
    "* AttributeError\t尝试访问未知的对象属性\n",
    "* EOFError\t用户输入文件末尾标志EOF（Ctrl+d）\n",
    "* FloatingPointError\t浮点计算错误\n",
    "* GeneratorExit\tgenerator.close()方法被调用的时候\n",
    "* ImportError\t导入模块失败的时候\n",
    "* IndexError\t索引超出序列的范围\n",
    "* KeyError\t字典中查找一个不存在的关键字\n",
    "* KeyboardInterrupt\t用户输入中断键（Ctrl+c）\n",
    "* MemoryError\t内存溢出（可通过删除对象释放内存）\n",
    "* NameError\t尝试访问一个不存在的变量\n",
    "* NotImplementedError\t尚未实现的方法\n",
    "* OSError\t操作系统产生的异常（例如打开一个不存在的文件）\n",
    "* OverflowError\t数值运算超出最大限制\n",
    "* ReferenceError\t弱引用（weak reference）试图访问一个已经被垃圾回收机制回收了的对象\n",
    "* RuntimeError\t一般的运行时错误\n",
    "* StopIteration\t迭代器没有更多的值\n",
    "* SyntaxError\tPython的语法错误\n",
    "* IndentationError\t缩进错误\n",
    "* TabError\tTab和空格混合使用\n",
    "* SystemError\tPython编译器系统错误\n",
    "* SystemExit\tPython编译器进程被关闭\n",
    "* TypeError\t不同类型间的无效操作\n",
    "* UnboundLocalError\t访问一个未初始化的本地变量（NameError的子类）\n",
    "* UnicodeError\tUnicode相关的错误（ValueError的子类）\n",
    "* UnicodeEncodeError\tUnicode编码时的错误（UnicodeError的子类）\n",
    "* UnicodeDecodeError\tUnicode解码时的错误（UnicodeError的子类）\n",
    "* UnicodeTranslateError\tUnicode转换时的错误（UnicodeError的子类）\n",
    "* ValueError\t传入无效的参数\n",
    "* ZeroDivisionError\t除数为零\n",
    "\n",
    "## 以下是 Python 内置异常类的层次结构：\n",
    "\n",
    "### BaseException\n",
    "*  SystemExit\n",
    "*  KeyboardInterrupt\n",
    "*  GeneratorExit\n",
    "*  Exception # 捕获未知异常\n",
    "  * > StopIteration\n",
    "  * > ArithmeticError\n",
    "    > * FloatingPointError\n",
    "    > * OverflowError\n",
    "    > * ZeroDivisionError\n",
    "  * > AssertionError\n",
    "  * > AttributeError\n",
    "  * > BufferError\n",
    "  * > EOFError\n",
    "  * > ImportError\n",
    "  * > LookupError\n",
    "    > * IndexError\n",
    "    > * KeyError\n",
    "  * > MemoryError\n",
    "  * > NameError\n",
    "    > * UnboundLocalError\n",
    "  * > OSError\n",
    "    > * BlockingIOError\n",
    "    > * ChildProcessError\n",
    "    > * ConnectionError\n",
    "    > * BrokenPipeError\n",
    "    > * ConnectionAbortedError\n",
    "    > * ConnectionRefusedError\n",
    "    > * ConnectionResetError\n",
    "    > * FileExistsError\n",
    "    > * FileNotFoundError\n",
    "    > * InterruptedError\n",
    "    > * IsADirectoryError\n",
    "    > * NotADirectoryError\n",
    "    > * PermissionError\n",
    "    > * ProcessLookupError\n",
    "    > * TimeoutError\n",
    "  * > ReferenceError\n",
    "  * > RuntimeError\n",
    "    > * NotImplementedError\n",
    "  * > SyntaxError\n",
    "    > * IndentationError\n",
    "    > * TabError\n",
    "  * > SystemError\n",
    "  * > TypeError\n",
    "  * > ValueError\n",
    "    > * UnicodeError\n",
    "    + UnicodeDecodeError\n",
    "    + UnicodeEncodeError\n",
    "    + UnicodeTranslateError\n",
    "  * > Warning\n",
    "    + DeprecationWarning\n",
    "    + PendingDeprecationWarning\n",
    "    + RuntimeWarning\n",
    "    + SyntaxWarning\n",
    "    + UserWarning\n",
    "    + FutureWarning\n",
    "    + ImportWarning\n",
    "    + UnicodeWarning\n",
    "    + BytesWarning\n",
    "    + ResourceWarning"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "# python\n",
    "```python\n",
    "if action in ['1','2','3']:\n",
    "if action == '1' or action == '2' or action == '3':\n",
    "```\n",
    "* 将复杂的条件多行化\n",
    "```python\n",
    "for a in range(10):\n",
    "    if ((a<3)\n",
    "        or (a>8)):\n",
    "        print(a)\n",
    "```\n",
    "* TODO注释 在井号后面空一格 输入TODO 之后在任意地方点击下方TODO窗口可以回到该行注释\n",
    "\n",
    "### [tkinter--小甲鱼GUI](https://www.bilibili.com/video/av4050443?p=65)\n",
    "\n",
    "```python\n",
    "import tkinter\n",
    "\n",
    "fm_main = tkinter.Tk()  # 创建一个窗口\n",
    "\n",
    "ent = tkinter.Entry(fm_main)  # 指定这个entry控件显示在fm_main上,Entry只是单行文本框\n",
    "ent.pack()  # pack的上下关系体现了在窗口中的上下关系\n",
    "\n",
    "ent1 = tkinter.Entry(fm_main)\n",
    "\n",
    "ent2 = tkinter.Text(fm_main)  # Text是多行文本框\n",
    "\n",
    "\n",
    "def hello():\n",
    "    ent_str = ent.get()\n",
    "    ent1.insert(index='end', string='你好,' + ent_str + ',欢迎回家!')\n",
    "    ent2.insert('end', 'hello,' + ent_str + ',welcome back!')\n",
    "    print(ent2.get(index1=1.0, index2=\"end\"))  # 从第1行第1个字开始一直读到最后\n",
    "\n",
    "\n",
    "btn = tkinter.Button(fm_main, text='press here', command=hello)  # 创建一个按钮\n",
    "btn.pack()\n",
    "\n",
    "ent1.pack()\n",
    "ent2.pack()\n",
    "\n",
    "fm_main.mainloop()\n",
    "```\n",
     ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "D:\\python\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "['6-26NOTE.py', '6-26NOTE2.py', 'day04_回归法选股策略.py', 'day04_打分法选股策略.py']"
      ]
     },
     "execution_count": 7,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "import shutil\n",
    "#shutil.copyfile('data.db', 'archive.db')\n",
    "#shutil.move('/build/executables', 'installdir')\n",
    "import glob\n",
    "glob.glob('*.py')\n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "人生苦短\n",
      "生命苦短\n",
      "False\n",
      "1.0 2.0\n",
      "I am (1+2j) years old\n",
      "--12,345\n",
      "0.333\n",
      "___hello___\n",
      "i love fishc.com\n",
      "i love fishc.com\n",
      "i love fishc.com\n",
      "hhh\n",
      "{0}\n",
      "17.770000gb\n",
      "a b c\n",
      "i love you\n",
      "4 + 5 = 9\n",
      "divmod(8,5) = 8//5,8%5 (1, 3)\n",
      "pow(2,3)=2^3=**8** and pow(2,3,8)=2^3//8=0****\n",
      "(round(3.5))4.00 is 2 times of (round(2.5)2.00\n",
      "round(4.444,2)=4.44\n",
      "a is a\n",
      "abs(-2) =  2\n",
      "True\n",
      "True\n",
      "0o10=10 and 0x10=10 and 10=0b10\n",
      "0b1010= 10\n",
      "0o10=0o10=oct(8)\n",
      "0x10=0x10=hex(16)\n",
      "0b10=0b10=bin(2)\n",
      "========test========\n",
      "test\n",
      "TEST\n",
      "es\n",
      "t　e　s　t\n",
      "3\n"
     ]
    }
   ],
   "source": [
    "str1 = '人生苦短'\n",
    "b1 = bytearray(str1.encode())\n",
    "print(b1.decode())\n",
    "b1[:6] = bytearray('生命'.encode()) # bytearray类型支持切片修改 而bytes类型不支持修改\n",
    "print(b1.decode())\n",
    "\n",
    "print(0.2+0.1==0.3)\n",
    "a = 1+2j\n",
    "print(a.real,a.imag)\n",
    "print(f'I am {a} years old')\n",
    "print('{:->8,}'.format(12345))  # 逗号为千位符\n",
    "print('{0:.3f}'.format(1.0/3))\n",
    "print("{:\"^30x}".format(16)) # \为字母小写\n",
    "print('{0:_^11}'.format('hello'))\n",
    "print('{0} love {1}.{2}'.format('i','fishc','com'))\n",
    "print('{a} love {b}.{c}'.format(a='i',b='fishc',c='com'))\n",
    "print('{0} love {b}.{c}'.format('i',b='fishc',c='com'))\n",
    "print('{0}'.format('hhh'))\n",
    "print('{{0}}'.format('hhh'))\n",
    "print('{0:1f}{1}'.format(17.77,'gb'))\n",
    "print('%c %c %c'%(97,98,99))\n",
    "print('%s'%'i love you')\n",
    "print('%d + %d = %d'% (4,5,4+5))\n",
    "print('divmod(8,5) = 8//5,8%5', divmod(8, 5))\n",
    "print('pow(2,3)=2^3={0:*^5d} and pow(2,3,8)=2^3//8={1:*<5d}'.format(pow(2, 3),pow(2, 3, 4)))\n",
    "print('(round(3.5)){0:.2f} is 2 times of (round(2.5){1:.2f}'.format(round(3.5), round(2.5)))\n",
    "print('round(4.444,2)={0}'.format(round(4.444, 2)))\n",
    "print('{0:c} is {1}'.format(97, chr(ord('a'))))\n",
    "print('abs(-2) = ', abs(-2))\n",
    "print(all([2 > 1, -1 > -2]))\n",
    "print(any((2, -1 < -2)))\n",
    "a, b, c = oct(8), hex(16), bin(2)\n",
    "print('{0}={1:o} and {2}={3:x} and {4:b}={5}'.format(a, 8, b, 16, 2, c))\n",
    "print('0b1010=', 0b1010)\n",
    "print(f'0o10={a}=oct(8)')\n",
    "print(f'0x10={b}=hex(16)')\n",
    "print(f'0b10={c}=bin(2)')\n",
    "print('test'.center(20, '='))\n",
    "print('test'.lower())\n",
    "print('test'.upper())\n",
    "print('test'.strip('t'))\n",
    "print(chr(12288).join('test'))\n",
    "a = u'iloveu' # python2中遍历字符串需要前加u\n",
    "print([i for i in a]) \n",
    "print('test'.find('t', 2))"
   ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "* 集合类型 (集合) 元素之间无序，相同元素在集合中唯一存在,集合中元素不可重复,元素类型只能是固定数据类型，例如：整数、浮点数等，列表、字典和集合类型本身都是可变数据类型，不能作为集合的元素出现。\n",
    "* 映射类型 (字典) 每个元素是一个键 值对，表示为(key, value)\n",
    "* 序列类型 (列表 元组 字符串) 是一维元素向量 元素之间存在先后关系，通过序号访问，元素之间不排他"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 7,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0 1\n",
      "['i']\n",
      "None\n",
      "['love']\n",
      "[]\n"
     ]
    }
   ],
   "source": [
    "# 集合 元组 列表 字典都可以用变量名加([])来创建\n",
    "a = list(['i','love'])\n",
    "print(a.index('i'),a.count('love'))\n",
    "# b = a[0:2] # 切片\n",
    "b = a[:]  # 浅拷贝 会复制一份，使地址发生变化\n",
    "d = a.copy() # 浅拷贝\n",
    "c = a # 仅仅是拷贝了地址，类似于贴了1个标签\n",
    "import copy\n",
    "a = [11,22]\n",
    "b = [22,33]\n",
    "c = [a,b]\n",
    "id(c) # 140300149367560\n",
    "d = copy.copy(c) # 浅拷贝可变类型比如列表时，地址会变，若是拷贝不可变类型比如元组，则地址不变，仅仅是多贴了1个标签(指向)\n",
    "id(d) # 140300149370696\n",
    "id(c[0]) # 140300149399496 但内部的引用不会变\n",
    "id(d[0]) # 140300149399496 地址一样\n",
    "e = copy.deepcopy(c)# 深拷贝可变类型时地址会变，拷元组时，若元组里面只有基本的数据，则是指向，地址不变，若元组里面有引用其他可变数据比如列表，则依然会将内部引用拷1份，造成地址改变\n",
    "#深拷贝一般用于对比较重要的数据进行实验，不修改源数据，而是用备份\n",
    "id(e) # 140300149370824\n",
    "id(e[0]) # 140300149369224内部的引用会变,即将内部列表一并拷了1份\n",
    "b.append('you')\n",
    "print(b[0:2:2])\n",
    "d.remove('i')\n",
    "print(d.reverse())\n",
    "print(sorted(d))\n",
    "c.clear()\n",
    "print(a)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 8,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "lang的口号是: program\n"
     ]
    }
   ],
   "source": [
    "# 在没用字典的情况下 用列表代替\n",
    "brand = ['li','nai','a','lang']#键key\n",
    "slogan = ['any','just','impossible','program']#值value\n",
    "print('lang的口号是:',slogan[brand.index('lang')])"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 16,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "{'f': 70, 'i': 105, 'a': 65}\n",
      "dict_keys([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31])\n",
      "dict_values(['an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an', 'an'])\n",
      "dict_items([(0, 'an'), (1, 'an'), (2, 'an'), (3, 'an'), (4, 'an'), (5, 'an'), (6, 'an'), (7, 'an'), (8, 'an'), (9, 'an'), (10, 'an'), (11, 'an'), (12, 'an'), (13, 'an'), (14, 'an'), (15, 'an'), (16, 'an'), (17, 'an'), (18, 'an'), (19, 'an'), (20, 'an'), (21, 'an'), (22, 'an'), (23, 'an'), (24, 'an'), (25, 'an'), (26, 'an'), (27, 'an'), (28, 'an'), (29, 'an'), (30, 'an'), (31, 'an')])\n",
      "None\n",
      "None\n",
      "(31, 'an')\n",
      "{0: 'an', 1: 'an', 2: 'an', 3: 'an', 4: 'an', 5: 'an', 6: 'an', 7: 'an', 8: 'an', 9: 'an', 10: 'an', 11: 'an', 12: 'an', 13: 'an', 14: 'an', 15: 'an', 16: 'an', 17: 'an', 18: 'an', 19: 'an', 20: 'an', 21: 'an', 22: 'an', 23: 'an', 24: 'an', 25: 'an', 26: 'an', 27: 'an', 28: 'an', 29: 'an', 30: 'an'}\n",
      "{} ====> {0: 'an', 1: 'an', 2: 'an', 3: 'an', 4: 'an', 5: 'an', 6: 'an', 7: 'an', 8: 'an', 9: 'an', 10: 'an', 11: 'an', 12: 'an', 13: 'an', 14: 'an', 15: 'an', 16: 'an', 17: 'an', 18: 'an', 19: 'an', 20: 'an', 21: 'an', 22: 'an', 23: 'an', 24: 'an', 25: 'an', 26: 'an', 27: 'an', 28: 'an', 29: 'an', 30: 'an'}\n",
      "{'a': ('65', '66', '67'), 'b': ('65', '66', '67'), 'c': ('65', '66', '67')} ('65', '66', '67')\n",
      "{'a': 65, 'b': ('65', '66', '67'), 'c': ('65', '66', '67'), 'd': '68', 'f': 70, 'i': 105}\n"
     ]
    }
   ],
   "source": [
    "# dict0 = dict([('f', 70), ('i', 105)])  #每一个键值组合称为项\n",
    "# dict0 = dict((('f', 70), ('i', 105)))\n",
    "dict0 = dict(f=70, i=105)  # 用关键字参数时,键不用引号,值随数据类型的格式写\n",
    "dict2 = {1:'one',2:'two',3:'three'}   #字典不是数据类型 是映射类型 可以直接用大括号创建\n",
    "dict0['a'] = 65  #在没规定字典的键的时候直接赋值会出错 此处直接赋值不会引起错误\n",
    "print(dict0)\n",
    "dict1 = {}.fromkeys(range(32), 'an') # 也可以只传入一个元组作为键 没有对应值\n",
    "print(dict1.keys()) # 返回所有的键信息 \n",
    "print(dict1.values()) # 返回所有的值信息 \n",
    "print(dict1.items()) # 返回所有的键值对 \n",
    "print(dict1.get('a', 'None')) # 键存在则返回相应值，否则返回默认值 不会改变原字典\n",
    "print(dict1.pop('b', 'None')) # 键存在则返回相应值，同时删除键值对，否则返回默认值 \n",
    "print(dict1.popitem()) # 随机从字典中随机取出一个键值对，以元组(key, value)形式返回 \n",
    "print(dict1)\n",
    "dict3 = dict1 #直接赋值会受原字典改变的影响 因为不会改变id地址\n",
    "dict3 = dict1.copy() #浅拷贝会改变id地址,原字典的键的改变并不影响dict3，但原字典内部键对应的值的改变会影响\n",
    "dict1.clear() # 删除所有的键值对 改变其中之一只会影响地址相同的\n",
    "print(dict1,'====>',dict3)\n",
    "dict2 = {}.fromkeys(('a','b','c'),('65','66','67'))\n",
    "print(dict2,dict2['b']) #字典中没有的键 直接访问会报错\n",
    "dict2.setdefault('d','68') #随即放进去 字典中没有特殊的顺序\n",
    "dict2.update(dict0) #随机更新\n",
    "print(dict2)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "<class 'dict'>\n",
      "<class 'set'>\n",
      "{1, (3, 4), 'a'}\n",
      "{2, 3}\n",
      "{1, 2, 3, 4, 'a', (3, 4)}\n",
      "{1, 4, 'a', (3, 4)}\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "tuple"
      ]
     },
     "execution_count": 19,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "num = {}\n",
    "print(type(num)) # <class 'dict'>\n",
    "num2 = {1,3}\n",
    "print(type(num2)) # <class 'set'>如果只有值 则被当成了集合\n",
    "set1 = {1, 2, 3, (3, 4), 'a'} #集合中的特性是唯一，会将重复的值去掉 可以利用该特性整理重复值 但得到的集合是无序的\n",
    "set2 = {2, 3, 4} \n",
    "# print(set1[0]) # 集合不可以访问单一的值\n",
    "set1.add(4)  # 如果数据项x不在集合S中，将x增加到s\n",
    "set1.remove(4)  # 如果4在集合Set1中，移除该元素；不在则产生 KeyError异常\n",
    "print(set1 - set2)  # 差集\n",
    "print(set1 & set2)  # 交集\n",
    "print(set1 | set2)  # 并集\n",
    "print(set1 ^ set2)  # 补集\n",
    "set1.clear()  # 移除Set1中所有数据项\n",
    "num3 = frozenset([1, 2, 3, 4, 5, 5])  # 可用来创建不可变集合\n",
    "# num3.add(3) # AttributeError: 'frozenset' object has no attribute 'add'\n",
    "\n",
    "exec('a = 100') # 等同于输入a=100\n",
    "\n",
    "tuple1 = tuple([1, 2, 3])\n",
    "type((2))  # int\n",
    "type((2,))  # tuple\n",
    "# 序列的方法：min max len index count"
   ]
  },
  {
   "cell_type": "raw",
   "metadata": {},
   "source": [
    ">>> def myfirstfunction(name):\n",
    "\t'''函数定义过程中的name叫形参\n",
    "\t因为这是一个形式，表示占据一个参数位置'''\n",
    "\tprint('传递进来的'+name+'叫做实参，因为这是具体的参数值')\n",
    "\n",
    ">>> myfirstfunction('me')\n",
    "传递进来的me叫做实参，因为这是具体的参数值\n",
    ">>> myfirstfunction.__doc__\n",
    "'函数定义过程中的name叫形参\\n\\t 因为这是一个形式，表示占据一个参数位置'\n",
    ">>> print.__doc__\n",
    "\"print(value, ..., sep=' ', end='\\\\n', file=sys.stdout, flush=False)\\n\\nPrints the values to a stream, or to sys.stdout by default.\\nOptional keyword arguments:\\nfile:  a file-like object (stream); defaults to the current sys.stdout.\\nsep:   string inserted between values, default a space.\\nend:   string appended after the last value, default a newline.\\nflush: whether to forcibly flush the stream.\"\n",
    ">>> def saysome(name,words):\n",
    "\tprint(name+'->'+words)\t\n",
    ">>> saysome('i','love you')#传递(调用)参数的方法有两种,这是位置参数,即按照默认位置来调用\n",
    "i->love you\n",
    ">>> saysome('love you','i') \n",
    "love you->i\n",
    ">>> saysome(words='love you',name='i')    #其中name,words为关键字参数,给定一个值\n",
    "i->love you\n",
    ">>> saysome()\n",
    "Traceback (most recent call last):\n",
    "  File \"<pyshell#15>\", line 1, in <module>\n",
    "    saysome()\n",
    "TypeError: saysome() missing 2 required positional arguments: 'name' and 'words'\n",
    ">>> def saysome(name='i',words='love you'):    #其中name,words为默认参数,i,love you为默认值\n",
    "\tprint(name+'->'+words)\t\n",
    ">>> saysome()\n",
    "i->love you\n",
    ">>> saysome('me')\n",
    "me->love you\n",
    ">>> saysome('she','love me')\n",
    "she->love me\n",
    ">>> def test(*params,exp):   #python默认会将*后面全当做收集参数\n",
    "\tprint('参数的长度是:',len(params));\n",
    "\tprint('第二个参数是:',params[1]);\t\n",
    ">>> test(1,'小和尚',3.14,5,6,7,8)\n",
    "Traceback (most recent call last):\n",
    "  File \"<pyshell#28>\", line 1, in <module>\n",
    "    test(1,'小和尚',3.14,5,6,7,8)\n",
    "TypeError:test() missing 1 required keyword-only argument:'exp'\n",
    ">>> test(1,'小和尚',3.14,5,6,7,8,exp=8) #解决方法为用关键字指定\n",
    "参数的长度是: 7\n",
    "第二个参数是: 小和尚\n",
    ">>> def test(exp,*params):     #或者将形式参数放在前面\n",
    "\tprint('参数的长度是:',len(params));\n",
    "\tprint('第二个参数是:',params[1]);\n",
    "\t\n",
    ">>> test(1,'小和尚',3.14,5,6,7,8)\n",
    "参数的长度是: 6\n",
    "第二个参数是: 3.14\n",
    ">>> def test(c,d,*args,**kwargs): # 多值不定长参数 
    "'''*告诉编译器在传入参数时，多传的通通给*args以元组身份保存,**用来接收多传的关键字参数作为字典'''\n",
    "    print(c,d)\n",
    "    print(args)\n",
    "    print('{0:=>20}'.format('*'))\n",
    "    print(kwargs)\n",
    ">>> test(1,2,(1,2,3,4),{'a':1,'b':2}) \n",
    "1 2\n",
    "((1,2,3,4),{'a':1,'b':2})\n", # 将后面都当成元组的元素传入
    "===================*\n",
    "{}\n",
    ">>> test(1,2,*(1,2,3,4),**{'a':1,'b':2})\n", # 需进行拆包\n",
    "1 2\n",
    "(1, 2, 3, 4)\n",
    "===================*\n",
    "{'a': 1, 'b': 2}\n",
    ">>> def hello():\n",
    "\tprint('hello fishc!')\n",
    "\t\n",
    ">>> temp = hello()\n",
    "hello fishc!\n",
    ">>> temp\n",
    ">>> print(temp)\n",
    "None\n",
    ">>> type(temp)\n",
    "<class 'NoneType'>\n",
    ">>> def back():\n",
    "\treturn [q1,'i',3]\n",
    "\n",
    ">>> back()\n",
    "Traceback (most recent call last):\n",
    "  File \"<pyshell#43>\", line 1, in <module>\n",
    "    back()\n",
    "  File \"<pyshell#42>\", line 2, in back\n",
    "    return [q1,'i',3]\n",
    "NameError: name 'q1' is not defined\n",
    ">>> def back():\n",
    "\treturn [1,'i',3.14]\n",
    "\n",
    ">>> back()\n",
    "[1, 'i', 3.14]\n",
    ">>> def back():\n",
    "\treturn 1,'i',3.14\n",
    "\n",
    ">>> back()\n",
    "(1, 'i', 3.14)\n",
    "#函数定义过程中的局部变量出了函数定义过程就不可使用，而函数定义过程外的变量为全局变量\n",
    "#在函数里面可以访问全局变量但不可以修改\n",
    ">>> count = 5\n",
    ">>> def myfun():\n",
    "\tcount = 10\n",
    "\tprint(10)\n",
    "\t\n",
    ">>> print(count)\n",
    "5\n",
    ">>> def myfun():\n",
    "\tglobal count#如果一定要改全局变量则用global关键字\n",
    "\tcount = 10\n",
    "\tprint(10)\n",
    "\t\n",
    ">>> myfun()\n",
    "10\n",
    ">>> print(count)\n",
    "10\n",
    ">>> def fun1():\n",
    "\tprint('fun1()正在被调用...')\n",
    "\tdef fun2():\n",
    "\t\tprint('fun2()正在被调用...')\n",
    "\tfun2()\n",
    "\n",
    "\t\n",
    ">>> fun1()\n",
    "fun1()正在被调用...\n",
    "fun2()正在被调用...\n",
    ">>> fun2()\n",
    "Traceback (most recent call last):\n",
    "  File \"<pyshell#37>\", line 1, in <module>#内嵌函数出了定义的函数之后就不能被调用了\n",
    "    fun2()\n",
    "NameError: name 'fun2' is not defined\n",
    ">>> def funx(x):\n",
    "\tdef funy(y):\n",
    "\t\treturn x*y  #在内部函数funy()里，引用外部作用域的变量x,则称funy()为闭包\n",
    "\treturn funy\n",
    "\n",
    ">>> funx(1)(3)\n",
    "3\n",
    ">>> i = funx(8)\n",
    ">>> type(i)\n",
    "<class 'function'>\n",
    ">>> def fun1():\n",
    "\tx = 5\n",
    "\tdef fun2():\n",
    "\t\tx*=x\n",
    "\t\treturn x  #闭包里面不可以用外部作用域的变量去赋值同样的变量名\n",
    "\treturn fun2()\n",
    "\n",
    ">>> fun1()\n",
    "Traceback (most recent call last):\n",
    "  File \"<pyshell#55>\", line 1, in <module>\n",
    "    fun1()\n",
    "  File \"<pyshell#54>\", line 6, in fun1\n",
    "    return fun2()\n",
    "  File \"<pyshell#54>\", line 4, in fun2\n",
    "    x*=x\n",
    "UnboundLocalError: local variable 'x' referenced before assignment\n",
    ">>> def abc():\n",
    "\tx = 1\n",
    "\tdef bcd():\n",
    "\t\tx = 2\n",
    "\t\treturn x   #但是可以直接赋值新的值\n",
    "\treturn bcd()\n",
    "\n",
    ">>> abc()\n",
    "2\n",
    ">>> def fun1():\n",
    "\tx = 5\n",
    "\tdef fun2():\n",
    "\t\tglobal x   #可以用global关键字改变\n",
    "\t\tx = 1\n",
    "\t\treturn x\n",
    "\treturn fun2()\n",
    "\n",
    ">>> fun1()\n",
    "1\n",
    ">>> def fun1():\n",
    "\tx = [5]\n",
    "\tdef fun2():\n",
    "\t\tx[0] *= x[0]   #也可以将变量改为元组\n",
    "\t\treturn x[0]\n",
    "\treturn fun2()\n",
    "\n",
    ">>> fun1()\n",
    "25\n",
    ">>> def fun1():\n",
    "\tx = 5\n",
    "\tdef fun2():\n",
    "\t\tnonlocal x   #也可以运用nonlocal关键字\n",
    "\t\tx *=x\n",
    "\t\treturn x\n",
    "\treturn fun2()\n",
    "\n",
    ">>> fun1()\n",
    "25\n",
    ">>> lambda x :2*x+1\n",
    "<function <lambda> at 0x000001F7A96F2438>#lambda表达式可以简化函数定义过程\n",
    ">>> g = lambda x :2*x+1\n",
    ">>> g(5)\n",
    "11\n",
    ">>> h = lambda x: x%2\n",
    ">>> list(filter(h,range(1,10)))#filter可以通过函数筛选可迭代区间中的值，默认筛选正数\n",
    "[1, 3, 5, 7, 9]\n",
    ">>> list(filter(None,[0,False,True]))\n",
    "[True]\n",
    ">>> list(filter(None,[0,1]))\n",
    "[1]\n",
    ">>> list(map(lambda x:x*2,range(10)))\n",
    "[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]#map可以将范围中的值带入函数中再返回值\n",
    ">>> def creatfile(name,content,censored_word='hello',changed_word='goodbye'):\n",
    "\tname = 'D:\\\\Users\\\\向致承\\\\Documents\\\\python\\\\'+name\n",
    "\tcontent = str(content.replace(censored_word,changed_word))\t\t   \n",
    "\tf = open(name,'w')\n",
    "\tf.write(content)\n",
    "\tprint('done')\n",
    ">>> creatfile('new2','hello word')#最后结果为goodbye world\n",
    "done"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "请输入原价：1000\n",
      "请输入折扣率:0.88\n",
      "这里试图打印全局变量 1000.0\n",
      "修改后的值为1 80\n",
      "修改后的值是2 80\n",
      "打折后的价格是: 880.0\n"
     ]
    },
    {
     "ename": "NameError",
     "evalue": "name 'final_price' is not defined",
     "output_type": "error",
     "traceback": [
      "\u001b[1;31m------------------------------------------------------------\u001b[0m",
      "\u001b[1;31mNameError\u001b[0m                  Traceback (most recent call last)",
      "\u001b[1;32m<ipython-input-9-7b39be55127f>\u001b[0m in \u001b[0;36m<module>\u001b[1;34m()\u001b[0m\n\u001b[0;32m     12\u001b[0m \u001b[0mprint\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;34m'修改后的值是2'\u001b[0m\u001b[1;33m,\u001b[0m\u001b[0mold_price\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0;32m     13\u001b[0m \u001b[0mprint\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;34m'打折后的价格是:'\u001b[0m\u001b[1;33m,\u001b[0m\u001b[0mnew_price\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[1;32m---> 14\u001b[1;33m \u001b[0mprint\u001b[0m\u001b[1;33m(\u001b[0m\u001b[1;34m'这里试图打印局部变量'\u001b[0m\u001b[1;33m,\u001b[0m\u001b[0mfinal_price\u001b[0m\u001b[1;33m)\u001b[0m\u001b[1;33m\u001b[0m\u001b[0m\n\u001b[0m",
      "\u001b[1;31mNameError\u001b[0m: name 'final_price' is not defined"
     ]
    }
   ],
   "source": [
    "def discounts(price,rate):\n",
    "    final_price = price*rate\n",
    "    global old_price # 若是要修改不可变类型的全局变量比如字符串则用global，若是要修改可变类型比如列表则不用global可以直接修改成功\n",
    "    print('这里试图打印全局变量',old_price)\n",
    "    old_price= 80\n",
    "    print('修改后的值为1',old_price)\n",
    "    return final_price\n",
    "\n",
    "old_price = float(input('请输入原价：'))\n",
    "rate = float(input('请输入折扣率:'))\n",
    "new_price = discounts(old_price,rate)\n",
    "print('修改后的值是2',old_price)\n",
    "print('打折后的价格是:',new_price)\n",
    "print('这里试图打印局部变量',final_price)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "x --> z\n",
      "x --> y\n",
      "z --> y\n",
      "x --> z\n",
      "y --> x\n",
      "y --> z\n",
      "x --> z\n",
      "1 1 2 3 5 8 13 21 34 55 "
     ]
    },
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "Warning, log file not found starting a new one\n"
     ]
    },
    {
     "ename": "SystemExit",
     "evalue": "",
     "output_type": "error",
     "traceback": [
      "An exception has occurred, use %tb to see the full traceback.\n",
      "\u001b[1;31mSystemExit\u001b[0m\n"
     ]
    },
    {
     "name": "stderr",
     "output_type": "stream",
     "text": [
      "D:\\anaconda\\lib\\site-packages\\IPython\\core\\interactiveshell.py:2969: UserWarning: To exit: use 'exit', 'quit', or Ctrl-D.\n",
      "  warn(\"To exit: use 'exit', 'quit', or Ctrl-D.\", stacklevel=1)\n"
     ]
    }
   ],
   "source": [
    "import sys\n",
    "sys.setrecursionlimit(100)#不可以轻易使用递归，要限制位数之后再使用\n",
    "def recursion():\n",
    "    return recursion()\n",
    "def fab(n):\n",
    "    if n == 0 or n==1:\n",
    "        return 1\n",
    "    else:\n",
    "        return n*fab(n-1)#求阶乘可用递归\n",
    "def fab(n):\n",
    "    i = 1\n",
    "    x = 1\n",
    "    while i!=n:#也可用while循环\n",
    "        i += 1\n",
    "        x = x*i\n",
    "    return x\n",
    "def fab(n):\n",
    "    result = n\n",
    "    for i in range(1,n):#也可用for循环\n",
    "        result *= i\n",
    "    return result\n",
    "fab(5)\n",
    "def hanoi(n,x,y,z):\n",
    "    if n == 1:\n",
    "        print(x,'-->',z)   \n",
    "    else:\n",
    "        hanoi(n-1,x,z,y)#将前n-1个盘子从x移动到y上 中间的z是借助针 xy分别为初始针和目的针\n",
    "        print(x,'-->',z)#将最底下的最后一个盘子从x移动到z上\n",
    "        hanoi(n-1,y,x,z)#将y上的n-1个移动到z上 x是借助针\n",
    "\n",
    "hanoi(3,'x','y','z')\n",
    "\n",
    "def fib(n):    #用迭代算斐波那契\n",
    "    n1 = 1\n",
    "    n2 = 1\n",
    "    n3 = 1\n",
    "    if n == 2 or n == 1:\n",
    "        return 1\n",
    "    while (n-2)>0:\n",
    "        n3 = n2 + n1\n",
    "        n1 = n2\n",
    "        n2 = n3\n",
    "        n = n-1\n",
    "    return n3\n",
    "\n",
    "def fib(n):\n",
    "    if n == 1 or n == 2:\n",
    "        return 1\n",
    "    else:\n",
    "        return fib(n-1)+fib(n-2)\n",
    "fib(8)\n",
    "\n",
    "def fib(max): \n",
    "   n, a, b = 0, 0, 1 \n",
    "   L = [] \n",
    "   while n < max: \n",
    "       L.append(b) \n",
    "       a, b = b, a + b \n",
    "       n = n + 1 \n",
    "   return L\n",
    "\n",
    "f = iter(fib(10))\n",
    "while True:\n",
    "    try:\n",
    "        print (next(f), end=\" \")\n",
    "    except StopIteration:\n",
    "        sys.stderr.write('Warning, log file not found starting a new one\\n')\n",
    "        sys.exit()"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 6,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "01-31-20. 31 Jan 2020 is a Friday on the 31 day of January.\n",
      "20272\n"
     ]
    }
   ],
   "source": [
    "from datetime import date\n",
    "now = date.today()\n",
    "print(now.strftime(\"%m-%d-%y. %d %b %Y is a %A on the %d day of %B.\"))\n",
    "birthday = date(1964, 7, 31)\n",
    "age = now - birthday\n",
    "print(age.days)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 9,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "41 37\n",
      "b'witch which has which witches wrist watch'\n"
     ]
    },
    {
     "data": {
      "text/plain": [
       "226805979"
      ]
     },
     "execution_count": 9,
     "metadata": {},
     "output_type": "execute_result"
    }
   ],
   "source": [
    "import zlib\n",
    "s = b'witch which has which witches wrist watch'\n",
    "t = zlib.compress(s)\n",
    "print(len(s),len(t))\n",
    "print(zlib.decompress(t))\n",
    "zlib.crc32(s)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 11,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0.11044700000002194\n",
      "0.046078599999873404\n"
     ]
    }
   ],
   "source": [
    "from timeit import Timer\n",
    "print(Timer('t=a;a=b;b=t','a=1;b=2').timeit())\n",
    "print(Timer('a,b=b,a','a=1;b=2').timeit())"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 2,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "755.0105955\n",
      "1581770100.5764608\n",
      "time.struct_time(tm_year=2020, tm_mon=2, tm_mday=15, tm_hour=12, tm_min=35, tm_sec=0, tm_wday=5, tm_yday=46, tm_isdst=0)\n",
      "time.struct_time(tm_year=2020, tm_mon=2, tm_mday=15, tm_hour=20, tm_min=35, tm_sec=0, tm_wday=5, tm_yday=46, tm_isdst=0)\n",
      "Sat Feb 15 20:35:00 2020\n",
      "1581741300.0\n",
      "time.struct_time(tm_year=2020, tm_mon=2, tm_mday=15, tm_hour=20, tm_min=35, tm_sec=0, tm_wday=5, tm_yday=46, tm_isdst=-1)\n",
      "205501.453\n",
      "game of guessing number\n"
     ]
    }
   ],
   "source": [
    "import time\n",
    "print(time.perf_counter())\n",
    "print(time.time())  # 获取当前时间戳,表示从1970年开始到现在经历的秒数\n",
    "print(time.gmtime())  # 获取当前美国时间戳对应的struct_time对象\n",
    "print(time.localtime())  # 获取当前时间戳对应的本地时间的struct_time对象\n",
    "# 注意结果与gmtime的区别,UTC时间已自动转换为北京时间。\n",
    "print(time.ctime())  # 获取当前时间戳对应的易读字符串表示,内部会调用time.localtime()函数以输出当地时间。\n",
    "print(time.mktime(time.gmtime()))  # 将struct_time对象t转换为时间戳\n",
    "lctime = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())  # 利用一个格式字符串，对时间格式进行表达\n",
    "print(time.strptime(lctime, '%Y-%m-%d %H:%M:%S'))  # 提取字符串中时间来生成strut_time对象\n",
    "print(time.monotonic())"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 3,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "0.5714025946899135\n",
      "5\n",
      "7\n",
      "13\n",
      "a\n",
      "12.060982321395016\n",
      "None\n",
      "['c', 'b', 'a']\n",
      "2\n"
     ]
    }
   ],
   "source": [
    "import random\n",
    "random.seed(10)  # 初始化随机数种子,默认值为当前系统时间,第二次设置同样的值再产生随机数则会产生一样的\n",
    "print(random.random())  # 生成一个[0.0, 1.0)之间的随机小数\n",
    "print(random.randint(2, 8))  # 生成一个[2,8]之间的整数\n",
    "print(random.randrange(10))  # 生成10之间的一个随机数\n",
    "print(random.randrange(1, 20, 3))  # 生成一个[1,20)之间以3为步数的随机整数\n",
    "print(random.choice(['a', 'b', 'c', 'd']))  # 从序列类型(例如：列表)中随机返回一个元素\n",
    "print(random.uniform(10, 20))  # 生成一个[10,20]之间的随机小数\n",
    "la = ['a', 'b', 'c', 'd']\n",
    "print(random.shuffle(la))  # 将序列类型中元素随机排列，返回打乱后的序列\n",
    "print(random.sample(la, 3))  # 从pop类型中随机选取k个元素，以列表类型返回\n",
    "print(random.getrandbits(3))  # 生成一个3比特长度的随机整数"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
       ]
  },
  {
   "cell_type": "markdown",
   "metadata": {},
   "source": [
    "[小甲鱼面向对象魔法方法](https://www.bilibili.com/video/av4050443?p=43)\n",
    "[黑马面向对象](https://www.bilibili.com/video/av14184325?p=368)"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": 1,
   "metadata": {},
   "outputs": [],
   "source": [
       ]
  },
  {
   "cell_type": "code",
   "execution_count": 14,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "u\n",
      "{'__module__': '__main__', '__init__': <function biology.__init__ at 0x00000242DD1502F0>, 'print_num': <function biology.print_num at 0x00000242DD1508C8>, '__dict__': <attribute '__dict__' of 'biology' objects>, '__weakref__': <attribute '__weakref__' of 'biology' objects>, '__doc__': None}\n",
      "{'animal': <__main__.animal object at 0x00000242DD152550>, 'person': <__main__.person object at 0x00000242DD152518>}\n",
      "{'animal': <__main__.animal object at 0x00000242DD152550>, 'person': <__main__.person object at 0x00000242DD152518>, 'x': 1}\n",
      "{'__module__': '__main__', '__init__': <function biology.__init__ at 0x00000242DD1502F0>, 'print_num': <function biology.print_num at 0x00000242DD1508C8>, '__dict__': <attribute '__dict__' of 'biology' objects>, '__weakref__': <attribute '__weakref__' of 'biology' objects>, '__doc__': None}\n",
      "u\n",
      "False\n",
      "True\n",
      "True\n",
      "False\n",
      "True\n",
      "你所访问的属性不存在\n",
      "new_attr\n"
     ]
    }
   ],
   "source": [
    ]
  },
  {
   "cell_type": "code",
   "execution_count": 19,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "10\n",
      "10\n",
      "18 18 <bound method fishc.getsize of <__main__.fishc object at 0x00000242DD14AEF0>>\n"]}],
   "source": [
    "class fishc:\n",
    "    def __init__(self,size = 10):\n",
    "        self.size = size\n",
    "    def getsize(self):\n",
    "        return self.size\n",
    "    def setsize(self,value):\n",
    "        self.size = value\n",
    "    def delsize(self):\n",
    "        del self.size\n",
    "    x = property(getsize,setsize,delsize) \n",
    "    # 三个参数分别是产生改变删除 对应属性的方法 将该属性的值赋值给新的属性\n",
    "c = fishc()\n",
    "print(c.getsize())\n",
    "print(c.x)\n",
    "c.x = 18\n",
    "print(c.x,c.size,c.getsize)\n"]}



# ipython
[详见CSDN](https://blog.csdn.net/lb245557472/article/details/80078882),
- Ctrl-P    或上箭头键 后向搜索命令历史中以当前输入的文本开头的命令,
- Ctrl-N   或下箭头键 前向搜索命令历史中以当前输入的文本开头的命令,
- Ctrl-R   按行读取的反向历史搜索（部分匹配）,
- Ctrl-Shift-v   从剪贴板粘贴文本,
- Ctrl-C   中止当前正在执行的代码,
- Ctrl-A   将光标移动到行首,
- Ctrl-E   将光标移动到行尾,
- Ctrl-K   删除从光标开始至行尾的文本,
- Ctrl-U   清除当前行的所有文本译注12,
- Ctrl-F   将光标向前移动一个字符,
- Ctrl-b   将光标向后移动一个字符,
- Ctrl-L   清屏,
+ %quickref 显示IPython 的快速参考,
+ %magic 显示所有魔术命令的详细文档,
+ %debug 从最新的异常跟踪的底部进入交互式调试器,
+ %hist 打印命令的输入历史,
+ %reset 删除interactive命名空间中的全部变量/名称,
+ %page OBJECT 通过分页器打印输出OBJECT,
+ %prun 通过cProfile 执行 statement，并打印分析器的输出结果,
+ %who、%who_ls、%whos 显示interactive 命名空间中定义的变量，信息级别/冗余度可变,
+ %xdel variable 删除变量，并尝试清除其在ipython中的对象上的一切引用,
+ %run + 文件名 执行文件代码,
+ %paste %cpaste 执行剪切板里面的代码,
+ %timeit + 函数 对此运行函数求所需时间的平均值 ,
+ %pdb on/off [打开/关闭调试代码] p [打印出各种值] q [退出],
+ `_`一个下划线表示上一个历史命令,`__`两个下划线代表上两个历史命令,
+ `_34` 显示第34行的输出代码 `_i34` 显示第34行的输入代码,
+ 输入a之后按上下方向键就只会出现啊开头的历史命令,
+ %bookmark,
+ func?? 函数名加两个问号可以看到函数定义的代码,
+ a = [];a.a*? 查询a开头的方法,
+ 直接运行ipconfig不行,需要加个叹号：!ipconfig,
# pdb 命令
+    1）进入命令行Debug模式，python -m pdb xxx.py,
+    2）h：（help）帮助,
+    3）w：（where）打印当前执行堆栈,
+    4）d：（down）执行跳转到在当前堆栈的深一层（个人没觉得有什么用处）,
+    5）u：（up）执行跳转到当前堆栈的上一层,
+    6）b：（break）添加断点,
> + 列出当前所有断点，和断点执行到统计次数,
> + line_no：当前脚本的line_no行添加断点,
> + filename:line_no：脚本filename的line_no行添加断点,
> + function：在函数function的第一条可执行语句处添加断点,
+    7）tbreak：（temporary break）临时断点,
> + 在第一次执行到这个断点之后，就自动删除这个断点，用法和b一样,
+    8）cl：（clear）清除断点,
> + 清除所有断点,
> + bpnumber1 bpnumber2... 清除断点号为bpnumber1,bpnumber2...的断点,
> + lineno 清除当前脚本lineno行的断点,
> + filename:line_no 清除脚本filename的line_no行的断点,
+    9）disable：停用断点，参数为bpnumber，和cl的区别是，断点依然存在，只是不启用,
+    10）enable：激活断点，参数为bpnumber,
+    11）s：（step）执行下一条命令,
> + 如果本句是函数调用，则s会执行到函数的第一句,
+    12）n：（next）执行下一条语句,
> + 如果本句是函数调用，则执行函数，接着执行当前执行语句的下一条。,
+    13）r：（return）执行当前运行函数到结束,
+    14）c：（continue）继续执行，直到遇到下一条断点,
+    15）l：（list）列出源码,
> + 列出当前执行语句周围11条代码,
> + first 列出first行周围11条代码,
> + first second 列出first--second范围的代码，如果second<first，second将被解析为行数,
+    16）a：（args）列出当前执行函数的函数,
+    17）p expression：（print）输出expression的值,
+    18）pp expression：好看一点的p expression,
+    19）run：重新启动debug，相当于restart,
+    20）q：（quit）退出debug,
+    21）j lineno：（jump）设置下条执行的语句函数,
> + 只能在堆栈的最底层跳转，向后重新执行，向前可直接执行到行号,
+    22）unt：（until）执行到下一行（跳出循环），或者当前堆栈结束,
+    23）condition bpnumber conditon，给断点设置条件，当参数condition返回True的时候bpnumber断点有效，否则bpnumber断点无效