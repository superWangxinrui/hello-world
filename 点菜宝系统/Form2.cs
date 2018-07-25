using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace can_yin_guan_li
{     
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
        }
        string str;
        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "") MessageBox.Show("请输入用户名");
            else if (textBox2.Text == "") MessageBox.Show("请输入密码");
            else if (textBox3.Text == "") MessageBox.Show("请确认密码");
            else  if (textBox4.Text == "") MessageBox.Show("请输入手机号");
            else if (textBox3.Text == textBox2.Text)
            {
                string strConnection = "Data Source=(localdb)\\Projects;Initial Catalog=can_yin_guan_li;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False";
                SqlConnection objConnection = new SqlConnection(strConnection);
                try
                {
                    objConnection.Open();
                }
                catch
                {
                    MessageBox.Show("数据库连接失败");
                }
                //MessageBox.Show("数据库连接成功");
                if (radioButton1.Checked == true) str = radioButton1.Text;
                if (radioButton2.Checked == true) str = radioButton2.Text;
                string insertSql = "insert into dbo.用户表 values('" + textBox1.Text.ToString() + "','" + textBox2.Text + "','" +str +"','" + textBox4.Text + "','" + textBox5.Text + "','" + textBox6.Text + "' )";
                SqlCommand cmd = new SqlCommand(insertSql, objConnection);
                 
                try
                {
                    cmd.ExecuteNonQuery();
                }
                catch
                {
                    MessageBox.Show("注册失败,检查用户名是否重复");
                }

                MessageBox.Show("注册成功");
                objConnection.Close();
            }
            else
            {
                MessageBox.Show("两次密码输入不一样，请重新输入");
            }

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 f1 = new Form1();
            f1.Show();
            this.Hide();
        }
    }
}
