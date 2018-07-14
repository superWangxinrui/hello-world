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
using System.Data.OleDb;
namespace can_yin_guan_li
{

    public partial class Form3 : Form
    {
        public string str = "";
        public Form3()
        {
            InitializeComponent();
            fill();
        }


        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
        private void fill()
        {
            //  this.dataGridView1.Rows.Add();
            //this.dataGridView1.Rows[0].Cells[1].Value = "手撕包菜";
            //this.dataGridView1.Rows[0].Cells[2].Value = "10";


        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
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
                DataSet ds = new DataSet();
                SqlDataAdapter sda = new SqlDataAdapter("SELECT * from[菜单] where 类别='recai'", objConnection);
                sda.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("付款成功！");
           


        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked == true)
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
                DataSet ds = new DataSet();
                SqlDataAdapter sda = new SqlDataAdapter("SELECT * from[菜单] where 类别='liangcai'", objConnection);
                sda.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0].DefaultView;
            }
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton3.Checked == true)
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
                DataSet ds = new DataSet();
                SqlCommand cmd = new SqlCommand("SELECT * from[菜单] where 类别='zhushi'", objConnection);
                SqlDataAdapter sda = new SqlDataAdapter();
                sda.SelectCommand = cmd;
                sda.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];

            }

        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {
            //int a = this.dataGridView1.CurrentRow.Index;
            if (dataGridView1.SelectedRows.Count > 0)
            {
                str = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            }
            //int a = this.dataGridView1.CurrentRow.Index;
            // string str1 = this.dataGridView1.SelectedRows[a].Cells[2].Value.ToString();




        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 f1 = new Form1();
            f1.Show();
            this.Hide();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SelectedRows.Count > 0)
            {
                str = dataGridView1.CurrentRow.Cells[0].Value.ToString();
                MessageBox.Show(str);
                //Form4 f4 = new Form4();
                //f4.Show();
                //this.Hide();
            }

        }

        private void button4_Click(object sender, EventArgs e)
        {
            //int a = this.dataGridView1.CurrentRow.Index;
            string str = this.dataGridView1.SelectedCells[2].Value.ToString();
            textBox1.Text = str;
        }
    }
}
