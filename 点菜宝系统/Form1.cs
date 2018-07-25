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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text == "")
            {
                MessageBox.Show("请输入用户名");
            }
            else if (textBox2.Text == "")
            {
                MessageBox.Show("请输入密码");
            }
            else
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
                SqlCommand sqlselect = new SqlCommand("SELECT * from[用户表]where xingming='" + textBox1.Text.ToString().Trim() + "'and mima='" + textBox2.Text.ToString().Trim() + "'", objConnection);
                SqlDataReader c = sqlselect.ExecuteReader();
                if (c.Read())
                {
                    Form3 f3 = new Form3();
                    f3.Show();
                    this.Hide();
                }
                else if (!c.Read())
                {
                    
                    MessageBox.Show("请检查用户名或密码是否正确，请重新输入");
                    c.Close();
                    return;
                }

                /*string selectsql = "select* from dbo.用户表;";
                 DataSet ds = new DataSet();
                 SqlDataAdapter objAdapter=new SqlDataAdapter();
                 objAdapter.SelectCommand=new SqlCommand(selectsql,objConnection);
                 objAdapter.Fill(ds, "用户表");*/

            }
        }
        

        private void button3_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "";
        }
    }
}
