using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Net.Sockets;
using System.Net;

namespace test
{
    public partial class ChatRoom : Form
    {
        public ChatRoom()
        {
            InitializeComponent();
        }
        String IP;
        int port;
        Socket ClientSocket;
        string line = "\n";
        string name;
        bool conn = false;
        private void button1_Click(object sender, EventArgs e)
        {
            if(conn)
            {
                MessageBox.Show("已连接!", "错误");
                return;
            }

            IP = ipBox.Text;//服务器ip
            port = int.Parse(portBox.Text);//端口
            name = "["+nickName.Text + "]:";
            //清空文本框内容
            ipBox.Clear();
            portBox.Clear();
            nickName.Clear();
            //建立连接
            ClientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);//使用指定的地址簇协议、套接字类型和通信协议
            IPAddress ip = IPAddress.Parse(IP);  //将IP地址字符串转换成IPAddress实例
            IPEndPoint ip_port = new IPEndPoint(ip, port); // 用指定的ip和端口号初始化IPEndPoint实例
            //ClientSocket.Blocking = false;//设置非阻塞
            try
            {
                ClientSocket.Connect(ip_port);  //与远程主机建立连接
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误");
            }
            conn = true;
            //显示建立连接的服务器ip与端口号
            show_ip.Text = "服务器: " + IP;
            show_port.Text = "端口号: " + port.ToString();

            //响应接收信息
            ClientSocket.BeginReceive(buffer, 0, buffer.Length, SocketFlags.None, new AsyncCallback(ReceiveMessage), ClientSocket);
        }
        static byte[] buffer = new byte[1024];
        public void ReceiveMessage(IAsyncResult ar)
        {
            try
            {
                var socket = ar.AsyncState as Socket;
                var length = socket.EndReceive(ar);
                //读取出来消息内容
                var message = Encoding.UTF8.GetString(buffer, 0, length);
                //显示消息
                chatBox.Text += line + DateTime.Now.ToLongTimeString().ToString() + line + message;
                //接收下一个消息(因为这是一个递归的调用，所以这样就可以一直接收消息了）
                socket.BeginReceive(buffer, 0, buffer.Length, SocketFlags.None, new AsyncCallback(ReceiveMessage), socket);
            }
            catch (Exception ex)
            {
               
            }
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
        }

        private void disBtn_Click(object sender, EventArgs e)
        {
            if (!conn)
            {
                MessageBox.Show("已断开!", "错误");
                return;
            }
            try
            {
                chatBox.Text += line + DateTime.Now.ToLongTimeString().ToString() + line + "与服务器断开";//显示断开提示
                //清除ip与端口显示
                show_ip.Text = "";
                show_port.Text = "";
                ClientSocket.Close();//关闭套接字
                conn = false;
            }
            catch
            {
            }
        }

        private void sendBtn_Click(object sender, EventArgs e)
        {
            if ("" != inputBox.Text)//输入框不能为空
            {
                byte[] send = Encoding.UTF8.GetBytes(name + inputBox.Text); //通信时实际发送的是字节数组，所以要将发送消息转换字节
                try
                {
                    ClientSocket.Send(send);//发送消息
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
                chatBox.Text += line + DateTime.Now.ToLongTimeString().ToString() + line + name + inputBox.Text;//将发送消息推送到聊天框
                inputBox.Clear();//消息框清除

            }
            else
            {
                MessageBox.Show("输入为空！", "错误");
            }
        }


        private void ChatRoom_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            chatBox.Clear();
        }
    }
}
